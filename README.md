# AZ-Envy
A MQTT implementation for AZ Envy delivering measured values each 2 seconds to the MQTT server

Eine einfache Implementierung eines MQTT Clients auf Basis des AZ Envy. Es werden alle 2 Sekunden Messwerte erfasst und per MQTT an den Server gesendet.

Es werden in der Hauptsache folgende Bibliotheken verwendet:

https://github.com/Risele/SHT3x
https://github.com/plapointe6/EspMQTTClient
https://github.com/labay11/MQ-2-sensor-library


Ich habe Software mit folgendem Link, sowie dem mitgelieferten Deutschen EBook aufgebaut

https://www.az-delivery.de/en/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/az-envy-das-etwas-andere-micro-controller-board

Ansonsten ist die Implementierung ziemlich geradeaus. Vorbereiten der Devices und Treiber im Setup sowie zyklisches Auslesen der Werte und senden im Loop.

A simple impelmentation of the MQTT client on the basis of AZ Envy. Every other second values are measured and send to the server via MQTT.

Mainly the following libraries are used:

https://github.com/Risele/SHT3x
https://github.com/plapointe6/EspMQTTClient
https://github.com/labay11/MQ-2-sensor-library

I used so following link as well es the included ebook from AZ Delivery

https://www.az-delivery.de/en/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/az-envy-das-etwas-andere-micro-controller-board

Besides that the implementation is pretty much straigt forward. The devices and software is prepared in the setup sectopm and the values are read and sent in the loop.
