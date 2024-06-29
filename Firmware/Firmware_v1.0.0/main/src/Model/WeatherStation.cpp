#include "WeatherStation.h"


WeatherStation::WeatherStation(uint8_t pin) : _dht(pin, DHT11){}

bool WeatherStation::begin()
{
    this->_dht.begin();
    return true;
}

float WeatherStation::GetTemperature() {
    return this->_dht.readTemperature();
}

float WeatherStation::GetHumidity() {
    return this->_dht.readHumidity();
}

 
String WeatherStation::ToString() {
    String stringObj = "{";
    stringObj += "\"temp\": " + String(this->GetTemperature()) + ", ";
    stringObj += "\"hum\": " + String(this->GetHumidity()) + ", ";
    stringObj += "}";
    return stringObj;
}
