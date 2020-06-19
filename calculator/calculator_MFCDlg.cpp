
// calculator_MFCDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "calculator_MFC.h"
#include "calculator_MFCDlg.h"
#include "afxdialogex.h"
#include"calculator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorMFCDlg 对话框



CcalculatorMFCDlg::CcalculatorMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, dis_text, TEXT);
}

BEGIN_MESSAGE_MAP(CcalculatorMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_1, &CcalculatorMFCDlg::OnBnClickedButton1)
	ON_EN_CHANGE(dis_text, &CcalculatorMFCDlg::OnEnChangetext)
	ON_BN_CLICKED(IDC_BUTTON_2, &CcalculatorMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CcalculatorMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CcalculatorMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CcalculatorMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CcalculatorMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CcalculatorMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CcalculatorMFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CcalculatorMFCDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_AC, &CcalculatorMFCDlg::OnBnClickedButtonAc)
	ON_BN_CLICKED(IDC_BUTTON_divide, &CcalculatorMFCDlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTON_multiply, &CcalculatorMFCDlg::OnBnClickedButtonmultiply)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CcalculatorMFCDlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_subtract, &CcalculatorMFCDlg::OnBnClickedButtonsubtract)
	ON_BN_CLICKED(IDC_BUTTON_add, &CcalculatorMFCDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTON_equal, &CcalculatorMFCDlg::OnBnClickedButtonequal)
	ON_BN_CLICKED(IDC_BUTTON_0, &CcalculatorMFCDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_dot, &CcalculatorMFCDlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTON_left, &CcalculatorMFCDlg::OnBnClickedButtonleft)
	ON_BN_CLICKED(IDC_BUTTON_right, &CcalculatorMFCDlg::OnBnClickedButtonright)
	ON_BN_CLICKED(IDC_BUTTON_power, &CcalculatorMFCDlg::OnBnClickedButtonpower)
END_MESSAGE_MAP()


// CcalculatorMFCDlg 消息处理程序

BOOL CcalculatorMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorMFCDlg::OnPaint()
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
HCURSOR CcalculatorMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalculatorMFCDlg::OnEnChangetext()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

int opt = 0;

void CcalculatorMFCDlg::OnBnClickedButton1()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'1';
	TEXT.SetWindowTextW(s);
}

void CcalculatorMFCDlg::OnBnClickedButton2()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'2';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton3()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'3';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton4()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'4';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton5()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'5';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton6()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'6';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton7()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'7';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton8()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'8';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButton9()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'9';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonAc()
{
	TEXT.SetWindowTextW(L"");
}


void CcalculatorMFCDlg::OnBnClickedButtondivide()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'/';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonmultiply()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'*';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonDel()
{
	CString s;
	TEXT.GetWindowTextW(s);
	s = s.Left(s.GetLength() - 1);
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonsubtract()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'-';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonadd()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'+';
	TEXT.SetWindowTextW(s);
}

void CcalculatorMFCDlg::OnBnClickedButton0()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'0';
	TEXT.SetWindowTextW(s);
}

void CcalculatorMFCDlg::OnBnClickedButtondot()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'.';
	TEXT.SetWindowTextW(s);
}

void CcalculatorMFCDlg::OnBnClickedButtonpower()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'^';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonleft()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L'(';
	TEXT.SetWindowTextW(s);
}


void CcalculatorMFCDlg::OnBnClickedButtonright()
{
	if (opt == 0)
	{
		TEXT.SetWindowTextW(L"");
		opt = 1;
	}
	CString s;
	TEXT.GetWindowTextW(s);
	s += L')';
	TEXT.SetWindowTextW(s);
}

void CcalculatorMFCDlg::OnBnClickedButtonequal()
{
	opt = 0;
	static fy::Calculator calc;
	static char buf[1 << 10];
	try
	{
		CString s, add_s;
		TEXT.GetWindowTextW(s);
		double ans = calc.calculate(std::string(CStringA(s)));
		add_s.Format(L"%lf", ans);
		s += L"\r\n";
		s += add_s;
		TEXT.SetWindowTextW(s);
	}
	catch (fy::error::math_error)
	{
		TEXT.SetWindowTextW(L"math error");
	}
	catch (fy::error::syntax_error)
	{
		TEXT.SetWindowTextW(L"syntax error");
	}
	catch (...)
	{
		TEXT.SetWindowTextW(L"unknown error");
	}

}
