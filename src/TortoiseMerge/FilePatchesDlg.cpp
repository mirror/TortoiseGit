// TortoiseGitMerge - a Diff/Patch program

// Copyright (C) 2006, 2008, 2010-2012 - TortoiseSVN
// Copyright (C) 2012 - Sven Strickroth <email@cs-ware.de>

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#include "stdafx.h"
#include "TortoiseMerge.h"
#include "FilePatchesDlg.h"
#include "GitPatch.h"
#include "AppUtils.h"
#include "PathUtils.h"
#include "SysProgressDlg.h"
#include "MessageBox.h"

IMPLEMENT_DYNAMIC(CFilePatchesDlg, CResizableStandAloneDialog)
CFilePatchesDlg::CFilePatchesDlg(CWnd* pParent /*=NULL*/)
	: CResizableStandAloneDialog(CFilePatchesDlg::IDD, pParent)
	, m_ShownIndex(-1)
	, m_bMinimized(FALSE)
	, m_pPatch(NULL)
	, m_pCallBack(NULL)
	, m_nWindowHeight(-1)
	, m_pMainFrame(NULL)
	, m_boldFont(NULL)
{
	m_ImgList.Create(16, 16, ILC_COLOR16 | ILC_MASK, 4, 1);
}

CFilePatchesDlg::~CFilePatchesDlg()
{
	if (m_boldFont)
		DeleteObject(m_boldFont);
}

void CFilePatchesDlg::DoDataExchange(CDataExchange* pDX)
{
	CResizableStandAloneDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILELIST, m_cFileList);
}

BOOL CFilePatchesDlg::SetFileStatusAsPatched(CString sPath)
{
	for (int i=0; i<m_arFileStates.GetCount(); i++)
	{
		if (sPath.CompareNoCase(GetFullPath(i))==0)
		{
			m_arFileStates.SetAt(i, (DWORD)FPDLG_FILESTATE_PATCHED);
			Invalidate();
			return TRUE;
		}
	}
	return FALSE;
}

CString CFilePatchesDlg::GetFullPath(int nIndex)
{
	CString temp = m_pPatch->GetStrippedPath(nIndex);
	temp.Replace('/', '\\');
	//temp = temp.Mid(temp.Find('\\')+1);
	if (PathIsRelative(temp))
		temp = m_sPath + temp;
	return temp;
}

BOOL CFilePatchesDlg::OnInitDialog()
{
	CResizableStandAloneDialog::OnInitDialog();

	// hide the grip since it would overlap with the "path all" button
#if 0
	HideGrip();
#endif

	HFONT hFont = (HFONT)m_cFileList.SendMessage(WM_GETFONT);
	LOGFONT lf = {0};
	GetObject(hFont, sizeof(LOGFONT), &lf);
	lf.lfWeight = FW_BOLD;
	m_boldFont = CreateFontIndirect(&lf);

	AddAnchor(IDC_FILELIST, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_PATCHSELECTEDBUTTON, BOTTOM_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_PATCHALLBUTTON, BOTTOM_LEFT, BOTTOM_RIGHT);

	return TRUE;
}

