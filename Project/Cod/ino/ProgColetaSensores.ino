
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
/* 
   MQ-4 - GÁS METANO 
   MQ-136 - GÁS Sulfidrico H2S
*/
 int analog_MQ4 = A2;
 int analog_MQ136 = A5;
 int analog_PH = A3;
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5,4, 3, 2);

// O fio de dados é conectado no pino digital 2 no Arduino
#define ONE_WIRE_BUS 7
// Prepara uma instância oneWire para comunicar com qualquer outro dispositivo oneWire
OneWire oneWire(ONE_WIRE_BUS);  
// Passa uma referência oneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

void setup(void)
{
   lcd.begin(16, 2);
   pinMode(analog_MQ4, INPUT);
   pinMode(analog_MQ136, INPUT); 
   sensors.begin();  // Inicia a biblioteca
   Serial.begin(9600);
}

void loop(void)
{ 
   lcd.setCursor(2, 0);
   lcd.print("OFICINAS 4.0");
   delay(3000);
   lcd.clear();
   
   int gas_HS2;
   gas_HS2=analogRead(analog_MQ136);
  // Escreve Gas sulfidrico em display
   lcd.setCursor(2, 0);
   lcd.print("GAS HS2:"); 
   lcd.print(gas_HS2);
   delay(5000);
   lcd.clear();

  sensors.requestTemperatures(); 
  // Escreve a temperatura em Celsius
    lcd.setCursor(2, 0);
    lcd.print("Temperatura:");
    lcd.setCursor(2, 1);
    lcd.print(sensors.getTempCByIndex(0));
    lcd.print(" graus");
    delay(5000);
    lcd.clear();
    
  // Escreve Gas Metano no display 
    int gas_MQ4 = analogRead(analog_MQ4);
    lcd.setCursor(2, 0);
    lcd.print("GAS CH4: ");
    lcd.print(gas_MQ4);
    delay(5000);
    lcd.clear();
}
