// WifiLocation.h

#ifndef _WIFILOCATION_h
#define _WIFILOCATION_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

//#define DEBUG_WIFI_LOCATION

#ifdef ARDUINO_ARCH_SAMD
#include <WiFi101.h>
#elif defined ARDUINO_ARCH_ESP8266
#include <ESP8266WiFi.h>
#else
#error Wrong platform
#endif 

const String googleApisHost = "www.googleapis.com";
const String googleApiUrl = "/geolocation/v1/geolocate";

typedef struct {
    float lat = 0;
    float lon = 0;
    int accuracy = 40000;
} location_t;

class WifiLocation {
public:
    WifiLocation(String googleKey = "");
    location_t getGeoFromWiFi();

protected:
    String _googleApiKey;
    //String _googleApiFingerprint = "2c 86 e4 67 e7 b5 ca df 11 9e bd 2e 41 c2 4b e8 b6 7e cd aa";
    //IPAddress _googleApiIP = IPAddress(216, 58, 214, 170);
#ifdef ESP8266
    WiFiClientSecure  _client;
#elif defined ARDUINO_ARCH_SAMD
    WiFiSSLClient  _client;
#endif

    static String getSurroundingWiFiJson();
    static String MACtoString(uint8_t* macAddress);
};

#endif
