#include <Servo.h>

Servo baseServo;

void setup() {
    baseServo.attach(10);
}

void loop() {
    int pos[9] = {35.78, 36.46, 55.29, 66.05, 90, 113.95, 124.71, 143.54, 144.22};

    for(int i = 0; i <= 9; i++) {
        baseServo.write(pos[i]);
        delay(5000);
    }
}
