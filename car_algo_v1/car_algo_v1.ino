// Pin Configurations *** CHANGE IF NEEDED ***
const int motorL1out = 2;           // pin 11 = left motor (lead 1)
const int motorL2out = 3;           // pin 10 = left motor (lead 2)
const int motorR1out = 4;            // pin 9 = right motor (lead 1)
const int motorR2out = 5;            // pin 8 = right motor (lead 2)

const int photoresist1 = A2;      // setting each photoresistor and distance sensor to its own 
const int photoresist2 = A1;      // analog input pin on the Arduino 
const int photoresist3 = A0;      // *** WEd CAN CHANGE THIS IF NEEDED ***
const int dFront = A6;            // distance sensor variables
const int dLeft = A7;
const int dRight = A5;

const int ledred = 11;            //we can like, uhh, change the led colors
const int ledblue = 10;
const int ledgreen = 9;


// Variable Declarations
bool flag = true;

int photoR1 = 0;                  // initialize photoresistor values to 0
int photoR2 = 0;                  // use analogRead in main code
int photoR3 = 0;
int photoR1avg = 0;
int photoR2avg = 0;
int photoR3avg = 0;

int dThresh = 400;

int photoR1white = 0;
int photoR2white = 0;
int photoR3white = 0;

float center = 0;
float centeravg = 0;

int distSen1 = 0;                 // initialize distance sensor values to 0
int distSen2 = 0;                 // use analogRead in main code        
int distSen3 = 0;


int leftMotor1 = 0;                // initialize motor speed for left and right to 0
int leftMotor2 = 0;                // each motor has 2 leads (4 loads) 
int rightMotor1 = 0;               // write values to these variables to control the car motors
int rightMotor2 = 0;


// red tape range for R1 is 473 +-10
// red tape range for R2 is 525 +-10
// red tape range for R3 is 442 +- 10


// add more variables as needed
// need to figure out supplying power to car through Arduino/battery/whatever

void setup() {
  pinMode(motorL1out, OUTPUT);           // left motor lead 1 = output
  pinMode(motorL2out, OUTPUT);           // left motor lead 2 = output
  pinMode(motorR1out, OUTPUT);           // right motor lead 1 = output
  pinMode(motorR2out, OUTPUT);           // right motor lead 2 = output

  pinMode(photoresist1, INPUT);          // pin initializations for photo resistor sensors
  pinMode(photoresist2, INPUT); 
  pinMode(photoresist3, INPUT); 
  pinMode(dFront, INPUT); 
  pinMode(dLeft, INPUT);                    // pin initializations for distance sensors
  pinMode(dRight, INPUT); 
  Serial.begin(9600);

  pinMode(ledred, OUTPUT);          // pin initializations for RGB led
  pinMode(ledblue, OUTPUT); 
  pinMode(ledgreen, OUTPUT);


  delay(1000);

  photoR1white = analogRead(photoresist1);
  photoR2white = analogRead(photoresist2);
  photoR3white = analogRead(photoresist3);
  
  delay(3000);       // 3 second delay before car starts moving (easier to manage bot physically)

  digitalWrite(motorL1out, HIGH);     // initial car motor values
  digitalWrite(motorL2out, LOW);
  digitalWrite(motorR1out, HIGH);
  digitalWrite(motorR2out, LOW); 
              
  // insert more pin initializations as needed

}

