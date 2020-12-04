# Welcome to Our ECE 4180 Final Project : Bluetooth Controlled Blinds

## About the Project
With home automation and IoT at the forefront of modern home innovation, we decided to make a device that would automate the operation of a set of blinds in one's room.  

Contrary to the popular approach of making an all-in-one “smart blind” that can be controlled via a smartphone app, we aimed to create a simpler and cheaper device that serves the same purpose on any regular set of blinds. 

The motor is remotely controlled via a bluetooth connection, with all related processing being done using the mbed device. We aim to create new drivers for this device and conclude with a product that stresses ease of use and low cost.

## Our Team
Team Name: Useful Idiots

<p float="left">
  <img src="https://user-images.githubusercontent.com/36117814/101086049-4eda1a80-357e-11eb-9b03-f182d7b89dd2.png" width="300"/>
  <img src="https://user-images.githubusercontent.com/36117814/101086058-513c7480-357e-11eb-8aa2-7b12cd6b55ab.png" width="300"/>
  <img src="https://user-images.githubusercontent.com/36117814/101086068-53063800-357e-11eb-80c4-fbec527a8928.png" width="300">
</p>
Our team (L to R): Cameron Davis, Prashikh Agrawal, Ebitimi Orubina

## Parts Used
1. ARM Mbed Microcontroller
2. Adafruit Bluefruit LE UART Friend - BLE
3. Sparkfun H-Bridge
4. DC - Motor
5. Photo Transistor Light Sensor
6. BlueFruit Phone Application

## Schematic
<img src="https://user-images.githubusercontent.com/44678943/101104986-66bf9780-359a-11eb-9f3a-dc1745bc5b30.png" width="800"/>

## Source Code
The source is uploaded at our GitHub Repository. The link to our repository is - https://github.com/Prashikh/ECE4180FinalProject.git
## Media
<br>
The circuit connected to the blinds.
<br>
<img src="https://user-images.githubusercontent.com/36117814/101101279-38d85400-3596-11eb-9565-5163225d76c5.jpg" width="600"/>
<img src="https://user-images.githubusercontent.com/44678943/101104390-ff551800-3598-11eb-9714-2a7cd96bd15e.jpg" width="600"/>
<img src="https://user-images.githubusercontent.com/44678943/101104455-257ab800-3599-11eb-911c-2342a997c4c2.jpg" width="600"/>

## Instructions and setup
### Setup
<img src="https://user-images.githubusercontent.com/36117814/101091843-bdbb7180-3586-11eb-9525-a35a6bdbf6b4.png" width="600"/>

1. This block diagram explains on a high level how the device works. The Mbed Microcontroller, with a Bluetooth module, will be able to communicate with the AdaFruit Bluetooth Mobile Application.
2. A luminosity sensor will be used to create various blind position profiles to main a certain luminosity value in a room via the inclination of the blinds. Using the luminosity sensor and the Bluetooth AdaFruit application as inputs, the mbed uses a motor to control the incline of the blinds.
3. The circuit requires 2 power sources: one for the microcontroller and one for the motor.
4. The photo transisitor is connected directly to the microcontroller, which controls the amount of current flowing in the circuit depending on the amount of light falling on the transistor. This value is returned to the board as an Analog In. 
5. For the motor, the board is connected to an H bridge which controls the forward and backward movement of the motor. This is required as we need the motor to be able to turn in both forward and backward direction to move the blinds up and down respectively.

### Image Circuit
<img src="https://user-images.githubusercontent.com/36117814/101094050-ca8d9480-3589-11eb-831d-d7c7ba40b734.jpeg" width="800">

### Instructions
 1. Connect the microcontroller and the motor to power. Make sure that the motor is connected properly in order to maintain the polarity of the motor.
 2. Download the 'BlueFruit Connect' mobile application on your phone and connect to the Bluetooth Module, which should then show up as 'Adafruit Bluefruit LE'.
 <img src="https://user-images.githubusercontent.com/36117814/101096547-b481d300-358d-11eb-83bd-e96aa7596998.jpg" width="400"/>
<br>
 3. Upon connecting with the Device, you will see the following screens. Choose <em>Controller -> Control Pad</em>
 <p float="left">
  <img src="https://user-images.githubusercontent.com/36117814/101096820-20fcd200-358e-11eb-8e1b-e78860218410.PNG" width="250"/>
  <img src="https://user-images.githubusercontent.com/36117814/101096821-20fcd200-358e-11eb-93fd-f05456484648.PNG" width="250"/> 
  <img src="https://user-images.githubusercontent.com/36117814/101096822-21956880-358e-11eb-90b8-0725aa47d429.PNG" width="250"/> 
</p>
4. In the control pad, the buttons do the following:
	
    - The Up Button : Moves the blinds up.
    - The Down Button :  Moves the blinds down.
    - 1 Button : Sets desired brightness to 0%
    - 2 Button : Sets desired brightness to 33%
    - 3 Button : Sets desired brightness to 66%
    - 4 Button : Sets desired brightness to 100%
 <img src="https://user-images.githubusercontent.com/36117814/101098158-733ef280-3590-11eb-9c55-4d44cd317fce.png" width="500"/>
 
## Video Demo

[![Demo Video Picture](http://img.youtube.com/vi/589KhcMjkko/0.jpg)](http://www.youtube.com/watch?v=589KhcMjkko "DEMO Video")

## Final Presentation PDF
[embed]https://docs.google.com/viewer?url=https://github.com/Prashikh/ECE4180FinalProject/files/5640051/FinalProjectPresentation.pdf[/embed]
