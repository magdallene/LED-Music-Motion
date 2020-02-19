#define motion_sensor 2
#define buttonPin 3
int ledPins[] = {8,9,10,11,12,13};
int ledPinslength = 6;
int pwmPins[] = {9,10,11};
int pwmPinslength = 3;
int buttonState = 0;
int lastbuttonState =1;
int buttonCounter = 0;
int dimmerValue = 0;

void setup() {
  led_initialize(ledPins);
  pinMode(motion_sensor,INPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
  delay(50000);
}

void loop() {

buttonModeSelector();

int  value_sensor = digitalRead(motion_sensor);

  if(value_sensor == HIGH) {
    //Serial.println(value_sensor);
    //digitalWrite(green,HIGH);

  switch(buttonCounter){
    case 0:
    dimmer(pwmPins);
    break;
    case 1:
    mode_constant(ledPins);
    break;
    case 2:
    mode_snake(ledPins,300);
    break;
    case 3:
    mode_blink(ledPins);
    break;
  }
 
  }
  else{
    Serial.println(value_sensor);
    //digitalWrite(green,LOW);
    delay(100);
    }
}
void led_initialize(int led_array[]){
  for(int i=0;i<ledPinslength;i++){
    pinMode(led_array[i],OUTPUT);
    digitalWrite(led_array[i],LOW);
  }
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

void mode_constant(int led_array[]){
  for(int i=0;i<ledPinslength;i++){
     digitalWrite(led_array[i],HIGH);
  }
}

void mode_snake(int led_array[],int delay_time){
  for(int i=0;i<ledPinslength;i++){
    digitalWrite(led_array[i],HIGH);
    delay(delay_time);
    digitalWrite(led_array[i],LOW);
    }
}

void mode_blink(int led_array[]){
  digitalWrite(led_array[random(0,ledPinslength)],HIGH);
  delay(random(20,200));
  digitalWrite(led_array[random(0,ledPinslength)],LOW);
}

void dimmer(int pwm_led[]){
  dimmerValue = map(analogRead(A0),95,927,0,255);
  Serial.println(dimmerValue);
    for (int i=0;i<3;i++){
    analogWrite(pwm_led[i],dimmerValue);
    }
}
