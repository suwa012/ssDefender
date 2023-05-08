#include <Servo.h>
int Speed;
Servo ESC1;
Servo ESC2;

void shootSetup(){
    ESC1.attach(12, 1000, 2000);
    ESC2.attach(13, 1000, 2000);
    delay(1);
    ESC1.write(10);
    ESC2.write(10);
}

/**
  power is from 0 - 100
  */
void shoot(int power, bool doInit) {
    Speed = power * 180 / 100;
    int minSpeed = 36;
    if(Speed < minSpeed && doInit == true) {
        ESC1.write(minSpeed);
        ESC2.write(minSpeed);

        delay(500);
    }

    ESC1.write(Speed);
    ESC2.write(Speed);
}
