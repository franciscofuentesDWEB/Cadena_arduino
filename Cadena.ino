#include <LiquidCrystal.h>
#include <math.h>
#include <time.h>
/*************************************************************/
// Código  que monitorea tres sensores, muetra fecha y hora: //
//  1.- Photoresistor                                        //
//  2.- Thermoresistor                                       //
//  3.- Sensor de Temp Digital                               //
//  Cadena: {fecha,hora,sound,luz,temp,LED1}                 //
/*************************************************************/
/*
FUNCION PARA OBTENER LA FECHA EN MODO TEXTO
Devuelve: DD-MM-AAAA HH:MM:SS
*/

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

double Thermister(int RawADC) {
  double Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15; // Convert Kelvin to Celcius
  return Temp;
}

// the setup routine runs once when you press reset:
void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int luz    = analogRead(A2);
  int sonido = analogRead(A0);
  int temp   = Thermister(analogRead(A1));

/*********** MUESTREO por LCD *******************************/
  // Cursor en la primera posición de la primera fila
  lcd.setCursor(0,0);
  lcd.print("sond");
  lcd.setCursor(0,1);
  lcd.print(sonido);

  lcd.setCursor(6,0);
  lcd.print("temp");  
  lcd.setCursor(7,5);
  lcd.print(temp);

  lcd.setCursor(13,0);
  lcd.print("luz");
  lcd.setCursor(13,1);
  lcd.print(luz);
  
/******* Muestreo de cadena *********************************/
  Serial.print("DD-MM-YY");Serial.print(";");
  Serial.print("Hra:min:seg");Serial.print(";");
  Serial.print(luz);Serial.print(";");
  Serial.print(sonido);Serial.print(";");
  Serial.print(temp);Serial.println(";");
  //Serial.println("*******************");
  delay(1000);        // delay in between reads for stability
}


