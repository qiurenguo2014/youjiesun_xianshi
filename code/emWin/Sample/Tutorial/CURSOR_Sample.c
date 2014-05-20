/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2013  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.20 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The software has been licensed to  ARM LIMITED whose registered office
is situated at  110 Fulbourn Road,  Cambridge CB1 9NJ,  England solely
for  the  purposes  of  creating  libraries  for  ARM7, ARM9, Cortex-M
series,  and   Cortex-R4   processor-based  devices,  sublicensed  and
distributed as part of the  MDK-ARM  Professional  under the terms and
conditions  of  the   End  User  License  supplied  with  the  MDK-ARM
Professional. 
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : CURSOR_Sample.c
Purpose     : demonstrates the use of cursors
----------------------------------------------------------------------
*/

#include "GUI.h"

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const GUI_COLOR ColorsSeggerLogoBlue16[] = {
     0x0000FF,0x000000,0x888888,0xFFFFFF
    ,0xFF0000,0xBBBBBB
};

static const GUI_LOGPALETTE PalSeggerLogoBlue16 = {
  6,	/* number of entries */
  1, 	/* Has transparency */
  &ColorsSeggerLogoBlue16[0]
};

static const unsigned char acSeggerLogoBlue16[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00,
  0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
  0x01, 0x11, 0x12, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x11, 0x10,
  0x01, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x53, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x53, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x22, 0x11, 0x12, 0x23, 0x33, 0x33, 0x32, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x35, 0x22, 0x11, 0x12, 0x53, 0x33, 0x33, 0x33, 0x35, 0x22, 0x11, 0x12, 0x53, 0x33, 0x33, 0x33, 0x21, 0x11, 0x11, 0x11, 0x11, 0x12, 0x33, 0x21, 0x11, 0x11, 0x11, 0x12, 0x53, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x34, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x53, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x53, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x21, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x21, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x12, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x15, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x21, 0x12, 0x33, 0x35, 0x11, 0x13, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32, 0x11, 0x25, 0x33, 0x52, 0x11, 0x13, 0x33, 0x32, 0x11, 0x25, 0x33, 0x52, 0x11, 0x13, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x21, 0x12, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x51, 0x23, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x51, 0x12, 0x33, 0x33, 0x33, 0x21, 0x23, 0x33, 0x51, 0x12, 0x33, 0x33, 0x33, 0x21, 0x23, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x21, 0x12, 0x53, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x15, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x15, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x31, 0x11, 0x11, 0x12, 0x23, 0x33, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x12, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x11, 0x13, 0x33, 0x33, 0x21, 0x12, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x52, 0x21, 0x11, 0x11, 0x23, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x12, 0x33, 0x11, 0x13, 0x33, 0x32, 0x11, 0x11, 0x12, 0x33, 0x11, 0x13, 0x33, 0x32, 0x11, 0x11, 0x12, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x54, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x52, 0x11, 0x12, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x32, 0x11, 0x11, 0x11, 0x33, 0x11, 0x13, 0x33, 0x32, 0x11, 0x11, 0x11, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x35, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x53, 0x33, 0x33, 0x51, 0x11, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x15, 0x33, 0x33, 0x33, 0x31, 0x11, 0x33, 0x21, 0x15, 0x33, 0x33, 0x33, 0x31, 0x11, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x21, 0x12, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x34, 0x44, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x51, 0x12, 0x33, 0x33, 0x33, 0x21, 0x11, 0x33, 0x51, 0x12, 0x33, 0x33, 0x33, 0x21, 0x11, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x11, 0x53, 0x33, 0x21, 0x12, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32, 0x11, 0x25, 0x33, 0x32, 0x11, 0x11, 0x33, 0x32, 0x11, 0x25, 0x33, 0x32, 0x11, 0x11, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x13, 0x33, 0x33, 0x31, 0x11, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x45, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x32, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x21, 0x11, 0x11, 0x11, 0x12, 0x11, 0x33, 0x33, 0x21, 0x11, 0x11, 0x11, 0x12, 0x11, 0x33, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x12, 0x33, 0x11, 0x13, 0x33, 0x33, 0x32, 0x11, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x53, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x52, 0x21, 0x11, 0x25, 0x33, 0x33, 0x32, 0x11, 0x11, 0x11, 0x11, 0x11, 0x23, 0x33, 0x35, 0x22, 0x11, 0x22, 0x35, 0x12, 0x33, 0x33, 0x35, 0x22, 0x11, 0x22, 0x35, 0x12, 0x33, 0x33, 0x21, 0x11, 0x11, 0x11, 0x11, 0x12, 0x33, 0x21, 0x23, 0x33, 0x33, 0x35, 0x12, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x21, 0x10,
  0x01, 0x12, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x10,
  0x01, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x35, 0x11, 0x10,
  0x01, 0x11, 0x12, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x21, 0x11, 0x10,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00,
  0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00,
  0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00
};

