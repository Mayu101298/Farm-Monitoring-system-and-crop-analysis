/* 
-----------------------------------------------------------------------------------
// Description
// -----------------------------------------------------------------------------------
// This sketch is in the public domain
// Written by : Third Year First shift 
// Mayuri Sangle, Gauri Kadam, Pradnya Padmukh &Shubdha Desai...
// -----------------------------------------------------------------------------------
// Connections:
// -----------------------------------------------------------------------------------
// DHT11 Humidity Sensor

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever the DHTPIN is // here Digital Pin 8 
// Connect pin 4 (on the right) of the sensor to GROUND
// -----------------------------------------------------------------------------------
// LM35 

// We are using the TO-92 Package device 
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 to an Analg Pin on the Arduino. Here Pin A0
// Connect pin 3 (on the right) of the sensor to GROUND
// -----------------------------------------------------------------------------------
// Soil & Rain Sensor

// Connect Vcc to 5V and Gnd to Gnd
// Connect AOUT Pin of Soil Sensor to A1, A2 & A3
// Connect Signal Pin of Rain Sensor to A4 
// ----------------------------------------------------------------------------------- 
//LCD Screen

 The circuit:
 * LCD RS pin to digital pin 2
 * LCD Enable pin to digital pin 3
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

// ------------------------------------------------------------------------------------
// The Code
// ------------------------------------------------------------------------------------

#include "DHT.h"            // Include DHT Library
#include<VirtualWire.h>     // Inclusion of Virtual Wire
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Humidity Sensor DHT11
#define DHTTYPE DHT11   // Declaration of DHT 11 being used
#define DHTPIN 8        // DTH11 Data Pin connected to Digital Pin 8 of Arduino 
DHT dht(DHTPIN, DHTTYPE);
int Humidity_1; 

// Rain
int Rain_Pin = A4;
int Rain_Value=0;

// Soil Sensor
int Soil_Pin[3] = {A1,A2,A3}; // Connect pin A0 to Analog Output pin of the Soil Sensor
int Soil_Read[3]={0,0,0};
int Moisture_Level[3]={0,0,0};
int avgMoisture = 0;

// Temperature Sensor LM35 
int Temp_Pin = A0;
float Temp_Value;
float mV;
int Temp_C;
// float Temp_F;

void setup(){
  for(int i=0; i <3; i++)
    pinMode(Soil_Pin[i], INPUT); // three Soil_Pins configured  as INPUT
    pinMode( Temp_Pin, INPUT); // Temp_Pin configured as INPUT
    pinMode(Rain_Pin,INPUT); // Rain_Pin configured as INPUT 
  
    Serial.begin(9600); // Initializing Serial Communication @ 9600 baud rate
    vw_setup(2000); // Bits per sec // Initialize the IO and ISR
    dht.begin();
    lcd.begin(16, 2); // set up the LCD's number of columns and rows:
    lcd.print("Welcome");
    delay(300);
    lcd.clear();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(200);

// Soil Moisture Analysis---------------------------------------------------------------------
  avgMoisture=0;
  for(int i=0;i<3; i++){
  Soil_Read[i] = analogRead(Soil_Pin[i]);
  Moisture_Level[i] = map(Soil_Read[i], 0, 1023, 100,0);
  avgMoisture+=Moisture_Level[i];
  }
  avgMoisture/=3; 
// -------------------------------------------------------------------------------------------

// Temperature Analysis-----------------------------------------------------------------------
  Temp_Value = analogRead(Temp_Pin);
  mV = (Temp_Value/1023.00)*5000;
  Temp_C = mV/10; // for temperature in *C
  // float Temp_F = (Temp_C*9)/5 +32; // for temp in *F
// -------------------------------------------------------------------------------------------

// Humidity Analysis--------------------------------------------------------------------------  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  Humidity_1 = dht.readHumidity();
  // Check if any reads failed and exit early (to try again).
  if (isnan(Humidity_1)) {
  //  Serial.println("Failed to read from DHT sensor!");
    Humidity_1=30;
  }
// -------------------------------------------------------------------------------------------

// Humidity Analysis--------------------------------------------------------------------------  
  Rain_Value = analogRead(Rain_Pin);
  if(Rain_Value>300)
  { 
    lcd.setCursor(0,0);
    lcd.print("RAINING");
    delay(1000);
    lcd.clear(); 
  } 
// -------------------------------------------------------------------------------------------

  LCDprint();  
  SerialPrintAll(); //Function to print values on the serial monitor

  String str1 = String(Temp_C);
  String str2 = String(Humidity_1);
  String str3 = String(avgMoisture);
  String str4 = ",";
  String toSend = str1+str4+str2+str4+str3;
  //Serial.println(toSend);
  int str_len = toSend.length() + 1;  // Length (with one extra character for the null terminator)
  char char_array[str_len];// Prepare the character array (the buffer)  
  toSend.toCharArray(char_array, str_len); // Copy it over 
Serial.println(char_array);
send(char_array);

}

// ---------------------------------------------------------------------------------
// Functions Declaration:
// ---------------------------------------------------------------------------------  

// ---------------------------------------------------------------------------------
// RF transmitter
// ---------------------------------------------------------------------------------
void send (char *message)
{
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx(); // Wait until the whole message has gone
}
// ---------------------------------------------------------------------------------
// End of Code
// ---------------------------------------------------------------------------------
void LCDprint(){
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.setCursor(2,0);
  lcd.print(Temp_C);
  lcd.print(" C");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("H:");
  lcd.setCursor(2,0);
  lcd.print(Humidity_1);
  lcd.print("%");
  delay(1000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("M:");
  lcd.setCursor(2,0);
  lcd.print(avgMoisture);
  lcd.print("%");
  delay(1000);
  lcd.clear();
}

void SerialPrintAll(){
  //
  Serial.print("Temperature: ");
  Serial.print(Temp_C);
  Serial.println(" *C");
//
  Serial.print("Humidity: ");
  Serial.print(Humidity_1);
  Serial.println(" %");
  //
  Serial.print("Avg Moisture : ");
  Serial.print(avgMoisture);
  Serial.println(" %"); 
  //
  Serial.print("Rain Sensor : ");
  Serial.println(Rain_Value);
}
