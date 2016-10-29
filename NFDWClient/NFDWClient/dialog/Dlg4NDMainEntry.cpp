#include "stdafx.h"
#include "Dlg4NDMainEntry.h"//
#include "framework/NFDWApp.h"
#include "NFDWEnvCfg.h"
#include "loader/YBImageLoader.h"
#include "frame/YBCtrlImageStatic.h"
#include "frame/YBCtrlImageDepository.h"
#include "pages/NDPage4Pay.h"

USING_NAMESPACE_YBCTRL

Dlg4NDMainEntry::Dlg4NDMainEntry() {
	_loadFont();
	_loadImage();

	m_containerPages.push_back( new NDPage4Pay() );
}

Dlg4NDMainEntry::~Dlg4NDMainEntry() {

}

YBCTRL_WNDMSGMAP_BEGIN( Dlg4NDMainEntry, YBCtrlBase )
YBCTRL_ONWNDMSG( WM_PAINT, _onWM_PAINT )
YBCTRL_ONWNDMSG( WM_CLOSE, _onWM_CLOSE )
YBCTRL_ONWNDMSG( WM_DESTROY, _onWM_DESTROY )
YBCTRL_WNDMSGMAP_END()

HWND Dlg4NDMainEntry::create( HINSTANCE hInst ) {
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	YBCtrlBase::_createHWND( 0, WS_VISIBLE | WS_POPUP, 0, 0, width, height, NULL, NULL, hInst, NULL );

	m_ivBK.setImageId( m_uImageIdBK );
	m_ivBK.setRect( 0, 0, width, height );
	_initPages( hInst );
	switchPage( NDPAGEID_4_PAY );
	return m_hWnd;
}

void Dlg4NDMainEntry::_onWM_DESTROY( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg ) {
	PostQuitMessage( 0 );
}

void Dlg4NDMainEntry::_onWM_CLOSE( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg ) {
	if( !pYBCtrlWndMsg )
		return;
	::DestroyWindow( pYBCtrlWndMsg->m_hWnd );
}

void Dlg4NDMainEntry::_onWM_PAINT(ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg) {
	if( !pYBCtrlWndMsg )
		return;
	HWND hWnd;
	HDC hPaintDC;
	PAINTSTRUCT ps;
	RECT rcClient;

	hWnd = pYBCtrlWndMsg->m_hWnd;
	::GetClientRect( hWnd, &rcClient );
	hPaintDC = ::BeginPaint( hWnd, &ps );

	m_ivBK.draw( hPaintDC );

	_drawPage( hPaintDC, rcClient );

	::EndPaint( hWnd, &ps );
}


void Dlg4NDMainEntry::_drawPage( HDC hDC, const RECT& rcClient ) {
	if( hDC == NULL )
		return;
	for( NDPageBase* page : m_containerPages ) {
		if( page != NULL && page->isVisible() ) {
			page->onDrawPage( hDC, rcClient );
		}
	}
}

void Dlg4NDMainEntry::_loadImage() {
	LOADIMAGE_BEGIN();
	LOADIMAGE_ENTRY( m_uImageIdBK, _T("main_bk.jpg") )
	LOADIMAGE_END();
}

void Dlg4NDMainEntry::_loadFont() {

}

void Dlg4NDMainEntry::_initPages( HINSTANCE hInst ) {
	if( m_hWnd == NULL )
		return;
	for( NDPageBase* page : m_containerPages ) {
		if( page != NULL ) {
			page->init( m_hWnd, hInst );
		}
	}
}

void Dlg4NDMainEntry::switchPage( unsigned int uPageId ) {
    // hide all
	for( NDPageBase* page : m_containerPages ) {
		if( page != NULL ) {
			page->setVisible( false );
		}
	}

	// switch to page which uPageId specify to.
	for( NDPageBase* page : m_containerPages ) {
		if( page != NULL && page->getPageId() == uPageId ) {
			page->setVisible( true );
			break;
		}
	}
}



