#ifndef __NDPAGEBASE_H__
#define __NDPAGEBASE_H__
#include <deque>
#include "controls/NDViewBase.h"

class NDPageBase {
public:
	typedef std::deque< NDViewBase* > ndview_container_type;
public:
	NDPageBase( unsigned int uPageId )
	: m_uPageId( uPageId )
	, m_bVisible( false ) {}
	virtual ~NDPageBase() {
		m_containerSubViews.clear();
	}

	// interface.
public:
	virtual void init( HWND hWndParent, HINSTANCE hInst ) = 0;
	virtual void onVisibleChange( bool bVisible ) = 0;
protected:
	virtual void doDrawBK( HDC hDC, const RECT& rcParent ){};
	virtual void doDrawFT( HDC hDC, const RECT& rcParent ){};

	//
public:
	void onDrawPage( HDC hDC, const RECT& rcParent ) {
		doDrawBK( hDC, rcParent );
		_drawSubView( hDC );
		doDrawFT( hDC, rcParent );
	}
	unsigned int getPageId() { return m_uPageId; }
	void setVisible( bool bVisible ) {
		if( bVisible == m_bVisible )
			return;
		onVisibleChange( bVisible );
		m_bVisible = bVisible;
	};
	bool isVisible() { return m_bVisible; }

protected:
	void _addSubView( NDViewBase* pView ) { m_containerSubViews.push_back( pView ); }

private:
	void _drawSubView( HDC hDC ) {
		for( NDViewBase* pView : m_containerSubViews ) {
			if( pView ) {
				pView->draw( hDC );
			}
		}
	}

protected:
	unsigned int m_uPageId;
	bool m_bVisible;
	ndview_container_type m_containerSubViews;
};













#endif //__NDPAGEBASE_H__