#include "hal.h"

bool break_animation = false;
unsigned int leds_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5,
                      GPIO_PIN_6, GPIO_PIN_8, GPIO_PIN_9,
                      GPIO_PIN_11, GPIO_PIN_12};
unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};
GPIO_PinState sw_now[4];



void clear_all_lights()
{
    for (int i = 0; i < 8; i++)
    {
        HAL_GPIO_WritePin(GPIOD, leds_num[i], GPIO_PIN_RESET);
    }
}

void light_all()
{
    for (int i = 0; i < 8; i++)
    {
        HAL_GPIO_WritePin(GPIOD, leds_num[i], GPIO_PIN_SET);
    }
}

void switch_cadr_one()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_two()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_three()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_four()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_five()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_RESET);
}

void switch_cadr_six()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
}

void switch_cadr_seven()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
}

void switch_cadr_eight()
{
    HAL_GPIO_WritePin(GPIOD, leds_num[0], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[1], GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, leds_num[2], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[3], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[4], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[5], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[6], GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, leds_num[7], GPIO_PIN_SET);
}

void run_next_cadr(int* i)
{
    switch (*i) {
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
            *i = -1;
            break;
    }

    *i = *i + 1;
}

// check in while(true) SW 
void check_SW(int* cadr_reset)
{
    while(1) {    
        for(int i = 0; i < 4; i++)
        {
            sw_now[i] = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
        }

        if (sw_now[0] && !sw_now[1] && sw_now[2] && !sw_now[3])
        {
           clear_all_lights();
           return;     
        }

        for(int i = 0; i < 4; i++)
        {
            HAL_GPIO_WritePin(GPIOD, leds_num[i], sw_now[i]);
            
            // reset animation if was interrupt not by nBTN 
            *cadr_reset = 0;
            //reset the button
            break_animation = false;
        }
    }
}

void check_nBTN() 
{
    GPIO_PinState state = GPIO_PIN_SET;
    int i = 0;

    while (i < 500) {
        state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15); // read nBTN
        if (state == GPIO_PIN_RESET)
        {
            break_animation = !break_animation;
            return;
        } 
        HAL_Delay(1);
        i++;
    }
}

int umain()
{
    int* current_cadr;
    *current_cadr = 0;
    int delay = 500;

    while(1) {
        // check_SW
        check_SW(current_cadr);

        // if SW = right_code (0x0A) -> go to cadr
        HAL_Delay(delay);
        if (!break_animation) 
        {
            run_next_cadr(current_cadr);
        }

        // after each cadr check the button
        check_nBTN();
        
        // clear lights because I can:-)
        //HAL_Delay(delay);
        //clear_all_lights();
    }
    
    return 0;
}