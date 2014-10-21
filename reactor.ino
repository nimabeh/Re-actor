
const int motorPin = 9;

int ledPin = 10;

int brightness = 0;
int sensorLow = 0;
int sensorHigh = 15;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  brightness = map(sensorValue, sensorLow, sensorHigh, 0, 255);
  analogWrite(ledPin, brightness);
  delay(300);        // delay in between reads for stability
  
  int speed;
  speed = map (sensorValue, sensorLow, sensorHigh, 255, 0);
  analogWrite(motorPin, speed);

}
