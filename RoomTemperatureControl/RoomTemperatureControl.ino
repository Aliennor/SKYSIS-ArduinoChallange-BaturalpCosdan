#include <LiquidCrystal.h>

//The DC motors symbolize as the air conditioning units their rotation ways represent cooling or heating actions.


  const int sensor_pin = A0, ac_pin1 = 6, ac_pin2 = 7, ac_pin3 = 9, ac_pin4 = 10;

  float MinTemp = 20, MaxTemp = 25;

  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  void setup() {
 
    
    lcd.begin(16, 2);
    
    pinMode(ac_pin1, OUTPUT);
    pinMode(ac_pin2, OUTPUT);
    pinMode(ac_pin3, OUTPUT);
    pinMode(ac_pin4, OUTPUT);
   
    
  // Display the desired range of temperature
    
    lcd.print("Room temp(C):");
    lcd.setCursor(2,1);
    lcd.print(MinTemp); lcd.print("-");lcd.print(MaxTemp);
    
    delay(2000);
 }

 void loop() {
   
   float Sensor_voltage, Temperature;
 
 // Read voltage and convert to temperature (Celsius)
   
   Sensor_voltage = analogRead(sensor_pin) * 5.0 / 1023;
   Temperature = 100.0 * Sensor_voltage-50.0;
    
   
    lcd.clear();
    lcd.print("Sensor reading:");
    lcd.setCursor(2,1);
    lcd.print(Temperature); lcd.print(" C");
   
    delay(2000);

   
   if(Temperature > MaxTemp){
      lcd.clear();
      lcd.print("HOT");
     
      lcd.setCursor(0, 1);lcd.print("ENGAGING COOLIN");
      for( int i = 0; i <= 255; i++ ) {
        analogWrite(ac_pin1, i);
        analogWrite(ac_pin3, i);
       }
      digitalWrite(ac_pin2, LOW);
      digitalWrite(ac_pin4, LOW);
       delay(2000);
     
       lcd.clear();
       lcd.print("AA SUGOI");
       lcd.setCursor(0, 1);
       lcd.print("WE DONE");
 
       for( int i = 255; i >= 0; i-- ) {
        analogWrite(ac_pin1, i);
        analogWrite(ac_pin3, i);
       }
        delay(2000);
       }
  else if(Temperature < MinTemp){
      lcd.clear();
      lcd.print("SAMMUII");
      lcd.setCursor(0, 1);
      lcd.print("HIITAA ON");
    
    
      for( int i = 0; i <= 255; i++ ) {
        analogWrite(ac_pin2, i);
        analogWrite(ac_pin4, i);
       }
      digitalWrite(ac_pin1, LOW);
      digitalWrite(ac_pin3, LOW);
    
      delay(3000);
    
      lcd.clear();
      lcd.print("GREATO");
      lcd.setCursor(0, 1);
      lcd.print("OWARI DA");
    
      delay(1000);
    
      for( int i = 255; i >= 0; i-- ) {
        analogWrite(ac_pin2, i);
        analogWrite(ac_pin4, i);
       }
      digitalWrite(ac_pin1, LOW);
      digitalWrite(ac_pin3, LOW);
      lcd.clear();
      }
  else if(Temperature > MinTemp && Temperature < MaxTemp){
      lcd.clear();
      lcd.print("STABILIZED");lcd.setCursor(2,1);
      lcd.print("TOKIYO TOMARE");
    
      delay(1000);
      lcd.clear();
   }
  else {
      lcd.clear();
      lcd.print("YABBAIZO");
      delay(1000);
      lcd.clear();
    }
    delay(1000);
   } 
