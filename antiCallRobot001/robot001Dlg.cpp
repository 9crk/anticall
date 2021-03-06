
// robot001Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "antiCallRobot001.h"
#include "robot001Dlg.h"
#include "afxdialogex.h"

//zhouhua
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

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
	ON_MESSAGE(WM_NC, OnUserThreadend)
	ON_BN_CLICKED(IDOK, &CRobotDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CRobotDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK6, &CRobotDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_BUTTON12, &CRobotDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_CHECK5, &CRobotDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_BUTTON1, &CRobotDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRobotDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CRobotDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_CHECK10, &CRobotDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_GROUP2, &CRobotDlg::OnBnClickedGroup2)
	ON_BN_CLICKED(IDC_BUTTON7, &CRobotDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CRobotDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON20, &CRobotDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON11, &CRobotDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON9, &CRobotDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON17, &CRobotDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON6, &CRobotDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CRobotDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CRobotDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON13, &CRobotDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON22, &CRobotDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON19, &CRobotDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON15, &CRobotDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CRobotDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON14, &CRobotDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON18, &CRobotDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON21, &CRobotDlg::OnBnClickedButton21)
END_MESSAGE_MAP()


// CRobotDlg 消息处理程序
//zhouhua
NOTIFYICONDATA nc;//类成员变量
//zhouhua end
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
	
	//创建托盘图标
	
	nc.cbSize = sizeof(NOTIFYICONDATA);
	nc.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	nc.hWnd = m_hWnd;
//	strcpy(nc.szTip, "CatchIP");
	nc.uCallbackMessage = WM_NC;
	nc.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nc.uID = IDC_NC;
	Shell_NotifyIcon(NIM_ADD, &nc);

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
	Shell_NotifyIcon(NIM_DELETE, &nc);
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


void CRobotDlg::OnBnClickedCheck10()
{
	// TODO:  在此添加控件通知处理程序代码
	this->GetDlgItem(IDC_GROUP1)->EnableWindow(0);
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK10)){
		this->GetDlgItem(IDC_GROUP1)->EnableWindow(0);
	}
}


void CRobotDlg::OnBnClickedGroup2()
{
	// TODO:  在此添加控件通知处理程序代码
}
/******************/
//zhouhua
/*****************/
CString helloVoiceFile;
CString questionVoiceFile;
CString recallVoiceFile;


LRESULT CRobotDlg::OnUserThreadend(WPARAM wParam, LPARAM lParam)
{
	if (lParam == WM_LBUTTONDOWN)
	{ //鼠标双击时主窗口出现
			this->ShowWindow(SW_SHOW);
	}
	return 0;
}
void CRobotDlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		helloVoiceFile = dlg.GetPathName(); //文件名保存在了FilePathName里
	}
	else
	{
		return;
	}
}


void CRobotDlg::OnBnClickedButton8()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		questionVoiceFile = dlg.GetPathName(); //文件名保存在了FilePathName里
	}
	else
	{
		return;
	}
}


void CRobotDlg::OnBnClickedButton20()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		recallVoiceFile = dlg.GetPathName(); //文件名保存在了FilePathName里
	}
	else
	{
		return;
	}
}


void CRobotDlg::OnBnClickedButton11()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\推销或辱骂关键词.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton9()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\问题答案.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton17()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\联系人.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(L"未启用，敬请期待！请访问http://www.9crk.com/antiCallRobot",L"使用教程");
}


void CRobotDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\骚扰短信.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\正常短信.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton13()
{
	// TODO:  在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}


void CRobotDlg::OnBnClickedButton22()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\短信安全词.txt", L"", L"", SW_SHOW);
}

int bRecord = 0;

#define FRAGMENT_NUM 4
#define FRAGMENT_SIZE 1024

HWAVEIN hWaveIn;//波形音频数据格式Wave_audio数据格式
WAVEFORMATEX wavform;
static WAVEHDR wh[FRAGMENT_NUM];
FILE* fp=NULL;
int wav_length;
CString gWavName;

#define WAVE_HEADER_SIZE 44
int write_wav_head(WAVEFORMATEX *wf, char **out_buffer)

