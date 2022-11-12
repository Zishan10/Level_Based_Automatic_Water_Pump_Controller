
/* Change these values based on your calibration values */ 

int lowerThreshold = 420; 

int upperThreshold = 520; 

 

// Sensor pins 

#define sensorPower 7 

#define sensorPin A0 

 

// Value for storing water level6 

int val = 0; 

 

// Declare pins to which LEDs are connected 

int redLED = 2; 

int yellowLED = 3; 

int greenLED = 4; 

int pump = 5; 

 

//motor A 

int enA=9; 

int in1=10; 

int in2=11; 

 

void setup() { 

  Serial.begin(9600); 

  pinMode(sensorPower, OUTPUT); 

  digitalWrite(sensorPower, LOW); 

   

  // Set LED pins as an OUTPUT 

  pinMode(redLED, OUTPUT); 

  pinMode(yellowLED, OUTPUT); 

  pinMode(greenLED, OUTPUT); 

  pinMode(pump, OUTPUT); 

 

  // Set motor pins as an OUTPUT 

  pinMode(enA, OUTPUT); 

  pinMode(in1, OUTPUT); 

  pinMode(in2, OUTPUT); 

 

   

  // Initially turn off all LEDs 

  digitalWrite(redLED, LOW); 

  digitalWrite(yellowLED, LOW); 

  digitalWrite(greenLED, LOW); 

  digitalWrite(pump, LOW); 

  analogWrite(enA,250); 

} 

void loop() { 

  int level = readSensor(); 

 

  if (level == 0) { 

    Serial.println("Water Level: Empty    Pump : ON"); 

    digitalWrite(redLED, LOW); 

    digitalWrite(yellowLED, LOW); 

    digitalWrite(greenLED, LOW); 

    digitalWrite(pump, HIGH); 

     

    //motor A forward 

  

    //analogWrite(enA,0); 

    digitalWrite(in1,HIGH); 

    digitalWrite(in2,LOW); 

    analogWrite(enA,250); 

    delay (200); 

  } 

  else if (level > 0 && level <= lowerThreshold) { 

    Serial.println("Water Level: Low    Pump : ON"); 

    digitalWrite(redLED, HIGH); 

    digitalWrite(yellowLED, LOW); 

    digitalWrite(greenLED, LOW); 

    digitalWrite(pump, HIGH); 

 

    //motor A forward 

  

    //analogWrite(enA,0); 

    digitalWrite(in1,HIGH); 

    digitalWrite(in2,LOW); 

    analogWrite(enA,250); 

    delay (200); 

  } 

  else if (level > lowerThreshold && level <= upperThreshold) { 

    Serial.println("Water Level: Medium    Pump : ON"); 

    digitalWrite(redLED, LOW); 

    digitalWrite(yellowLED, HIGH); 

    digitalWrite(greenLED, LOW); 

    digitalWrite(pump, HIGH); 

 

 

    //motor A forward 

  

    //analogWrite(enA,0); 

    digitalWrite(in1,HIGH); 

    digitalWrite(in2,LOW); 

    analogWrite(enA,250); 

    delay (200); 

  } 

  else if (level > upperThreshold) { 

    Serial.println("Water Level: High    Pump : OFF"); 

    digitalWrite(redLED, LOW); 

    digitalWrite(yellowLED, LOW); 

    digitalWrite(greenLED, HIGH); 

    digitalWrite(pump, LOW); 

 

    //motor A stop 

  

    analogWrite(enA,0); 

    digitalWrite(in1,HIGH); 

    digitalWrite(in2,LOW); 

    analogWrite(enA,0); 

    delay (200); 

  } 

  delay(1000); 

} 

 

//This is a function used to get the reading 

int readSensor() { 

  digitalWrite(sensorPower, HIGH); 

  delay(10); 

  val = analogRead(sensorPin); 

  digitalWrite(sensorPower, LOW); 

  return val; 

} 

 
