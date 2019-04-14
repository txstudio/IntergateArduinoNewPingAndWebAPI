#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(500);

  String _sonar_ping = String(sonar.ping());
  String _sonar_ping_cm = String(sonar.ping_cm());
  String _QueryString = String("?ping="+_sonar_ping+"&pingCm="+_sonar_ping_cm);

  // URL => /api/IoT/GetLog?ping=0.00&pingCm=0.00

  //使用 HttpPost 不會成功
  Serial.print("GET /api/IoT/GetLog");
  Serial.print(_QueryString);
  Serial.println(" HTTP/1.1");
  Serial.println("Host: 192.168.0.106");
  Serial.println();
  Serial.flush();
}
