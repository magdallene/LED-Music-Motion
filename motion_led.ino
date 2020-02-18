#define motion_sensor 2
#define green 7
#define red1 8
#define yellow 9
#define red2 10
const int buttonPin = 3;
int buttonState = 0;
int lastbuttonState =1;
int buttonCounter = 0;

void setup() {
  //led
  for(int i=7;i<=10;i++){
  pinMode(i,OUTPUT);
  digitalWrite(i,LOW);
  }
  pinMode(motion_sensor,INPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
  delay(50000);
}
void buttonModeSelector(){
  buttonState = digitalRead(buttonPin);
if(buttonState == 1 && buttonState != lastbuttonState){
  buttonCounter++;
  Serial.println(buttonCounter);
  
  if(buttonCounter>3){
  buttonCounter =0;
}
}
lastbuttonState = buttonState;
  }
void loop() {

buttonModeSelector();
int  value_sensor = digitalRead(motion_sensor);

  if(value_sensor == HIGH) {
    Serial.println(value_sensor);
    digitalWrite(green,HIGH);

  switch(buttonCounter){
    case 1:
    mode_constant(red1,yellow,red2);
    break;
    case 2:
    mode_snake(red1,yellow,red2,300);
    break;
    case 3:
    mode_blink(red1,yellow,red2);
    break;
  }
 
  }
  else{
    Serial.println(value_sensor);
    digitalWrite(green,LOW);
    delay(100);
    }
}

void mode_constant(int led1,int led2,int led3){
  int leds[3] = {led1,led2,led3};
  for(int i=0;i<3;i++){
     digitalWrite(leds[i],HIGH);
  }
}

void mode_snake(int led1,int led2, int led3,int delay_time){
  int leds[3] = {led1,led2,led3};
  for(int i=0;i<3;i++){
    digitalWrite(leds[i],HIGH);
        delay(delay_time);
    digitalWrite(leds[i],LOW);
    }
}

void mode_blink(int led1,int led2, int led3){
  int leds[3] = {led1,led2,led3};
  digitalWrite(leds[random(0,sizeof(leds)/sizeof(int))],HIGH);
  delay(random(20,200));
  digitalWrite(leds[random(0,sizeof(leds)/sizeof(int))],LOW);
}
