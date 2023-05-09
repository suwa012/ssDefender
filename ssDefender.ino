#include <Servo.h>
int Speed;
Servo ESC1;
Servo horizontalServo;

Servo verticalServo;
int LINEAR_SERVO_POWER = 6;
int BALL_LOADER_SERVO_POWER=5;

struct Target {
    float horizontal;
    float vertical;
    float firing_speed;
};

void setupBallLoader() {
    pinMode(BALL_LOADER_SERVO_POWER, OUTPUT);
    digitalWrite(BALL_LOADER_SERVO_POWER, HIGH);

}

void loadNerfBall() {
    // Load nerf ball
    digitalWrite(BALL_LOADER_SERVO_POWER, LOW);
    delay(150);
    digitalWrite(BALL_LOADER_SERVO_POWER, HIGH);
}

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

    horizontalServo.writeMicroseconds(newHorizontal);
    Serial.println(horizontal);

    /* Vertical aim (linear actuator) */
    verticalServo.writeMicroseconds(1000 + (1000 * vertical));
    // verticalServo.writeMicroseconds(2000);
    // delay(2000); // Delay so linear servo can complete route

    // Cut off power to linear actuator
    digitalWrite(LINEAR_SERVO_POWER, HIGH);
}


void shootSetup(){
    ESC1.attach(11, 1000, 2000);
    delay(1);
    ESC1.write(10);
}

/**
  power is from 0 - 100
 */

void shoot(int power) {
    Speed = power * 180 / 100;
    ESC1.write(Speed);
}

void setup() {
    Serial.begin(9600);
    setupBallLoader();
    aimSetup();
    shootSetup();
    //doInit = true;
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

    shoot(10);

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
            shoot(0);
            //doInit = true;
            delay(5000);
        }

        shoot(target.firing_speed); // set firing speed
        //doInit = false;

        Serial.println("shooting");

        delay(3000); // give the motors time to get to firing speed
        loadNerfBall();
        delay(1000); // Barrel is longer so we need a wait time so the nerf ball can exit the tube.
    }
}
