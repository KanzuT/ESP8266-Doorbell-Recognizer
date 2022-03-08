#include <ESP8266WiFi.h>

const char *ssid = "ssid";
const char *pass = "pw";

// Deklaration und Initialisierung der Eingang-Pins
int Analog_Eingang = A0; // Analoger Ausgang des Sensors
int Digital_Eingang = D3; // Digitaler Ausgang des Sensors
  
void setup ()
{
    
  pinMode (Analog_Eingang, INPUT);
  pinMode (Digital_Eingang, INPUT);
  
  Serial.begin(115200);

  
  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");

}
  
// Das Programm liest die aktuellen Werte der Eingang-Pins
// und gibt diese auf der seriellen Ausgabe aus
void loop ()
{
  float Analog;
  int Digital;
    
  //Aktuelle Werte werden ausgelesen, auf den Spannungswert konvertiert...
  Analog = analogRead (Analog_Eingang) * (3.3f / 1023.0f); 
  Digital = digitalRead (Digital_Eingang);
  Serial.println("DIGITALER WERT: " + (String)Digital);
    
  //... und an dieser Stelle ausgegeben
  Serial.print ("Analoger Spannungswert:"); Serial.print (Analog, 4);  Serial.print ("V, ");
  //Serial.print ("Grenzwert:");
  
  if(Digital==1)
  {
      Serial.println (" erreicht");
  }
  else
  {
      //Serial.println (" noch nicht erreicht");
  }
  Serial.println ("----------------------------------------------------------------");
  delay (1);
}
