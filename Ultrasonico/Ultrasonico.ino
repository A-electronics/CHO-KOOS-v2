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

const int EchoPin = 7;
const int TriggerPin = 8;
int tiempo = 0;

void setup() {
  analogWrite(3, 0);
  analogWrite(5, 0);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  delay(200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();  //Borra el buffer
  display.display();       //Muestra la imagen
  delay(100);
}

void loop() {
  int cm = ping(TriggerPin, EchoPin);
  display.setTextSize(1);       //Establece el tamaño de fuente, admite tamaños de 1 a 8
  display.setTextColor(WHITE, BLACK);  //Establece el color
  display.setCursor(35, 10);    //Establecer las coordenadas para mostrar la posición del texto
  display.print("Distancia: ");
  display.println(cm);
  display.display();  //Muestra el texto
  delay(1000);
  if (cm > 30){
    display.clearDisplay();
    display.display();
    delay(50);
  }
}

int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);     //medimos el tiempo entre pulsos, en microsegundos
  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}
