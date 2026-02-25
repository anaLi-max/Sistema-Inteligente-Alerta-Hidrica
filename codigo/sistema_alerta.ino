/// =======================================================
// Sistema Inteligente de Alerta Temprana de Estrés Hídrico
// Proyecto Integrador - Sistema Embebido
// =======================================================

const int sensorHumedad = A0;   // Pin del sensor de humedad
const int buzzer = 8;           // Pin del buzzer
const int ledAlerta = 7;        // LED indicador

int valorHumedad = 0;
int umbralSeco = 500;           // Ajustable según calibración

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(ledAlerta, OUTPUT);
  Serial.println("Sistema de Monitoreo Hidrico Iniciado...");
}

void loop() {
  valorHumedad = analogRead(sensorHumedad);

  Serial.print("Nivel de humedad: ");
  Serial.println(valorHumedad);

  if (valorHumedad > umbralSeco) {
    Serial.println("ALERTA: Posible estres hidrico detectado");
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledAlerta, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledAlerta, LOW);
  }

  delay(2000);
}/ Código inicial del Sistema Inteligente de Alerta Hídrica
