#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"



static char Count = 0;
static enum{ off = 0, dim= 1, bright = 2} led_mode;


void slow_Clock(){  /* slow cycle through enumeration*/
  led_mode +=1 % 3;
}

void fast_Clock(){
  Count +=1  % 3;
}
void st_update_led(){
  char nred_on;
  switch(led_mode){
  case off:
    nred_on = 0;
    break;
  case bright:
    nred_on = 1;
    break;
  case dim:
    nred_on = (Count < 1);
    break;
  }
  if(red_on != nred_on)
    {
      red_on = nred_on;
      led_changed = 1;
    }
}
    
char turn_red()	/*turn on red*/
{
  static char state = 0;
  switch (state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
      red_on = 0;
    state = 0;
    break;
  }
  return 1;
}
char turn_green(){
  char has_changed = 0;/*turn on green when red is on */
  if(red_on){
    green_on ^=1;
   has_changed = 1;
  }
  return has_changed;
}
void st_advance(){     /*change between red and green*/
  char has_changed =  0;
  static enum  {R=0,G=1} color = G;
  switch(color){
    
  case R: has_changed = turn_red(); color = G;break;
  case G: has_changed = turn_green(); color = R; break;
  }
  led_changed = has_changed;
    led_update();
}


