 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#include "IntCtrl.h"
#include "IntCtrl_Regs.h"


/************************************************************************************
* Service Name: IntCtrl_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the IntCtrl module.
************************************************************************************/
void IntCtrl_init(const IntCtrl_ConfigType * ConfigPtr)
{
	Enable_Interrupts();
	
	APINT = 0xFA050000;
	APINT = (APINT & 0xFFFFF8FF) | (0x4 << 8); /*xxx >> 8 Group Priorities and 1 Sub-Group Proprity*/
	
	uint8 id;
	for(id=0; id<INTCTRL_CONFIGURED_CHANNLES; id++)
	{
		if(ConfigPtr->Channels[id].InterruptPeripheralGates == SYSTICK)
		{
			/* Assign priority level 3 to the SysTick Interrupt */
			NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | ((ConfigPtr->Channels[id].InterruptGroupPriority) << SYSTICK_PRIORITY_BITS_POS);
		}
		else if(ConfigPtr->Channels[id].InterruptPeripheralGates == GPIO_PORT_A)
		{
			/* Set GPIO PORTA priotiy by set Bit number 5, 6 and 7 with value defined by user */
			NVIC_PRI0_REG = (NVIC_PRI0_REG & 0xFFFFFF1F) | ((ConfigPtr->Channels[id].InterruptGroupPriority)<<5);
			NVIC_EN0_REG         |= 0x00000001;   /* Enable NVIC Interrupt for GPIO PORTA by set bit number 0 in EN0 Register */
		}
		else if(ConfigPtr->Channels[id].InterruptPeripheralGates == GPIO_PORT_B)
		{
			/* Set GPIO PORTB priotiy by set Bit number 13, 14 and 15 with value defined by user */
			NVIC_PRI0_REG = (NVIC_PRI0_REG & 0xFFFF1FFF) | ((ConfigPtr->Channels[id].InterruptGroupPriority)<<13);
			NVIC_EN0_REG         |= 0x00000002;   /* Enable NVIC Interrupt for GPIO PORTB by set bit number 1 in EN0 Register */
		}
		else if(ConfigPtr->Channels[id].InterruptPeripheralGates == GPIO_PORT_C)
		{
			/* Set GPIO PORTC priotiy by set Bit number 21, 22 and 23 with value defined by user */
			NVIC_PRI0_REG = (NVIC_PRI0_REG & 0xFF1FFFFF) | ((ConfigPtr->Channels[id].InterruptGroupPriority)<<21);
			NVIC_EN0_REG         |= 0x00000004;   /* Enable NVIC Interrupt for GPIO PORTC by set bit number 2 in EN0 Register */
		}
		else if(ConfigPtr->Channels[id].InterruptPeripheralGates == GPIO_PORT_D)
		{
			/* Set GPIO PORTD priotiy by set Bit number 29, 30 and 31 with value defined by user */
			NVIC_PRI0_REG = (NVIC_PRI0_REG & 0x1FFFFFFF) | ((ConfigPtr->Channels[id].InterruptGroupPriority)<<29);
			NVIC_EN0_REG         |= 0x00000008;   /* Enable NVIC Interrupt for GPIO PORTD by set bit number 3 in EN0 Register */
		}
		else if(ConfigPtr->Channels[id].InterruptPeripheralGates == GPIO_PORT_E)
		{
			/* Set GPIO PORTE priotiy by set Bit number 5, 6 and 7 with value defined by user */
			NVIC_PRI1_REG = (NVIC_PRI1_REG & 0xFFFFFF1F) | ((ConfigPtr->Channels[id].InterruptGroupPriority)<<5);
			NVIC_EN0_REG         |= 0x00000010;   /* Enable NVIC Interrupt for GPIO PORTE by set bit number 4 in EN0 Register */
		}
		else
		{
			/*Do nothing*/
		}
	}
	
}