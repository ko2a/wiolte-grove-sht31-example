#include <WioLTEforArduino.h>
#include <SHT31.h>

WioLTE Wio;
SHT31 sht31 = SHT31();

void setup() {  
  delay(200);
  SerialUSB.println("### Initialize...");
  Wio.Init();
  SerialUSB.println("### Grove Power On...");
  Wio.PowerSupplyGrove(true);
  SerialUSB.println("### SHT31 begin sensing...");
  sht31.begin();
}

void loop() {
  float temp = sht31.getTemperature();
  float humi = sht31.getHumidity();
  SerialUSB.print("Temperature = "); 
  SerialUSB.print(temp);
  SerialUSB.println(" C");
  SerialUSB.print("Humidity = "); 
  SerialUSB.print(humi);
  SerialUSB.println("%"); 
  SerialUSB.println();
  delay(10000);
}

