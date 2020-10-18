// DonateDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TrafficMonitor.h"
#include "DonateDlg.h"
#include "afxdialogex.h"
#include "DrawCommon.h"


// CDonateDlg �Ի���

IMPLEMENT_DYNAMIC(CDonateDlg, CDialog)

CDonateDlg::CDonateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DONATE_DIALOG, pParent)
{

}

CDonateDlg::~CDonateDlg()
{
}

void CDonateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_DONATE_PIC, m_donate_pic);
}


BEGIN_MESSAGE_MAP(CDonateDlg, CDialog)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// CDonateDlg ��Ϣ�������


BOOL CDonateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowText(CCommon::LoadText(IDS_TITLE_DONATE));

    //����������ά��ͼƬ��λ��
    CRect rect{};
    CWnd* pWnd = nullptr;
    pWnd = GetDlgItem(IDC_TEXT_STATIC);
    if (pWnd != nullptr)
    {
        pWnd->GetWindowRect(rect);
        ScreenToClient(rect);
    }

    CRect rc_pic_area;
    GetClientRect(rc_pic_area);
    rc_pic_area.top = rect.bottom + theApp.DPI(8);
    rc_pic_area.left += theApp.DPI(10);
    rc_pic_area.right -= theApp.DPI(10);
    pWnd = GetDlgItem(IDOK);
    if (pWnd != nullptr)
    {
        pWnd->GetWindowRect(rect);
        ScreenToClient(rect);
    }
    rc_pic_area.bottom = rect.top - theApp.DPI(8);
    m_pic1_rect = rc_pic_area;
    m_pic1_rect.right = m_pic1_rect.left + (rc_pic_area.Width() / 2) - theApp.DPI(4);

    m_pic2_rect = rc_pic_area;
    m_pic2_rect.left = m_pic2_rect.right - (rc_pic_area.Width() / 2) + theApp.DPI(4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDonateDlg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
                       // TODO: �ڴ˴������Ϣ����������
                       // ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
    CDrawCommon draw;
    draw.Create(&dc, this);
    draw.DrawBitmap(IDB_DONATE_BITMAP, m_pic1_rect.TopLeft(), m_pic1_rect.Size(), CDrawCommon::StretchMode::FIT);
    draw.DrawBitmap(IDB_DONATE_WECHAT, m_pic2_rect.TopLeft(), m_pic2_rect.Size(), CDrawCommon::StretchMode::FIT);
}
