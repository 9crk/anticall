
// robot001Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "antiCallRobot001.h"
#include "robot001Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRobotDlg �Ի���



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


// CRobotDlg ��Ϣ�������

BOOL CRobotDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//zhouhua
	OnBnClickedCheck5();
	OnBnClickedCheck6();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRobotDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRobotDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRobotDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CRobotDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CRobotDlg::OnBnClickedMfcbutton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRobotDlg::OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CRobotDlg::OnBnClickedCheck6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK6)){
		this->GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	}
	else{
		this->GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	}
}


void CRobotDlg::OnBnClickedButton12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}


void CRobotDlg::OnBnClickedCheck5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\ɧ�ŵ绰.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\�����绰.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\�������д�.txt", L"", L"", SW_SHOW);
}
