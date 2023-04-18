#include <Servo.h>

void setup() {
    Serial.begin(9600);
    setupBallLoader();
    aimSetup();
    shootSetup();
    delay(5000);
}

void loop() {
    // int horizontal_pos[9] = {35.78, 36.46, 55.29, 66.05, 90, 113.95, 124.71, 143.54, 144.22};
    // int horizontal_pos[9] = {0, 360, 360, 360, 0, 360, 0, 360, 0};
    int horizontal_pos[9] = {0, 90, 180, 90, 0, 30, 60, 90, 0};
    // int vertical_pos[9] = {0.25, 0, 0.30, 0, 1, 0, 0.30, 0, 0.25};
    int vertical_pos[9] = {1, 0, 1, 0, 1, 0, 1, 0, 1};
    int firing_speed[9] = {15, 15, 15, 15, 15, 15, 15, 15, 15};

    for(int i = 0; i <= 9; i++) {
        aimBarrel(horizontal_pos[i], vertical_pos[i]);

        loadNerfBall();

        shoot(firing_speed[i]);
        delay(2000);
    }
}
