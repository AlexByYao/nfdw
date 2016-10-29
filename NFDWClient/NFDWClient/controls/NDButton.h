#ifndef __NDBUTTON_H__
#define __NDBUTTON_H__
#include "controls/NDViewBase.h"

//
#define BTN_FLAG_LBTNDOWN (0x00000001)
#define BTN_FLAG_TRACEMOUSELEAVE (0x00000002)
#define BTN_FLAG_DISABLE (0x00000004)
//
//class NDButton : public NDViewBase {
//{
//public:
//	enum ENUMBTNSTATE{ BTN_STATE_NORMAL = 0, BTN_STATE_HOVER, BTN_STATE_PRESS, BTN_STATE_DISABLE };
//	enum ENUMDISTRICTID {
//		EDISTRICTID_BK_NOR = 0,
//		EDISTRICTID_BK_HOV,
//		EDISTRICTID_BK_PRE,
//		EDISTRICTID_BK_DIS
//	};
//
//public:
//	NDButton( hmskin_event_listener_base* pHMSkinEventListener );
//	virtual ~NDButton();
//
//	// interface of hm_cmn_observer_i
//public:
//	virtual void update( void* pSubject, UINT idEvent, long pEventParam, long pEventParam2, BOOL* pbContinue );
//
//private:
//	void _doDrawSkin( HDC hDC, const RECT& rcCanvas, ENUMBTNSTATE eBtnState );
//	ENUMBTNSTATE _getCurState();
//
//private:
//	void _OnLButtonDown( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnLButtonDblClk( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnLButtonUp( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnRButtonDown( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnRButtonUp( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnMouseMove( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnMouseLeave( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnSetText( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//	void _OnGetText( hm_keel_obj* pKeelObj, CWPSTRUCT* pWP, msg_sink_i::WNDPROCPARAM* pParamWndProc );
//
//private:
//	unsigned int m_uBtnStateFlags;
//};



















#endif //__NDBUTTON_H__

