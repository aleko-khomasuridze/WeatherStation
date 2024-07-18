#ifndef VIEW_H
#define VIEW_H

#include <Ethernet.h>
#include "../../src/Model/WeatherStation.h"

/**
 * @class View
 * @brief Manages the Ethernet server and handles client requests for the Weather Station.
 */
class View {
private:
    EthernetServer server; /**< The Ethernet server instance */

public:
    /**
     * @brief Constructor for View class. Initializes the Ethernet server on port 80.
     */
    View() : server(EthernetServer(8080)) {}

    /**
     * @brief Initializes the Ethernet server and starts listening for client connections.
     */
    void begin();

    /**
     * @brief Handles incoming client requests and processes them.
     * @param weatherStation A reference to the WeatherStation object containing sensor data.
     */
    void HandleClient(const WeatherStation &weatherStation);

    /**
     * @brief Sends an HTTP response to the client with the current weather data.
     * @param client The Ethernet client to send the response to.
     * @param weatherStation The WeatherStation object containing the current weather data.
     */
    void SendResponse(EthernetClient client, WeatherStation weatherStation);
};

#endif // VIEW_H
