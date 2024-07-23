#include <Arduino.h>
#include <EspMQTTClient.h>
#include <SHT3x.h>
#include <string.h>
#include <MQ2.h>

#undef __DEBUG__
//#define __DEBUG__

int MQ2pin = A0;

MQ2 mq2(MQ2pin);
SHT3x SHTSensor;

EspMQTTClient client(
  "Your WLAN ID", // Your WLAN ID
  "Your WLAN Password", // Your WLAN Password
  "Your MQTT Server IP",  // MQTT Broker server ip
  "Your MQTT Username",            // Can be omitted if not needed - your MQTT User
  "Your MQTT Userpassword",        // Can be omitted if not needed - Your MQTT password
  "Your name of the AZ Envy Device",      // Client name that uniquely identify your device - will not automatically added
  1883               // The MQTT port, default to 1883. this line can be omitted
);

void onConnectionEstablished() 
{
#ifdef __DEBUG__
  Serial.println(("Con established"));
#endif
  client.publish("Environsensor/Alive", "True");
  //digitalWrite(LED_BUILTIN, LOW); // LED an wenn verbunden
  delay(10);
#ifdef __DEBUG__
  Serial.println(("Con established ... fini"));
#endif
}
SHT3x::CalibrationFactors TemperatureCalibration;
void setup() {
#ifdef __DEBUG__
  Serial.begin(19200);
#endif
  pinMode(LED_BUILTIN,OUTPUT);
  TemperatureCalibration.Factor = 1.;
  TemperatureCalibration.Shift = -6.0;
  SHTSensor.Begin();
  SHTSensor.SetTemperatureCalibrationFactors(TemperatureCalibration);
  mq2.begin();
  
#ifdef __DEBUG__
  Serial.println(("Setup..fini"));
#endif
}

void loop() {
#ifdef __DEBUG__
  Serial.println(("Loop start"));
#endif
  client.loop();
#ifdef __DEBUG__
  Serial.println(("Client loop - done"));
#endif
  SHTSensor.UpdateData();
  float SensTemp=SHTSensor.GetTemperature();
  float SensAbsHum=SHTSensor.GetAbsHumidity();
  float SensRelHum=SHTSensor.GetRelHumidity();
#ifdef __DEBUG__
  Serial.println("Values aquired");
#endif
  if (client.isConnected())
  {
    char str[10];
    dtostrf(SensTemp,-1,2,str);
    client.publish("Environsensor/Temperatur",str);
#ifdef __DEBUG__
    Serial.print("Temp:");
    Serial.println(str);
#endif    
    dtostrf(SensAbsHum,-1,2,str);
    client.publish("Environsensor/Absolute Feuchte",str);
#ifdef __DEBUG__
    Serial.print("Abs:");
    Serial.println(str);
#endif    
    dtostrf(SensRelHum,-1,2,str);
    client.publish("Environsensor/Rel_Feuchte",str);
#ifdef __DEBUG__
    Serial.print("Rel:");
    Serial.println(str);
#endif
    float lpg = mq2.readLPG();
    float co = mq2.readCO();
    float smoke = mq2.readSmoke();
    dtostrf(lpg,-1,3,str);
    client.publish("Environsensor/LPG",str);
#ifdef __DEBUG__
    Serial.print("LPG:");
    Serial.println(str);
#endif
    dtostrf(co,-1,3,str);
    client.publish("Environsensor/CO",str);
#ifdef __DEBUG__
    Serial.print("CO:");
    Serial.println(str);
#endif
    dtostrf(smoke,-1,3,str);
    client.publish("Environsensor/Rauch",str);
#ifdef __DEBUG__
    Serial.print("Rauch:");
    Serial.println(str);
#endif
  };
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
}