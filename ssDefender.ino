#include <Servo.h>
bool doInit;

struct Target {
    float horizontal;
    float vertical;
    float firing_speed;
};

void setup() {
    Serial.begin(9600);
    setupBallLoader();
    aimSetup();
    shootSetup();
    doInit = true;
    delay(500);
}

void loop() {
    Target low_targets[4] = {
        {53, 0.35, 17}, 
        {83, 0.15, 14},
        {127, 0.2, 14},
        {146, 0.3, 14}
    };

    Target tubs[5] = {
        {53, 1, 18},
        {70, 0.8, 13},
        {98, 0.7, 12},
        {124, 0.7, 12},
        {150, 0.9, 13}
    };

    shoot(10, false);

    /*
    for(int i = 0; i < 9; i++) {
        int j = i;

        Target target;

        if(i < 4) {
            j = i;
            target = low_targets[j];
        } else {
            j = i - 4;
            target = tubs[j];
        }

        float horizontal_pos = target.horizontal;
        float vertical_pos = target.vertical;

        aimBarrel(horizontal_pos, vertical_pos);

        if(i % 4 == 0) {
            shoot(0, false);
            doInit = true;
            delay(5000);
        }

        shoot(target.firing_speed, doInit); // set firing speed
        doInit = false;

        Serial.println("shooting");

        delay(3000); // give the motors time to get to firing speed
        loadNerfBall();
        delay(1000); // Barrel is longer so we need a wait time so the nerf ball can exit the tube.
    }
    */
}
