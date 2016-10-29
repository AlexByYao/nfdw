#include "stdafx.h"
#include "NDTextView.h"
#include "frame/YBCtrlFontDepository.h"

USING_NAMESPACE_YBCTRL

NDTextView::NDTextView()
: m_tstrText( _T("") ){
}

NDTextView::~NDTextView() {
}

void NDTextView::draw( HDC hDC ) {
	//
	RECT rcDrawText;
	RECT rcCalc;
	const YBCtrlFont* pYBCtrlFont = NULL;
	HFONT hFontOld = NULL;
	int iBkModeOld;
	COLORREF clrTxtOld;
	unsigned int uLineTop = 0;
	tstring_type tstrLineData;

	if( _getDrawTextRect( rcDrawText )
		&& ( rcDrawText.right - rcDrawText.left )
		&& ( rcDrawText.bottom - rcDrawText.top )
		&& ( m_tstrText.length() > 0 ) ) {
		pYBCtrlFont = YBCtrlFontDepository::getInstance()->getYBFont( m_uFontId );
		if( pYBCtrlFont ) {
			hFontOld = ( HFONT )::SelectObject( hDC, pYBCtrlFont->m_hFont );
			iBkModeOld = ::SetBkMode( hDC, TRANSPARENT );
			clrTxtOld = ::SetTextColor( hDC, m_clrText );
					
			::DrawText( hDC, m_tstrText.c_str(), m_tstrText.length(), &rcDrawText, DT_SINGLELINE | DT_END_ELLIPSIS | DT_CENTER | DT_VCENTER );
			
			::SetTextColor( hDC, clrTxtOld );
			::SetBkMode( hDC, iBkModeOld );
			::SelectObject( hDC, hFontOld );
		}
	}
}

void NDTextView::setTextClr( COLORREF clrText ) {
	m_clrText = clrText;
}

bool NDTextView::_getDrawTextRect( RECT& rcDrawText ){
	rcDrawText = m_rcView;

	return ( rcDrawText.right >= rcDrawText.left ) && ( rcDrawText.bottom >= rcDrawText.top );
}

void NDTextView::setText( const tstring_type& tstrText ) {
	m_tstrText = tstrText;
}

void NDTextView::setFontId( unsigned int uFontId ) {
	m_uFontId = uFontId;
}
