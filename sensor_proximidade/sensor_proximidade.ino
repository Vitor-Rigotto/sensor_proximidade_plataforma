//Programa : Sensor de Proximidade para plataforma de embarque
//Autor : Vitor Rigotto
//Data de início: 27/10/2019

#define trigPin 8
#define echoPin 7
#define pino_luz 5
#define alimentacao_sensor 4 /*pino digital usado para alimentar o sensor
devido a falta de pinos de alimentação 5V no arduino e impossibilidade de derivar
cabos*/

// Definição Variáveis:
long duration;
int distance;

void setup(){
    // Define entradas e saídas
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(pino_luz, OUTPUT);
    pinMode(alimentacao_sensor,OUTPUT);

    /*irá fazer com que o pino sempre esteja escrevndo
     * para que a alimentção do sensor seje constante
     */
    digitalWrite(alimentacao_sensor, HIGH);
    
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
    delay(250);
    
    if(distance < 62){ 
      digitalWrite(pino_luz, 0);
      Serial.print ("Acendeu \n");//liga luz caso a distância entre o sensor e o objeto seje inferior a 62 cm
       }
                 
         else{
            digitalWrite(pino_luz, 1);
            }
  }
