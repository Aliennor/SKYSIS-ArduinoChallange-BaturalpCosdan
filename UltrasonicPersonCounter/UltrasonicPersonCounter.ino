#include <LiquidCrystal.h>

#define echoPin 8
#define trigPin 9 



  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  long duration;
  int distance;
  int count=0;
  int state=1;
  int laststate=1;

int counter() {
  

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2; 
  
  lcd.setCursor(0 ,0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  
    if(distance<50 && state==1){
      state=0;
      return 1;
     }
    else{
      state=1;    
      return 0;
     }
  }


  void setup() {
 
    
    lcd.begin(16, 2);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    
 }

 void loop() {
   
   
   count = count + counter();
   
   lcd.setCursor(0 ,1);
   
   lcd.print("Visitors : ");
   lcd.print(count);
   delay(2000);
   } 
