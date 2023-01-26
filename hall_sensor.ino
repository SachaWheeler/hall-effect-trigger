int hallSensorPin = 4;
int hallSensorValue = 0;

int period = 1 * 1000;  // 1 second
unsigned long time_now = 0;
unsigned long trigger_time = 0;
bool trigger = true;

void setup() {
  Serial.begin(115200);
  pinMode(hallSensorPin, INPUT);

  while (!Serial.available())
    ;
}

void loop() {
  time_now = millis();
  hallSensorValue = digitalRead(hallSensorPin);

  if (trigger == true && hallSensorValue == 0) {
    Serial.println(1);

    trigger_time = time_now;
    trigger = false;
  }
  if (trigger == false && time_now > trigger_time + period) {
    // turn it on again
    trigger = true;
  }
}