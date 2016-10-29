#ifndef __DLG4NDMAINENTRY_H__
#define __DLG4NDMAINENTRY_H__
#include "3rdlib\ybctrl\inc\frame\YBCtrlBase.h"
#include "framework\NDPageBase.h"
#include "controls\NDImageView.h"
#include <deque>

class Dlg4NDMainEntry : public ybctrl::YBCtrlBase {
public:
	typedef std::deque< NDPageBase* > page_container_type;
public:
	Dlg4NDMainEntry();
	virtual ~Dlg4NDMainEntry();

public:
	YBCTRL_WNDMSGMAP_DECLARE()

protected:
	void _onWM_PAINT( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_CLOSE( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );
	void _onWM_DESTROY( ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg );

public:
	HWND create(HINSTANCE hInst);
	void switchPage( unsigned int uPageId );

private:
	void _loadImage();
	void _loadFont();
	void _initPages( HINSTANCE hInst );
	void _drawPage( HDC hDC, const RECT& rcClient );


private:
	unsigned int m_uImageIdBK;
	NDImageView m_ivBK;
	HWND m_hWndMain;
	page_container_type m_containerPages;
};





#endif //__DLG4NDMAINENTRY_H__