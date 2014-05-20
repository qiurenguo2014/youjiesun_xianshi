/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.20                          *
*        Compiled Mar 19 2013, 15:01:00                              *
*        (c) 2013 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/

// USER START (Optionally insert additional includes)
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0        (GUI_ID_USER + 0x41)
#define ID_BUTTON_0        (GUI_ID_USER + 0x4B)
#define ID_BUTTON_1        (GUI_ID_USER + 0x4C)
#define ID_TEXT_0        (GUI_ID_USER + 0x4D)
#define ID_TEXT_1        (GUI_ID_USER + 0x4E)
#define ID_TEXT_2        (GUI_ID_USER + 0x4F)
#define ID_TEXT_3        (GUI_ID_USER + 0x50)
#define ID_TEXT_4        (GUI_ID_USER + 0x51)
#define ID_TEXT_5        (GUI_ID_USER + 0x52)
#define ID_TEXT_6        (GUI_ID_USER + 0x53)
#define ID_TEXT_7        (GUI_ID_USER + 0x54)
#define ID_TEXT_8        (GUI_ID_USER + 0x55)
#define ID_TEXT_9        (GUI_ID_USER + 0x56)
#define ID_TEXT_10        (GUI_ID_USER + 0x57)
#define ID_TEXT_11        (GUI_ID_USER + 0x58)
#define ID_TEXT_12        (GUI_ID_USER + 0x59)
#define ID_TEXT_13        (GUI_ID_USER + 0x5A)
#define ID_TEXT_14        (GUI_ID_USER + 0x5B)
#define ID_TEXT_15        (GUI_ID_USER + 0x5C)


// USER START (Optionally insert additional defines)
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontkaiti16;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontweiruanyahei20;
// USER END

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/

// USER START (Optionally insert additional static data)
// USER END

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "historydataWindow", ID_WINDOW_0, 0, 0, 240, 128, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "上一个", ID_BUTTON_0, 190, 15, 48, 32, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "下一个", ID_BUTTON_1, 190, 55, 48, 32, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "NO.00", ID_TEXT_0, 190, 95, 50, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "介 损 tgδ=", ID_TEXT_1, 5, 0, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "电  容  量=", ID_TEXT_2, 5, 16, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "交流  电压=", ID_TEXT_3, 5, 32, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "介电  常数=", ID_TEXT_4, 5, 48, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "直流  电压=", ID_TEXT_5, 5, 64, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "体积电阻率=", ID_TEXT_6, 5, 80, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "油      温=", ID_TEXT_7, 5, 96, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_8, 96, 0, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_9, 96, 16, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_10, 96, 32, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_11, 96, 48, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_12, 96, 64, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_13, 96, 80, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_14, 96, 96, 88, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "2014/05/08 12:00", ID_TEXT_15, 96, 112, 88, 16, 0, 0x0, 0 },
  // USER START (Optionally insert additional widgets)
  // USER END
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/

// USER START (Optionally insert additional static code)
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
  // USER START (Optionally insert additional variables)
  // USER END

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    //
    // Initialization of 'NO.00'
    //
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    // USER START (Optionally insert additional code for further widget initialization)
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
	BUTTON_SetFont (hItem, &GUI_Fontweiruanyahei20);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
	BUTTON_SetFont (hItem, &GUI_Fontweiruanyahei20);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_8);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_9);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_10);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_11);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_12);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_13);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_14);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
	hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_15);
	TEXT_SetFont (hItem, &GUI_Fontkaiti16);
    // USER END
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by '上一个'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by '下一个'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      case WM_NOTIFICATION_RELEASED:
        // USER START (Optionally insert code for reacting on notification message)
        // USER END
        break;
      // USER START (Optionally insert additional code for further notification handling)
      // USER END
      }
      break;
    // USER START (Optionally insert additional code for further Ids)
    // USER END
    }
    break;
  // USER START (Optionally insert additional message handling)
	case WM_KEY:
	WM_HideWindow(pMsg->hWin);
	Mainwin_SetFocus ();
	break;
  // USER END
  default:
    WM_DefaultProc(pMsg);
    break;
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
*       CreatehistorydataWindow
*/
WM_HWIN CreatehistorydataWindow(void);
WM_HWIN CreatehistorydataWindow(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
