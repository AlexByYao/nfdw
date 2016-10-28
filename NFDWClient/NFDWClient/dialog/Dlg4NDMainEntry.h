#ifndef __DLG4NDMAINENTRY_H__
#define __DLG4NDMAINENTRY_H__
#include "3rdlib\ybctrl\inc\frame\YBCtrlBase.h"

class Dlg4NDMainEntry : public ybctrl::YBCtrlBase {
public:
	Dlg4NDMainEntry();
	virtual ~Dlg4NDMainEntry();

public:
	YBCTRL_WNDMSGMAP_DECLARE()

protected:
	void _onWM_PAINT(ybctrl::YBCtrlWndMsg* pYBCtrlWndMsg);

public:
	HWND create(HINSTANCE hInst);

private:
	void loadImage();
	void loadFont();


private:
	unsigned int m_uImageIdBK;
};





#endif //__DLG4NDMAINENTRY_H__