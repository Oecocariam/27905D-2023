#include "main.h"
//#define DIGITAL_SENSOR_PORT_A 'A'
//#define DIGITAL_SENSOR_PORT_B 'B'

void opcontrol() {
	
	pros::Controller master (CONTROLLER_MASTER);

//	pros::ADIDigitalOut pistonA (DIGITAL_SENSOR_PORT_A);
//	pros::ADIDigitalOut pistonB (DIGITAL_SENSOR_PORT_B);
	
	pros::Motor left1 (9, MOTOR_GEARSET_18, false);
	pros::Motor left2 (10, MOTOR_GEARSET_18, false); 
	pros::Motor right1 (19, MOTOR_GEARSET_18, false); 
	pros::Motor right2 (20, MOTOR_GEARSET_18, false); 
	
	bool transistion = false;

//Ah, yes, the simple comment, definition of piston, controller , and motors

	while (true) {
		
//		switch(master.get_digital(DIGITAL_A)) {
//			transistion = !transistion;
//			pros::delay(10);
//		}


//		pistonA.set_value(transistion);
//		pistonB.set_value(!transistion);


		int left1Control = master.get_analog(ANALOG_LEFT_Y)+master.get_analog(ANALOG_LEFT_X);
		int left2Control = master.get_analog(ANALOG_LEFT_Y)-master.get_analog(ANALOG_LEFT_X);

		int right1Control = master.get_analog(ANALOG_LEFT_Y)-master.get_analog(ANALOG_LEFT_X);
		int right2Control = master.get_analog(ANALOG_LEFT_Y)-master.get_analog(ANALOG_LEFT_X);


		left1.move(left1Control);
		left2.move(left2Control);

		right1.move(right1Control);
		right2.move(right2Control);
	}
}