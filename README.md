# Car-FreeRTOS

This is a project to build a car with FreeRTOS.

## Hardware
- IR sensors: lane keeping assistance.
- Joystick: we use it for car movements.
- 7-Segment display (4 digit): we can see readings from the joystick. 
-  Breadboard and Jumpers: connecting components.
- Headlights, IDR module, lamps: control light intensity of the car.
- MP3 module, speaker, SD card: control car sound system.

## Libraries used:
- Arduino.h: contains the supporting info the "main" needs to function.
- SoftwareSerial.h: allows serial communication on other digital pins of
an Arduino board using software to replicate the functionality.
- DFRobotDFPlayerMini.h: controls DFPlayer module.
- <Arduino_FreeRTOS.h>: creating and managing tasks, semaphores,mutexes, and other FreeRTOS features.
- <stdio.h>: used for file manipulation and input/output operations.
- <time.h>: date and time manipulation; for example, to get the current time, format time and date, measure time intervals and so on. 
- <semphr.h>: creating and using semaphores.

## Tasks Priorities:
1. Lane Keeping assistance and Headlights: because they’re safety measures and safety comes first.
2. Gear: car movements.
3. Speaker: it’s a luxury thing, so it comes last.


### Inputs:
We have the following inputs:
- IR: black object detection to detect lane. • LDR: light intensity, sensor.
- Joystick: car movements.
- Button: pause and play.
- Button: next.

### Outputs:
- LED: turns on based on LDR.
- Motors: turns on and off based on the lane.
- Speaker: on/off with a button; next with a button: based on what the
user wants to listen to.
- 7-Segment: readings from the joystick (4 directions).

### Requirements:

1. Lane Keeping Assist (LKA)
   - Autonomous lane departure system that detects if the vehicle is leaving its lane using sensors.
   -  It will gently steer the car back into the lane if it begins to drift out of it while alerting the driver.

2. Control Indicators (CI)
   - Current Gear.
      - Display the current gear on a 7-Segment display.
    - Adaptive Headlights.
       - Adapt the car headlights according to the surrounding light intensity.
    #### Requirements
        -  The current gear should reflect one of the four automatic gears (P,D,N,R).
        - You should be able to change gears via a joystick, however, it is not a must to control the car using the gears.
        -The light intensity should be detected using a sensor, and automatically adapt the car’s headlights represented as LEDs.

3. Sound System (SS)
     -  You should play MP3 files via a speaker on the car.
     - You should control the system to implement the following operations:
       - Play/Pause 
       - Next


## How to run the code:
1. Download the code from the repository.
2. Open the code in Arduino IDE.
3. Connect the hardware to the Arduino board.
4. Upload the code to the Arduino board.
5. Enjoy the car!


## Demo: 

- [Demo 1](https://drive.google.com/file/d/1o9DvnJZurKMH3aSuHdu3h5I3TROgshpH/view?usp=sharing)
- [Demo 2](https://drive.google.com/file/d/1IvtAw24sfUH9W3ZRSh44HawsGkrdgLu9/view?usp=sharing)
