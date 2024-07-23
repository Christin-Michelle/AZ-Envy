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

Letztlich wurde noch ein Gehäuse designed mit dem sich das ganze an der Wand befestigen lässt.

https://www.thingiverse.com/thing:6706285

Wichtig wäre noch zu Erwähnen dass der AZ Envy eine etwas ungewöhnliche Anschlusskonfiguration hat. Zum Flashen ist es notwendig diesem über USB mit Strom zu versorgen, jedoch mittels eines USB zu Serial Adapters die Daten zu übertragen.

VORSICHT 3,3V Pegel einstellen sonst wird der Chip geröstet!

Ferner hat der Chip die Besonderheit, dass TX auf TX und RX auf RX angeschlossen werden muss damit es funktioniert.



A simple impelmentation of the MQTT client on the basis of AZ Envy. Every other second values are measured and send to the server via MQTT.

Mainly the following libraries are used:

https://github.com/Risele/SHT3x

https://github.com/plapointe6/EspMQTTClient

https://github.com/labay11/MQ-2-sensor-library

I used so following link as well es the included ebook from AZ Delivery

https://www.az-delivery.de/en/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/az-envy-das-etwas-andere-micro-controller-board

Besides that the implementation is pretty much straigt forward. The devices and software is prepared in the setup sectopm and the values are read and sent in the loop.

Finally a case was designed to afix this to the wall.

https://www.thingiverse.com/thing:6706285

Also important would be to mention that the AZ Envy has a little a unusual conncetion configuration. To falsh it it is necessary to suplly power via the integrated USB port but to send data with a USB to serial adapter.

CAUTION: Set your adapter to 3,3V otherwise you'll rost the Chip.

Last but not least the AZ Envy has the specialty that you need to connect the TX to TX and the RX to RX in order to have the transfer working.
