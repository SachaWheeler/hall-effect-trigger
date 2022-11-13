int hallSensorPin = 4;
int hallSensorValue = 0;

int period = 1 * 1000; // 1 second
unsigned long time_now = 0;
unsigned long trigger_time = 0;
bool trigger = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(hallSensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  time_now = millis();

  hallSensorValue = digitalRead(hallSensorPin);
  //Serial.print("hallSensorValue: ");
  //Serial.println(hallSensorValue);

  if (trigger == true && hallSensorValue == 0) {
    // send a serial message and only do this once per second
    Serial.println("trigger");

    trigger_time = time_now;
    trigger = false;
  }
  if (trigger == false && time_now > trigger_time + period) {
    // turn it on again
    trigger = true;
  }
}