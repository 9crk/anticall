
// robot001Dlg.cpp : ʵ���ļ�
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


// CRobotDlg ��Ϣ�������
//zhouhua
NOTIFYICONDATA nc;//���Ա����
//zhouhua end
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
	
	//��������ͼ��
	
	nc.cbSize = sizeof(NOTIFYICONDATA);
	nc.hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	nc.hWnd = m_hWnd;
//	strcpy(nc.szTip, "CatchIP");
	nc.uCallbackMessage = WM_NC;
	nc.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nc.uID = IDC_NC;
	Shell_NotifyIcon(NIM_ADD, &nc);

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
	Shell_NotifyIcon(NIM_DELETE, &nc);
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


void CRobotDlg::OnBnClickedCheck10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->GetDlgItem(IDC_GROUP1)->EnableWindow(0);
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK10)){
		this->GetDlgItem(IDC_GROUP1)->EnableWindow(0);
	}
}


void CRobotDlg::OnBnClickedGroup2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	{ //���˫��ʱ�����ڳ���
			this->ShowWindow(SW_SHOW);
	}
	return 0;
}
void CRobotDlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		helloVoiceFile = dlg.GetPathName(); //�ļ�����������FilePathName��
	}
	else
	{
		return;
	}
}


void CRobotDlg::OnBnClickedButton8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		questionVoiceFile = dlg.GetPathName(); //�ļ�����������FilePathName��
	}
	else
	{
		return;
	}
}


void CRobotDlg::OnBnClickedButton20()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		recallVoiceFile = dlg.GetPathName(); //�ļ�����������FilePathName��
	}
	else
	{
		return;
	}
}


void CRobotDlg::OnBnClickedButton11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\����������ؼ���.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\�����.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton17()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\��ϵ��.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(L"δ���ã������ڴ��������http://www.9crk.com/antiCallRobot",L"ʹ�ý̳�");
}


void CRobotDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\ɧ�Ŷ���.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\��������.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}


void CRobotDlg::OnBnClickedButton22()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\���Ű�ȫ��.txt", L"", L"", SW_SHOW);
}

int bRecord = 0;

#define FRAGMENT_NUM 4
#define FRAGMENT_SIZE 1024

HWAVEIN hWaveIn;//������Ƶ���ݸ�ʽWave_audio���ݸ�ʽ
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
	*int_tmp = 0;// WAVE_HEADER_SIZE + 999999999 - 8;/**//*���ο�Ĵ�С��������С��8��*/
	pos += 4;

	memcpy(buffer + pos, "WAVEfmt ", 8);
	pos += 8;

	int_tmp = (int*)(buffer + pos);
	*int_tmp = 16;
	pos += 4;

	/**//*��ʽ��Ϣ*/
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
	char * pFileName = (char*)malloc(len + 1);   //���ֽ�Ϊ��λ
	WideCharToMultiByte(CP_ACP, 0, str, str.GetLength(), pFileName, len, NULL, NULL);
	pFileName[len] = '\0';   //���ֽ��ַ���'/0'����
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (bRecord == 0){
		
		this->GetDlgItemTextW(IDC_EDIT3, gWavName);
		if (gWavName.IsEmpty()){
			//CTime m_time;
			//m_time = CTime::GetCurrentTime();             //��ȡ��ǰʱ������  
			//gWavName = m_time.Format(_T("%Y%m%d%H%M%S.wav"));
			gWavName = L"δ����.wav";
			this->SetDlgItemTextW(IDC_EDIT3, gWavName);
		}
		bRecord = 1;
		this->SetDlgItemTextW(IDC_BUTTON19, L"ֹͣ");

		int nReturn = waveInGetNumDevs();
		//CString msg;
		//msg.Format(L"%d", nReturn);
		//MessageBox(msg);
		if (nReturn < 1){
			MessageBox(L"�Ҳ�������¼���豸");
			return;
		}
		wavform.wFormatTag = WAVE_FORMAT_PCM;  //WAVE_FORMAT_PCM���������
		wavform.nChannels = 2;  // ����
		wavform.nSamplesPerSec = 8000; // ����Ƶ��
		wavform.nAvgBytesPerSec = 8000 * 16 * 2 / 8;  // ÿ��������
		wavform.nBlockAlign = 4;
		wavform.wBitsPerSample = 16; // ������С
		wavform.cbSize = 0;  //��С�����ֽڣ����Ӷ���ĸ�ʽ��ϢWAVEFORMATEX�ṹ

		//��¼���豸����
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

			//Ϊ¼���豸׼�����溯����
			//MMRESULT waveInPrepareHeader(  HWAVEIN hwi,  LPWAVEHDR pwh, UINT bwh );
			waveInPrepareHeader(hWaveIn, &wh[i], sizeof(WAVEHDR));

			//�������豸����һ�����棺
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
		
		waveInStop(hWaveIn);this->SetDlgItemTextW(IDC_BUTTON19, L"¼��");
		//waveInReset(hWaveIn);//ֹͣ¼��
		
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
	sndPlaySound(L"δ����.wav", SND_ASYNC);
	//sndPlaySound(gWavName, SND_ASYNC);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//PlaySound(_T("C:\\WINDOWS\\Media\\Windows �ػ�.wav"), NULL, SND_FILENAME | SND_ASYNC);
	
	//sndPlaySound(_T("C:\\WINDOWS\\Media\\Windows Ӳ������.wav"), SND_ASYNC);
}


void CRobotDlg::OnBnClickedButton16()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString wavNameNow;
	this->GetDlgItemTextW(IDC_EDIT3, wavNameNow);
	MoveFile(gWavName,wavNameNow);
	MessageBox(L"����ɹ���", L"��ɧ������");
}


void CRobotDlg::OnBnClickedButton23()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(this->m_hWnd, L"open", L"..\\rules\\����ؼ���.txt", L"", L"", SW_SHOW);
}


void CRobotDlg::OnBnClickedButton14()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||"),
		NULL);
	dlg.m_ofn.lpstrInitialDir = L".\\";
	if (dlg.DoModal() == IDOK)
	{
		gWavName = dlg.GetPathName(); //�ļ�����������FilePathName��
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (bRunning == 0){
		bRunning = 1;
		this->SetDlgItemTextW(IDC_BUTTON18, L"ֹͣ����");
	}
	else{
		bRunning = 0;
		this->SetDlgItemTextW(IDC_BUTTON18, L"��ʼ����");
	}
}


void CRobotDlg::OnBnClickedButton21()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}
