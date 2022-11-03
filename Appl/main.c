#include "Led.h"
#include "Gpt.h"
#include "Dio.h"
#include "Port.h"
#include "IntCtrl.h"

/* Global variable to indicate the the timer has a new tick */
static uint8 g_New_Time_Tick_Flag = 0;

void NewTimerTick(void)
{
    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*********************************************************************************************/

int main(void)
{
	
	/* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);

    /* Initialize Port Driver */
    Port_Init(&Port_Configuration);
	
		/* Initialize IntCtrl Driver */
		IntCtrl_init(&IntCtrl_Configuration);
	
		/* 
     * Set the Call Back function to call NewTimerTick
     * this function will be called every SysTick Interrupt
     */
    SysTick_SetCallBack(NewTimerTick);

    /* Start SysTickTimer to generate interrupt every 1s */
    SysTick_Start(1000);
	
	while(1)
	{
		if(g_New_Time_Tick_Flag == 1)
		{
			LED_toggle();
			g_New_Time_Tick_Flag = 0;
		}
	}
}