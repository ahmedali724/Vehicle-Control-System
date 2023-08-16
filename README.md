This repository contains an implementation of a Vehicle Control System that simulates the functionalities of a vehicle's engine control and sensor readings. The system allows the user to interact with various features of the vehicle and observe its state.

# Specifications

### User Interaction
The program provides the following options to the user:

1. Turn on the vehicle engine

2. Turn off the vehicle engine

3. Quit the system

### Quitting the System
If the user selects "Quit the system," the program will exit.

### Turning Off the Engine
If the user chooses "Turn off the vehicle engine," they will be prompted again with the options mentioned in Requirement 1.

### Displaying System State
After any choice is made, the current system state will be displayed on the screen.

### Turning On the Engine and Sensor Readings
If the user selects "Turn on the vehicle engine," the program will enter the "Sensors set menu" where the user can interact with sensor readings. The menu includes the following options:

1. Turn off the engine

2. Set the traffic light color

3. Set the room temperature (Temperature Sensor)

4. Set the engine temperature (Engine Temperature Sensor)

### Continuous Display of Sensor Menu
While the engine is ON, the sensor menu (Requirement 5) will always be displayed, waiting for the user's input.

### Responding to Sensor Data
Based on the user's choices from the sensor menu:

1. If the traffic light is 'G,' set vehicle speed to 100 km/hr
   
2. If the traffic light is 'O,' set vehicle speed to 30 km/hr

3. If the traffic light is 'R,' set vehicle speed to 0 km/hr

4. If the room temperature is less than 10 or greater than 30, turn on the AC and set the temperature to 20. Otherwise, turn off the AC.

5. If the engine temperature is less than 100 or greater than 150, turn on the "Engine Temperature Controller" and set the temperature to 125. Otherwise, turn off the "Engine Temperature Controller."

6. If the vehicle speed is 30 km/hr, turn on the AC if it was off and set room temperature to: current temperature * (5/4) + 1. Turn on "Engine Temperature Controller" if it was off and set engine temperature to: current temperature * (5/4) + 1.

### Display the current vehicle state, including:

1. Engine state: ON/OFF
2. AC: ON/OFF
3. Vehicle Speed
Room Temperature
Engine Temperature Controller State
Engine Temperature

### Turning Off the Engine
If the user selects "Turn off the engine" in the sensor menu, the menu from Requirement 1 will be displayed again.
