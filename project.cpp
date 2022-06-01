// This #include statement was automatically added by the Particle IDE.
// Library that get Functions needed to get the humidity and temperature
//temperature reading from the Sensors
#include <Adafruit_DHT.h>


DHT dht(A0,DHT11); // Get the DHT pin and DHT type 
int blue = D2; // Set Pin D2 as led 
int yellow = D3; // Set Pin D2 as led 

void setup() {
    pinMode(blue, OUTPUT); // D2 pin in-built LED
    pinMode(yellow, OUTPUT); // D3 pin in-built LED
    dht.begin(); // Activate DHT11
    
}

void loop() {
     
    float temp = dht.getTempCelcius(); // Get Tempreture in Celcius

    // Trigger the Webhook - Puplish event to Cloud
    //Particle.publish("temp",String(temp),PRIVATE); // Test - Show Temperature
    if(temp > 20 ) {
        Particle.publish("temp", "warm", PRIVATE); // if the temp is more 20 Celcius the data is warm
        digitalWrite(yellow,HIGH); // Turn On Yellow Light 
        digitalWrite(blue,LOW); // Turn Off Blue Light 
        delay(1800s); // Wait for 30 Minutes
        delay(3s); // Test - Wait for 3 seconds
    }
    else  {// if(temp < 20 )
        Particle.publish("temp", "cold", PRIVATE); // if the temp is less then 20 Celcius the data is cold
        digitalWrite(yellow,LOW); // Turn Off Yellow Light 
        digitalWrite(blue,HIGH); // Turn On Blue Light 
        //delay(3s); // Test - Wait for 3 seconds
        delay(1800s); // Wait for 30 Minutes
    }
   
}
