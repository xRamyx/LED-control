 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNLES              (43U)

/******************************************************************************
 *            Channel Index in the array of structures in Port_PBcfg.c        *
 ******************************************************************************/
#define PORTA_PIN0      (0U)
#define PORTA_PIN1      (1U)
#define PORTA_PIN2      (2U)
#define PORTA_PIN3      (3U)
#define PORTA_PIN4      (4U)
#define PORTA_PIN5      (5U)
#define PORTA_PIN6      (6U)
#define PORTA_PIN7      (7U)

#define PORTB_PIN0      (8U)
#define PORTB_PIN1      (9U)
#define PORTB_PIN2      (10U)
#define PORTB_PIN3      (11U)
#define PORTB_PIN4      (12U)
#define PORTB_PIN5      (13U)
#define PORTB_PIN6      (14U)
#define PORTB_PIN7      (15U)

#define PORTC_PIN0      (16U)
#define PORTC_PIN1      (17U)
#define PORTC_PIN2      (18U)
#define PORTC_PIN3      (19U)
#define PORTC_PIN4      (20U)
#define PORTC_PIN5      (21U)
#define PORTC_PIN6      (22U)
#define PORTC_PIN7      (23U)

#define PORTD_PIN0      (24U)
#define PORTD_PIN1      (25U)
#define PORTD_PIN2      (26U)
#define PORTD_PIN3      (27U)
#define PORTD_PIN4      (28U)
#define PORTD_PIN5      (29U)
#define PORTD_PIN6      (30U)
#define PORTD_PIN7      (31U)

#define PORTE_PIN0      (32U)
#define PORTE_PIN1      (33U)
#define PORTE_PIN2      (34U)
#define PORTE_PIN3      (35U)
#define PORTE_PIN4      (36U)
#define PORTE_PIN5      (37U)

#define PORTF_PIN0      (38U)
#define PORTF_PIN1      (39U)
#define PORTF_PIN2      (40U)
#define PORTF_PIN3      (41U)
#define PORTF_PIN4      (42U)

/* PORT Configured Channel Direction */
#define	PORTA_PIN0_DIRECTION	            (PORT_PIN_IN)
#define PORTA_PIN1_DIRECTION		        (PORT_PIN_IN)
#define PORTA_PIN2_DIRECTION		        (PORT_PIN_IN)
#define PORTA_PIN3_DIRECTION		        (PORT_PIN_IN)
#define PORTA_PIN4_DIRECTION		        (PORT_PIN_IN)
#define PORTA_PIN5_DIRECTION		        (PORT_PIN_IN)
#define PORTA_PIN6_DIRECTION		        (PORT_PIN_IN)
#define PORTA_PIN7_DIRECTION		        (PORT_PIN_IN)

#define PORTB_PIN0_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN1_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN2_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN3_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN4_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN5_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN6_DIRECTION		        (PORT_PIN_IN)
#define PORTB_PIN7_DIRECTION		        (PORT_PIN_IN)

#define PORTC_PIN0_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN1_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN2_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN3_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN4_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN5_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN6_DIRECTION		        (PORT_PIN_IN)
#define PORTC_PIN7_DIRECTION		        (PORT_PIN_IN)

#define PORTD_PIN0_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN1_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN2_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN3_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN4_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN5_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN6_DIRECTION		        (PORT_PIN_IN)
#define PORTD_PIN7_DIRECTION		        (PORT_PIN_IN)

#define PORTE_PIN0_DIRECTION		        (PORT_PIN_IN)
#define PORTE_PIN1_DIRECTION		        (PORT_PIN_IN)
#define PORTE_PIN2_DIRECTION		        (PORT_PIN_IN)
#define PORTE_PIN3_DIRECTION		        (PORT_PIN_IN)
#define PORTE_PIN4_DIRECTION		        (PORT_PIN_IN)
#define PORTE_PIN5_DIRECTION		        (PORT_PIN_IN)

#define PORTF_PIN0_DIRECTION		        (PORT_PIN_IN)
#define PORTF_PIN1_DIRECTION		        (PORT_PIN_OUT)
#define PORTF_PIN2_DIRECTION		        (PORT_PIN_IN)
#define PORTF_PIN3_DIRECTION		        (PORT_PIN_IN)
#define PORTF_PIN4_DIRECTION		        (PORT_PIN_IN)

/* PORT Configured Channel Initial Values */
#define PORTA_PIN0_INIT_VALUE    	        (STD_LOW)
#define PORTA_PIN1_INIT_VALUE		        (STD_LOW)
#define PORTA_PIN2_INIT_VALUE		        (STD_LOW)
#define PORTA_PIN3_INIT_VALUE		        (STD_LOW)
#define PORTA_PIN4_INIT_VALUE		        (STD_LOW)
#define PORTA_PIN5_INIT_VALUE		        (STD_LOW)
#define PORTA_PIN6_INIT_VALUE  	            (STD_LOW)
#define PORTA_PIN7_INIT_VALUE		        (STD_LOW)

#define PORTB_PIN0_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN1_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN2_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN3_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN4_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN5_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN6_INIT_VALUE		        (STD_LOW)
#define PORTB_PIN7_INIT_VALUE		        (STD_LOW)

#define PORTC_PIN0_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN1_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN2_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN3_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN4_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN5_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN6_INIT_VALUE		        (STD_LOW)
#define PORTC_PIN7_INIT_VALUE		        (STD_LOW)

#define PORTD_PIN0_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN1_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN2_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN3_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN4_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN5_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN6_INIT_VALUE		        (STD_LOW)
#define PORTD_PIN7_INIT_VALUE		        (STD_LOW)

