
// antiCallRobot001.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#define WM_NC WM_USER+10 
#define IDC_NC 1002 

// CRobotApp: 
// �йش����ʵ�֣������ antiCallRobot001.cpp
//

class CRobotApp : public CWinApp
{
public:
	CRobotApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	
};

extern CRobotApp theApp;