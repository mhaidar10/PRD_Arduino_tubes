#define trigPin 7
#define echoPin 6
#include <Servo.h>
Servo servokanan;
Servo servokiri;

void setup()
{
    Serial.begin(9600);
    servokanan.attach(5);
    servokiri.attach(3);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 29.1;

    if (distance <= 5) // jarak sensor
    {
        servokanan.write(100), servokiri.write(20);
        delay(1000);
    }

    else
    {
        servokanan.write(10), servokiri.write(120); //sudut
        delay(100);
    }
}
