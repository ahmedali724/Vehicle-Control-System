/*
 ============================================================================
 Name        : Mini_Project1.c
 Author      : Ahmed Ali
 Date        : 8 Aug 2023
 Description : Vehicle Control System With C
 ============================================================================
 */

#include <stdio.h>

typedef enum {
	False = 0, True = 1
} bool;

/* prototype of the functions */
char main_menu(void);
char sensors_set_menu(void);
void display_vehicle_state(bool engine_state, bool ac_state, int vehicle_speed,
		int room_temp, bool eng_cont_state, int eng_temp);
void traffic_sensor(char state, int *vehicle_speed);
void AC_state(int *room_temp, bool *ac_state);
void eng_controller_state(int *eng_temp, bool *eng_cont_state);
void speed_30(int *room_temp, bool *ac_state, int *eng_temp,
		bool *eng_cont_state);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char main_menu_input, sensors_menu_input, traffic_light_data;
	/* set engine state off, ac off, vehicle speed = 20,room temperature = 36,
	 engine controller state off and engine temperature = 90 as default */
	bool engine_state = False, ac_state = False, eng_cont_state = False;
	int vehicle_speed, room_temp, eng_temp;
	while (1) {
		main_menu_input = main_menu();
		/* if user choose to Quit system, the infinite loop will break */
		if (main_menu_input == 'c') {
			break;
		}
		/* if user choose b and engine is off, it will ask him again */
		if (main_menu_input == 'b' && engine_state == False) {
			printf("The engine is already off.\n");
			continue;
		}
		/* if user choose b and engine is on, the engine will turned off */
		else if (main_menu_input == 'b' && engine_state == True) {
			engine_state = False;
			printf("The engine is turned off.\n");
		}
		/* if user choose a the engine will turned on */
		if (main_menu_input == 'a') {
			/* assign value to vehicle state as default when turned on */
			engine_state = True;
			vehicle_speed = 20;
			room_temp = 25;
			eng_temp = 90;
			room_temp = 35;
			/* to display all vehicle state */
			display_vehicle_state(engine_state, ac_state, vehicle_speed,
					room_temp, eng_cont_state, eng_temp);
			while (1) {
				sensors_menu_input = sensors_set_menu();
				/* if user choose a, the engine will turned off */
				if (sensors_menu_input == 'a') {
					/* reset all sensor values and engine state */
					engine_state = False;
					vehicle_speed = 0;
					room_temp = 0;
					eng_temp = 0;
					room_temp = 0;
					/* to display all vehicle state */
					display_vehicle_state(engine_state, ac_state, vehicle_speed,
							room_temp, eng_cont_state, eng_temp);
					break;
				}
				/* if user choose b, he will enter the traffic light state */
				if (sensors_menu_input == 'b') {
					printf("Enter the traffic light state (G, O, R): ");
					/* Read the traffic light data from the user */
					scanf(" %c", &traffic_light_data);
					/* sending traffic light data by value and vehicle speed by
					 reference to change its value depend on traffic light data */
					traffic_sensor(traffic_light_data, &vehicle_speed);
					/* to display all vehicle state */
					display_vehicle_state(engine_state, ac_state, vehicle_speed,
							room_temp, eng_cont_state, eng_temp);
				}
				/* if user choose b, he will enter the room temperature */
				if (sensors_menu_input == 'c') {
					printf("Enter the room temperature: ");
					/* Read the room temperature from the user */
					scanf("%d", &room_temp);
					/* sending room temperature and ac state by reference
					 to change its value depend on room temperature */
					AC_state(&room_temp, &ac_state);
					/* to display all vehicle state */
					display_vehicle_state(engine_state, ac_state, vehicle_speed,
							room_temp, eng_cont_state, eng_temp);
				}
				/* if user choose b, he will enter the engine temperature */
				if (sensors_menu_input == 'd') {
					printf("Enter the engine temperature: ");
					/* Read the engine temperature from the user */
					scanf("%d", &eng_temp);
					/* sending engine temperature and engine temperature
					 controller state by reference to change its value
					 depend on engine temperature */
					eng_controller_state(&eng_temp, &eng_cont_state);
					/* to display all vehicle state */
					display_vehicle_state(engine_state, ac_state, vehicle_speed,
							room_temp, eng_cont_state, eng_temp);
				}
				/* if the vehicle speed is 30 km/hr, the ac state,
				 engine temperature controller state, room temperature
				 and engine temperature will change */
				if (vehicle_speed == 30) {
					printf("\nThe speed is 30 km/hr, There are some changes\n");
					speed_30(&room_temp, &ac_state, &eng_temp, &eng_cont_state);
					/* to display all vehicle state */
					display_vehicle_state(engine_state, ac_state, vehicle_speed,
							room_temp, eng_cont_state, eng_temp);
				}
			}
		}
	}
	printf("\nThe system is closed, Good Bye :)");
	return 0;
}

