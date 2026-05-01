#include <TM1637Display.h>


const int trigPin = 9;
const int echoPin = 10;
// defines variables
float duration;
float distance;
double Height;
float feets;

const int CLK = 11; //Set the CLK pin connection to the display
const int DIO = 12; //Set the DIO pin connection to the display
const uint8_t blank[] = {0x00, 0x00, 0x00,0x00};
TM1637Display display(CLK, DIO); //set up the 4-Digit Display.

void setup()

{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

display.setBrightness(0x0a); //set the diplay to maximum brightness
display.setSegments(blank);//clear display
}

void loop()

{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
feets = distance * 0.032808;
Height=6.1-feets;
int Height1=Height*100;
display.showNumberDecEx(Height1,0b01000000, false, 4,0);
delay(100);
 }