void loop() {
  /* P1: car stays in the middle of the black tape:
   *    - Check for black tape (photoresistor), then check for obstacle (distance sensor), repeat
   *    - Black = certain value from photoresistor reading, check for this continuously
   *    - when car starts to deviate from path (or if path changes, readjust motor configurations to keep the car on tape
   *    - once obstacle detected, break from checking the black tape (no longer needed)
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
 

//      digitalWrite(motorL1out, HIGH);
//      digitalWrite(motorL2out, LOW);
//      digitalWrite(motorR1out, HIGH);
//      digitalWrite(motorR2out, LOW); 

// PHOTORESISTOR PORTION
   /*We're gonna pull photoresistor values! 
     this bit makes the maps the photoresist values to ~0 if it's on white, and like ~200 if it's on black */
if(analogRead(dFront) < dThresh && flag){
     if (analogRead(photoresist1) < photoR1white)
        photoR1 = (-1) * analogRead(photoresist1) + photoR1white;

    else if (analogRead(photoresist1) > photoR1white)
        photoR1 = 0;
  
    if (analogRead(photoresist2) < photoR2white)
        photoR2 = (-1) * analogRead(photoresist2) + photoR2white;

    else if (analogRead(photoresist2) > photoR2white)
        photoR2 = 5;
        
    if (analogRead(photoresist3) < photoR3white)
        photoR3 = (-1) * analogRead(photoresist3) + photoR3white;

    else if (analogRead(photoresist3) > photoR3white)
        photoR3 = 0;

        photoR1 = photoR1 * 10;
        photoR2 = photoR2 * 10;
        photoR3 = photoR3 * 10;

   /*this smooths out the values over time*/
  
  photoR1avg = (photoR1 + photoR1avg)/2;
  photoR2avg = (photoR2 + photoR2avg)/2;
  photoR3avg = (photoR3 + photoR3avg)/2;

  if (photoR1avg > 0)
        photoR1avg = photoR1avg;

    else if (photoR1avg < 0)
        photoR1avg = 0;

  if (photoR2avg > 0)
        photoR2avg = photoR2avg;

    else if (photoR2avg < 0)
        photoR2avg = 0;

  if (photoR3avg > 0)
        photoR3avg = photoR3avg;

    else if (photoR3avg < 0)
        photoR3avg = 0; 
  /*we will approximate the center of the tape*/

/*  center = (photoR1avg * (-1))/(photoR1avg + photoR2avg + photoR3avg) + (photoR3avg)/(photoR1avg + photoR2avg + photoR3avg);
  /*then smooth that value out too*/

  /*centeravg = (7*centeravg + center)/8;*/


  // Calculation of photoresistor data needed for car to navigate black tape path
if(photoR1avg > photoR2avg && photoR1avg > photoR3avg || ( photoR1avg && photoR2avg > 8000)){
      center = -1;
  } else if (photoR2avg > photoR1avg && photoR2avg > photoR3avg){
      center = 0;
  } else if (photoR3avg > photoR1avg && photoR3avg > photoR2avg|| ( photoR3avg && photoR2avg > 8000)){
      center = 1;
  }

  // When car moving on black tape 
  if(center > 0){
      digitalWrite(motorL1out, HIGH);
      digitalWrite(motorL2out, LOW);
      digitalWrite(motorR1out, LOW);
      digitalWrite(motorR2out, HIGH); 

      analogWrite(ledred, 0);
      analogWrite(ledblue, 0);
      analogWrite(ledgreen, 255);
  } else if (center < 0){
      digitalWrite(motorL1out, LOW);
      digitalWrite(motorL2out, HIGH);
      digitalWrite(motorR1out, HIGH);
      digitalWrite(motorR2out, LOW);

      analogWrite(ledred, 0);
      analogWrite(ledblue, 255);
      analogWrite(ledgreen, 0);
  } else {
      digitalWrite(motorL1out, HIGH);
      digitalWrite(motorL2out, LOW);
      digitalWrite(motorR1out, HIGH);
      digitalWrite(motorR2out, LOW); 

      
      analogWrite(ledred, 0);
      analogWrite(ledblue, 0);
      analogWrite(ledgreen, 255);
   }



// DISTANCE SENSOR PORTION

// red tape range for R1 is 473 +-10
// red tape range for R2 is 525 +-10
// red tape range for R3 is 442 +- 10
}
else if (analogRead(dFront) > dThresh && flag){
   /* Serial.print("second portion");
    if ((483 > analogRead(photoresist1) > 463) && (535 > analogRead(photoresist2) > 515) && (452 > analogRead(photoresist1) > 432)){
  */
      if(analogRead(dFront) > dThresh){
        digitalWrite(motorL1out, LOW);
        digitalWrite(motorL2out, LOW);
        digitalWrite(motorR1out, LOW);
        digitalWrite(motorR2out, LOW);
      }else{
        flag = false;
      }
}else{
      if ((483 > analogRead(photoresist1) > 463) && (535 > analogRead(photoresist2) > 515) && (452 > analogRead(photoresist1) > 432)){ //found red
        digitalWrite(motorL1out, LOW);
        digitalWrite(motorL2out, LOW);
        digitalWrite(motorR1out, LOW);
        digitalWrite(motorR2out, LOW);
      }else{
        digitalWrite(motorL1out, HIGH);
        digitalWrite(motorL2out, LOW);
        digitalWrite(motorR1out, HIGH);
        digitalWrite(motorR2out, LOW);
      }
  }
  Serial.println(analogRead(dFront));
  Serial.print(" ");
}
