#define trigPin 9
#define echoPin 10
#define relayPin 7 // Relay connected to pin 7

long duration;
int distance;
void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(relayPin, OUTPUT);
 Serial.begin(9600);
 digitalWrite(relayPin, HIGH); // TV ON initially
}

void loop() {
 // Send ultrasonic pulse
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 
 digitalWrite(trigPin, LOW);
 
 // Read echo
 duration = pulseIn(echoPin, HIGH);
 // Calculate distance (in cm)
 distance = duration * 0.034 / 2;
 Serial.print("Distance: ");
 Serial.println(distance);
 // Condition: if kid is too close
 if (distance < 25) {
 digitalWrite(relayPin, LOW); // OFF (TV OFF)
 Serial.println("Too Close! Turning OFF");
 } 
 else {
 digitalWrite(relayPin, HIGH); // ON (TV ON)
 Serial.println("Safe Distance - ON");
 }
 delay(500);
}
