/*
	This module uses the L293D chip to modulate and power
	two DC motors controlling the wheels of the FryeBot
*/

/*L293D INPUT 7*/
const int YELLOW_GEAR_MOTOR_BACK = 8;

/*L293D INPUT 2*/
const int YELLOW_GEAR_MOTOR_FORWARD = 9;

/*L293D INPUT 10*/
const int RED_GEAR_MOTOR_BACK = 10;

/*L293D INPUT 15*/
const int RED_GEAR_MOTOR_FORWARD = 11;

/*
	Establish ratio os the rate of the faster slower gear
	to the faster gear to scale the duty cycle of the
	faster gear
*/
const float RED_GEAR_SPEED_TO_YELLOW = 0.97;

/*Constant for full duty cycle for analogWrite*/
const int FULL_ANALOG_MOTOR_SPEED = 255;

void setup() {
	Serial.begin(9600);

	/* add setup code here */
	pinMode(YELLOW_GEAR_MOTOR_FORWARD, OUTPUT);
	pinMode(YELLOW_GEAR_MOTOR_BACK, OUTPUT);
	pinMode(RED_GEAR_MOTOR_BACK, OUTPUT);
	pinMode(RED_GEAR_MOTOR_FORWARD, OUTPUT);

}

void loop() {

	analogWrite(YELLOW_GEAR_MOTOR_FORWARD, (int)(RED_GEAR_SPEED_TO_YELLOW * (float)FULL_ANALOG_MOTOR_SPEED));
	digitalWrite(YELLOW_GEAR_MOTOR_BACK, LOW);

	digitalWrite(RED_GEAR_MOTOR_BACK, LOW);
	digitalWrite(RED_GEAR_MOTOR_FORWARD, HIGH);

}
