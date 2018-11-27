
int photoresist1 = A0;
int photoresist2 = A1;
int photoresist3 = A2;
int photo1 = 0;
int photo2 = 0;
int photo3 = 0;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int sum = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.print("aaaaa");
}

void loop() {
  // read the value from the sensor:
  photo1 = analogRead(photoresist1) - 55;
  photo2 = analogRead(photoresist2) - 55;
  photo3 = analogRead(photoresist3) - 55;

  
  sensorValue = analogRead(photoresist1);
 
  Serial.println(sensorValue);
  Serial.print(" ");
  analogWrite(led1, photo1);
  analogWrite(led2, photo2);
  analogWrite(led3, photo3);

  
}
