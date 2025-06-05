

//bibliotecas
#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHT11);//inicializa o obejeto DHT com o pino e o tipo 

//variaveis globais são funçoes acenderLEDDetectarPresença
const int PIR = 2;        //Pino Digital que o PIR está plugado
const int ledVerde = 13;  //Led onde está plugado no arduíno
//
const int MQ135 = A0;  //Pino analógico do mq-135
const int buzzer = 11; //Pino digital do buzzer

void detectorLED() {
  int estadoPIR = digitalRead(PIR);  //Lê o pino Digital 2

  //HIGH - Vale o valor de 1
  //LOW - vale o valor de 0

  if (estadoPIR == HIGH) {
    digitalWrite(ledVerde, HIGH);  //Fala ao programa para pino 13 "ACENDER"
    Serial.println("LUZ acesa!");
  } else {
    digitalWrite(ledVerde, LOW);  //Fala ao programa para pino 13 "APAGAR"
    Serial.println("LUZ apagada!");
  }
}

void vazamentoGas() {
  int estadoMQ135 = analogRead(MQ135);

  //if - verificar a intensidade do valor do estadoMQ135 >= 600
  //sim - ativar o alarme
  //não - 0
  if(estadoMQ135 >= 400){
    alarme2tons();
  } else {
    noTone(buzzer);
  }
  Serial.println(estadoMQ135);
  delay(1000);
}

void alarme2tons(){
  int freqAlta = 2000;
  int freqBaixa = 800;
  int duracaoTom = 450;

  tone(buzzer, freqAlta, duracaoTom);
  delay(duracaoTom);
  tone(buzzer, freqBaixa, duracaoTom);
  delay(duracaoTom);
}

void verificarTemperaturaEUmidade (){
  float umidade = dht.readHumidity(); 
  float temperature = dht.readTemperature(); // lê a temperatura em celsius

  Serial.println("Umidade" + String(umidade) + "%");
  Serial.println("Temperatura" + String(temperature) + "C");
  delay(7000);
}



void setup() {
  Serial.begin(9600);

  pinMode(ledVerde, OUTPUT);
  pinMode(MQ135, INPUT);
  pinMode(buzzer, OUTPUT);

  //inicializa sensor do DHT
  dht.begin();

  Serial.println("CALIBRANDO OS SENSORES...");
  delay(1000);
  Serial.println("SENSORES CALIBRADOS!");
}

void loop() {
  //detectorLED();
 // vazamentoGas();
  //alarme2tons();
  verificarTemperaturaEUmidade ();
}