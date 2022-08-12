// C++ code


void light_it_up(int led)
{
  for(int i=8;i<14;i++){
    if(i==led){
      digitalWrite(i, HIGH);
    }
    else
      digitalWrite(i, LOW);
  }
}

void setup()
{
  Serial.begin(9600);
  
  for(int i=2; i<8; i++){
  	pinMode(i,OUTPUT);
  }
  
  for(int i=8; i<14; i++){
  	pinMode(i,INPUT_PULLUP);
  }
  
}

void loop()
{
  int state1 = digitalRead(7);
  int state2 = digitalRead(6);
  int state3 = digitalRead(5);
  int state4 = digitalRead(4);
  int state5 = digitalRead(3);
  int state6 = digitalRead(2);
  
  
  
  if(state1==1){
  	light_it_up(8);
  }
  else if(state2==1){
  	light_it_up(9);
  }
  else if(state3==1){
  	light_it_up(10);
  }
  else if(state4==1){
  	light_it_up(11);
  }
  else if(state5==1){
  	light_it_up(12);
  }
  else if(state6==1){
  	light_it_up(13);
  }
  delay(1000);
}
