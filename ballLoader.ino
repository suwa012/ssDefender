int BALL_LOADER_SERVO_POWER=5;

void setupBallLoader() {
    pinMode(BALL_LOADER_SERVO_POWER, OUTPUT);
    digitalWrite(BALL_LOADER_SERVO_POWER, HIGH);
}

void loadNerfBall() {
    // Load nerf ball
    digitalWrite(BALL_LOADER_SERVO_POWER, LOW);
    delay(400);
    digitalWrite(BALL_LOADER_SERVO_POWER, HIGH);
}
