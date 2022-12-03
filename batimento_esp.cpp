#include <EspMQTTClient.h>



EspMQTTClient client(
  "Desktop_F0927349",           // SSID WiFi
  "chapecoense",                // Password WiFi
  "broker.hivemq.com",          // MQTT Broker
  "macsuel",                    // Client
  1883                          // MQTT port
);

int bpm;


void setup() {
  Serial.begin(9600);


  client.enableDebuggingMessages(); 
  client.enableHTTPWebUpdater();
  client.enableOTA();
  client.enableLastWillMessage("TestClient/lastwill", "Vou ficar offline"); 
}


void lerEnviarDados() {
    client.publish("mackenziemac10920508603/batimento", String(bpm) + " bpm");
}


void onConnectionEstablished() {
    client.subscribe("mackenziemac10920508603/msgRecebida/#", [](const String & topic, const String & payload) {
    Serial.println("Mensagem recebida no topic: " + topic + ", payload: " + payload);
  });
  lerEnviarDados();
}

void loop() {
    boolean StringReady = false;

    while(Serial.available()) {
        bpm = Serial.read();
        StringReady = true;
    }

    if (StringReady) {
        client.loop();
        lerEnviarDados();
        delay(5000);
        
    }

}
