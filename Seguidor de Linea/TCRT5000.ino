int TCRT5000-4 = 0; //pines analogicos almacenados en una variable
int TCRT5000-3 = 1; //pines analogicos almacenados en una variable
int TCRT5000-2 = 2; //pines analogicos almacenados en una variable
int TCRT5000-1 = 3; //pines analogicos almacenados en una variable
int valorSensor4 = 0;
int valorSensor3 = 0;
int valorSensor2 = 0;
int valorSensor1 = 0;
const int Buzzer = 9;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  delay(10);
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,LOW);
  //pinMode(sensor4, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor2, INPUT);
  //pinMode(sensor1, INPUT);
  Serial.begin(9600);
}

void loop() {
  //valorSensor1 = analogRead(TCRT5000-1);
  valorSensor2 = analogRead(TCRT5000-2);
  valorSensor3 = analogRead(TCRT5000-3);
  //valorSensor4 = analogRead(TCRT5000-4);
  Serial.print("Valor Sensor1 TCRT5000_1: ");
  Serial.println(valorSensor1);
  Serial.print("Valor Sensor2 TCRT5000_2: ");
  Serial.println(valorSensor2);
  Serial.print("Valor Sensor3 TCRT5000_3: ");
  Serial.println(valorSensor3);
  Serial.print("Valor Sensor4 TCRT5000_4: ");
  Serial.println(valorSensor4);
  delay(1000);
  if (valorSensor2&&valorSensor3<=300){
  Serial.println("Bien");
  }
  else{
  Serial.println("Mal");
  }
}
