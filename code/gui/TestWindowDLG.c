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
#include "..\app\flashdata.h"
#include "..\app\commun.h"
// USER END

#include "DIALOG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_WINDOW_0  (GUI_ID_USER + 0x26)
#define ID_BUTTON_0  (GUI_ID_USER + 0x30)
#define ID_BUTTON_1  (GUI_ID_USER + 0x31)
#define ID_BUTTON_2  (GUI_ID_USER + 0x32)
#define ID_BUTTON_3  (GUI_ID_USER + 0x33)
#define ID_BUTTON_4  (GUI_ID_USER + 0x34)
#define ID_BUTTON_5  (GUI_ID_USER + 0x35)
#define ID_TEXT_0  (GUI_ID_USER + 0x3B)
#define ID_TEXT_1  (GUI_ID_USER + 0x3C)
#define ID_TEXT_2  (GUI_ID_USER + 0x3D)
#define ID_TEXT_3  (GUI_ID_USER + 0x3E)
#define ID_TEXT_4  (GUI_ID_USER + 0x3F)
#define ID_TEXT_5  (GUI_ID_USER + 0x40)
#define ID_TEXT_6  (GUI_ID_USER + 0x41)

#define ID_TEXT_7 (GUI_ID_USER + 0x43)
#define ID_PROGBAR_0 (GUI_ID_USER + 0x44)
// USER START (Optionally insert additional defines)
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontweiruanyahei20;
extern GUI_CONST_STORAGE GUI_FONT GUI_Fontkaiti16;
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
  { WINDOW_CreateIndirect, "TestWindow", ID_WINDOW_0, 0, 0, 240, 128, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "启动测试", ID_BUTTON_0, 160, 50, 60, 40, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "介质损耗", ID_BUTTON_1, 5, 5, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "交流频率", ID_BUTTON_2, 5, 30, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "体积电阻", ID_BUTTON_3, 5, 55, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "加热启动", ID_BUTTON_4, 5, 80, 80, 20, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "测试方式", ID_BUTTON_5, 5, 105, 80, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 90, 5, 40, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_1, 90, 30, 120, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_2, 90, 55, 40, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_3, 90, 80, 40, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_4, 90, 105, 40, 20, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_5, 140, 96, 100, 32, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "长按3秒测试", ID_TEXT_6, 144, 0, 128, 16, 0, 0x0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_7, 5+65, 30+36, 100, 32, 0, 0x0, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 5+65, 5+36, 100, 20, 0, 0x0, 0 },
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
#define WM_NOTIFICATION_TEST3S WM_NOTIFICATION_USER+0x01 //鍚姩娴嬭瘯
int TestWin_GetTestNotifi (void)
{
	return WM_NOTIFICATION_TEST3S;
}
WM_HWIN hItem_pg;
void TestWin_SetProgbar(int v)
{
	static int vb=0;
	if(vb < v){
		for(;vb<=v;vb++){
			PROGBAR_SetValue (hItem_pg,vb);
			WM_Exec();
			T6963_ScreenUpdata ();
		}
	}else{
		vb = v;
		PROGBAR_SetValue (hItem_pg,vb);
		WM_Exec();
		T6963_ScreenUpdata ();
	}	

}
// USER END

/*********************************************************************
*
*       _cbDialog
*/
static void _cbDialog(WM_MESSAGE * pMsg) {
  int NCode;
  int Id;
  // USER START (Optionally insert additional variables)
	WM_HWIN hItem;
	char str[20];
  // USER END

  switch (pMsg->MsgId) {
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 
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
      case WM_NOTIFICATION_TEST3S:
		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
		WM_ShowWindow (hItem);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
		WM_ShowWindow (hItem);
		GUI_ClearKeyBuffer ();
		WM_Exec();
		T6963_ScreenUpdata ();
		SIGOP_StartTest ();
			
		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
		WM_HideWindow (hItem);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
		WM_HideWindow (hItem);
		WM_Exec();
		T6963_ScreenUpdata ();
		 break;
	  // USER END
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		FD_Inc_jiezhisunhao ();
		FD_GetHisdataStr_jiezhisunhao (str);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetText(hItem, str);
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
    case ID_BUTTON_2: // Notifications sent by 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		FD_Inc_jiaoliupinlv ();
		FD_GetHisdataStr_jiaoliupinlv (str);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, str);
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
    case ID_BUTTON_3: // Notifications sent by 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		FD_Inc_tijidianzu ();
		FD_GetHisdataStr_tijidianzu (str);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
		TEXT_SetText(hItem, str);
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
    case ID_BUTTON_4: // Notifications sent by 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		FD_Inc_jiareqidong ();
		FD_GetHisdataStr_jiareqidong (str);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
		TEXT_SetText(hItem, str);
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
    case ID_BUTTON_5: // Notifications sent by 
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        // USER START (Optionally insert code for reacting on notification message)
		FD_Inc_ceshifangsi ();
		FD_GetHisdataStr_ceshifangsi (str);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
		TEXT_SetText(hItem, str);
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
	case WM_INIT_DIALOG:
    // USER START (Optionally insert additional code for further widget initialization)
	//_cb_DialogInit(pMsg);	
		GUI_UC_SetEncodeUTF8();
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetFont(hItem,&GUI_Fontkaiti16);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
		BUTTON_SetFont(hItem,&GUI_Fontweiruanyahei20);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
		BUTTON_SetFont(hItem,&GUI_Fontweiruanyahei20);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_2);
		BUTTON_SetFont(hItem,&GUI_Fontweiruanyahei20);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_3);
		BUTTON_SetFont(hItem,&GUI_Fontweiruanyahei20);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_4);
		BUTTON_SetFont(hItem,&GUI_Fontweiruanyahei20);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_5);
		BUTTON_SetFont(hItem,&GUI_Fontweiruanyahei20);
		FD_GetHistoryData ();
	  
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		FD_GetHisdataStr_jiezhisunhao (str);
		TEXT_SetText(hItem, str);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		FD_GetHisdataStr_jiaoliupinlv (str);
		TEXT_SetText(hItem, str);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		FD_GetHisdataStr_tijidianzu (str);
		TEXT_SetText(hItem, str);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_3);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		FD_GetHisdataStr_jiareqidong (str);
		TEXT_SetText(hItem, str);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_4);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		FD_GetHisdataStr_ceshifangsi (str);
		TEXT_SetText(hItem, str);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_5);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		TEXT_SetTextAlign(hItem, GUI_TA_CENTER);
		FD_GetHisdataStr_kongbeidianrong (str);
		TEXT_SetText(hItem, str);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_6);
		TEXT_SetFont (hItem, &GUI_Fontkaiti16);
		
		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_7);
		WM_HideWindow (hItem);
		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
		hItem_pg = hItem;
		WM_HideWindow (hItem);
    // USER END
    break;
	case WM_KEY:
		WM_DeleteWindow(pMsg->hWin);
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
*       CreateTestWindow
*/
WM_HWIN CreateTestWindow(void);
WM_HWIN CreateTestWindow(void) {
  WM_HWIN hWin;
  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

// USER START (Optionally insert additional public code)
// USER END

/*************************** End of file ****************************/
