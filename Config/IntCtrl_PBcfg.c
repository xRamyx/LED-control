 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#include "IntCtrl.h"

/* PB structure used with IntCtrl_Init API */
const IntCtrl_ConfigType IntCtrl_Configuration = {
                                             INTCTRL_CONF_PERIPHERAL_TYPE,INTCTRL_CONF_GROUP_PRI,INTCTRL_CONF_SUB_GROUP_PRI
				         };