static const GUI_BITMAP bmSeggerLogoBlue = {
 138, /* XSize */
  65, /* YSize */
  69, /* BytesPerLine */
   4, /* BitsPerPixel */
 acSeggerLogoBlue16,   /* Pointer to picture data (indices) */
 &PalSeggerLogoBlue16  /* Pointer to palette */
};

static const GUI_CURSOR* _apCursor[] = {
  &GUI_CursorArrowS,  &GUI_CursorArrowM,  &GUI_CursorArrowL,
  &GUI_CursorArrowLI, &GUI_CursorArrowMI, &GUI_CursorArrowSI,
  &GUI_CursorCrossS,  &GUI_CursorCrossM,  &GUI_CursorCrossL,
  &GUI_CursorCrossLI, &GUI_CursorCrossMI, &GUI_CursorCrossSI
};

static char* _aacCursorName[] = {
  "GUI_CursorArrowS",  "GUI_CursorArrowM",  "GUI_CursorArrowL",
  "GUI_CursorArrowLI", "GUI_CursorArrowMI", "GUI_CursorArrowSI",
  "GUI_CursorCrossS",  "GUI_CursorCrossM",  "GUI_CursorCrossL",
  "GUI_CursorCrossLI", "GUI_CursorCrossMI", "GUI_CursorCrossSI"
};

/*********************************************************************
*
*       static code
*
**********************************************************************
*/

/*********************************************************************
*
*       _MoveCursor
*/
static void _MoveCursor(){
  int x, y, tm, cnt = 0;
  int yStep=-1;
  int xPos,yPos;
  xPos = LCD_GetXSize() / 2 - bmSeggerLogoBlue.XSize/2;
  yPos = LCD_GetYSize() / 2 - bmSeggerLogoBlue.YSize/2+25;
  GUI_DispStringHCenterAt("Cursor shape can be changed\nand the cursor can be moved", 160,  75);
  GUI_CURSOR_Show(); 
  GUI_DrawBitmap(&bmSeggerLogoBlue, xPos, yPos );
  y = 150;
  for (x = 0; x < 320; x++) {
    if ((x % 54) == 0) {
      GUI_CURSOR_Select(_apCursor[cnt++]);
    }
    tm = GUI_GetTime();
    y += yStep;
    if(y<=80) yStep=1;
    if(y>=150) yStep=-1;
    GUI_CURSOR_SetPosition(x, y);
    while ((GUI_GetTime() - tm) < 10);
  }
  for (x = 320; x > 0; x--) {
    tm = GUI_GetTime();
    if ((x % 54) == 0) {
      GUI_CURSOR_Select(_apCursor[cnt++]);
    }
    y += yStep;
    if(y<=80) yStep=1;
    if(y>=150) yStep=-1;
    GUI_CURSOR_SetPosition(x, y);
    while ((GUI_GetTime() - tm) < 10);
  }
  GUI_CURSOR_Hide(); 
  GUI_Delay(500);
}

/*********************************************************************
*
*       _DispCursor
*/
static void _DispCursor(void) {
  int i, x, y;
  GUI_DispStringHCenterAt("Available cursors:", 160,  80);
  for (i = 0; i < 12; i++) {
    x = 160 - (_apCursor[i]->pBitmap->XSize / 2);
    y = 120 - (_apCursor[i]->pBitmap->YSize / 2);
    GUI_DrawBitmap(_apCursor[i]->pBitmap, x, y);
    GUI_DispStringHCenterAt(_aacCursorName[i], 160,145);
    GUI_Delay(750);
    GUI_ClearRect(0, 100, 319, 165);
  }
  GUI_ClearRect(0, 80, 319, 100);
  GUI_Delay(500);
}

/*********************************************************************
*
*       _DemoCursor
*/
static void _DemoCursor(void) {
  GUI_SetBkColor(GUI_BLUE);
  GUI_Clear();
  GUI_SetColor(GUI_WHITE);
  GUI_SetFont(&GUI_Font24_ASCII);
  GUI_DispStringHCenterAt("CURSOR_Sample - Sample", 160, 5);
  GUI_SetFont(&GUI_Font8x16);
  while (1) {
    _DispCursor();
    GUI_ClearRect(0, 60, 319, 200);
    _MoveCursor();
    GUI_ClearRect(0, 60, 319, 200);
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
  GUI_Init();
  _DemoCursor();
}

/*************************** End of file ****************************/

