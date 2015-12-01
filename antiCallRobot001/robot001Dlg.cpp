
// robot001Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "antiCallRobot001.h"
#include "robot001Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRobotDlg 对话框



CRobotDlg::CRobotDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRobotDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRobotDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRobotDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CRobotDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CRobotDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK6, &CRobotDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_BUTTON12, &CRobotDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_CHECK5, &CRobotDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_BUTTON1, &CRobotDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRobotDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CRobotDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CRobotDlg 消息处理程序

BOOL CRobotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//zhouhua
	OnBnClickedCheck5();
	OnBnClickedCheck6();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRobotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRobotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRobotDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CRobotDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CRobotDlg::OnBnClickedMfcbutton1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CRobotDlg::OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void CRobotDlg::OnBnClickedCheck6()
{
	// TODO:  在此添加控件通知处理程序代码
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK6)){
		this->GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	}
	else{
		this->GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	}
}


void CRobotDlg::OnBnClickedButton12()
{
	// TODO:  在此添加控件通知处理程序代码
	OnOK();
}


void CRobotDlg::OnBnClickedCheck5()
{
	// TODO:  在此添加控件通知处理程序代码
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK5)){
		this->GetDlgItem(IDC_BUTTON8)->EnableWindow(1);
		this->GetDlgItem(IDC_BUTTON9)->EnableWindow(1);
	}
	else{
		this->GetDlgItem(IDC_BUTTON8)->EnableWindow(0);
		this->GetDlgItem(IDC_BUTTON9)->EnableWindow(0);
	}

}


void CRobotDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\骚扰电话.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\正常电话.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\短信敏感词.txt", L"", L"", SW_SHOW);
}
