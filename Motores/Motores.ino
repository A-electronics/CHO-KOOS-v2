int PWM1 = 3;
int INA = 4;
int PWM2 = 5;
int INC = 6;
int vel = 60;

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INC, OUTPUT);
  digitalWrite(PWM1, LOW); //Deshabilitar los motores
  digitalWrite(PWM2, LOW); //Deshabilitar los motores
}

void loop() {
  //Derecha
  analogWrite(PWM1, vel);
  digitalWrite(INA, HIGH);
  analogWrite(PWM2, vel);
  digitalWrite(INC, LOW);
  delay(2000);
  //Reversa
  analogWrite(PWM1, vel);
  digitalWrite(INA, LOW);
  analogWrite(PWM2, vel);
  digitalWrite(INC, LOW);
  delay(2000);
  //Parar
  analogWrite(PWM1, LOW);
  digitalWrite(INA, LOW);
  analogWrite(PWM2, LOW);
  digitalWrite(INC, LOW);
  delay(4000);
  //Recto
  analogWrite(PWM1, vel);
  digitalWrite(INA, HIGH);
  analogWrite(PWM2, vel);
  digitalWrite(INC, HIGH);
  delay(2000);
  //Izquierda
  analogWrite(PWM1, vel);
  digitalWrite(INA, LOW);
  analogWrite(PWM2, vel);
  digitalWrite(INC, HIGH);
  delay(2000);
}
