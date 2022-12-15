/*
 * Programmer : Gavin.Butcher
 * Date: 12.12.2022
 * Program: Ultasonic Security System
 * 
 * Resource: https://create.arduino.cc/projecthub/Krepak/ultrasonic-security-system-3afe13?ref=search&ref_id=red%20green%20yellow%20light%20echo%20sensor&offset=1
 * 
 */
int trigPin = 3;
int echoPin = 4;
int LEDlampRed = 12;
int LEDlampYellow = 11;
int LEDlampGreen = 10;
int soundbuzzer = 5;
int sound = 6000;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampRed, OUTPUT);
  pinMode(LEDlampYellow, OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 10 && distanceincm>=7 ) {
      digitalWrite(LEDlampGreen, HIGH);
      Serial.println("Getting close - Proced");
}
  else {
      digitalWrite(LEDlampGreen, LOW);
  }
  
  if (distanceincm < 7) {
    digitalWrite(LEDlampYellow, HIGH);
}
  else {
    digitalWrite(LEDlampYellow,LOW);
  }
  if (distanceincm < 4) {
    digitalWrite(LEDlampRed, HIGH);
    tone(soundbuzzer, sound);
}
  else {
    digitalWrite(LEDlampRed,LOW);
  }
 
  if (distanceincm > 10 || distanceincm <= 0){
    Serial.println("All Clear - Proced");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println(" cm");
    
  }
  
  delay(300);
}
