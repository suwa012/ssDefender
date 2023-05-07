#include <Servo.h>
bool doInit;

void setup() {
    Serial.begin(9600);
    setupBallLoader();
    aimSetup();
    shootSetup();
    doInit = true;
    delay(500);
}

void loop() {
    float low_targets_h[4] = {53, 83, 127, 146};
    // float tubs_h[5] = {146, 146, 146, 146, 146};
    float tubs_h[5] = {53, 70, 98, 128, 146};

    float low_targets_v[4] = {0, 0, 0, 0};
    float tubs_v[5] = {0.8, 1, 0.8, 1, 0.8};

    int firing_speed[9] = {12, 10, 10, 12,
        14, 12, 10, 12, 14};

    for(int i = 0; i < 9; i++) {
        float horizontal_pos;
        float vertical_pos;

        int j = i;

        /* TESTING
           ------------------------------------------
           j = i % 4;
           ----------- TESTING ENDS -----------------
        */

        if(i < 4) {
            j = i;
            horizontal_pos = low_targets_h[j];
            vertical_pos = low_targets_v[j];
        } else {
            j = i - 4;
            horizontal_pos = tubs_h[j];
            vertical_pos = tubs_v[j];
        }

        aimBarrel(horizontal_pos, vertical_pos);

        if(i % 4 == 0) {
            shoot(0, false);
            doInit = true;
            delay(5000);
        }

        shoot(firing_speed[i], doInit); // set firing speed
        doInit = false;

        delay(2000); // give the motors time to get to firing speed
        loadNerfBall();
        delay(1000); // Barrel is longer so we need a wait time so the nerf ball can exit the tube.
    }
}