BOOL CFilePatchesDlg::Init(GitPatch * pPatch, CPatchFilesDlgCallBack * pCallBack, CString sPath, CWnd * pParent)
{
	if ((pCallBack==NULL)||(pPatch==NULL))
	{
		m_cFileList.DeleteAllItems();
		return FALSE;
	}
	m_arFileStates.RemoveAll();
	m_pPatch = pPatch;
	m_pCallBack = pCallBack;
	m_sPath = sPath;
	if (m_sPath.IsEmpty())
	{
		CString title(MAKEINTRESOURCE(IDS_DIFF_TITLE));
		SetWindowText(title);
	}
	else
	{
		CRect rect;
		GetClientRect(&rect);
		SetTitleWithPath(rect.Width());
		if (m_sPath.Right(1).Compare(_T("\\"))==0)
			m_sPath = m_sPath.Left(m_sPath.GetLength()-1);

		m_sPath = m_sPath + _T("\\");
		for (int i=m_ImgList.GetImageCount();i>0;i--)
		{
			m_ImgList.Remove(0);
		}
	}

	m_cFileList.SetExtendedStyle(LVS_EX_INFOTIP | LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER);
	m_cFileList.DeleteAllItems();
	int c = ((CHeaderCtrl*)(m_cFileList.GetDlgItem(0)))->GetItemCount()-1;
	while (c>=0)
		m_cFileList.DeleteColumn(c--);
	m_cFileList.InsertColumn(0, _T(""));

	m_cFileList.SetRedraw(false);

	for(int i=0; i<m_pPatch->GetNumberOfFiles(); i++)
	{
		CString sFile = CPathUtils::GetFileNameFromPath(m_pPatch->GetStrippedPath(i));

		int state;
		if (m_sPath.IsEmpty())
			state = 0;
		else
		{
			state = m_pPatch->GetFailedHunks(i);
		}
		if (state > 0)
			state = FPDLG_FILESTATE_ERROR;
		m_arFileStates.Add(state);
		SHFILEINFO    sfi;
		SHGetFileInfo(
			GetFullPath(i),
			FILE_ATTRIBUTE_NORMAL,
			&sfi,
			sizeof(SHFILEINFO),
			SHGFI_ICON | SHGFI_SMALLICON | SHGFI_USEFILEATTRIBUTES);
		m_cFileList.InsertItem(i, sFile, m_ImgList.Add(sfi.hIcon));

	}
	int mincol = 0;
	int maxcol = ((CHeaderCtrl*)(m_cFileList.GetDlgItem(0)))->GetItemCount()-1;
	int col;
	for (col = mincol; col <= maxcol; col++)
	{
		m_cFileList.SetColumnWidth(col,LVSCW_AUTOSIZE_USEHEADER);
	}

	m_cFileList.SetImageList(&m_ImgList, LVSIL_SMALL);
	m_cFileList.SetRedraw(true);

	RECT parentrect;
	pParent->GetWindowRect(&parentrect);
	RECT windowrect;
	GetWindowRect(&windowrect);

	int width = windowrect.right - windowrect.left;
	int height = windowrect.bottom - windowrect.top;
	windowrect.right = parentrect.left;
	windowrect.left = windowrect.right - width;
	if (windowrect.left < 0)
	{
		windowrect.left = 0;
		windowrect.right = width;
	}
	windowrect.top = parentrect.top;
	windowrect.bottom = windowrect.top + height;

	SetWindowPos(NULL, windowrect.left, windowrect.top, width, height, SWP_NOACTIVATE | SWP_NOZORDER);

	m_nWindowHeight = windowrect.bottom - windowrect.top;
	m_pMainFrame = pParent;
	return TRUE;
}

BEGIN_MESSAGE_MAP(CFilePatchesDlg, CResizableStandAloneDialog)
	ON_WM_SIZE()
	ON_NOTIFY(LVN_GETINFOTIP, IDC_FILELIST, OnLvnGetInfoTipFilelist)
	ON_NOTIFY(NM_DBLCLK, IDC_FILELIST, OnNMDblclkFilelist)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_FILELIST, OnNMCustomdrawFilelist)
	ON_NOTIFY(NM_RCLICK, IDC_FILELIST, OnNMRclickFilelist)
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_MOVING()
	ON_BN_CLICKED(IDC_PATCHSELECTEDBUTTON, &CFilePatchesDlg::OnBnClickedPatchselectedbutton)
	ON_BN_CLICKED(IDC_PATCHALLBUTTON, &CFilePatchesDlg::OnBnClickedPatchallbutton)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_FILELIST, &CFilePatchesDlg::OnLvnItemchangedFilelist)
END_MESSAGE_MAP()

void CFilePatchesDlg::OnSize(UINT nType, int cx, int cy)
{
	CResizableStandAloneDialog::OnSize(nType, cx, cy);
	if (this->IsWindowVisible())
	{
		m_cFileList.SetColumnWidth(0, LVSCW_AUTOSIZE);
	}
	SetTitleWithPath(cx);
}

