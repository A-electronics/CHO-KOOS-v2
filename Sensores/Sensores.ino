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


int sensor4 = 0;  //pines analogicos almacenados en una variable
int sensor3 = 1;  //pines analogicos almacenados en una variable
int sensor2 = 2;  //pines analogicos almacenados en una variable
int sensor1 = 3;  //pines analogicos almacenados en una variable
int valorSensor4 = 0;
int valorSensor3 = 0;
int valorSensor2 = 0;
int valorSensor1 = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  delay(10);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  Serial.begin(9600);
  analogWrite(3, 0);
  analogWrite(5, 0);
  /* Se inicia la comunicación I2C en la direcion 0x3C para la pantalla oled 128x32*/
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();  //Borra el buffer
  display.display();       //Muestra la imagen
  delay(100);
}

void loop() {
  valorSensor1 = analogRead(sensor1);
  valorSensor2 = analogRead(sensor2);
  valorSensor3 = analogRead(sensor3);
  valorSensor4 = analogRead(sensor4);
  //Mapeo de Sensores
  valorSensor1 = map(valorSensor1, 0, 1023, 0, 255);
  valorSensor2 = map(valorSensor2, 0, 1023, 0, 255);
  valorSensor3 = map(valorSensor3, 0, 1023, 0, 255);
  valorSensor4 = map(valorSensor4, 0, 1023, 0, 255);


  display.setTextSize(1);       //Establece el tamaño de fuente, admite tamaños de 1 a 8
  display.setTextColor(WHITE,BLACK);  //Establece el color
  display.setCursor(0, 0);      //Establecer las coordenadas para mostrar la posición del texto
  display.print("Sens1= ");
  display.println(valorSensor1);

  display.setTextSize(1);       //Establece el tamaño de fuente, admite tamaños de 1 a 8
  display.setTextColor(WHITE,BLACK);  //Establece el color
  display.setCursor(0, 10);     //Establecer las coordenadas para mostrar la posición del texto
  display.print("Sens2= ");
  display.println(valorSensor2);

  display.setTextSize(1);       //Establece el tamaño de fuente, admite tamaños de 1 a 8
  display.setTextColor(WHITE,BLACK);  //Establece el color
  display.setCursor(0, 20);     //Establecer las coordenadas para mostrar la posición del texto
  display.print("Sens3= ");
  display.println(valorSensor3);

  display.setTextSize(1);       //Establece el tamaño de fuente, admite tamaños de 1 a 8
  display.setTextColor(WHITE,BLACK);  //Establece el color
  display.setCursor(65, 0);     //Establecer las coordenadas para mostrar la posición del texto
  display.print("Sens4= ");
  display.println(valorSensor4);
  display.display();  //Muestra el texto
  delay(1000);
  
  if (valorSensor1 >= 10 || valorSensor2 >= 10 || valorSensor3 >= 10 || valorSensor4 >= 10){
    display.clearDisplay();
    display.display();
    delay(100);
  }
}
