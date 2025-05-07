#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "Jasmine's A52s 5G";
const char* password = "tebakdong";

ESP8266WebServer server(80);
String webpage;

void setup() {
    Serial.begin(9600);
    delay(10);

    pinMode(D2, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D6, OUTPUT);

    // Connect to Wi-Fi
    Serial.println();
    Serial.print("Connecting to ");

    //Configure Wi-Fi
    WiFi.mode(WIFI_AP);
    WiFi.begin(ssid, password);

    //Print status
    Serial.println("Ip Address: ");
    Serial.println(WiFi.softAPIP());

    // Isi dari Webpage
    webpage+= "<h1>Web Control ESP8266</h1>";
    webpage+= "<h2>Jasmine</h2>";
    webpage+= "<p>LED 1 :";
    webpage+= "<a href=\"/LED1ON\"><button>ON</button></a> <a href=\"/LED1OFF\"><button>OFF</button></a></p><br>";
    webpage+= "<p>LED 2 :";
    webpage+= "<a href=\"/LED2ON\"><button>ON</button></a> <a href=\"/LED2OFF\"><button>OFF</button></a></p><br>";
    webpage+= "<p>LED 3 :";
    webpage+= "<a href=\"/LED3ON\"><button>ON</button></a> <a href=\"/LED3OFF\"><button>OFF</button></a></p><br>";

    //tampilan webpage
    server.on("/", []() {
        server.send(200, "text/html", webpage);
    });

    // respon perintah masuk
    server.on("/LED1ON", []() {
        server.send(200, "text/html", webpage);
        digitalWrite(D2, HIGH);
        delay(1000);
    });
    server.on("/LED2ON", []() {
        server.send(200, "text/html", webpage);
        digitalWrite(D4, HIGH);
        delay(1000);
    });
    server.on("/LED3ON", []() {
        server.send(200, "text/html", webpage);
        digitalWrite(D6, HIGH);
        delay(1000);
    });
    server.on("/LED1OFF", []() {
        server.send(200, "text/html", webpage);
        digitalWrite(D2, LOW);
        delay(1000);
    });
    server.on("/LED2OFF", []() {
        server.send(200, "text/html", webpage);
        digitalWrite(D4, LOW);
        delay(1000);
    });
    server.on("/LED3OFF", []() {
        server.send(200, "text/html", webpage);
        digitalWrite(D6, LOW);
        delay(1000);
    });
}

void loop() {
    server.handleClient();
}