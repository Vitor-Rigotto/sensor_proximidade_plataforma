#define trigPin 8
#define echoPin 7
#define pino_luz 5

// Definição Variáveis:
long duration;
int distance;

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

    // Calcula adistância:
    distance = duration * 0.034 / 2;

    // Imprime a distância no Monitor Serial (Ctrl+Shift+M)
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);

    switch (distance){

        case (27):
            digitalWrite(pino_luz, HIGH);
            Serial.print("Chegou \n");
            delay(5000);
            digitalWrite(pino_luz, LOW);
            break;

        default:
            break;
        }
}