#define USE_ARDUINO_INTERRUPTS true
#include <LiquidCrystal_I2C.h>
#include <PulseSensorPlayground.h>


LiquidCrystal_I2C lcd(0x27,16,2);
const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550;
PulseSensorPlayground pulseSensor; // Cria uma instância do objeto PulseSensorPlayground chamado "pulseSensor"

void setup() {
  Serial.begin(9600); // Para monitor serial
  lcd.init();
  lcd.setBacklight(HIGH);
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13); //piscar automaticamente o LED Arduino com batimento cardíaco.
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    Serial.println("Nós criamos um objeto pulseSensor !");
    lcd.setCursor(0,0);
    lcd.print(" Monitor de frequência cardíaca");
  }
}
void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();

  if (pulseSensor.sawStartOfBeat()) {
    Serial.println("♥ Aconteceu um batimento cardíaco ! ");
    Serial.print("BPM: ");
    Serial.println(myBPM);
    lcd.setCursor(0,2);
    lcd.print("HeartBeat Happened !");
    lcd.setCursor(5,3);
    lcd.print("BPM: ");
    lcd.print(myBPM);
    Serial.write(myBPM);
  }

  delay(20);
}