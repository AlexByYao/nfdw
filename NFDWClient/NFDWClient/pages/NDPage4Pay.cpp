#include "stdafx.h"
#include "NDPage4Pay.h"
#include "NFDWEnvCfg.h"
#include "framework/NFDWApp.h"
#include "loader/YBImageLoader.h"
#include "frame/YBCtrlImageStatic.h"
#include "frame/YBCtrlImageDepository.h"
#include "frame/YBCtrlFontDepository.h"
#include "frame\YBCtrlMisc.h"
USING_NAMESPACE_YBCTRL

NDPage4Pay::NDPage4Pay()
	: NDPageBase( NDPAGEID_4_PAY )
	, m_uImageIdPageBK( YBCTRL_IMAGE_ID_INVALID )
	, m_uFontIdTitle( YBCTRL_FONT_ID_INVALID ) {
	_loadFont();
	_loadImage();

}

NDPage4Pay::~NDPage4Pay() {

}

void NDPage4Pay::init( HWND hWndParent, HINSTANCE hInst ) {
	RECT rcClient;
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;

	::GetClientRect( hWndParent, &rcClient );


	// ±³¾°Í¼Æ¬
	m_ivBK.setRect( rcClient.left + 100, rcClient.top + 100, (rcClient.right - rcClient.left - 200), ( rcClient.bottom - rcClient.top - 200 ) );
	m_ivBK.setImageId( m_uImageIdPageBK );
	_addSubView( &m_ivBK );
	// ±êÌâ
	width = 400;
	height = 120;
	x = ( rcClient.left + rcClient.right - width ) / 2;
	y = rcClient.top + 200;
	m_tvTitle.setRect( x, y, width, height );
	m_tvTitle.setFontId( m_uFontIdTitle );
	m_tvTitle.setTextClr( RGB( 5, 80, 138 ) );
	m_tvTitle.setText( _T( "ÇëÑ¡Ôñ²éÑ¯·½Ê½" ) );
	_addSubView( &m_tvTitle );

}

void NDPage4Pay::doDrawBK( HDC hDC, const RECT& rcParent ) {
	if( !m_bVisible )
		return;


}

void NDPage4Pay::onVisibleChange( bool bVisible ) {
	
}

void NDPage4Pay::_loadImage() {

	LOADIMAGE_BEGIN();
	LOADIMAGE_ENTRY( m_uImageIdPageBK, _T( "page_bk_2.png" ) )
	LOADIMAGE_END();
}

void NDPage4Pay::_loadFont() {
	LOGFONT lFont;

	memset( &lFont, 0, sizeof( LOGFONT ) );
	_tcscpy_s( lFont.lfFaceName, _T( "Î¢ÈíÑÅºÚ" ) );
	lFont.lfHeight = 70;
	m_uFontIdTitle = ybctrl::YBCtrlFontDepository::getInstance()->insertLOGFONT( lFont, RGB( 255, 0, 0 ) );
}


