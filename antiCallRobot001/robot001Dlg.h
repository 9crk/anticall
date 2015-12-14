
// robot001Dlg.h : 头文件
//

#pragma once


// CRobotDlg 对话框
class CRobotDlg : public CDialogEx
{
// 构造
public:
	CRobotDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ANTICALLROBOT001_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUserThreadend(WPARAM wParam, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedMfcbutton1();
	afx_msg void OnTcnSelchangeTab2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedGroup2();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton21();
};
