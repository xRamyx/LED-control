 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Standard types */
#include "Std_Types.h"
#include "Common_Macros.h"
   
/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

   
/******************************************************************************
 *                              Port Definitions                              *
 ******************************************************************************/
#define PORTA           (0U)
#define PORTB           (1U)
#define PORTC           (2U)
#define PORTD           (3U)
#define PORTE           (4U)
#define PORTF           (5U)
/******************************************************************************
 *                              Pin Definitions                              *
 ******************************************************************************/
#define PIN0            (0U)
#define PIN1            (1U)
#define PIN2            (2U)
#define PIN3            (3U)
#define PIN4            (4U)
#define PIN5            (5U)
#define PIN6            (6U)
#define PIN7            (7U)

/*******************************************************************************
 *                              Pin Mode Types                              *
 *******************************************************************************/
#define PIN_MODE_DIO                   (uint8)0x00
#define PIN_MODE_UART                  (uint8)0x01
#define PIN_MODE_SSI                   (uint8)0x02
#define PIN_MODE_I2C                   (uint8)0x03
#define PIN_MODE_M0PWM                 (uint8)0x04
#define PIN_MODE_M1PWM                 (uint8)0x05
#define PIN_MODE_ADC                   (uint8)0x06
#define PIN_MODE_WDT                   (uint8)0x07
#define PIN_MODE_CAN                   (uint8)0x08
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalAttach;

/* Different port pin modes */
typedef uint8 Port_PinModeType;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 *      5. the initial value of the pin if it is output
 *      6. the mode of the pin
 */
typedef struct
{
	/* Member contains the ID of the Port that this pin belongs to */
	uint8 port_num;
	/* Member contains the ID of the pin */
	uint8 pin_num;
	/* Member contains the direction of the pin */
	Port_PinDirectionType direction;
	/* Member contains the value of the internal resistor of the pin in case the direction is input */
	Port_InternalAttach resistor;
	/* Member contains the initial value of the pin in case the direction is output */
	uint8 initial_value;
	/* Member contains the mode of the pin */
	Port_PinModeType mode;
}Port_ConfigChannel;

typedef struct Port_ConfigType
{
    Port_ConfigChannel Channels[PORT_CONFIGURED_CHANNLES];
}Port_ConfigType;

/* Data type for the symbolic name of a port pin */
typedef uint8 Port_PinType;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for PORT Initialization API */
void Port_Init(const Port_ConfigType* ConfigPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
