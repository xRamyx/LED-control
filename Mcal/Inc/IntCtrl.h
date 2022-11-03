 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#ifndef INTCTRL_H
#define INTCTRL_H

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")

/* Standard types */
#include "Std_Types.h"
#include "Common_Macros.h"

/* Dio Pre-Compile Configuration Header file */
#include "IntCtrl_Cfg.h"

#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_PRIORITY_BITS_POS   29

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for IntCtrl_InterruptType used by the IntCtrl APIs */
typedef enum
{
	SYSTICK=15, GPIO_PORT_A, GPIO_PORT_B, GPIO_PORT_C, GPIO_PORT_D, GPIO_PORT_E /* And so on... */
}IntCtrl_InterruptType;

typedef struct
{
	/* Member contains the interrupt type */
	IntCtrl_InterruptType InterruptPeripheralGates;
	/* Member contains the priority of the group*/
	uint8 InterruptGroupPriority;
	/* Member contains the priority of the sub-group*/
	uint8 InterruptSubGroupPriority;
}IntCtrl_ConfigChannel;

/* Data Structure required for initializing the IntCtrl Driver */
typedef struct IntCtrl_ConfigType
{
	IntCtrl_ConfigChannel Channels[INTCTRL_CONFIGURED_CHANNLES];
} IntCtrl_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for IntCtrl init API */
void IntCtrl_init(const IntCtrl_ConfigType * ConfigPtr);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by IntCtrl and other modules */
extern const IntCtrl_ConfigType IntCtrl_Configuration;

#endif /* INTCTRL_H */
