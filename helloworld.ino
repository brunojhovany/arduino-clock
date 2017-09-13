#include <TimeLib.h>

void setup() {
  pinMode(2,OUTPUT); //Declaración de los puertos de los Dip display
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  pinMode(10, OUTPUT); //Controladores Mutiplexacón Catodo común
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(10, HIGH); //se apagan todos los dips de inicio
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);

  setTime(23,37,00,12,8,2017); //Configuración de la hora con la libreria TimeLib.h de arduino

  Serial.begin(9600); //Configuración del puerto Serial.
}

class Clock{
private:
  int H1,H2,M1,M2;

  void display(int numero){ //Función privada que recibe un numero para poder dibujarlo en el Dip
    byte  Digit[11][7] = {
        { 1,1,1,1,1,1,0 },    // 0
        { 0,1,1,0,0,0,0 },    // 1
        { 1,1,0,1,1,0,1 },    // 2
        { 1,1,1,1,0,0,1 },    // 3
        { 0,1,1,0,0,1,1 },    // 4
        { 1,0,1,1,0,1,1 },    // 5
        { 1,0,1,1,1,1,1 },    // 6
        { 1,1,1,0,0,0,0 },    // 7
        { 1,1,1,1,1,1,1 },    // 8
        { 1,1,1,0,0,1,1 },    // 9
        { 0,0,0,0,0,0,0 }     //null
      };

  digitalWrite (2,Digit[numero][0]);
  digitalWrite (3,Digit[numero][1]);
  digitalWrite (4,Digit[numero][2]);
  digitalWrite (5,Digit[numero][3]);
  digitalWrite (6,Digit[numero][4]);
  digitalWrite (7,Digit[numero][5]);
  digitalWrite (8,Digit[numero][6]);
    return 0;
}

public:
 void hora(int h1, int h2, int m1, int m2){ //Función publica que recibe los parmetros de hora y minutos separados por digitos.
    H1 = h1; H2 = h2; M1 = m1; M2=m2;
    display(H1);
    digitalWrite(10, LOW);
    delay(5);
    digitalWrite(10, HIGH);
    display(H2);
    digitalWrite(11, LOW);
    delay(5);
    digitalWrite(11,HIGH);
    display(M1);
    digitalWrite(12,LOW);
    delay(5);
    digitalWrite(12,HIGH);
    display(M2);
    digitalWrite(13,LOW);
    delay(5);
    digitalWrite(13,HIGH);
  }
};


Clock c1; //se instancia la clase con Clock con c1
void loop() {
  time_t t = now(); //se instancia la libreria TimeLib.h, esto tiene que hacer una consulta constante.
  c1.hora(hourFormat12(t) / 10, hourFormat12(t) % 10, minute(t) / 10, minute(t) % 10); //pase de parametros la función hora de la clase Clock.
}
