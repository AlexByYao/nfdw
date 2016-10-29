#ifndef __NDVIEWBASE_H__
#define __NDVIEWBASE_H__

class NDViewBase {
public:
	NDViewBase();
	virtual ~NDViewBase();

public:
	virtual void draw( HDC hDC ) = 0;

public:
	void setRect( int x, int y, int width, int height );

protected:
	RECT m_rcView;
};


#endif //__NDVIEWBASE_H__