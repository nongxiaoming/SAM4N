#include "sam4n16c.h"
#include "drv_led.h"
#include "delay.h"
#include "drv_usart.h"

int main(void)
{
 systick_hw_init();
 led_hw_init();
 USART0_Init(115200);
 while(1){
	 USART0_Init(115200);
USART0_SendString("hello\r\n");
 PIOB->PIO_CODR=(0x01<<LED0_PIN);
 delay_ms(100);
 PIOB->PIO_SODR=(0x01<<LED0_PIN);
 delay_ms(100);
 }

}

