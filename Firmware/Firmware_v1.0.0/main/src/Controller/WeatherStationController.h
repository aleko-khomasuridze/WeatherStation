#ifndef WEATHERSTATIONCONTROLLER_H
#define WEATHERSTATIONCONTROLLER_H

#include "../../src/Model/WeatherStation.h"
#include "../../src/View/View.h"

/**
 * @class WeatherStationController
 * @brief Controls the WeatherStation model and the View to handle requests and responses.
 */
class WeatherStationController {
private:
    WeatherStation weatherStation; /**< Instance of the WeatherStation model */
    View view; /**< Instance of the View */

public:
    /**
     * @brief Constructor for WeatherStationController class. Initializes the WeatherStation with the given pin.
     * @param pin The pin number where the DHT sensor is connected.
     */
    WeatherStationController(uint8_t pin);

    /**
     * @brief Initializes the WeatherStation and View.
     */
    void begin();

    /**
     * @brief Handles incoming requests by using the View to process and respond to client requests.
     */
    void HandleRequests();
};

#endif // WEATHERSTATIONCONTROLLER_H
