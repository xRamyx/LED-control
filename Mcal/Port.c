 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

STATIC const Port_ConfigChannel * Port_PortChannels = NULL_PTR;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{

	volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
	volatile uint32 delay = 0;
	uint8 id;
	for(id=0; id<PORT_CONFIGURED_CHANNLES; id++)
	{
		if(!((ConfigPtr->Channels[id].port_num == 2) && (ConfigPtr->Channels[id].pin_num <= 3)))
		{
			switch(ConfigPtr->Channels[id].port_num)
			{
				case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
						 break;
				case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
						 break;
				case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
						 break;
				case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
						 break;
				case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
						 break;
				case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
						 break;
			}

			/* Enable clock for PORT and allow time for clock to start*/
			SYSCTL_REGCGC2_REG |= (1<<ConfigPtr->Channels[id].port_num);
			delay = SYSCTL_REGCGC2_REG;

			if( ((ConfigPtr->Channels[id].port_num == 3) && (ConfigPtr->Channels[id].pin_num == 7)) || ((ConfigPtr->Channels[id].port_num == 5) && (ConfigPtr->Channels[id].port_num == 0)) ) /* PD7 or PF0 */
			{
				*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
			}
			else if( (ConfigPtr->Channels[id].port_num == 2) && (ConfigPtr->Channels[id].pin_num <= 3) ) /* PC0 to PC3 */
			{
				/* Do Nothing ...  this is the JTAG pins */
			}
			else
			{
				/* Do Nothing ... No need to unlock the commit register for this pin */
			}
			
			if(PORT_PIN_OUT == ConfigPtr->Channels[id].direction)
			{
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
				  
				if(STD_HIGH == ConfigPtr->Channels[id].initial_value)
				{
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
				}
				else
				{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
				}
			}
			else if(PORT_PIN_IN == ConfigPtr->Channels[id].direction)
			{
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
				  
				if(PULL_UP == ConfigPtr->Channels[id].resistor)
				{
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
				}
				else if(PULL_DOWN == ConfigPtr->Channels[id].resistor)
				{
					SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
				}
				else
				{
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
				}
			}
			else
			{
				/* Do Nothing */
			}
			
			/*Check the mode of the pin*/
			if(PIN_MODE_DIO == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_UART == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000001 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_SSI == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000002 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_I2C == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000003 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_M0PWM == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000004 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_M1PWM == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000005 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_ADC == ConfigPtr->Channels[id].mode)
			{
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_WDT == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000007 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else if(PIN_MODE_CAN == ConfigPtr->Channels[id].mode)
			{
			  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[id].pin_num * 4));     /* Clear the PMCx bits for this pin */
			  *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (ConfigPtr->Channels[id].pin_num * 4));     /* Set the PMCx bits for this pin */
			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[id].pin_num);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
			}
			else
			{
			  /* Do nothing */
			}
		}
	}
}