void CFilePatchesDlg::OnLvnGetInfoTipFilelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVGETINFOTIP pGetInfoTip = reinterpret_cast<LPNMLVGETINFOTIP>(pNMHDR);

	if (m_arFileStates.GetCount() > pGetInfoTip->iItem)
	{
		CString temp;
		if (m_arFileStates.GetAt(pGetInfoTip->iItem) == 0)
			temp = GetFullPath(pGetInfoTip->iItem);
		else
			temp.Format(IDS_PATCH_ITEMTT, (LPCTSTR)GetFullPath(pGetInfoTip->iItem), m_arFileStates.GetAt(pGetInfoTip->iItem));
		_tcsncpy_s(pGetInfoTip->pszText, pGetInfoTip->cchTextMax, temp, pGetInfoTip->cchTextMax);
	}
	else
		pGetInfoTip->pszText[0] = 0;

	*pResult = 0;
}

void CFilePatchesDlg::OnNMDblclkFilelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	*pResult = 0;
	if ((pNMLV->iItem < 0) || (pNMLV->iItem >= m_arFileStates.GetCount()))
		return;
	if (m_pCallBack==NULL)
		return;

	if (m_arFileStates.GetAt(pNMLV->iItem) == FPDLG_FILESTATE_ERROR)
	{
		MessageBox(m_pPatch->GetPatchRejects(pNMLV->iItem), NULL, MB_ICONERROR);
		return;
	}

	if (m_sPath.IsEmpty())
	{
		m_pCallBack->DiffFiles(GetFullPath(pNMLV->iItem), _T(""),
							   _T(""), _T(""));
		m_ShownIndex = pNMLV->iItem;
		m_cFileList.Invalidate();
	}
	else
	{
		if (m_arFileStates.GetAt(pNMLV->iItem)!=FPDLG_FILESTATE_PATCHED)
		{
			m_pCallBack->PatchFile(m_pPatch->GetStrippedPath(pNMLV->iItem), m_pPatch->GetContentMods(pNMLV->iItem), m_pPatch->GetPropMods(pNMLV->iItem), _T(""));
			m_ShownIndex = pNMLV->iItem;
			m_cFileList.Invalidate();
		}
	}
}

