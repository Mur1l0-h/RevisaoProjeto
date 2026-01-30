const int PIN_VERDE = 10;
const int PIN_AMARELO = 11;
const int PIN_VERMELHO = 12;

const int PIN_SENSOR_FLUXO = A0;
const int PIN_SENSOR_CHUVA = A1;

int tempoVerde = 5000;
int tempoAmarelo = 2000;
int tempoVermelho = 5000;

int historicoFluxo[5];

void setup() {
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PIN_AMARELO, OUTPUT);
  pinMode(PIN_VERMELHO, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("--- Sistema de Semaforo Inteligente Iniciado ---");
}

void loop() {
  bool sensorOk = verificarIntegridade();
  bool servidorOnline = true;

  if (!sensorOk) {
    modoSeguranca();
    return; 
  }

  if (!servidorOnline) {
    Serial.println("[AVISO] Operando em Modo Local - Servidor Offline.");
  }
  
  atualizarHistorico();
  float mediaFluxo = calcularMediaFluxo();
  int statusChuva = analogRead(PIN_SENSOR_CHUVA);

  int ajusteVerde = 0;
  int ajusteAmarelo = 0;

  if (statusChuva > 700) {
    Serial.println("-> Alerta: Chuva forte! Aumentando cautela.");
    ajusteAmarelo = 2000; 
    ajusteVerde = -1000;  
  }

  if (mediaFluxo > 300) { 
    Serial.println("-> Alerta: Fluxo intenso! Estendendo sinal verde.");
    ajusteVerde += 3000; 
  }
 
  executarCiclo(tempoVerde + ajusteVerde, tempoAmarelo + ajusteAmarelo, tempoVermelho);
}

bool verificarIntegridade() {

  int leitura = analogRead(PIN_SENSOR_FLUXO);
  return (leitura > 5 && leitura < 1020); 
}

void atualizarHistorico() {
  for (int i = 0; i < 4; i++) {
    historicoFluxo[i] = historicoFluxo[i + 1]; 
  }
  historicoFluxo[4] = analogRead(PIN_SENSOR_FLUXO);
}

float calcularMediaFluxo() {
  int soma = 0;
  for (int i = 0; i < 5; i++) {
    soma += historicoFluxo[i];
  }
  return soma / 5.0;
}

void executarCiclo(int v, int a, int r) {
  digitalWrite(PIN_VERDE, HIGH);
  delay(v);
  digitalWrite(PIN_VERDE, LOW);

  digitalWrite(PIN_AMARELO, HIGH);
  delay(a);
  digitalWrite(PIN_AMARELO, LOW);

  digitalWrite(PIN_VERMELHO, HIGH);
  delay(r);
  digitalWrite(PIN_VERMELHO, LOW);
}

void modoSeguranca() {
  Serial.println("!!! FALHA DETECTADA - MODO SEGURANÇA !!!");
  digitalWrite(PIN_VERDE, LOW);
  digitalWrite(PIN_VERMELHO, LOW);
  
  digitalWrite(PIN_AMARELO, HIGH);
  delay(500);
  digitalWrite(PIN_AMARELO, LOW);
  delay(500);
}