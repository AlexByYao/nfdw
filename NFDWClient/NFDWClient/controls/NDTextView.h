#ifndef __NDTEXTVIEW_H__
#define __NDTEXTVIEW_H__
#include "controls/NDViewBase.h"

class NDTextView : public NDViewBase{
public:
	NDTextView();
	virtual ~NDTextView();

	// interface of NDViewBase
public:
	virtual void draw( HDC hDC );
	
public:
	void setText( const tstring_type& tstrText );
	void setFontId( unsigned int uFontId );
	void setTextClr( COLORREF clrText );

private:
	bool NDTextView::_getDrawTextRect( RECT& rcDrawText );

private:
	tstring_type m_tstrText;
	unsigned int m_uFontId;
	COLORREF m_clrText;

};





#endif //__NDTEXTVIEW_H__



