Servo horizontalServo;

Servo verticalServo;
int LINEAR_SERVO_POWER = 6;

void aimSetup() {
    horizontalServo.attach(4);
    pinMode(LINEAR_SERVO_POWER, OUTPUT);

    verticalServo.attach(7);
    verticalServo.writeMicroseconds(1000);
}

void aimBarrel(float horizontal, float vertical) {
    int midpoint = 1590; // Will get 180 degrees on servo
    float newHorizontal;

    if(horizontal <= 180) {
        float dist = midpoint - 500;
        float distInMicroseconds = (horizontal / 180) * dist;
        newHorizontal = 500 + distInMicroseconds;
    }

    // Supply power to linear actuator
    digitalWrite(LINEAR_SERVO_POWER, LOW);

    delay(3000);
    horizontalServo.writeMicroseconds(newHorizontal);
    Serial.println(horizontal);

    /* Vertical aim (linear actuator) */
    verticalServo.writeMicroseconds(1000 + (1000 * vertical));
    // verticalServo.writeMicroseconds(2000);
    // delay(2000); // Delay so linear servo can complete route
    // Cut off power to linear actuator
    digitalWrite(LINEAR_SERVO_POWER, HIGH);
}
