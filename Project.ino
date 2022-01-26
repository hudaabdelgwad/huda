#include <LiquidCrystal.h>
// LCD pins RS, EN, D4, D5, D6, D7 connection
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int VoltageSensor = A0;
int CurrentSensor = A1;
int VsensorValue = 0; 
float Vout = 0;

int Relay = 7;
int Buzzer = 6;
void setup() {
  pinMode(VoltageSensor, INPUT);
  pinMode(Relay, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
   VsensorValue = analogRead(VoltageSensor);
   Vout = (VsensorValue * 5.0 / 1024);
   Vout = Vout * 5;
   lcd.clear();
   Serial.println(Vout);
   lcd.print("Volt = ");
   lcd.setCursor(0, 1);
   lcd.print(Vout);
   delay(500);
   if (Vout >= 7) {
    // turn Buzzer on, disconnect the load
    digitalWrite(Relay, LOW);
    digitalWrite(Buzzer, HIGH);
    lcd.setCursor(6, 1);
    lcd.print("max volt");
  } else {
    // turn Buzzer off, connect the load
    digitalWrite(Relay, HIGH);
    digitalWrite(Buzzer, LOW);
  }

}
