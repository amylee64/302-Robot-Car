int photoR1 = 0;                  // initialize photoresistor values to 0
int photoR2 = 0;                  // use analogRead in main code
int photoR3 = 0;

int distSen1 = 0;                 // initialize distance sensor values to 0
int distSen2 = 0;                 // use analogRead in main code        
int distSen3 = 0;

int leftMotor = 0;                // initialize motor speed for left and right
int rightMotor = 0;               // write values to these variables to control the car motors
                                 
// add more variables as needed
// need to figure out supplying power to car through Arduino

void setup() {
  // put your setup code here, to run once:
  int buttonPressed = 0;
  
  pinMode(switch, INPUT);         // sets "pin" to input (use if switch included)
  pinMode(pin, OUTPUT);           // "pin" for left motor
  pinMode(pin, OUTPUT);           // "pin" for right motor  

  // insert more pin initializations as needed
  // somehow set "5V" pins to "HIGH" so Arduino powers car? 

}

void loop() {
  // put your main code here, to run repeatedly:

  // CHECK IF SWITCH IS ON // 
  buttonPressed = digitalRead(switch);
  if (buttonPressed == 1) {          // if power on, car moves (if switch included)     

   leftMotor = 10;   // just move car forward
   rightMotor = 10;

   // CODE TO READ IN SENSOR VALUES GOES HERE



   // CODE TO CHANGE MOTOR SPEEDS, ETC. GOES HERE






   // write any speed values to these two variables to change car mvmt
   // change if needed
   analogWrite(pin, leftMotor);
   analogWrite(pin, right Motor); 

    
    

    
    

    
  }

}
