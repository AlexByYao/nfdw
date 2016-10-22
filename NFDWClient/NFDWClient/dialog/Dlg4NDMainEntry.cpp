#include "stdafx.h"
#include "Dlg4NDMainEntry.h"//

Dlg4NDMainEntry::Dlg4NDMainEntry() {

}

Dlg4NDMainEntry::~Dlg4NDMainEntry() {

}

YBCTRL_WNDMSGMAP_BEGIN(Dlg4NDMainEntry, YBCtrlBase )
    YBCTRL_ONWNDMSG(WM_PAINT, _onWM_PAINT)
YBCTRL_WNDMSGMAP_END()

HWND Dlg4NDMainEntry::create( HINSTANCE hInst ) {
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	return YBCtrlBase::_createHWND(0, WS_VISIBLE | WS_POPUP, 0, 0, width, height, NULL, NULL, hInst, NULL);
}

void Dlg4NDMainEntry::_onWM_PAINT(ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg) {
	RECT rcClient;
	PAINTSTRUCT ps;
	HDC hPaintDC = NULL;
	HBRUSH hBrush = NULL;

	::GetClientRect(m_hWnd, &rcClient);
	hPaintDC = ::BeginPaint(m_hWnd, &ps);
	hBrush = ::CreateSolidBrush(RGB(255, 100, 100));

	::FillRect(hPaintDC, &rcClient, hBrush);
	
	::DeleteObject( hBrush );
	::EndPaint( m_hWnd, &ps );

}