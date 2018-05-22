#include <LiquidCrystal.h>
#include <math.h>

double Thermister(int RawADC) {
  double Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15; // Convert Kelvin to Celcius
  return Temp;
}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
/******** Variables ******************************************/
  int luz    = analogRead(A2);
  int sonido = analogRead(A0);
  int temp   = Thermister(analogRead(A1));


/****** Muestreo por pantalla ********************************/
  Serial.print(luz);Serial.print(";");
  Serial.print(sonido);Serial.print(";");
  Serial.print(temp);Serial.println(";");
  //Serial.println("*******************");
  delay(1000);        // delay in between reads for stability
}


