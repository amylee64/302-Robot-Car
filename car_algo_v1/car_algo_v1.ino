// Pin Configurations *** CHANGE IF NEEDED ***
const int motorL1out = 2;           // pin 11 = left motor (lead 1)
const int motorL2out = 3;           // pin 10 = left motor (lead 2)
const int motorR1out = 4;            // pin 9 = right motor (lead 1)
const int motorR2out = 5;            // pin 8 = right motor (lead 2)

const int p1 = A0;      // setting each photoresistor and distance sensor to its own 
const int p2 = A1;      // analog input pin on the Arduino 
const int p3 = A2;      // *** WE CAN CHANGE THIS IF NEEDED ***
const int d1 = A3;
const int d2 = A4;
const int d3 = A5;

// Variable Declarations
int photoR1 = 0;                  // initialize photoresistor values to 0
int photoR2 = 0;                  // use analogRead in main code
int photoR3 = 0;

int distSen1 = 0;                 // initialize distance sensor values to 0
int distSen2 = 0;                 // use analogRead in main code        
int distSen3 = 0;

int leftMotor1 = 0;                // initialize motor speed for left and right to 0
int leftMotor2 = 0;                // each motor has 2 leads (4 loads) 
int rightMotor1 = 0;               // write values to these variables to control the car motors
int rightMotor2 = 0;

// add more variables as needed
// need to figure out supplying power to car through Arduino/battery/whatever

void setup() {
  pinMode(motorL1out, OUTPUT);           // left motor lead 1 = output
  pinMode(motorL2out, OUTPUT);           // left motor lead 2 = output
  pinMode(motorR1out, OUTPUT);           // right motor lead 1 = output
  pinMode(motorR2out, OUTPUT);           // right motor lead 2 = output

  // insert more pin initializations as needed

}

void loop() {
  /* P1: car stays in the middle of the black tape:
   *    - Check for black tape (photoresistor), then check for obstacle (distance sensor), repeat
   *    - Black = certain value from photoresistor reading, check for this continuously
   *    - when car starts to deviate from path (or if path changes, readjust motor configurations to keep the car on tape
   *    - once obstacle detected, break from checking the black tape (no longer needed)
   *    
   * P2: car navigates around the obstacle:
   *    - find minimum distance car should be from the obstacle (distance sensor)
   *    - go around the thing 
   *    
   * P3: car navigates through walls and looks for red tape:
   *    - use distance sensors/flex sensor? to navigate car through the wall portion.
   *    - keep checking for red tape at end of distance sensor loop portion 
   *    - once red tape detected, car stops (turn off 
   */   
   // when switch on, car will move forwards
   digitalWrite(motorL1out, HIGH);
   digitalWrite(motorR1out, HIGH); 
   digitalWrite(motorL2out, LOW);
   digitalWrite(motorR2out, LOW); 
   
  
 /*else {
    digitalWrite(motorL1out, LOW);
    digitalWrite(motorL2out, LOW);
    digitalWrite(motorR1out, LOW);
    digitalWrite(motorR2out, LOW);
 } */

}
