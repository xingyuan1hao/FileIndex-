// FileTree.h : main header file for the FILETREE application
//

#if !defined(AFX_FILETREE_H__935F1121_9B4C_40C7_A3A5_1188E18A14EE__INCLUDED_)
#define AFX_FILETREE_H__935F1121_9B4C_40C7_A3A5_1188E18A14EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileTreeApp:
// See FileTree.cpp for the implementation of this class
//

class CFileTreeApp : public CWinApp
{
public:
	CFileTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileTreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETREE_H__935F1121_9B4C_40C7_A3A5_1188E18A14EE__INCLUDED_)
