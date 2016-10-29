#ifndef __PAGE4PAY_H__
#define __PAGE4PAY_H__
#include "framework/NDPageBase.h"
#include "static/YBStatic.h"
#include "controls/NDTextView.h"
#include "controls/NDImageView.h"

class NDPage4Pay : public NDPageBase {
public:
	NDPage4Pay();
	~NDPage4Pay();

	// interface of NDPageBase
public:
	virtual void init( HWND hWndParent, HINSTANCE hInst );
	virtual void doDrawBK( HDC hDC, const RECT& rcParent );
	virtual void onVisibleChange( bool bVisible );


private:
	void _loadImage();
	void _loadFont();

private:
	unsigned int m_uImageIdPageBK;
	unsigned int m_uFontIdTitle;
	NDTextView m_tvTitle;
	NDImageView m_ivBK;
};


#endif //__PAGE4PAY_H__