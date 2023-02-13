int PWM1 = 3;
int PWM2 = 5;
int pinBuzzer = 9;
int Do = 261;
int Re = 293;
int Mi = 329;
int Fa = 349;
int Sol = 392;
int La = 440;
int Si = 493;
int duracion = 100;
int retardo = 200;

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  digitalWrite(PWM1, LOW); //Deshabilitar los motores
  digitalWrite(PWM2, LOW); //Deshabilitar los motores
}

void loop() {
  tone(pinBuzzer, Do, duracion);
  delay(retardo);
  tone(pinBuzzer, Re, duracion);
  delay(retardo);
  tone(pinBuzzer, Mi, duracion);
  delay(retardo);
  tone(pinBuzzer, Fa, duracion);
  delay(retardo);
  tone(pinBuzzer, Sol, duracion);
  delay(retardo);
  tone(pinBuzzer, La, duracion);
  delay(retardo);
  tone(pinBuzzer, Si, duracion);
  delay(retardo);
}
