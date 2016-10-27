#ifndef __NFDWAPP_H__
#define __NFDWAPP_H__

class NFDWApp {
public:
	NFDWApp();
	~NFDWApp();

public:
	static NFDWApp* getInstance() {
		static NFDWApp s_instance;
		return &s_instance;
	}



};



#endif //__NFDWAPP_H__