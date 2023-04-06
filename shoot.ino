#include <Servo.h>
int Speed;
Servo ESC;

void setup(){
    ESC.attach(9, 1000, 2000);
}

void loop() {
    Speed = analogRead(A0);
    Speed = map(Speed, 0, 1023, 0, 180);

    ESC.write(Speed);
    /*
    ESC.write(90);
    ESC.write(Speed);
    ESC.write(100);
    ESC.write(Speed);
    ESC.write(90);
    ESC.write(180);
    */
}
