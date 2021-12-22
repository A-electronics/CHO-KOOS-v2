int sensor4 = 0; //pines analogicos almacenados en una variable
int sensor3 = 1; //pines analogicos almacenados en una variable
int sensor2 = 2; //pines analogicos almacenados en una variable
int sensor1 = 3; //pines analogicos almacenados en una variable
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
}

void loop() {
  valorSensor1 = analogRead(sensor1);
  valorSensor2 = analogRead(sensor2);
  valorSensor3 = analogRead(sensor3);
  valorSensor4 = analogRead(sensor4);
//Mapeo de 
  valorSensor1 = map(valorSensor1, 0, 1023, 0, 255);
  valorSensor2 = map(valorSensor2, 0, 1023, 0, 255);
  valorSensor3 = map(valorSensor3, 0, 1023, 0, 255);
  valorSensor4 = map(valorSensor4, 0, 1023, 0, 255);

  Serial.print("Valor Sensor1 TCRT5000_1: ");
  Serial.println(valorSensor1);
  Serial.print("Valor Sensor2 TCRT5000_2: ");
  Serial.println(valorSensor2);
  Serial.print("Valor Sensor3 TCRT5000_3: ");
  Serial.println(valorSensor3);
  Serial.print("Valor Sensor4 TCRT5000_4: ");
  Serial.println(valorSensor4);
  Serial.println("");
  delay(1000);
}
