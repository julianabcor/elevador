#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Configuração do LCD e Servo
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo portaServo;

// Definição dos Pinos
const int leds[] = {2, 4, 7};        // LED 0 no pino 2, LED 1 no pino 4, LED 2 no pino 7
const int botoes[] = {A0, A1, A2};   // Botões nos pinos A0, A1 e A2
const int pinoServo = 9;             // Servo no pino 9

int andar_atual = 0;

void setup() {
  // Inicializa LCD
  lcd.init();
  lcd.backlight();
  
  // Inicializa Servo e garante posição inicial
  portaServo.attach(pinoServo);
  portaServo.write(0); // Porta fechada
  delay(500); 
  // Opcional: portaServo.detach(); // Desativa para economizar energia até o uso
  
  // Configura LEDs e Botões
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT_PULLUP); 
  }
  
  // Estado inicial
  atualizarSistema("Elevador Pronto", andar_atual);
}

void loop() {
  // Monitora os botões
  for (int i = 0; i < 3; i++) {
    if (digitalRead(botoes[i]) == LOW) { 
      moverParaAndar(i);
    }
  }
}

void moverParaAndar(int destino) {
  if (destino == andar_atual) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ja esta no andar");
    delay(2000);
    atualizarSistema("Aguardando...", andar_atual);
    return;
  }

  while (andar_atual != destino) {
    if (destino > andar_atual) {
      andar_atual++;
      atualizarSistema("Subindo...", andar_atual);
    } else {
      andar_atual--;
      atualizarSistema("Descendo...", andar_atual);
    }
    delay(2500); 
  }

  // --- CHEGADA ---
  atualizarSistema("Chegamos!", andar_atual);
  delay(1000);
  
  // --- CICLO DA PORTA ---
  lcd.setCursor(0, 0);
  lcd.print("Abrindo porta   ");
  
  portaServo.attach(pinoServo); // "Acorda" o servo
  delay(100);
  portaServo.write(90);         // Abre a porta
  delay(2000);                  // Tempo aberta
  
  lcd.setCursor(0, 0);
  lcd.print("Fechando porta  ");
  portaServo.write(0);          // Fecha a porta
  delay(1500);                  // Tempo para concluir o fechamento
  // portaServo.detach();       // Opcional: libera o pino para evitar ruído nos LEDs
  
  atualizarSistema("Aguardando...", andar_atual);
}

void atualizarSistema(String msg, int andar) {
  // Atualiza os LEDs
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], i == andar ? HIGH : LOW);
  }
  
  // Atualiza o Display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg);
  lcd.setCursor(0, 1);
  lcd.print("Andar Atual: ");
  lcd.print(andar);
}
