#include "WeatherStationController.h"

WeatherStationController::WeatherStationController(uint8_t pin)
 : weatherStation(pin), view() {   
}

void WeatherStationController::begin() {
    this->weatherStation.begin();
    this->view.begin();
}

void WeatherStationController::HandleRequests() {
    view.HandleClient(weatherStation);
}
