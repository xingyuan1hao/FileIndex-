// FileTreeDlg.h : header file
//

#if !defined(AFX_FILETREEDLG_H__BB3E545E_C6D7_4412_BC60_C99459B61554__INCLUDED_)
#define AFX_FILETREEDLG_H__BB3E545E_C6D7_4412_BC60_C99459B61554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileTreeDlg dialog

class CFileTreeDlg : public CDialog
{
// Construction
public:
	CFileTreeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileTreeDlg)
	enum { IDD = IDD_FILETREE_DIALOG };
	CTreeCtrl	m_FileTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void BrowseFile(int CallNum,CString strFile);
	HICON m_hIcon;
	CImageList m_iImageList;//Õº±Í¡¥
	HTREEITEM strRoot;
	HTREEITEM strHTFir;
	HTREEITEM strHTSec;
	HTREEITEM strHtThi;
	HTREEITEM strHtFor;
	HTREEITEM strHtFif;
	HTREEITEM strHtEnd;
	// Generated message map functions
	//{{AFX_MSG(CFileTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILETREEDLG_H__BB3E545E_C6D7_4412_BC60_C99459B61554__INCLUDED_)
