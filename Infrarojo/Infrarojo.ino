#include <IRremote.h>    // importa libreria IRremote
int PWM1 = 3;
int INA = 4;
int PWM2 = 5;
int INC = 6;
int SENSOR = 2;    // sensor KY-022 a pin digital 11
IRrecv irrecv(SENSOR);    // establece al 11 para objeto irrecv
decode_results codigo;    // crea objeto codigo de la clase decode_results

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INC, OUTPUT);
  Serial.begin(9600);     // inicializa comunicacion serie a 9600 bps
  irrecv.enableIRIn();    // inicializa recepcion de datos
}

void loop() {
  digitalWrite(PWM1, LOW);
  digitalWrite(INA, LOW);
  digitalWrite(PWM2, LOW);
  digitalWrite(INC, LOW);
  if (irrecv.decode(&codigo)) {   // si existen datos ya decodificados
    Serial.println(codigo.value, HEX);  // imprime valor en hexadecimal en monitor
    irrecv.resume();      // resume la adquisicion de datos
  }
  delay (100);        // breve demora de 100 ms.
}
