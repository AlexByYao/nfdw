#include "stdafx.h"
#include "NDImageView.h"
#include "frame/YBCtrlImageStatic.h"
#include "frame/YBCtrlImageDepository.h"
#include "frame/YBCtrlFontDepository.h"
#include "frame\YBCtrlMisc.h"
USING_NAMESPACE_YBCTRL

NDImageView::NDImageView()
: m_uImageId( YBCTRL_IMAGE_ID_INVALID ) {

}

NDImageView::~NDImageView() {

}

void NDImageView::draw( HDC hDC ) {
	ybctrl::YBCtrlImageBase* pYBImage = NULL;

	if( !YBCTRLIMAGEDEPOSITORY_INSTANCE_WITHNAMESPACE->getImage( m_uImageId, &pYBImage ) ) {
		assert( false );
	}
	else {
		ybctrl::YBCtrlImageStatic* pYBImageStatic = NULL;
		if( pYBImage->getType() == YBCTRL_IMAGE_TYPE_STATIC ) {
			pYBImageStatic = ( ybctrl::YBCtrlImageStatic* )pYBImage;
			Gdiplus::Image* pGPImage = NULL;

			Gdiplus::Graphics graphics( hDC );
			ybctrl::GdipStretchBlt( &graphics, pYBImageStatic->getImage(), m_rcView.left, m_rcView.top, ( m_rcView.right - m_rcView.left ), ( m_rcView.bottom - m_rcView.top )
				, 0, 0, pYBImageStatic->getImage()->GetWidth(), pYBImageStatic->getImage()->GetHeight() );
		}
	}
}

void NDImageView::setImageId( unsigned int uImageId ) {
	m_uImageId = uImageId;
}

//	unsigned int m_uImageId;