void CFilePatchesDlg::OnNMCustomdrawFilelist(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>( pNMHDR );

	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;

	// First thing - check the draw stage. If it's the control's prepaint
	// stage, then tell Windows we want messages for every item.

	if ( CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if ( CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage )
	{
		// This is the prepaint stage for an item. Here's where we set the
		// item's text color. Our return value will tell Windows to draw the
		// item itself, but it will use the new color we set here.

		COLORREF crText = ::GetSysColor(COLOR_WINDOWTEXT);

		if (m_arFileStates.GetCount() > (INT_PTR)pLVCD->nmcd.dwItemSpec)
		{
			if (m_arFileStates.GetAt(pLVCD->nmcd.dwItemSpec)==FPDLG_FILESTATE_ERROR)
			{
				crText = RGB(200, 0, 0);
			}
			if (m_arFileStates.GetAt(pLVCD->nmcd.dwItemSpec)>0)
			{
				crText = RGB(100, 0, 0);
			}
			if (m_arFileStates.GetAt(pLVCD->nmcd.dwItemSpec)==FPDLG_FILESTATE_PATCHED)
			{
				crText = ::GetSysColor(COLOR_GRAYTEXT);
			}
			// Store the color back in the NMLVCUSTOMDRAW struct.
			pLVCD->clrText = crText;
			if (m_ShownIndex == (int)pLVCD->nmcd.dwItemSpec)
			{
				SelectObject(pLVCD->nmcd.hdc, m_boldFont);
				// We changed the font, so we're returning CDRF_NEWFONT. This
				// tells the control to recalculate the extent of the text.
				*pResult = CDRF_NOTIFYSUBITEMDRAW | CDRF_NEWFONT;
			}
		}
	}
}

void CFilePatchesDlg::OnNMRclickFilelist(NMHDR * /*pNMHDR*/, LRESULT *pResult)
{
	*pResult = 0;
	if (m_sPath.IsEmpty())
		return;
	CString temp;
	CMenu popup;
	POINT point;
	DWORD ptW = GetMessagePos();
	point.x = GET_X_LPARAM(ptW);
	point.y = GET_Y_LPARAM(ptW);
	if (!popup.CreatePopupMenu())
		return;

	UINT nFlags = MF_STRING | (m_cFileList.GetSelectedCount()==1 ? MF_ENABLED : MF_DISABLED | MF_GRAYED);
	temp.LoadString(IDS_PATCH_PREVIEW);
	popup.AppendMenu(nFlags, ID_PATCHPREVIEW, temp);
	popup.SetDefaultItem(ID_PATCHPREVIEW, FALSE);

	temp.LoadString(IDS_PATCH_ALL);
	popup.AppendMenu(MF_STRING | MF_ENABLED, ID_PATCHALL, temp);

	nFlags = MF_STRING | (m_cFileList.GetSelectedCount() > 0 ? MF_ENABLED : MF_DISABLED | MF_GRAYED);
	temp.LoadString(IDS_PATCH_SELECTED);
	popup.AppendMenu(nFlags, ID_PATCHSELECTED, temp);

	// if the context menu is invoked through the keyboard, we have to use
	// a calculated position on where to anchor the menu on
	if ((point.x == -1) && (point.y == -1))
	{
		CRect rect;
		GetWindowRect(&rect);
		point = rect.CenterPoint();
	}

	int cmd = popup.TrackPopupMenu(TPM_RETURNCMD | TPM_LEFTALIGN | TPM_NONOTIFY | TPM_RIGHTBUTTON, point.x, point.y, this, 0);
	switch (cmd)
	{
	case ID_PATCHPREVIEW:
		if (m_pCallBack)
		{
			int nIndex = m_cFileList.GetSelectionMark();
			if (m_arFileStates.GetAt(nIndex) == FPDLG_FILESTATE_ERROR)
			{
				MessageBox(m_pPatch->GetPatchRejects(nIndex), NULL, MB_ICONERROR);
			}
			else if ( m_arFileStates.GetAt(nIndex)!=FPDLG_FILESTATE_PATCHED)
			{
				m_pCallBack->PatchFile(m_pPatch->GetStrippedPath(nIndex), m_pPatch->GetContentMods(nIndex), m_pPatch->GetPropMods(nIndex), _T(""));
				m_ShownIndex = nIndex;
				m_cFileList.Invalidate();
			}
		}
		break;
	case ID_PATCHALL:
		PatchAll();
		break;
	case ID_PATCHSELECTED:
		PatchSelected();
		break;
	default:
		break;
	}
}

void CFilePatchesDlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	if (!m_bMinimized)
	{
		RECT windowrect;
		RECT clientrect;
		GetWindowRect(&windowrect);
		GetClientRect(&clientrect);
		m_nWindowHeight = windowrect.bottom - windowrect.top;
		MoveWindow(windowrect.left, windowrect.top,
			windowrect.right - windowrect.left,
			m_nWindowHeight - (clientrect.bottom - clientrect.top));
	}
	else
	{
		RECT windowrect;
		GetWindowRect(&windowrect);
		MoveWindow(windowrect.left, windowrect.top, windowrect.right - windowrect.left, m_nWindowHeight);
	}
	m_bMinimized = !m_bMinimized;
	CResizableStandAloneDialog::OnNcLButtonDblClk(nHitTest, point);
}

void CFilePatchesDlg::OnMoving(UINT fwSide, LPRECT pRect)
{
	RECT parentRect;
	m_pMainFrame->GetWindowRect(&parentRect);
	const int stickySize = 5;
	if (abs(parentRect.left - pRect->right) < stickySize)
	{
		int width = pRect->right - pRect->left;
		pRect->right = parentRect.left;
		pRect->left = pRect->right - width;
	}
	CResizableStandAloneDialog::OnMoving(fwSide, pRect);
}

