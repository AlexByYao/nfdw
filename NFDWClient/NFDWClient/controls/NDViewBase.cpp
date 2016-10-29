#include "stdafx.h"
#include "NDViewBase.h"

NDViewBase::NDViewBase() {
	memset( &m_rcView, 0, sizeof(m_rcView) );
}

NDViewBase::~NDViewBase() {
}

void NDViewBase::setRect( int x, int y, int width, int height ) {
	::SetRect( &m_rcView, x, y, x+width, y+height );
}
