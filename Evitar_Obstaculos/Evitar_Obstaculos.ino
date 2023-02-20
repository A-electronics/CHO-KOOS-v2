const int EchoPin = 7;
const int TriggerPin = 8;
int tiempo = 0;
int PWM1 = 3;
int INA = 4;
int PWM2 = 5;
int INC = 6;
int vel = 80;

void setup() {
  Serial.begin(9600);
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INC, OUTPUT);
  digitalWrite(PWM1, LOW); //Deshabilitar los motores
  digitalWrite(PWM2, LOW); //Deshabilitar los motores
  delay(200);
}


void loop() {  
  int cm = ping(TriggerPin, EchoPin);
  if (cm >= 0 && cm <= 6) {
    //Reversa
    analogWrite(PWM1, vel);
    digitalWrite(INA, LOW);
    analogWrite(PWM2, vel);
    digitalWrite(INC, HIGH);
    delay(300);
    //Derecha
    analogWrite(PWM1, vel);
    digitalWrite(INA, LOW);
    analogWrite(PWM2, vel);
    digitalWrite(INC, LOW);
    delay(300);
  }
  analogWrite(PWM1, vel);
  digitalWrite(INA, HIGH);
  analogWrite(PWM2, vel);
  digitalWrite(INC, LOW);
}

int ping(int TriggerPin, int EchoPin) {
  long duration, distanceCm;
  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}
