#include "stdafx.h"
#include "NFDWApp.h"

NFDWApp::NFDWApp() {
}

NFDWApp::~NFDWApp() {

}

bool NFDWApp::getImageFileDir(tstring_type& tstrImageDirPath) {
	TCHAR szModulePath[MAX_PATH];
	TCHAR* posTmp = NULL;

	GetModuleFileName(NULL, szModulePath, MAX_PATH);
	posTmp = _tcsrchr(szModulePath, _T('\\'));
	if (!posTmp) {
		assert(false);
		return false;
	}
	posTmp += 1;
	*posTmp = 0;

	tstrImageDirPath = szModulePath;
	tstrImageDirPath += _T("Image\\");

	return true;
}