#include <Servo.h>
int Speed;
Servo ESC1;
Servo ESC2;

void shootSetup(){
    ESC1.attach(9, 1000, 2000);
    ESC2.attach(10, 1000, 2000);
    delay(1);
    ESC1.write(10);
    ESC2.write(10);
}

/**
  power is from 0 - 100
  */
void shoot(int power) {
    Speed = power * 180 / 100;
    ESC1.write(Speed);
    ESC2.write(Speed);
    // delay(2000);
    // ESC.write(0);
}
