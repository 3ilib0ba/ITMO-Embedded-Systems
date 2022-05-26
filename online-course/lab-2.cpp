#include "hal.h"

int i = 0;
int T = 50;
int SW_current = 0;
int leds_num[] =   {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5,
                    GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9,
                    GPIO_PIN_11, GPIO_PIN_12};
unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};
GPIO_PinState sw_now[4];



void switch_cadr_one()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_two()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_three()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_four()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
}

void switch_cadr_five()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_six()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_seven()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_eight()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void run_next_cadr(int i)
{
    switch (i) {
        case 0:
            switch_cadr_one();
            break;
        case 1:
            switch_cadr_two();
            break;
        case 2:
            switch_cadr_three();
            break;
        case 3:
            switch_cadr_four();
            break;
        case 4:
            switch_cadr_five();
            break;
        case 5:
            switch_cadr_six();
            break;
        case 6:
            switch_cadr_seven();
            break;
        case 7:
            switch_cadr_eight();
            i = -1;
            break;
    }
}

void chectk_sw() 
{
    int tmp = 0;

    // read all sw to create delay
    for(int i = 0; i < 4; i++)
    {
        sw_now[i] = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);

        if (sw_now[i]) 
        {
            int a = 3 - i;
            int b = 1;
            while (a > 0) 
            {
                b = b * 2;
                a--;
            }

            tmp = tmp + b;
        }
    }
    
    // resize delay
    SW_current = tmp;
}

void TIM6_IRQ_Handler()
{
    run_next_cadr(i);
    i = i + 1;
    if(i == 8)
    {
        i = 0;
    }
}

void TIM7_IRQ_Handler()
{
    // often check SW to change delay on timer 6 to change delay from cadrs
    chectk_sw();
    int current_delay_from_sw = 500 + T * SW_current; 
    WRITE_REG(TIM6_ARR, current_delay_from_sw);
}

int umain()
{
    i = 0;

    // register interrupt of timers on needed functions
    registerTIM6_IRQHandler(TIM6_IRQ_Handler);
    registerTIM7_IRQHandler(TIM7_IRQ_Handler);
    
    __enable_irq();
    
    // enable first delays
    WRITE_REG(TIM6_ARR, 500);
    WRITE_REG(TIM6_DIER, TIM_DIER_UIE);
    WRITE_REG(TIM6_PSC, 0);
    WRITE_REG(TIM7_ARR, 200);
    WRITE_REG(TIM7_DIER, TIM_DIER_UIE);
    WRITE_REG(TIM7_PSC, 0);
    
    // turn on timers
    WRITE_REG(TIM6_CR1, TIM_CR1_CEN);
    WRITE_REG(TIM7_CR1, TIM_CR1_CEN);
    
    return 0;
}