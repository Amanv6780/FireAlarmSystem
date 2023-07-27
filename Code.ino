#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
String textForSMS;
int Firesensor = 4; 
int Buzzer = 5; 
int gled = 2;
int rled = 3;
void setup() {
randomSeed(analogRead(0));
Serial.begin(9600);
SIM900.begin(9600); 
Serial.println(" logging time completed!");
pinMode(Firesensor, INPUT); 
pinMode(Buzzer, OUTPUT); 
pinMode(gled, OUTPUT); 
pinMode(rled, OUTPUT); 
digitalWrite(Buzzer, LOW);
digitalWrite(gled, HIGH); 
delay(5000); 
}
void loop() {
 if ( digitalRead(Firesensor) == HIGH) // 
 {
 textForSMS = "\nFire Detected!"; 
 analogWrite(Buzzer, 200); 
 analogWrite(rled, 200);
 sendSMS(textForSMS);
Page 28 of 38
 Serial.println(textForSMS);
 Serial.println("message sent."); 
 delay(8000);
 }
 if ( digitalRead(Firesensor) == LOW) // 
 {
 Serial.println("No Fire Detected"); 
 digitalWrite(Buzzer, LOW);
 digitalWrite(gled, HIGH);
 delay(1000);
 }
}
void sendSMS(String message)
{
 SIM900.print("AT+CMGF=1"); 
 delay(1000);
SIM900.println("AT+CMGS=\"+91**********\"\r"); 
 delay(1000);
 SIM900.println("Fire Detected");
 SIM900.println((char)26); 
 delay(1000);
 Serial.println("Calling through GSM Modem");
 Serial.begin(9600);//setting baudrate at 9600;
 delay(1000);
 Serial.println("ATD**********;");
 delay(1000);
 SIM900.println("ATH");
SIM900.println();
 delay(1000); 
}
