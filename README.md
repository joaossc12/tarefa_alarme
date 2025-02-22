# README

## Descrição
Este projeto implementa um sistema de controle de LEDs utilizando a Raspberry Pi Pico. Os LEDs são acionados através de um botão e desligados sequencialmente após um determinado intervalo de tempo.

## Objetivos
- Demonstrar o uso de interrupções para captura de eventos do botão.
- Implementar um sistema de temporização para desligamento gradual dos LEDs.
- Explorar o uso de alarmes para tarefas agendadas na Raspberry Pi Pico.

## Tecnologias Utilizadas
- **Microcontrolador:** RP 2040
- **Linguagem de Programação:** C
- **IDE:** Visual Studio Code
- **SDK:** Pico SDK
- **Simulador:** Wokwi
- **Controle de Versão:** Git
- **Plataforma de Hospedagem:** GitHub

### Video demostração

- **Simulação no Wokwi:** [Assista no YouTube](https://youtu.be/0Q1RIRC-wT0)

## Como executar o Projeto
### Pré-requisitos
- Raspberry Pi Pico
- LED RGB com resistores apropriados
- Botão de pressão
- Ambiente de desenvolvimento configurado para Raspberry Pi Pico (SDK C/C++)

### Passos para execução
1. Clone este repositório para o seu ambiente de desenvolvimento.
2. Compile o código utilizando o SDK da Raspberry Pi Pico.
3. Carregue o binário gerado na Raspberry Pi Pico.
4. Conecte os pinos conforme as definições no código:
   - **Pino 13** - Vermelho
   - **Pino 12** - Azul
   - **Pino 11** - Verde
   - **Pino 5**  - Botão
5. Ao pressionar o botão, os LEDs acenderão simultaneamente e apagarão um a um após um intervalo de 3 segundos.

