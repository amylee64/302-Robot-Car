// Pin Configurations *** CHANGE IF NEEDED ***
const int motorL1out = 2;           // pin 11 = left motor (lead 1)
const int motorL2out = 3;           // pin 10 = left motor (lead 2)
const int motorR1out = 4;            // pin 9 = right motor (lead 1)
const int motorR2out = 5;            // pin 8 = right motor (lead 2)

int photoresist1 = A0;
int photoresist2 = A1;
int photoresist3 = A2;
int photo1 = 0;
int photo2 = 0;
int photo3 = 0;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int off1 = 420;
int off2 = 407;
int off3 = 376;
float photo1avg = 0;
float photo2avg = 0;
float photo3avg = 0;
float center = 0;
float centerold = 0;
float PID = 0;
int P = 1;
int I = -1;
int D = -.1;
<<<<<<< HEAD
int vel = 100;
int radius = 100;
float w = 0;
float centeravg = 0;
int velocity = 100;
int runtime = 100;
float Y = 0;
//int posThresh = 0.2;
//int negThresh = -0.2;

=======
int posThresh = 0.2;
int negThresh = -0.2;
int redValLow = 435;
int redValHigh = 455;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(photo2, INPUT);
  pinMode(photo2, INPUT);
  pinMode(photo3, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
   if (analogRead(photoresist1) < off1)
        photo1 = (-1) * analogRead(photoresist1) + off1;

    else if (analogRead(photoresist1) > off1)
        photo1 = 0;
  
    if (analogRead(photoresist2) < off2)
        photo2 = (-1) * analogRead(photoresist2) + off2;

    else if (analogRead(photoresist2) > off2)
        photo2 = 0;
        
    if (analogRead(photoresist3) < off3)
        photo3 = (-1) * analogRead(photoresist3) + off3;

    else if (analogRead(photoresist3) > off3)
        photo3 = 0;

        photo1 = photo1 * 10;
        photo2 = photo2 * 10;
        photo3 = photo3 * 10;

/*
        
  photo1 = 5 * abs(analogRead(photoresist1) - off);
  photo2 = 5 * abs(analogRead(photoresist2) - off);
  photo3 = 5 * abs(analogRead(photoresist3) - off);*/
  
  photo1avg = (photo1 + 3 * photo1avg)/4;
  photo2avg = (photo2 + 3 * photo2avg)/4;
  photo3avg = (photo3 + 3 * photo3avg)/4;

  analogWrite(led1, photo1avg);
  analogWrite(led2, photo2avg);
  analogWrite(led3, photo3avg);

  //centerold = center;

  center = (photo1avg * (-1))/(photo1avg + photo2avg + photo3avg) + (photo3avg)/(photo1avg + photo2avg + photo3avg);
  
  centeravg = (centerold * 7) + center;
  
  Serial.println(center);
  Serial.print(" ");

  delay(4);

  //turning algo
  
  //Y = radius - centeravg;


  if(center <= 1 || center >= -1){
       Serial.println(center);
       Serial.print(" ");
  }

  delay(4);

  PID = P*center + I*(center+centerold) + D*(center-centerold);

  //turning algo without PID
  if(center > posThresh){
         analogWrite(motorL1out, 5);
         analogWrite(motorR1out, 50); 
  } else if (center < negThresh){
         analogWrite(motorL1out, 50);
         analogWrite(motorR1out, 5); 
  } else {
         analogWrite(motorL1out, 50);
         analogWrite(motorR1out, 50); 
  }

  //stopping at red tape
  if(analogRead(photoresist1) > redValLow && analogRead(photoresist1) < redValHigh &&
     analogRead(photoresist2) > redValLow && analogRead(photoresist2) < redValHigh &&
     analogRead(photoresist3) > redValLow && analogRead(photoresist3) < redValHigh){ 
         analogWrite(motorL1out, 0);
         analogWrite(motorR1out, 0); 
  }
  //Y = radius - center;

  // v^2/r= (w*r)^2/r, w*r=v

  //w = vel/radius;

  

}

  
 

 
