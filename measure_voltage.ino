float batteryVoltage = 0.0;
float referenceVoltage = 3.3;
float senseVoltage = 0.0;
float resistorOne = 99800.0;
float resistorTwo = 99900.0;
int analogInputPin = A0;
int analogInputVal = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  analogInputVal = analogRead(analogInputPin);
  senseVoltage = (float)analogInputVal * referenceVoltage / 1024.0; 
  batteryVoltage = (resistorOne+resistorTwo)*senseVoltage/resistorTwo;
  Serial.print("adc value = ");
  Serial.print(analogInputVal);
  Serial.print(" sense value = ");
  Serial.print(senseVoltage);
  Serial.print(" battery value = ");
  Serial.println(batteryVoltage);
  delay(1000);
}
