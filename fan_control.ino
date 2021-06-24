#include <LiquidCrystal.h>

const int oLed = 5;
const int gLed = 4;
const int bLed = 3;
const int mPin = 6;
const int sensPin = A0;
int mSpeed = 0;

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup()
{

    pinMode(oLed, OUTPUT);
    pinMode(gLed, OUTPUT);
    pinMode(bLed, OUTPUT);

    digitalWrite(oLed, LOW);
    digitalWrite(gLed, LOW);
    digitalWrite(bLed, LOW);

    pinMode(mPin, OUTPUT);
    pinMode(sensPin, INPUT);

    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
    double sensVal = analogRead(sensPin);
    double t = ((100*sensVal-10400)/200);

    lcd.setCursor(0, 0);
    lcd.print("T = ");
    lcd.print(t);

    lcd.setCursor(0,1);

    if (t<15){
        Serial.println("It's too cold");
        mSpeed = 0;
        digitalWrite(bLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
        delay(10);
    }
    else if (t <= 27 && t>15){
        Serial.println("Below Normal temperature");
        mSpeed=0;
        digitalWrite(bLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
    }
    else if(t<=35 && t>27){
        mSpeed=80;
        Serial.println("Normal");
        digitalWrite(gLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
    }
    else if (t<=40 && t>35){
        mSpeed = 150;
        Serial.println("Too Hot");
        digitalWrite(oLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
    }
    else if (t<=50 && t>40){
        mSpeed = 255;
        Serial.println("Extrem hot");
        digitalWrite(oLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
    }
    else if (t>50){
        mSpeed = 255;
        Serial.print("Motor speed is at max = ");
        Serial.println(mSpeed);
        Serial.println("And the weather is not suitable to survive");
        digitalWrite(oLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
    }
    else{
        Serial.println("It's too cold");
        mSpeed = 0;
        digitalWrite(bLed,HIGH);
        lcd.print(mSpeed);
        analogWrite(mPin,mSpeed);
    }

    delay(10);

    digitalWrite(oLed, LOW);
    digitalWrite(gLed, LOW);
    digitalWrite(bLed, LOW);

    lcd.clear();

}