/* the main menu which include the main 3 options in system */
char main_menu(void) {
	char input;
	printf("\na. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	printf("Enter your choice: ");
	scanf(" %c", &input);
	return input;
}

/* the sensors set menu which simulates the vehicle sensors readings */
char sensors_set_menu(void) {
	char input;
	printf("\na. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature\n");
	printf("d. Set the engine temperature\n\n");
	printf("Enter your choice: ");
	scanf(" %c", &input);
	return input;
}

/* function to display all vehicle state Engine state, AC, Vehicle Speed...etc */
void display_vehicle_state(bool engine_state, bool ac_state, int vehicle_speed,
		int room_temp, bool eng_cont_state, int eng_temp) {
	/* if condition to check the engine state */
	if (engine_state == False) {
		printf("\nEngine state: OFF\n");
	} else {
		printf("\nEngine state: ON\n");
		/* if condition to check the AC state */
		if (ac_state == False) {
			printf("AC: OFF\n");
		} else {
			printf("AC: ON\n");
		}
		/* print the value of vehicle speed */
		printf("Vehicle Speed: %d km/hr\n", vehicle_speed);
		/* print the value of room temperature */
		printf("Room Temperature: %d°C\n", room_temp);
		/* if condition to check the engine temperature controller state */
		if (eng_cont_state == False) {
			printf("Engine Temperature Controller State: OFF\n");
		} else {
			printf("Engine Temperature Controller State: ON\n");
		}
		/* print the value of engine temperature */
		printf("Engine Temperature: %d°C\n", eng_temp);
	}
}

/* function to set the vehicle speed depend on the traffic light state */
void traffic_sensor(char state, int *vehicle_speed) {
	if (state == 'G' || state == 'g') {
		/* if state of traffic light is G, set vehicle speed to 100 */
		*vehicle_speed = 100;
	} else if (state == 'O' || state == 'o') {
		/* if state of traffic light is O, set vehicle speed to 30 */
		*vehicle_speed = 30;
	} else if (state == 'R' || state == 'r') {
		/* if state of traffic light is O, set vehicle speed to 0 */
		*vehicle_speed = 0;
	}
}

/* function to set the ac state and temperature depend on the room temperature */
void AC_state(int *room_temp, bool *ac_state) {
	if (*room_temp < 10) {
		/* if room temperature less than 10, set room temperature to 20 and turn on AC */
		*ac_state = True;
		*room_temp = 20;
	} else if (*room_temp > 30) {
		/* if room temperature greater than 30, set room temperature to 20 and turn on AC */
		*ac_state = True;
		*room_temp = 20;
	} else {
		/* otherwise turn off AC */
		*ac_state = False;
	}
}

/* function to set the engine controller state depend on the engine temperature */
void eng_controller_state(int *eng_temp, bool *eng_cont_state) {
	if (*eng_temp < 100) {
		/* if engine temperature less than 100, set engine temperature to 125
		 and turn on engine controller */
		*eng_cont_state = True;
		*eng_temp = 125;
	} else if (*eng_temp > 150) {
		/* if engine temperature greater than 150, set engine temperature to 125
		 and turn on engine controller */
		*eng_cont_state = True;
		*eng_temp = 125;
	} else {
		/* otherwise turn off engine controller */
		*eng_cont_state = False;
	}
}

/* function to change the vehicle states if the speed is 30 */
void speed_30(int *room_temp, bool *ac_state, int *eng_temp,
		bool *eng_cont_state) {
	/* turn on AC */
	*ac_state = True;
	/* change room temperature as this equation */
	(*room_temp) = (((*room_temp) * 5) / 4) + 1;
	/* turn on engine controller */
	*eng_cont_state = True;
	/* change engine temperature as this equation */
	(*eng_temp) = (((*eng_temp) * 5) / 4) + 1;
}
