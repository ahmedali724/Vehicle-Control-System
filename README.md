This repository contains an implementation of a Vehicle Control System that simulates the functionalities of a vehicle's engine control and sensor readings. The system allows the user to interact with various features of the vehicle and observe its state.

Specifications
1. User Interaction
The program provides the following options to the user:

a. Turn on the vehicle engine
b. Turn off the vehicle engine
c. Quit the system
2. Quitting the System
If the user selects "Quit the system," the program will exit.

3. Turning Off the Engine
If the user chooses "Turn off the vehicle engine," they will be prompted again with the options mentioned in Requirement 1.

4. Displaying System State
After any choice is made, the current system state will be displayed on the screen.

5. Turning On the Engine and Sensor Readings
If the user selects "Turn on the vehicle engine," the program will enter the "Sensors set menu" where the user can interact with sensor readings. The menu includes the following options:

a. Turn off the engine
b. Set the traffic light color
c. Set the room temperature (Temperature Sensor)
d. Set the engine temperature (Engine Temperature Sensor)

6. Continuous Display of Sensor Menu
While the engine is ON, the sensor menu (Requirement 5) will always be displayed, waiting for the user's input.

7. Responding to Sensor Data
Based on the user's choices from the sensor menu:

a. If the traffic light is 'G,' set vehicle speed to 100 km/hr

b. If the traffic light is 'O,' set vehicle speed to 30 km/hr

c. If the traffic light is 'R,' set vehicle speed to 0 km/hr

i. If the room temperature is less than 10 or greater than 30, turn on the AC and set the temperature to 20. Otherwise, turn off the AC.

ii. If the engine temperature is less than 100 or greater than 150, turn on the "Engine Temperature Controller" and set the temperature to 125. Otherwise, turn off the "Engine Temperature Controller."

d. If the vehicle speed is 30 km/hr, turn on the AC if it was off and set room temperature to: current temperature * (5/4) + 1. Turn on "Engine Temperature Controller" if it was off and set engine temperature to: current temperature * (5/4) + 1.

Display the current vehicle state, including:

Engine state: ON/OFF
AC: ON/OFF
Vehicle Speed
Room Temperature
Engine Temperature Controller State
Engine Temperature
8. Turning Off the Engine
If the user selects "Turn off the engine" in the sensor menu, the menu from Requirement 1 will be displayed again.
