/*Se importan las librerías*/
#include <Adafruit_GFX.h>      //Liberia para gráficos
#include <Adafruit_SSD1306.h>  //Liberia para Oleds monocromáticos basados ​​en controladores SSD1306
/*Se declara el pin de reset, este es requerido por el constructor de la librería SSD1306
 *para definir el tipo de OLED y la comunicación I2C en los (pines SDA, SCL)*/
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_RESET);
/*Se define una condición para saber si en la librería esta definida la altura de 32 de lo contrario 
 *no dejara compilar el código hasta que se cambie la altura correcta desde la librería*/
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif

#define PWM1 3
#define INA 4
#define PWM2 5
#define INC 6
#define boton 11


int a = 0;
int vel = 60;
int sensor4 = 0;  //pines analogicos almacenados en una variable
int sensor3 = 1;  //pines analogicos almacenados en una variable
int sensor2 = 2;  //pines analogicos almacenados en una variable
int sensor1 = 3;  //pines analogicos almacenados en una variable
int valorSensor4 = 0;
int valorSensor3 = 0;
int valorSensor2 = 0;
int valorSensor1 = 0;

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INC, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  analogWrite(PWM1, 0);  //Deshabilitar los motores
  analogWrite(PWM2, 0);  //Deshabilitar los motores
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();  //Borra el buffer
  display.display();       //Muestra la imagen
  delay(100);
}

void loop() {

  if (digitalRead(boton) == LOW) {
    a = a + 1;
  }


  while (a == 1) {
    //Mapeo de Sensores
    valorSensor1 = map(analogRead(sensor1), 0, 1023, 0, 255);
    valorSensor2 = map(analogRead(sensor2), 0, 1023, 0, 255);
    valorSensor3 = map(analogRead(sensor3), 0, 1023, 0, 255);
    valorSensor4 = map(analogRead(sensor4), 0, 1023, 0, 255);

    //Recto
    analogWrite(PWM1, vel);
    digitalWrite(INA, HIGH);
    analogWrite(PWM2, vel);
    digitalWrite(INC, LOW);

    if (valorSensor4 >= 12 && valorSensor4 <= 255) {
      //Derecha
      analogWrite(PWM1, vel);
      digitalWrite(INA, HIGH);
      analogWrite(PWM2, vel);
      digitalWrite(INC, HIGH);
    }

    if (valorSensor1 < 8 && valorSensor2 < 8 && valorSensor3 < 8 && valorSensor4 < 8) {
      while (valorSensor2 < 9) {
        //Derecha
        analogWrite(PWM1, vel);
        digitalWrite(INA, LOW);
        analogWrite(PWM2, vel);
        digitalWrite(INC, LOW);
        valorSensor2 = map(analogRead(sensor2), 0, 1023, 0, 255);
      }
    }
  }
}
