// ExStudPE插件示例程式.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "ExStudPE插件示例程式.h"
#include "../include/plugindef_sdk.h"


WNDPROC g_pfnMainWndProc = NULL;
BOOL g_blnIsLoaded = FALSE;

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			{
				g_pfnMainWndProc = NULL;
			}break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}


LRESULT CALLBACK MainWndProc_NewHooked(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if(uMsg==WM_COMMAND && LOWORD(wParam)==9001)
	{
		//
		// 彈出一個信息框而已
		//
		MessageBox(hWnd,_T("你選擇了插件新添加的菜單項!"),_T("^_^!"),MB_OK);
		return TRUE;
	}
	else if(uMsg == WM_CLOSE)
	{
		//
		// 還原窗口處理函數
		//
		SetWindowLong(hWnd,GWL_WNDPROC,(LONG)g_pfnMainWndProc);
		PostMessage(hWnd,WM_CLOSE,0,0);
		return TRUE;
	}
	return g_pfnMainWndProc(hWnd,uMsg,wParam,lParam);
}

extern "C" EXSTUDPE_API BOOL PLUGIN_MAIN_CALLBACK PluginMain(PPLUGIN_PARAM_STRUCT pParams)
{
	switch(pParams->dwMessage)
	{
	case WM_CREATE:
		//
		// 設置僅允許加載一次(重複加載此類插件會導致災難性的錯誤發生)
		//
		if(g_blnIsLoaded) 
			return FALSE;
		g_blnIsLoaded = TRUE;
		// 
		// 設置處理函數
		//
		g_pfnMainWndProc = (WNDPROC)SetWindowLong(pParams->hMainFrame,GWL_WNDPROC,(LONG)MainWndProc_NewHooked);
		//
		// 此處必須返回TRUE
		//
		return TRUE;
		break;
	case WM_CLOSE:
		break;
	case WM_NOTIFY:
		break;
	case WM_CONTEXTMENU:
		if(pParams->v143.hContextWnd==pParams->hTreeView
			|| pParams->v143.hContextWnd==pParams->hDeASMList
			|| pParams->v143.hContextWnd==pParams->hMainFrame)
		{
			//
			// 新添加右鍵菜單
			//
			AppendMenu(pParams->v143.hContextMenu,MF_SEPARATOR,0,0);
			AppendMenu(pParams->v143.hContextMenu,MF_STRING,9001,_T("這是示例插件新添加的菜單! ^_^!"));
		}
		break;
	default:
		break;
	}
	return FALSE;
}

