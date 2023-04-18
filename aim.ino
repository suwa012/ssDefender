Servo horizontalServo;

Servo verticalServo;
int LINEAR_SERVO_POWER = 6;

void aimSetup() {
    horizontalServo.attach(4);
    pinMode(LINEAR_SERVO_POWER, OUTPUT);

    verticalServo.attach(7);
    verticalServo.writeMicroseconds(1000);
    horizontalServo.writeMicroseconds(500);
}

void aimBarrel(float horizontal, float vertical) {
    int midpoint = 1590; // Will get 180 degrees on servo
    float newHorizontal;

    if(horizontal <= 180) {
        float dist = midpoint - 500; // 60 gets me what should be 90 degrees
        float distInMicroseconds = (horizontal / 180) * midpoint;
        newHorizontal = 500 + distInMicroseconds;
    }

    // Supply power to linear actuator
    digitalWrite(LINEAR_SERVO_POWER, LOW);

    /* Horizontal aim (rotary servo) */
    // horizontalServo.write(horizontal);
    // horizontalServo.writeMicroseconds(500 + ((horizontal/360) * 2000) );
    // horizontalServo.write(0);
    // delay(2000);

    delay(3000);
    horizontalServo.writeMicroseconds(newHorizontal);
    // horizontalServo.write(180);
    Serial.println(horizontal);
    // horizontalServo.writeMicroseconds(2500);

    /* Vertical aim (linear actuator) */
    // verticalServo.writeMicroseconds(1000);
    verticalServo.writeMicroseconds(1000 + (1000 * vertical));
    // delay(2000); // Delay so linear servo can complete route
    // Cut off power to linear actuator
    digitalWrite(LINEAR_SERVO_POWER, HIGH);
}
