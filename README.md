# 🛗 Simulador de Elevador com Arduino

Este projeto consiste numa simulação funcional de um elevador de 3 andares utilizando a plataforma Arduino. O sistema controla o movimento entre andares, sinalização visual via LEDs, feedback textual num display LCD I2C e a automação de uma porta utilizando um servomotor.

## 🚀 Funcionalidades

- **Controlo de 3 Andares:** Botões dedicados para os andares 0 (Térreo), 1 e 2.
- **Interface Visual:** LCD 16x2 que exibe o estado atual (Subindo, Descendo, Porta Aberta, etc.).
- **Indicadores Luminosos:** LEDs que identificam em que andar o elevador está parado.
- **Automação da Porta:** Servomotor que abre e fecha automaticamente ao chegar ao destino.
- **Lógica de Segurança:** Impede o movimento se o elevador já estiver no andar solicitado.

## 🛠️ Componentes Necessários

- 1x Arduino (Uno, Nano ou Mega)
- 1x Display LCD 16x2 com Módulo I2C
- 1x Micro Servomotor (ex: SG90)
- 3x LEDs (Cores à escolha)
- 3x Resistores de 220Ω (para os LEDs)
- 3x Botões Push-button
- Jumpers e Protoboard

## 🔌 Esquema de Ligação

Abaixo estão os pinos configurados no código:

| Componente | Pino Arduino |
|---|---|
| **LED Andar 0** | Digital 2 |
| **LED Andar 1** | Digital 4 |
| **LED Andar 2** | Digital 7 |
| **Botão Andar 0** | Analógico A0 |
| **Botão Andar 1** | Analógico A1 |
| **Botão Andar 2** | Analógico A2 |
| **Servo (Sinal)** | Digital 9 |
| **LCD (SDA)** | Analógico A4 |
| **LCD (SCL)** | Analógico A5 |


🛠️ Como Instalar
Clone o repositório.

Abra o ficheiro na Arduino IDE.

Instale a biblioteca LiquidCrystal I2C (por Frank de Brabander).

Ligue os componentes conforme o esquema.

Faça o Upload para a sua placa.
