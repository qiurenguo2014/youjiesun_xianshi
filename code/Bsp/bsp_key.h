﻿/*************************************************************************
#    FileName: bsp_key.h
#      Author: Allen
#       Email: qiurenguo@gmail.com
#    HomePage: Allen
#       Brief: 
#  LastChange: 2014-05-07 16:33:10
*************************************************************************/
/* Define to prevent recursive inclusion -------------------------------*/
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

/* Includes ------------------------------------------------------------*/
#include <stdint.h>
/* Exported types ------------------------------------------------------*/
/* Exported constants --------------------------------------------------*/
/* Exported define -----------------------------------------------------*/
#define DELAY_VK1 2			//
#define DELAY_VK2 50		//连按
#define DELAY_VK3 15		//继续连按

/* Function Key Code Table -------------------------------------*/
#define VK_NOKEY		0
#define VK_LOOSE		0X80//松开
#define VK_CONT			0x40//连续
#define VK_LBUTTON     0X01	//
#define VK_RBUTTON     0X02	//
#define VK_CANCEL      0X03	//
#define VK_MBUTTON     0X04	//
#define VK_BACK        0X08	//
#define VK_TAB         0X09	//
#define VK_CLEAR       0X0C	//
#define VK_ENTER       0X0D	//
#define VK_SHIFT       0X10	//
#define VK_CONTROL     0X11	//
#define VK_MENU        0X12	//
#define VK_PAUSE       0X13	//
#define VK_CAPITAL     0X14	//
#define VK_ESCAPE      0X1B	//
#define VK_SPACE       0X20	//
#define VK_PRIOR       0X21	//
#define VK_NEXT        0X22	//
#define VK_END         0X23	//
#define VK_HOME        0X24	//
#define VK_LEFT        0X25	//
#define VK_UP          0X26	//
#define VK_RIGHT       0X27	//
#define VK_DOWN        0X28	//
#define VK_SELECT      0X29	//
#define VK_EXECUTE     0X2B	//
#define VK_SNAPSHOT    0X2C	// 
#define VK_INSERT      0X2D	//
#define VK_DELETE      0X2E	// 
#define VK_HELP        0X2F	//
#define VK_SYSSET      0X30	//
#define VK_PAIYOU		0X31
/* Exported variables --------------------------------------------------*/
/* Exported functions prototypes ---------------------------------------*/
extern void KEY_Send_Keymsg (uint8_t VK_MSG);
extern void KEY_Listen_KEY (void);
extern uint8_t GUI_Get_Keymsg (void);
extern uint8_t GUI_Get_Keymsg_a (void);
#endif 
/*********************************END OF FILE****************************/


