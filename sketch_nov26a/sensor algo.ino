
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
  photo1 = analogRead(photoresist1);
  photo2 = analogRead(photoresist2);
  photo3 = analogRead(photoresist3);
  sum = photo1 + photo2 + photo3;
  
  // turn the ledPin on
  digitalWrite(led1, HIGH);
  delayMicroseconds(photo1);
  digitalWrite(led1, LOW);
  
  digitalWrite(led2, HIGH);
  delayMicroseconds(photo2);
  digitalWrite(led2, LOW);

  digitalWrite(led3, HIGH);
  delayMicroseconds(photo3);
  digitalWrite(led3, LOW);

  Serial.print(photo1);
  Serial.print("");

}
