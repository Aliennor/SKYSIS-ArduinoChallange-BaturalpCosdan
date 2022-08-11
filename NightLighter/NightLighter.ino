// C++ code
const int ldr=A0,led=3;


int lightCur; int lightVal;

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  pinMode(ldr, INPUT);   
}

void loop() {

  int ldrStatus = analogRead(ldr);  
  

   if (ldrStatus <=400) {

    digitalWrite(led, HIGH);               
    Serial.println("LDR is DARK, LED is ON");
    
   }
  else {

    digitalWrite(led, LOW);         
    Serial.println("---------------");
  }
}