void CFilePatchesDlg::OnOK()
{
	return;
}

void CFilePatchesDlg::SetTitleWithPath(int width)
{
	CString title;
	title.LoadString(IDS_PATCH_TITLE);
	title += _T("  ") + m_sPath;
	title = title.Left(MAX_PATH-1);
	CDC * pDC = GetDC();
	if (pDC)
	{
		PathCompactPath(pDC->GetSafeHdc(), title.GetBuffer(), width);
		ReleaseDC(pDC);
	}
	title.ReleaseBuffer();
	SetWindowText(title);
}

void CFilePatchesDlg::OnBnClickedPatchselectedbutton()
{
	PatchSelected();
}

void CFilePatchesDlg::OnBnClickedPatchallbutton()
{
	PatchAll();
}

void CFilePatchesDlg::PatchAll()
{
	if (m_pCallBack)
	{
		CSysProgressDlg progDlg;
		progDlg.SetTitle(IDR_MAINFRAME);
		progDlg.SetShowProgressBar(true);
		progDlg.SetLine(1, CString(MAKEINTRESOURCE(IDS_PATCH_ALL)));
		progDlg.ShowModeless(m_hWnd);
		for (int i=0; i<m_arFileStates.GetCount() && !progDlg.HasUserCancelled(); i++)
		{
			if (m_arFileStates.GetAt(i) == FPDLG_FILESTATE_ERROR)
				MessageBox(m_pPatch->GetPatchRejects(i), NULL, MB_ICONERROR);
			else if (m_arFileStates.GetAt(i) != FPDLG_FILESTATE_PATCHED)
			{
				progDlg.SetLine(2, GetFullPath(i), true);
				m_pCallBack->PatchFile(m_pPatch->GetStrippedPath(i), m_pPatch->GetContentMods(i), m_pPatch->GetPropMods(i), _T(""), TRUE);
				m_ShownIndex = i;
				m_cFileList.Invalidate();
			}
			progDlg.SetProgress64(i, m_arFileStates.GetCount());
		}
		progDlg.Stop();
	}
}

void CFilePatchesDlg::PatchSelected()
{
	if (m_pCallBack)
	{
		CSysProgressDlg progDlg;
		progDlg.SetTitle(IDR_MAINFRAME);
		progDlg.SetShowProgressBar(true);
		progDlg.SetLine(1, CString(MAKEINTRESOURCE(IDS_PATCH_SELECTED)));
		progDlg.ShowModeless(m_hWnd);
		// The list cannot be sorted by user, so the order of the
		// items in the list is identical to the order in the array
		// m_arFileStates.
		int selCount = m_cFileList.GetSelectedCount();
		int count = 1;
		POSITION pos = m_cFileList.GetFirstSelectedItemPosition();
		int index;
		while (((index = m_cFileList.GetNextSelectedItem(pos)) >= 0) && (!progDlg.HasUserCancelled()))
		{
			if (m_arFileStates.GetAt(index) == FPDLG_FILESTATE_ERROR)
				MessageBox(m_pPatch->GetPatchRejects(index), NULL, MB_ICONERROR);
			else if (m_arFileStates.GetAt(index) != FPDLG_FILESTATE_PATCHED)
			{
				progDlg.SetLine(2, GetFullPath(index), true);
				m_pCallBack->PatchFile(m_pPatch->GetStrippedPath(index), m_pPatch->GetContentMods(index), m_pPatch->GetPropMods(index), _T(""), TRUE);
				m_ShownIndex = index;
				m_cFileList.Invalidate();
			}
			progDlg.SetProgress64(count++, selCount);
		}
		progDlg.Stop();
	}
}

void CFilePatchesDlg::OnLvnItemchangedFilelist(NMHDR * /*pNMHDR*/, LRESULT *pResult)
{
	DialogEnableWindow(IDC_PATCHSELECTEDBUTTON, m_cFileList.GetSelectedCount() > 0);

	*pResult = 0;
}
