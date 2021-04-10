#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down, switch_state_changed; /* effectively boolean */ 
static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  /* all 4 buttons defined and ready to be pressed, pressed = 1 , !pressed = 0*/
  char  s1_pressed = (p2val & SW1) ? 0 : 1; /* 0 when button is up */
  char  s2_pressed = (p2val & SW2) ? 0 : 1;
  char  s3_pressed = (p2val & SW3) ? 0 : 1;
  char  s4_pressed = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;

  if(s1_pressed){
    led_st = 0;
    led_changed = 1;
    switch_state_down = 1;
    led_advance();
    led_update();
    
  }
  if(s2_pressed){
    led_st = 0;
    led_changed = 1;
    switch_state_down = 1;
    led_advance();
    led_update();
  }
  if(s3_pressed){
    led_st = 0;
    led_changed = 1;
    switch_state_down = 1;
    led_advance();
    led_update();
    
  }
  if(s4_pressed){
    led_st = 0;
    led_changed = 1;
    switch_state_down = 1;
    led_advance();
    led_update();
    
  }
}
