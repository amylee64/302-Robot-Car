
int photoresist1 = A0;
int photoresist2 = A1;
int photoresist3 = A2;
int photo1 = 0;
int photo2 = 0;
int photo3 = 0;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int off = 40;
float photo1avg = 0;
float photo2avg = 0;
float photo3avg = 0;
float off2 = 20;
float center = 0;

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
   if (analogRead(photoresist1) < off)
        photo1 = (-1) * analogRead(photoresist1) + off;

    else if (analogRead(photoresist1) > off)
        photo1 = 0;
  
    if (analogRead(photoresist2) < off)
        photo2 = (-1) * analogRead(photoresist2) + off;

    else if (analogRead(photoresist2) > off)
        photo2 = 0;
        
    if (analogRead(photoresist3) < off)
        photo3 = (-1) * analogRead(photoresist3) + off;

    else if (analogRead(photoresist3) > off)
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

  center = (photo1avg * (-1))/(photo1avg + photo2avg + photo3avg) + (photo3avg)/(photo1avg + photo2avg + photo3avg);

  
  Serial.println(center);
  Serial.print(" ");
 

  
}
