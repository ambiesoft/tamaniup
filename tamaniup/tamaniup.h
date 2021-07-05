
// tamaniup.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CtamaniupApp:
// See tamaniup.cpp for the implementation of this class
//

class CtamaniupApp : public CWinApp
{
public:
	CtamaniupApp();

// Overrides
public:
	virtual BOOL InitInstance();
	std::wstring GetBarnFolder() const;
private:
	BOOL PreInitInstance();
// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CtamaniupApp theApp;
