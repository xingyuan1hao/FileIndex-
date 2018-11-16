// FileTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileTree.h"
#include "FileTreeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileTreeDlg dialog

CFileTreeDlg::CFileTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileTreeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileTreeDlg)
	DDX_Control(pDX, IDC_FILETREE, m_FileTree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CFileTreeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileTreeDlg message handlers

BOOL CFileTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	m_iImageList.Create(24, 24, TRUE,1, 0);
	HICON hIcon = NULL;
	hIcon = (HICON)::LoadImage(::AfxGetInstanceHandle(), 
		MAKEINTRESOURCE(IDI_KEBIAO), IMAGE_ICON, 24, 24, 0);
	m_iImageList.Add(hIcon);
	m_FileTree.SetImageList ( &m_iImageList,TVSIL_NORMAL );
	BrowseFile(0,"成绩表");//遍历"成绩表"文件夹内的所有目录
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFileTreeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFileTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileTreeDlg::BrowseFile(int CallNum, CString strFile)
{
	CallNum++;
	CFileFind ff;
	CString szDir = strFile;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			//如果是一个子目录，用递归继续往深一层找
			CString strPath = ff.GetFilePath();
			CString strTitle = ff.GetFileTitle();
			int i =0;
			switch(CallNum)
			{
				case 1:
					strHTFir = m_FileTree.InsertItem(strTitle,0,0,NULL);						
					break;
				case 2:
					strHTSec = m_FileTree.InsertItem(strTitle,0,0,strHTFir);											
					break;
				case 3:
					strHtThi = m_FileTree.InsertItem(strTitle,0,0,strHTSec);					
					break;
				case 4:
					strHtFor = m_FileTree.InsertItem(strTitle,0,0,strHtThi);					
					break;
				default:
					strHtFif = m_FileTree.InsertItem(strTitle,0,0,strHtFor);
					break;					
			}
			BrowseFile(CallNum,strPath);
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//显示当前访问的文件
			CString strPath;
			CString strTitle;
			strPath = ff.GetFilePath();
			strTitle = ff.GetFileTitle();
			switch(CallNum)
			{
			case 1:
				strRoot = m_FileTree.InsertItem(strTitle,0,0,NULL);
				break;
			case 2:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHTFir);
				break;
			case 3:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHTSec);				
				break;
			case 4:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHtThi);
				break;
			case 5:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHtFor);
				break;
			default:
				strHtEnd = m_FileTree.InsertItem(strTitle,0,0,strHtFif);
				break;
			}
		}
	}
	ff.Close();//关闭
}

