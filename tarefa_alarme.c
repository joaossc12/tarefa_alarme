#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define DELAY_MS 3000
#define BUTTON 5


volatile bool leds_ativos = false;  // Flag para evitar múltiplos acionamentos

void init_pinos();
int64_t alarm_callback(alarm_id_t id, void *user_data); // Função de callback do alarme
void button_callback(uint gpio, uint32_t events);

int main() {
    init_pinos();
    stdio_init_all();
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (true) {
      tight_loop_contents(); //Loop vazio
    }
}

// Inicializa os pinos do LED RGB e Botão
void init_pinos(){
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
 
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
 
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON); 
}

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    static int etapa = 0;  // Controle de qual LED será apagado

    switch (etapa) {
        case 0:
            gpio_put(LED_RED, 0);  //
            add_alarm_in_ms(DELAY_MS, alarm_callback, NULL, false);  // Próximo alarme 
            etapa++;
            break;
        case 1:
            gpio_put(LED_BLUE, 0);  
            add_alarm_in_ms(DELAY_MS, alarm_callback, NULL, false);  // Próximo alarme 
            etapa++;
            break;
        case 2:
            gpio_put(LED_GREEN, 0);  
            leds_ativos = false;  // Permite pressionar o botão novamente
            etapa = 0;
            break;
    }
    return 0;  
}

void button_callback(uint gpio, uint32_t events) {
    if (!leds_ativos) {  // Só permite ativar os LEDs se a flag for false
        leds_ativos = true;

        // Liga os LEDs
        gpio_put(LED_RED, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_GREEN, 1);

        // Inicia o alarme para desligar os LEDs um a um após 3 segundos
        add_alarm_in_ms(DELAY_MS, alarm_callback, NULL, false);
    }
}