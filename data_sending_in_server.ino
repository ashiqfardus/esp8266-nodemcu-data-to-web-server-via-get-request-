#include <ESP8266WiFi.h>

const char* ssid = ""; //Your SSID here
const char* password = ""; //Your network password here
const char* host="//Your host adress here. Like- www.google.com";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while(WiFi.status() !=WL_CONNECTED) //Wifi connection
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Wifi connected");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
  Serial.println("NesMask: ");
  Serial.println(WiFi.subnetMask());
  Serial.println("Getway: ");
  Serial.println(WiFi.gatewayIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Connecting to: ");
  Serial.println(host);

  WiFiClient client;
 const int httpPort= 80; //default port
 if(!client.connect(host,httpPort)) //HTTP Connection
 {
  Serial.println("Connection failed");
  return;
 }
 int r=1000;
 String url ="/index.php?rfid="+ String(r); //Url which will insert data to database
 Serial.println("Requesting URLL  ");
 Serial.println(url);

 client.print(String("GET ") + url + " HTTP/1.0\r\n" + //get request to the server
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

 delay(5000);
 while(client.available())
 {
  String line = client.readStringUntil('\r');
  Serial.print(line);
 }
 Serial.println();
 Serial.println("Closing connection");
 delay(10000);

}
