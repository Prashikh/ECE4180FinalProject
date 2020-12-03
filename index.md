# Welcome to Our ECE 4180 Final Project : Bluetooth Controller Blinds

## About the Project
With home automation and IoT at the fore front of mordern home innovation, we decided to make the blinds control in ones room wireless.  

Contrary to the popular approach of making an all-in-one “smart blind” that can be controlled via a smartphone app, we aim to create a simpler and cheaper device that serves the same purpose on any regular set of blinds. 

The motor will be remotely controlled via a bluetooth connection, with all related processing being done using the mbed device. We aim to create new drivers for this device and conclude with a product that stresses ease of use and low cost.

## Our Team
<img src="https://user-images.githubusercontent.com/36117814/101086049-4eda1a80-357e-11eb-9b03-f182d7b89dd2.png" width="300"/> 
<img src="https://user-images.githubusercontent.com/36117814/101086058-513c7480-357e-11eb-8aa2-7b12cd6b55ab.png" width="300"/> 
<img src="https://user-images.githubusercontent.com/36117814/101086068-53063800-357e-11eb-80c4-fbec527a8928.png" width="300">

## Parts Used
1. ARM MBED Microcontroller
2. Adafruit Bluefruit LE UART Friend - BLE
3. Sparkfun H-Bridge
4. BlueFruit Phone Application

## Schematic
In progress

## Source Code
The source is uploaded at our GitHub Repository. The link to our repository is - https://github.com/Prashikh/ECE4180FinalProject.git
## Media
Add photos and videos of the project

## Instructions and setup
### Setup
<img src="https://user-images.githubusercontent.com/36117814/101091843-bdbb7180-3586-11eb-9525-a35a6bdbf6b4.png" width="400"/>
<br>

1. This block diagram explains on a high level how the device is going to work. The Mbed Microcontroller, with a Bluetooth module, will be able to communicate with the AdaFruit Bluetooth Mobile Application.
2. A luminosity sensor will be used to create various blind position profiles to main a certain luminosity value in a room via the window. Using the luminosity sensor and the Bluetooth AdaFruit application as inputs, the mbed would use a motor to control the incline of the blinds.
3. The circuit requires 2 power sources. One for the microcontroller and one for the motor.
4. The photo transisitor is connected directly to the microcontroller which controls the amount of current flowing in the circuit depending on the amount of light falling on the transistor. This value is returned to the board as an Analog In. 
5. For the motor, the board is connected to an H bridge which controls the forward and backward movement of the motor. This is required as we need the motor to be able to turn in both forward and backward direction to move the blinds up and down respectively.

### Image Circuit
!<img src="https://user-images.githubusercontent.com/36117814/101094050-ca8d9480-3589-11eb-831d-d7c7ba40b734.jpeg" width="800">

### Instructions
 1. Connect the microcontroller and the motor to power. Make sure that the motor is connected properly in order to maintain the polarity of the motor.
 2. Download the 'BlueFruit Connect' mobile application on your phone and connect to the Bluetooth Module which should show up as 'Adafruit Bluefruit LE'.
 <img src="https://user-images.githubusercontent.com/36117814/101096547-b481d300-358d-11eb-83bd-e96aa7596998.jpg" width="400"/>
<br>
 3. On connecting with the Device, you will see the following screens. Choose Controller > Control Pad
 <p float="left">
  <img src="https://user-images.githubusercontent.com/36117814/101096820-20fcd200-358e-11eb-8e1b-e78860218410.PNG" width="250"/>
  <img src="https://user-images.githubusercontent.com/36117814/101096821-20fcd200-358e-11eb-93fd-f05456484648.PNG" width="250"/> 
  <img src="https://user-images.githubusercontent.com/36117814/101096822-21956880-358e-11eb-90b8-0725aa47d429.PNG" width="250"/> 
</p>
4. In the control pad, the following buttons do the following:
  - 
<br>
