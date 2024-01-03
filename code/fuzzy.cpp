////---------DEKLARASI VAR & FUNGSI 
///==========wifi  =========

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

const char* ssid = "Unknown";
const char* password = "handsome";

const char* server = "api.thingspeak.com";
const String apiKey = "H8BIHU4D8VC9VSRW"; // Ganti dengan API Key Thingspeak Anda
const String channelID = "2298952"; // Ganti dengan Channel ID Thingspeak Anda

///////ini pin pin lah gue agak bingung tapi gas aja ini udh malem :)
const int SensorMQ2_A = 34; // Pin analog untuk sensor MQ-2  A     
const int SensorMQ2_B = 39; // Pin analog untuk sensor MQ B gue g tau pin brp anggap aj
const int pirSensorPin = 12;  // Pin sensor PIR
const int LED1 = 13;       // Pin LED built-in pada Arduino
const int Buzzer = 14;
const int Pressure = 36; /// pin sensor pressure gue g tau dimana
int Valve = 5;  

/////----------input & outut
int Mq1Value;     
int Mq2Value;    
int pirValue;  ///mau di apus dulu soalny gtau kodingan nnti ditambah 
int pressValue;
int valveValue; ///ini apa?solenoid ? maybe ini diganti float bukan int 

int ledOutputValue = 0.0;
int buzzerOutputValue = 0.0;
int valveOutputValue = 0.0;

//// FUZZY SET FOR VAR 
#include <Fuzzy.h>
Fuzzy *fuzzy = new Fuzzy();
////////===========================================

// Fuzzy input MQ2 A nih
FuzzySet *normal_mqA                    = new FuzzySet(0, 400, 400, 1000);
FuzzySet *bocor_sedangA                 = new FuzzySet(1000, 1100, 1100, 1200);
FuzzySet *banyak_mqA                    = new FuzzySet(1200, 1500, 1500, 3000);

// Fuzzy input  MQ B nih
FuzzySet *normal_mqB                    = new FuzzySet(0, 400, 400, 1000);
FuzzySet *bocor_sedangB                 = new FuzzySet(1000, 1100, 1100, 1200);
FuzzySet *banyak_mqB                    = new FuzzySet(1200, 1500, 1500, 3000);

// Fuzzy input Pressure nih -> belum set pasti
FuzzySet *Rendah                        = new FuzzySet(0, 0, 800, 1600);
FuzzySet *Sedang                        = new FuzzySet(800, 1600, 2400, 3200);
FuzzySet *Tinggi                        = new FuzzySet(2400, 3200, 4000, 4000);

 ///Fuzzy Output LED nih 
FuzzySet *Off                           = new FuzzySet(0, 0, 0, 0);
FuzzySet *On                            = new FuzzySet(1, 1, 1, 1);

///Fuzzy Output Buzzer nih 
FuzzySet *mati                          = new FuzzySet(0, 0, 0, 0);
FuzzySet *nyala                         = new FuzzySet(1, 1, 1, 1);

///Fuzzy Output Valve nih 
FuzzySet *Closed                        = new FuzzySet(1, 1, 1, 1);
FuzzySet *Open                          = new FuzzySet(0, 0, 0, 0);



//-----------Panggil Tab Lain ---------------
#include "fuzzySet.h"
#include "fuzzyRule.h"


unsigned long lastMovementTime = 0;

const unsigned long waitTime = 1 * 60 * 1000;   // Waktu tunggu sebelum mengaktifkan LED (1 menit dalam milidetik)
unsigned long elapsedTime;

//----------------------------------------------
//               VOID SETUP 
//----------------------------------------------
WiFiMulti wifiMulti;
void setup() {

  Serial.begin(115200);

  //----------- set pinmode----------------

  pinMode(SensorMQ2_A, INPUT);
  pinMode(pirSensorPin, INPUT);
  pinMode(SensorMQ2_B, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Valve, OUTPUT);
  digitalWrite(LED1, LOW);

  // Koneksi WiFi
  wifiMulti.addAP(ssid, password);

  Serial.print("Connecting to WiFi");
  while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to WiFi");
  
  fuzzyset ();
  fuzzyrule();
}
                                                                
////--------------------------------------------------
//       VOID LOOP 
//---------------------------------------------------
void loop () {
  Mq1Value = analogRead(SensorMQ2_A); 
  Mq2Value = analogRead(SensorMQ2_B);
  pressValue = analogRead(Pressure);
  elapsedTime   = millis() - lastMovementTime;
  pirValue      = digitalRead(pirSensorPin);
  
  //pengiriman data thingspeak
  if (wifiMulti.run() == WL_CONNECTED) {
    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=" + apiKey + "&field1=" + String(Mq1Value) + "&field2=" + String(Mq2Value) + "&field3=" + String (pressValue);
    Serial.print("Sending data to Thingspeak: ");
    Serial.println(url);

    http.begin(url);
    int httpCode = http.GET();

  if (httpCode > 0) {
      Serial.print("HTTP Response Code: ");
      Serial.println(httpCode);
    } else {
      Serial.println("Failed to connect to Thingspeak");
    }

    http.end();
  }

  Serial.print("Sensor Value 1: ");
  Serial.println(Mq1Value);
  Serial.print("Sensor Value 2: ");
  Serial.println(Mq2Value);
  Serial.print("Pressure Value : ");
  Serial.println(pressValue);
  
  fuzzy->setInput(1, Mq1Value);
  fuzzy->setInput(2, Mq2Value);
  fuzzy->setInput(3, pressValue);
  fuzzy->fuzzify();
  ledOutputValue = fuzzy->defuzzify(1); //// kalau error hapus cog atau ganti angkanya(harusny g mslh)
  buzzerOutputValue = fuzzy->defuzzify(2);  /// atau cnth float ledOutputValue = defuzzifyCOG(ledOutput);
  valveOutputValue = fuzzy->defuzzify(3);


  // Kendalikan output berdasarkan nilai defuzzified
  //controlOutputs(ledOutputValue, buzzerOutputValue, valveOutputValue);

  // Tampilkan hasil di Serial Monitor
  Serial.print("LED Output: ");
  Serial.println(ledOutputValue);
  Serial.print("Buzzer Output: ");
  Serial.println(buzzerOutputValue);
  Serial.print("Valve Output: ");
  Serial.println(valveOutputValue);

  digitalWrite(LED1,ledOutputValue );
  digitalWrite(Buzzer, buzzerOutputValue);
  digitalWrite(Valve, valveOutputValue);

  //program sensor PIR
  if (pirValue == HIGH) {
    lastMovementTime = millis(); // Perbarui waktu terakhir mendeteksi gerakan
  }

  // Periksa apakah sudah 10 detik tanpa mendeteksi gerakan
  if (elapsedTime >= waitTime) {
    // Jika sudah 10 detik tanpa gerakan, hidupkan LED
    digitalWrite(LED1, HIGH);
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Valve, HIGH);
  }
  Serial.print("Sensor PIR: ");
  Serial.println(pirValue);
  Serial.print("Waktu tanpa pergerakan: ");
  Serial.println(elapsedTime);

  delay(5000);
 
}