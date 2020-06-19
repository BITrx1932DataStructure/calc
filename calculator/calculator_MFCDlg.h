
// calculator_MFCDlg.h: 头文件
//

#pragma once


// CcalculatorMFCDlg 对话框
class CcalculatorMFCDlg : public CDialogEx
{
	// 构造
public:
	CcalculatorMFCDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_MFC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangetext();
	CEdit TEXT;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonAc();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButtonmultiply();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonsubtract();
	afx_msg void OnBnClickedButtonadd();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButtonequal();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtondot();
	afx_msg void OnBnClickedButtonleft();
	afx_msg void OnBnClickedButtonright();
	afx_msg void OnBnClickedButtonpower();
};
