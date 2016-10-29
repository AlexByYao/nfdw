#ifndef __NDIMAGEVIEW_H__
#define __NDIMAGEVIEW_H__
#include "controls/NDViewBase.h"

class NDImageView : public NDViewBase {
public:
	NDImageView();
	virtual ~NDImageView();

	// interface of NDViewBase.
public:
	virtual void draw( HDC hDC );

public:
	void setImageId( unsigned int uImageId );

private:
	unsigned int m_uImageId;

};








#endif //__NDIMAGEVIEW_H__