{
	char *buffer;
	int *int_tmp, pos = 0;

	buffer = (char*)malloc(44);
	if (buffer == NULL)
		return -1;
	memcpy(buffer, "RIFF", 4);
	pos = 4;

	int_tmp = (int*)(buffer + pos);
	*int_tmp = 0;// WAVE_HEADER_SIZE + 999999999 - 8;/**//*波形块的大小（档案大小减8）*/
	pos += 4;

	memcpy(buffer + pos, "WAVEfmt ", 8);
	pos += 8;

	int_tmp = (int*)(buffer + pos);
	*int_tmp = 16;
	pos += 4;

	/**//*格式信息*/
	memcpy(buffer + pos, wf, 16);
	pos += 16;

	memcpy(buffer + pos, "data", 4);
	pos += 4;
	int_tmp = (int*)(buffer + pos);

	*out_buffer = buffer;
	return 0;
}
void finish_wav(FILE* fp,int length)
{
	int len = WAVE_HEADER_SIZE + length - 8;
	fseek(fp, 4, 0);
	fwrite((char*)&len, 4, 1, fp);
}
void wideChar2Char(CString str, char**autoMallocStr)
{
	int len = WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), NULL, 0, NULL, NULL);
	char * pFileName = (char*)malloc(len + 1);   //以字节为单位
	WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), pFileName, len, NULL, NULL);
	pFileName[len] = '\0';   //多字节字符以'/0'结束
	*autoMallocStr = pFileName;
}
void CALLBACK waveInProc(HWAVEIN hwi, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
{
 LPWAVEHDR pwh = (LPWAVEHDR)dwParam1;
 if (WIM_DATA == uMsg)
 {
	 fwrite(pwh->lpData, pwh->dwBytesRecorded,1,fp);	 
	 wav_length += pwh->dwBytesRecorded;
	 waveInAddBuffer(hwi, pwh, sizeof(WAVEHDR));
 }
 
}
void CRobotDlg::OnBnClickedButton19()
{
	// TODO:  在此添加控件通知处理程序代码
	if (bRecord == 0){
		
		this->GetDlgItemTextW(IDC_EDIT3, gWavName);
		if (gWavName.IsEmpty()){
			//CTime m_time;
			//m_time = CTime::GetCurrentTime();             //获取当前时间日期  
			//gWavName = m_time.Format(_T("%Y%m%d%H%M%S.wav"));
			gWavName = L"未命名.wav";
			this->SetDlgItemTextW(IDC_EDIT3, gWavName);
		}
		bRecord = 1;
		this->SetDlgItemTextW(IDC_BUTTON19, L"停止");

		int nReturn = waveInGetNumDevs();
		//CString msg;
		//msg.Format(L"%d", nReturn);
		//MessageBox(msg);
		if (nReturn < 1){
			MessageBox(L"找不到可用录音设备");
			return;
		}
		wavform.wFormatTag = WAVE_FORMAT_PCM;  //WAVE_FORMAT_PCM即脉冲编码
		wavform.nChannels = 2;  // 声道
		wavform.nSamplesPerSec = 8000; // 采样频率
		wavform.nAvgBytesPerSec = 8000 * 16 * 2 / 8;  // 每秒数据量
		wavform.nBlockAlign = 4;
		wavform.wBitsPerSample = 16; // 样本大小
		wavform.cbSize = 0;  //大小，以字节，附加额外的格式信息WAVEFORMATEX结构

		//打开录音设备函数
		waveInOpen(&hWaveIn, WAVE_MAPPER, &wavform, (DWORD_PTR)waveInProc, 0, CALLBACK_FUNCTION);
		
		for (int i = 0; i<FRAGMENT_NUM; i++)
		{
			wh[i].lpData = new char[FRAGMENT_SIZE];
			wh[i].dwBufferLength = FRAGMENT_SIZE;
			wh[i].dwBytesRecorded = 0;
			wh[i].dwUser = NULL;
			wh[i].dwFlags = 0;
			wh[i].dwLoops = 1;
			wh[i].lpNext = NULL;
			wh[i].reserved = 0;

			//为录音设备准备缓存函数：
			//MMRESULT waveInPrepareHeader(  HWAVEIN hwi,  LPWAVEHDR pwh, UINT bwh );
			waveInPrepareHeader(hWaveIn, &wh[i], sizeof(WAVEHDR));

			//给输入设备增加一个缓存：
			//MMRESULT waveInAddBuffer(  HWAVEIN hwi, LPWAVEHDR pwh, UINT cbwh );
			waveInAddBuffer(hWaveIn, &wh[i], sizeof(WAVEHDR));
		}
		waveInStart(hWaveIn);
		
		char* fname;
		wideChar2Char(gWavName, &fname);
		fp = fopen(fname, "wb");
		free(fname);

		char* buff=NULL;
		write_wav_head(&wavform, &buff);
		fwrite(buff,44,1,fp);
		free(buff);
		
		wav_length = 0;
	}
	else{
		bRecord = 0;
		
		waveInStop(hWaveIn);this->SetDlgItemTextW(IDC_BUTTON19, L"录音");
		//waveInReset(hWaveIn);//停止录音
		
		for (int i = 0; i<FRAGMENT_NUM; i++)
		{
			waveInUnprepareHeader(hWaveIn, &wh[i], sizeof(WAVEHDR));
			delete wh[i].lpData;
		}
		waveInClose(hWaveIn);
		finish_wav(fp, wav_length);
		fclose(fp);
	}
}


void CRobotDlg::OnBnClickedButton15()
{
	sndPlaySound(L"未命名.wav", SND_ASYNC);
	//sndPlaySound(gWavName, SND_ASYNC);
	// TODO:  在此添加控件通知处理程序代码
	//PlaySound(_T("C:\\WINDOWS\\Media\\Windows 关机.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	//sndPlaySound(_T("C:\\WINDOWS\\Media\\Windows 硬件插入.wav"), SND_ASYNC);
}


void CRobotDlg::OnBnClickedButton16()
{
	// TODO:  在此添加控件通知处理程序代码
	CString wavNameNow;
	this->GetDlgItemTextW(IDC_EDIT3, wavNameNow);
	MoveFile(gWavName,wavNameNow);
	MessageBox(L"保存成功！", L"防骚扰助手");
}


void CRobotDlg::OnBnClickedButton23()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\辱骂关键词.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton14()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE, //TRUE为OPEN对话框，FALSE为SAVE AS对话框
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		gWavName = dlg.GetPathName(); //文件名保存在了FilePathName里
		this->SetDlgItemTextW(IDC_EDIT3, gWavName);
	}
	else
	{
		return;
	}
}

int bRunning = 0;
void CRobotDlg::OnBnClickedButton18()
{
	// TODO:  在此添加控件通知处理程序代码
	if (bRunning == 0){
		bRunning = 1;
		this->SetDlgItemTextW(IDC_BUTTON18, L"停止运行");
	}
	else{
		bRunning = 0;
		this->SetDlgItemTextW(IDC_BUTTON18, L"开始运行");
	}
}


void CRobotDlg::OnBnClickedButton21()
{
	// TODO:  在此添加控件通知处理程序代码

}
