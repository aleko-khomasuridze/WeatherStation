#include "View.h"


void View::begin() {
    this->server.begin();
}

void View::HandleClient(const WeatherStation &weatherStation) {
    EthernetClient client = server.available();
    if (client) {
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                if (c == '\n' && currentLineIsBlank) {
                    this->SendResponse(client, weatherStation);
                    break;
                }
                if (c == '\n') {
                    currentLineIsBlank = true;
                }
                else if (c != '\r'){
                    currentLineIsBlank = false;
                }
            }
        }
        delay(1);
        client.stop();
    }
}

void View::SendResponse(EthernetClient client, WeatherStation weatherStation) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: application/json");
    client.println("Connection: close");
    client.println();
    client.println(weatherStation.ToString());
}