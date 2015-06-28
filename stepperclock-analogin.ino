#define CLOCKDIR_PIN 6
#define CLOCKSTEP_PIN 5

int CLOCKDIR = LOW;
int CLOCKTIMESAT = 0;
float CLOCKSPEED = 0.25;

//speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger,
//the clock stepper works from 0.00000001 to 0,4 with external power, 0,00000001-0,25 with battery


void setup() {
  Serial.begin(9600);


  pinMode(CLOCKDIR_PIN, OUTPUT);
  pinMode(CLOCKSTEP_PIN, OUTPUT);

}

void loop() {
  
  
   // read the sensor value:
  float sensorReading = analogRead(A0);
//  Serial.println("A0:");
//  Serial.println(sensorReading);
//  // map it to a range from 0 to 100:
//  CLOCKSPEED = (((sensorReading)/1000)-0.02);
//  Serial.println("CLOCKSPEED:");
//  Serial.println(CLOCKSPEED);  
  
    if (sensorReading > 523) {
      CLOCKSPEED = map(sensorReading, 523,2000,0,1);
      Serial.println(CLOCKSPEED);
      rotate(44, (CLOCKSPEED), HIGH, CLOCKDIR_PIN, CLOCKSTEP_PIN);
    }
    
//  rotate(6288, CLOCKSPEED, HIGH, CLOCKDIR_PIN, CLOCKSTEP_PIN);
//  delay(1000);
//  
//  rotate(6288, CLOCKSPEED, HIGH, CLOCKDIR_PIN, CLOCKSTEP_PIN);
//  delay(1000);
//  
//  rotate(6288, CLOCKSPEED, LOW, CLOCKDIR_PIN, CLOCKSTEP_PIN);
//  delay(1000);  
//  
//  rotate(6288, CLOCKSPEED, LOW, CLOCKDIR_PIN, CLOCKSTEP_PIN);
//  delay(1000);    
}



void rotate(int steps, float speed, int dir, int DIR_PIN, int STEP_PIN) {
  //rotate a specific number of microsteps (8 microsteps per step) - (negative for reverse movement)


  digitalWrite(DIR_PIN, dir);

  float usDelay = (1 / speed) * 70;

  for (int i = 0; i < steps; i++) {

    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(usDelay);

    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(usDelay);
  }
}

