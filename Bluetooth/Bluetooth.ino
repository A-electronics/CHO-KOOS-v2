#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
 
//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(13,12); //12 RX, 13 TX.
int estado = 48;
int PWM1 = 3;
int INA = 4;
int PWM2 = 5; 
int INC = 6;
int vel = 245;

void setup() {
  BT.begin(9600);
}

void loop() {
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
