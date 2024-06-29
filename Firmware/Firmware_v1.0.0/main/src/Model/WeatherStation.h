#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include <DHT.h>

/**
 * @class WeatherStation
 * @brief Manages the DHT sensor for reading temperature and humidity.
 */
class WeatherStation {
private:
    DHT _dht; /**< DHT sensor instance */

public:
    /**
     * @brief Constructor for WeatherStation class. Initializes the DHT sensor.
     * @param pin The pin number where the DHT sensor is connected.
     */
    WeatherStation(uint8_t pin);

    /**
     * @brief Initializes the DHT sensor.
     * @return true if the sensor was initialized successfully, false otherwise.
     */
    bool begin();

    /**
     * @brief Gets the current temperature from the DHT sensor.
     * @return The temperature in Celsius.
     */
    float GetTemperature();

    /**
     * @brief Gets the current humidity from the DHT sensor.
     * @return The humidity percentage.
     */
    float GetHumidity();

    /**
     * @brief Returns a string representation of the current weather data.
     * @return A string containing the temperature and humidity.
     */
    String ToString();
};

#endif // WEATHERSTATION_H
