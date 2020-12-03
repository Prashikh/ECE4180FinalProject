#include "mbed.h"
#include "rtos.h"
#include "mbed.h"
#include "Motor.h"

Motor bl_dcmotor(p23, p6, p5); // pwm, fwd, rev
RawSerial  pc(USBTX, USBRX);

Serial blue(p28,p27);
AnalogIn photoSensor(p20);
Mutex position_mutex;
Mutex desired_bright_mutex;

volatile float lightSensorReading = 0.0f;
volatile float desired_brightness = 0.0f;
volatile float diff;
bool isAutomatic = false;
bool moveUp = false;
bool moveDown = false;

Thread thread1;
Thread thread2;
Thread thread3;
  
//thread for brightness thread
void brightnessReader()
{
  while(1)
  {
    desired_bright_mutex.lock();
    lightSensorReading = (photoSensor < 0.3f) ? photoSensor / 0.3f : 1.0f;
    diff = desired_brightness - lightSensorReading;
    printf("Diff: %.4f | Desired_bright: %.4f | LightSensorReading: %.4f\n", diff, desired_brightness, lightSensorReading);
    desired_bright_mutex.unlock();
    Thread::wait(500);  
  }
}

void motorController() {
  while(1)
  {
    if (isAutomatic) 
    {
      if (diff < -0.05f) //too bright
      {
        position_mutex.lock();
        // adjust position
        while (diff < -0.05f && isAutomatic) {
            bl_dcmotor.speed(0.7f);
        }
        bl_dcmotor.speed(0.0f);
        position_mutex.unlock();
        // dim the shades by one increment
      } else if (diff > 0.05f) //too dim
      {
        position_mutex.lock();
        //adjust position
        while (diff > 0.05f && isAutomatic) {
         bl_dcmotor.speed(-0.7f); 
        }
        bl_dcmotor.speed(0.0f);
        position_mutex.unlock();
        // open the shades by one increment
      }
    } else {
      if (moveUp) {
       bl_dcmotor.speed(0.7f);
       Thread::wait(1000);
       bl_dcmotor.speed(0.0f);
       moveDown = false;
       moveUp = false;
      } else if (moveDown) {
       bl_dcmotor.speed(-0.7f);
       Thread::wait(1000);
       bl_dcmotor.speed(0.0f);
       moveDown = false;
       moveUp = false;
      }
    }
  }
}
//thread for bluetooth input thread
void bluetoothReader()
{
  pc.printf("| bluetooth Reader Entered |\n");
  char bnum;
  char bhit;

  while(1) {
    // char dummy = blue.getc();
    if (blue.getc()=='!'){ //button data
      if (blue.getc() == 'B'){
        bnum = blue.getc();
        bhit = blue.getc();

        switch (bnum) {
          case '1': //number button 1
            if (bhit == '1') {
              desired_bright_mutex.lock();
              //add hit code here
              pc.printf("| Bluetooth button: 1 |\n");
              desired_brightness = 0.0f;
              desired_bright_mutex.unlock();
              isAutomatic = true;
            }
              break;

          case '2': //number button 2
            if (bhit == '1') {
              desired_bright_mutex.lock();
              pc.printf("| Bluetooth button: 2 |\n");
                    //add hit code here
              desired_brightness = 0.3f;
              isAutomatic = true;
              desired_bright_mutex.unlock();
            }
            break;

          case '3': //number button 3
            if (bhit == '1') {
              desired_bright_mutex.lock();
              pc.printf("| Bluetooth button: 3 |\n");
                    //add hit code here
              desired_brightness = 0.6f;
              isAutomatic = true;
                
              desired_bright_mutex.unlock();
            }
            break;

          case '4': //number button 4
            if (bhit == '1') {
              desired_bright_mutex.lock();
              pc.printf("| Bluetooth button: 4 |\n");
              desired_brightness = 1.0f;
              isAutomatic = true;
                
              desired_bright_mutex.unlock();
            }
            break;

          case '5': //button 5 up arrow
            if (bhit == '1') {
              pc.printf("| Bluetooth button: 5 |\n");
              isAutomatic = false;
              moveUp = true;
            }
            break;

          case '6': //button 6 down arrow
            if (bhit == '1') {
              pc.printf("| Bluetooth button: 6 |\n");
              isAutomatic = false;
              moveDown = true;
            }
            break;

          default:
              break;
        }
        Thread::wait(500);

      }
    }
  }
}


int main()
{
    thread1.start(brightnessReader);
    thread2.start(bluetoothReader);
    pc.printf("starting up motor Controller \n");
    thread3.start(motorController);

//  while(1)
//  { 
//    printf("Diff: %.4f | Desired_bright: %.4f | LightSensorReading: %.4f\n", diff, desired_brightness, lightSensorReading);
//    wait(2);    
//  }  
}