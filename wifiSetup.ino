/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 */
#include <WiFi.h>

#include <WiFiUdp.h>
#include <NTPClient.h>

// #include <WebS


const char *ssid = "eduroam";
const char *password = "yourPassword"; 
const char *username = "yourLogin@shernet.sheridancollege.ca";

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP);



void connect_wifi()
{
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP());  
}
void connect_wifi_enterprise() 
{
  int counter = 0;
  WiFi.disconnect(true);  
  WiFi.mode(WIFI_STA);    

  WiFi.begin(ssid, WPA2_AUTH_PEAP, username, username, password);
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to get IP address");
}
}

void setup()
{
  Serial.begin(115200);
  // connect_wifi(); swap this depending on network (home vs. school)
  connect_wifi_enterprise();
  Serial.println("connected!");
  // timeClient.begin();
  // timeClient.setTimeOffset(3600 * -5); local time
  // timeClient.update();

}

void loop()
{
  // Serial.print(timeClient.getFormattedTime());
  delay(1000);
  Serial.println(WiFi.localIP());  

}
   