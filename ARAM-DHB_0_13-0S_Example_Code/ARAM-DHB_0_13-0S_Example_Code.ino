//ARAM-DHB_0_13-0S      Example Code                rev: 4/25/2026

#define CNTRL_PIN 4     //change me to your desired cntrl pin
#define MICROS_TO_SECONDS (1000000)
uint32_t timeClock;
uint32_t nextSwitch;
short state = 0;
int switchFrequency = 10; //change me to your desired switching frequency (1/seconds)
double timeStep = MICROS_TO_SECONDS/switchFrequency;

void setup() {
  pinMode(CNTRL_PIN,OUTPUT);
  digitalWrite(CNTRL_PIN,HIGH);
  nextSwitch = micros();
}

void loop() {
  timeClock = micros();
  //every time we want to switch polarity simple shift the control pin from low to high or vise versa
  if(timeClock > nextSwitch){
    nextSwitch = timeClock + timeStep;
    state = !state;
    if(state) digitalWrite(CNTRL_PIN,HIGH);
    else digitalWrite(CNTRL_PIN,LOW);
  }
}


