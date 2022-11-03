 /******************************************************************************
 *
 * Module: IntCtrl
 *
 * File Name: IntCtrl_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - IntCtrl Driver
 *
 * Author: Ramy Mohamed Ahmed Mohamed
 ******************************************************************************/

#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/* Number of the configured IntCtrl Channels */
#define INTCTRL_CONFIGURED_CHANNLES             (1U)

/* Channel Index in the array of structures in IntCtrl_PBcfg.c */
#define IntCtrlConf_TIMER_CHANNEL_ID_INDEX        (uint8)0x00

/* INTCTRL Configured Peripheral  */
#define INTCTRL_CONF_PERIPHERAL_TYPE                (IntCtrl_InterruptType)15 /* TIMER */

/* INTCTRL Configured Group Priority */
#define INTCTRL_CONF_GROUP_PRI             			(uint8)0 /* Priority 0 */

/* INTCTRL Configured Sub-Group Priority */
#define INTCTRL_CONF_SUB_GROUP_PRI             		(uint8)0 /* Priority 0 */

#endif /* INTCTRL_CFG_H */
