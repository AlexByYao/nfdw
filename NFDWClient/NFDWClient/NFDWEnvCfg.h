#pragma once

#include "resource.h"

#define NDPAGEID_4_PAY (100)


#define LOADIMAGE_BEGIN() \
tstring_type tstrImageDirPath; \
tstring_type tstrImageFilePath; \
if( !NFDWApp::getInstance()->getImageFileDir( tstrImageDirPath ) ) \
    return;
#define LOADIMAGE_END()
#define LOADIMAGE_ENTRY( image_id, image_name ) \
tstrImageFilePath = tstrImageDirPath + image_name; \
if( !YBImageLoader::getInstance()->loadImage( tstrImageFilePath, image_id ) ) \
    return;