#define PORTE_PIN0_INIT_VALUE		        (STD_LOW)
#define PORTE_PIN1_INIT_VALUE		        (STD_LOW)
#define PORTE_PIN2_INIT_VALUE		        (STD_LOW)
#define PORTE_PIN3_INIT_VALUE		        (STD_LOW)
#define PORTE_PIN4_INIT_VALUE		        (STD_LOW)
#define PORTE_PIN5_INIT_VALUE		        (STD_LOW)

#define PORTF_PIN0_INIT_VALUE		        (STD_LOW)
#define PORTF_PIN1_INIT_VALUE		        (STD_LOW)
#define PORTF_PIN2_INIT_VALUE		        (STD_LOW)
#define PORTF_PIN3_INIT_VALUE		        (STD_LOW)
#define PORTF_PIN4_INIT_VALUE		        (STD_LOW)

/* PORT Configured Channel Internal Resistors */
#define PORTA_PIN0_RESISTOR			 (OFF)
#define PORTA_PIN1_RESISTOR			 (OFF)
#define PORTA_PIN2_RESISTOR			 (OFF)
#define PORTA_PIN3_RESISTOR			 (OFF)
#define PORTA_PIN4_RESISTOR			 (OFF)
#define PORTA_PIN5_RESISTOR			 (OFF)
#define PORTA_PIN6_RESISTOR			 (OFF)
#define PORTA_PIN7_RESISTOR			 (OFF)

#define PORTB_PIN0_RESISTOR			 (OFF)
#define PORTB_PIN1_RESISTOR			 (OFF)
#define PORTB_PIN2_RESISTOR			 (OFF)
#define PORTB_PIN3_RESISTOR			 (OFF)
#define PORTB_PIN4_RESISTOR			 (OFF)
#define PORTB_PIN5_RESISTOR			 (OFF)
#define PORTB_PIN6_RESISTOR			 (OFF)
#define PORTB_PIN7_RESISTOR			 (OFF)

#define PORTC_PIN0_RESISTOR			 (OFF)
#define PORTC_PIN1_RESISTOR			 (OFF)
#define PORTC_PIN2_RESISTOR			 (OFF)
#define PORTC_PIN3_RESISTOR			 (OFF)
#define PORTC_PIN4_RESISTOR			 (OFF)
#define PORTC_PIN5_RESISTOR			 (OFF)
#define PORTC_PIN6_RESISTOR			 (OFF)
#define PORTC_PIN7_RESISTOR			 (OFF)

#define PORTD_PIN0_RESISTOR			 (OFF)
#define PORTD_PIN1_RESISTOR			 (OFF)
#define PORTD_PIN2_RESISTOR			 (OFF)
#define PORTD_PIN3_RESISTOR			 (OFF)
#define PORTD_PIN4_RESISTOR			 (OFF)
#define PORTD_PIN5_RESISTOR			 (OFF)
#define PORTD_PIN6_RESISTOR		     (OFF)
#define PORTD_PIN7_RESISTOR			 (OFF)

#define PORTE_PIN0_RESISTOR			 (OFF)
#define PORTE_PIN1_RESISTOR			 (OFF)
#define PORTE_PIN2_RESISTOR			 (OFF)
#define PORTE_PIN3_RESISTOR			 (OFF)
#define PORTE_PIN4_RESISTOR			 (OFF)
#define PORTE_PIN5_RESISTOR			 (OFF)

#define PORTF_PIN0_RESISTOR			 (OFF)
#define PORTF_PIN1_RESISTOR			 (OFF)
#define PORTF_PIN2_RESISTOR			 (OFF)
#define PORTF_PIN3_RESISTOR			 (OFF)
#define PORTF_PIN4_RESISTOR			 (OFF)

/* PORT Configured Channel Mode */
#define PORTA_PIN0_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN1_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN2_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN3_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN4_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN5_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN6_MODE		                (PIN_MODE_DIO)
#define PORTA_PIN7_MODE		                (PIN_MODE_DIO)

#define PORTB_PIN0_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN1_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN2_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN3_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN4_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN5_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN6_MODE		                (PIN_MODE_DIO)
#define PORTB_PIN7_MODE		                (PIN_MODE_DIO)

#define PORTC_PIN0_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN1_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN2_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN3_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN4_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN5_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN6_MODE		                (PIN_MODE_DIO)
#define PORTC_PIN7_MODE		                (PIN_MODE_DIO)

#define PORTD_PIN0_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN1_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN2_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN3_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN4_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN5_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN6_MODE		                (PIN_MODE_DIO)
#define PORTD_PIN7_MODE		                (PIN_MODE_DIO)

#define PORTE_PIN0_MODE		                (PIN_MODE_DIO)
#define PORTE_PIN1_MODE		                (PIN_MODE_DIO)
#define PORTE_PIN2_MODE		                (PIN_MODE_DIO)
#define PORTE_PIN3_MODE		                (PIN_MODE_DIO)
#define PORTE_PIN4_MODE		                (PIN_MODE_DIO)
#define PORTE_PIN5_MODE		                (PIN_MODE_DIO)

#define PORTF_PIN0_MODE		                (PIN_MODE_DIO)
#define PORTF_PIN1_MODE		                (PIN_MODE_DIO)
#define PORTF_PIN2_MODE		                (PIN_MODE_DIO)
#define PORTF_PIN3_MODE		                (PIN_MODE_DIO)
#define PORTF_PIN4_MODE		                (PIN_MODE_DIO)

#endif /* PORT_CFG_H */
