const int RED_GEAR_MOTOR_CONTROL = 9;
const int YELLOW_GEAR_MOTOR_CONTROL = 10;
int MOVE = 1;
const int FULL_SPEED_ANALOG = 255;
const int NO_MOVE_SPEED = 0;

/*This value will need to be tuned through testing*/
const float RATIO_RED_YELLOW = 0.965;

const int RED_SPEED = FULL_SPEED_ANALOG;
const int YELLOW_SPEED = (int)(RATIO_RED_YELLOW * (float)FULL_SPEED_ANALOG);

int millisecondsPassed = 1;

void setup() {
	Serial.begin(9600);

	/* add setup code here */
	pinMode(RED_GEAR_MOTOR_CONTROL, OUTPUT);
	pinMode(YELLOW_GEAR_MOTOR_CONTROL, OUTPUT);


}

void loop() {

	MOVE = 1;
	if (MOVE) {
		analogWrite(RED_GEAR_MOTOR_CONTROL, RED_SPEED);
		analogWrite(YELLOW_GEAR_MOTOR_CONTROL, YELLOW_SPEED);
	}
	else {
		analogWrite(RED_GEAR_MOTOR_CONTROL, NO_MOVE_SPEED);
		analogWrite(YELLOW_GEAR_MOTOR_CONTROL, NO_MOVE_SPEED);
	}

	millisecondsPassed++;
}
