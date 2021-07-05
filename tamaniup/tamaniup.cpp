
// tamaniup.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"


#include "framework.h"
#include "tamaniup.h"
#include "tamaniupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Ambiesoft;
using namespace Ambiesoft::stdosd;
using namespace std;

// CtamaniupApp

BEGIN_MESSAGE_MAP(CtamaniupApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtamaniupApp construction
CtamaniupApp::CtamaniupApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CtamaniupApp object
CtamaniupApp theApp;


// CtamaniupApp initialization

BOOL CtamaniupApp::PreInitInstance()
{
	TCHAR szT[MAX_PATH];
	if (!GetFolderIniDirEx(
		m_hInstance,
		szT,
		_countof(szT),
		L"Ambiesoft",
		AfxGetAppName()))
	{
		// I18N(_T("%s is not found. Exiting.")));
		AfxMessageBox(L"Failed to get ini folder.");
		return FALSE;
	}

	if (!PathIsDirectory(szT))
	{
		if (IDYES != AfxMessageBox(
			stdFormat(I18N(L"'%s' is not a directory. Do you want to create it now?"), szT).c_str(),
			MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2))
		{
			return FALSE;
		}
		CreateCompleteDirectory(szT);
		if (!PathIsDirectory(szT))
		{
			AfxMessageBox(I18N(L"Failed to create directory."));
			return FALSE;
		}
	}
	wstring strT = stdCombinePath(szT, (LPCTSTR)(CString() + AfxGetAppName() + _T(".ini")));

	free((void*)m_pszProfileName);
	m_pszProfileName = _tcsdup(strT.c_str());

	return TRUE;
}
BOOL CtamaniupApp::InitInstance()
{
	if (!PreInitInstance())
		return FALSE;

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	CtamaniupDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
std::wstring CtamaniupApp::GetBarnFolder() const
{
	string barnFolder;
	Profile::GetString(SECTION_OPTION, KEY_BARNFOLDER, "", barnFolder, m_pszProfileName);
	if (barnFolder.empty())
	{
		return stdCombinePath(
			stdGetParentDirectory(stdGetModuleFileName()).c_str(), 
			STR_BARNDIRECTORYNAME);
	}
	return toStdWstringFromUtf8(barnFolder);
}
