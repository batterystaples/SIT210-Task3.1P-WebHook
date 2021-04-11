#include <Adafruit_DHT.h>

#define DHTPIN 0     // The sensor is connected to pin D0

#define DHTTYPE DHT22 // DHT 22 (AM2302)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    // Ini
	dht.begin();
}

void loop() {
    // Wait 30 seconds before taking the next reading
	delay(30000);
	
	// Read the temperature from the sensor.
	// If the read was unsuccessful, keep trying to
	// read again until it is successful
	float temp = dht.getTempCelcius();
	while (isnan(temp)) {
	    temp = dht.getTempCelcius();
	}
	
	// Send the data to ThingSpeak
	Particle.publish("temperature", String(temp, 1), PRIVATE);
}


