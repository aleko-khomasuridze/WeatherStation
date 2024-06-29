#include <SPI.h>
#include <Ethernet.h>

#include "src/Controller/WeatherStationController.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);

WeatherStationController weatherStationController = WeatherStationController(D2);

void setup(void) {  
    Serial.begin(115200);

    Ethernet.begin(mac, ip);
    Serial.print("Server is at ");
    Serial.println(Ethernet.localIP());

    weatherStationController.begin();
}

void loop(void) {
    weatherStationController.HandleRequests();
}