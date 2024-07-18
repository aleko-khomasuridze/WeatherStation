#include <SPI.h>
#include <Ethernet.h>
#include "src/Controller/WeatherStationController.h"

// MAC address for the Ethernet shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// IP address for the Ethernet shield
IPAddress ip(192, 168, 1, 2);

// Create an instance of WeatherStationController with pin D2
WeatherStationController weatherStationController = WeatherStationController(PC13);

/**
 * @brief Setup function initializes the serial communication, Ethernet connection,
 * and starts the weather station controller.
 */
void setup(void) {  
    // Initialize serial communication at a baud rate of 115200
    Serial.begin(115200);

    // Start the Ethernet connection with the provided MAC and IP address
    Ethernet.begin(mac, ip);
    Serial.print("Server is at ");
    Serial.println(Ethernet.localIP());

    // Initialize the weather station controller
    weatherStationController.begin();
}

/**
 * @brief Main loop function that continuously handles incoming requests
 * to the weather station controller.
 */
void loop(void) {
    // Handle incoming requests to the weather station controller
    weatherStationController.HandleRequests();
}
