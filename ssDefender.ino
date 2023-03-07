#include <Servo.h>

Servo baseServo;
Servo linearServo;
int RELAY_PIN1=6;
int RELAY_PIN2=5;
int REGULAR_SERVO_POWER=RELAY_PIN2;

void setup() {
    baseServo.attach(10);
    linearServo.attach(7);
    pinMode(RELAY_PIN1, OUTPUT);
    pinMode(RELAY_PIN2, OUTPUT);
}

void loop() {
    int horizontal_pos[9] = {35.78, 36.46, 55.29, 66.05, 90, 113.95, 124.71, 143.54, 144.22};
    int vertical_pos[3] = {90, 180, 270};

    for(int i = 0; i <= 9; i++) {
        // Turn on linear actuator
        digitalWrite(RELAY_PIN1, HIGH);
        
        // Horizontal aim (rotary servo)
        baseServo.write(horizontal_pos[i]);

        // Vertical aim (linear actuator)
        linearServo.write(vertical_pos[i%3]);
        delay(500);

        // Load nerf ball
        digitalWrite(REGULAR_SERVO_POWER, HIGH);
        delay(500);
        digitalWrite(REGULAR_SERVO_POWER, LOW);

        // Turn off linear actuator
        // digitalWrite(RELAY_PIN1, HIGH);
        delay(1000);
    }
}
