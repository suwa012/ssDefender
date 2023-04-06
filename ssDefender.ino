#include <Servo.h>

int RELAY_PIN1=6;
int RELAY_PIN2=5;

Servo baseServo;
Servo linearServo;
int LINEAR_SERVO_POWER = RELAY_PIN1;

int BALL_LOADER_SERVO_POWER=RELAY_PIN2;

void setup() {
    shootSetup();
    baseServo.attach(10);
    linearServo.attach(7);
    linearServo.writeMicroseconds(1000);
    pinMode(RELAY_PIN1, OUTPUT);
    pinMode(RELAY_PIN2, OUTPUT);
    delay(5000);
}

void loop() {
    int horizontal_pos[9] = {35.78, 36.46, 55.29, 66.05, 90, 113.95, 124.71, 143.54, 144.22};
    // int vertical_pos[9] = {0.25, 0, 0.30, 0, 1, 0, 0.30, 0, 0.25};
    int vertical_pos[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    int firing_speed[9] = {100, 50, 30, 100, 13, 12, 33, 78, 90};

    for(int i = 0; i <= 9; i++) {
        // Load nerf ball
        digitalWrite(BALL_LOADER_SERVO_POWER, LOW);
        delay(800);
        digitalWrite(BALL_LOADER_SERVO_POWER, HIGH);
        delay(300);

        // AIM barrel

        // Supply power to linear actuator
        digitalWrite(LINEAR_SERVO_POWER, LOW);
        // Horizontal aim (rotary servo)
        baseServo.write(horizontal_pos[i]);
        // Vertical aim (linear actuator)
        linearServo.writeMicroseconds(1000);
        delay(3000); // Delay so linear servo can complete route
        // linearServo.writeMicroseconds(2000);
        linearServo.writeMicroseconds(1000 + (1000 * vertical_pos[i]));
        delay(3000); // Delay so linear servo can complete route
        delay(1000); // Delay so linear servo can complete route
        // Cut off power to linear actuator
        digitalWrite(LINEAR_SERVO_POWER, HIGH);

        // SHOOT
        shoot(firing_speed[i]);
    }
}
