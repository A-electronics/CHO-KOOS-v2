/*Se importan las librerías*/
#include <Adafruit_GFX.h> //Liberia para gráficos
#include <Adafruit_SSD1306.h> //Liberia para Oleds monocromáticos basados ​​en controladores SSD1306
/*Se declara el pin de reset, este es requerido por el constructor de la librería SSD1306
 *para definir el tipo de OLED y la comunicación I2C en los (pines SDA, SCL)*/
#define OLED_RESET 13 
Adafruit_SSD1306 display(OLED_RESET);
/*Se define una condición para saber si en la librería esta definida la altura de 32 de lo contrario 
  no dejara compilar el código hasta que se cambie la altura correcta desde la librería*/
#if (SSD1306_LCDHEIGHT != 32)
#error("Altura incorrecta, cambie en la librería de Adafruit_SSD1306.h!");
#endif
#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(13,12); //12 RX, 13 TX.

int TCRT5000_4 = 0; //pines analogicos almacenados en una variable
int TCRT5000_3 = 1; //pines analogicos almacenados en una variable
int TCRT5000_2 = 2; //pines analogicos almacenados en una variable
int TCRT5000_1 = 3; //pines analogicos almacenados en una variable
int valorSensor4 = 0;
int valorSensor3 = 0;
int valorSensor2 = 0;
int valorSensor1 = 0;
int PWM1 = 3;
int INA = 4;
int PWM2 = 5; 
int INC = 6;
int vel = 245; // Velocidad de los motores (0-255)
const int EchoPin = 7;
const int TriggerPin = 8;
const int Buzzer = 9;
int tiempo = 0;
int estado = 48;  

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT); 
  pinMode(INA, OUTPUT);
  pinMode(INC, OUTPUT);
  //pinMode(TCRT5000_4, INPUT);
  pinMode(TCRT5000_3, INPUT);
  pinMode(TCRT5000_2, INPUT);
  //pinMode(TCRT5000_1, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // inicia la comunicacion I2C con el display que tiene la direccion 0x3C
  display.setRotation(0);  // se escoje la orientacion del display puede ser 0 o 2
  display.dim(true); //dejamos el brillo en maximo
  display.setTextColor(WHITE);
  display.setTextSize(1);  // ajusta el tamaño de texto en el minimo valor
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(Buzzer, OUTPUT);
  tone(9,247,200);
  delay(200);
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
}
 // funcion = tone(pin,frecuencia,duracion)
void loop() {
   int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
   valorSensor2 = analogRead(TCRT5000_2);
   valorSensor3 = analogRead(TCRT5000_3);
   delay(1000);
   display.clearDisplay(); //Borra el buffer
   display.drawRect(0,0,128,32,WHITE); //rectangulo (x,Y,ancho, alto)
   display.setTextSize(1); //Establece el tamaño de fuente, admite tamaños de 1 a 8
   display.setTextColor(WHITE); //Establece el color 
   display.setCursor(2,2); //Establecer las coordenadas para mostrar la posición del texto
   display.print("Distancia: ");
   display.print(cm);
   display.print(F("cm"));
   
   display.setCursor(2,18);
   display.print("S2: ");
   display.print(valorSensor2);
   display.print(F(" S3: "));
   display.print(valorSensor3);
   display.display(); //Muestra el texto
   
     if(BT.available())
  {
    //Serial.write(BT.read());
    estado = BT.read();
  }
 
  
  Serial.println(estado);
  delay(100);
  if(estado == 49){    //RECTO
    analogWrite(PWM1,vel);
    digitalWrite(INA,HIGH);
    digitalWrite(PWM2,HIGH);  
    digitalWrite(INC,LOW);

  }
    
  if(estado == 50){    //IZQUIERDA
  
    digitalWrite(PWM1,HIGH);
    digitalWrite(INA,LOW);
    digitalWrite(PWM2,HIGH);  
    digitalWrite(INC,LOW);

  }

  if(estado == 48){     //Parar
    digitalWrite(PWM1,LOW);
    digitalWrite(INA,LOW);
    digitalWrite(PWM2,LOW);  
    digitalWrite(INC,LOW);
  }
  
    
  if(estado == 51){    //DERECHA
  
    digitalWrite(PWM1,HIGH);
    digitalWrite(INA,HIGH);
    digitalWrite(PWM2,HIGH);  
    digitalWrite(INC,HIGH);
  }
  
  if(estado == 52){    //REVERSA
  
    digitalWrite(PWM1,HIGH);
    digitalWrite(INA,LOW);
    digitalWrite(PWM2,HIGH);  
    digitalWrite(INC,HIGH);
  }

}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
