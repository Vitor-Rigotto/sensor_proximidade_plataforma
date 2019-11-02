//Programa : Sensor de Proximidade para plataforma de embarque
//Autor : Vitor Rigotto
//Data de início: 27/10/2019

#define trigPin 8
#define echoPin 7
#define pino_luz 5

// Definição Variáveis:
long duration;
int distance;
bool acendeu = true;

void setup(){
    // Define entradas e saídas
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(pino_luz, OUTPUT);

    Serial.begin(9600);
}

void loop(){
    // Limpa o trigPin inicializando ele como LOW
    digitalWrite(trigPin, LOW);

    delayMicroseconds(5);

    //Ativa o sensor configurando o trigPin HIG por 10 microssegundos:
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Lê o echoPin. pulseIn () retorna a duração (duração do pulso) em microssegundos:
    duration = pulseIn(echoPin, HIGH);

    // Calcula a distância:
    distance = duration * 0.034 / 2;

    // Imprime a distância no Monitor Serial (Ctrl+Shift+M)
    Serial.print("Distancia = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);

    //primeira vez que a luz acende
    if(distance = 27){
      acendeu = false //já não será mais a prmeira vez
        for(int i = 0; i<1; i++){
          digitalWrite(pino_luz, HIGH);
          delay(5000);
          digitalWrite(pino_luz, LOW);
          delay(1500);
          }
          
          else{
            digitalWrite(pino_luz, LOW);
            }
   }
}
