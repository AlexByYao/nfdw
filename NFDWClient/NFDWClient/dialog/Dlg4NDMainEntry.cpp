#include "stdafx.h"
#include "Dlg4NDMainEntry.h"//
#include "framework/NFDWApp.h"
#include "NFDWEnvCfg.h"
#include "loader/YBImageLoader.h"
#include "frame/YBCtrlImageStatic.h"
#include "frame/YBCtrlImageDepository.h"

USING_NAMESPACE_YBCTRL

Dlg4NDMainEntry::Dlg4NDMainEntry() {
	loadFont();
	loadImage();
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
	//RECT rcClient;
	//PAINTSTRUCT ps;
	//HDC hPaintDC = NULL;
	//HBRUSH hBrush = NULL;

	//::GetClientRect(m_hWnd, &rcClient);
	//hPaintDC = ::BeginPaint(m_hWnd, &ps);
	//hBrush = ::CreateSolidBrush(RGB(255, 100, 100));

	//::FillRect(hPaintDC, &rcClient, hBrush);
	//
	//::DeleteObject( hBrush );
	//::EndPaint( m_hWnd, &ps );

	if( !pYBCtrlWndMsg )
		return;
	HWND hWnd;
	HDC hPaintDC;
	HBRUSH hBrushBK;
	PAINTSTRUCT ps;
	RECT rcClient;

	hWnd = pYBCtrlWndMsg->m_hWnd;
	::GetClientRect( hWnd, &rcClient );
	hPaintDC = ::BeginPaint( hWnd, &ps );

	if( m_uImageIdBK == YBCTRL_IMAGE_ID_INVALID ) {
		hBrushBK = ::CreateSolidBrush( RGB( 0, 29, 73 ) );
		::FillRect( hPaintDC, &rcClient, hBrushBK );
		::DeleteObject( hBrushBK );
	}
	else {
		ybctrl::YBCtrlImageBase* pYBImage = NULL;

		if( !YBCTRLIMAGEDEPOSITORY_INSTANCE_WITHNAMESPACE->getImage( m_uImageIdBK, &pYBImage ) ) {
			assert( false );
		}
		else {
			ybctrl::YBCtrlImageStatic* pYBImageStatic = NULL;
			if( pYBImage->getType() == YBCTRL_IMAGE_TYPE_STATIC ) {
				pYBImageStatic = ( ybctrl::YBCtrlImageStatic* )pYBImage;
				Gdiplus::Image* pGPImage = NULL;

				pGPImage = pYBImageStatic->getImage();
				::StretchBlt( hPaintDC, 0, 0, ( rcClient.right - rcClient.left ), ( rcClient.bottom - rcClient.top )
					, pYBImageStatic->getMemDC(), 0, 0, pGPImage->GetWidth(), pGPImage->GetHeight(), SRCCOPY );

				//Gdiplus::Graphics graphics( hPaintDC );
				//ybctrl::GdipStretchBlt( &graphics, pYBImageStatic->getImage(), 0, 0, ( rcClient.right - rcClient.left ), ( rcClient.bottom - rcClient.top )
				//	, 0, 0, pYBImageStatic->getImage()->GetWidth(), pYBImageStatic->getImage()->GetHeight() );

			}

		}
	}
	::EndPaint( hWnd, &ps );
}


void Dlg4NDMainEntry::loadImage() {
	tstring_type tstrImageDirPath;
	tstring_type tstrImageFilePath;

	if (!NFDWApp::getInstance()->getImageFileDir(tstrImageDirPath))
		return;
	// 
	tstrImageFilePath = tstrImageDirPath + _T("main_bk.jpg");
	if( !YBImageLoader::getInstance()->loadImage( tstrImageFilePath, m_uImageIdBK ) )
		return;
	
}

void Dlg4NDMainEntry::loadFont() {

}