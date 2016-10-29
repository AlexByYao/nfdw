#ifndef __NFDWAPP_H__
#define __NFDWAPP_H__
#include <string>
#include "tchar.h"

class NFDWApp {
public:
	typedef std::basic_string< TCHAR > tstring_type;
public:
	NFDWApp();
	~NFDWApp();

public:
	static NFDWApp* getInstance() {
		static NFDWApp s_instance;
		return &s_instance;
	}

public:
	bool getImageFileDir(tstring_type& tstrImageDirPath);
	
};



#endif //__NFDWAPP_H__