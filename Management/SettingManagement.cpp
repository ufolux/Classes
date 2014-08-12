#include "SettingManagement.h"


SettingManagement::SettingManagement()
{
}

SettingManagement::~SettingManagement()
{
}

void SettingManagement::changeBackgroundImage( int label )
{
	auto userDefaultInstance = UserDefault::getInstance();
	switch ( label )
	{
	case 1:
		userDefaultInstance -> setStringForKey( __BACKGROUND_IMAGE_NAME__,__BACK_GROUND_IMAGE_1__ );
		testLog::sharedtestLog() -> L(__BACK_GROUND_IMAGE_1__);
		break;
	case 2:
		userDefaultInstance -> setStringForKey( __BACKGROUND_IMAGE_NAME__,__BACK_GROUND_IMAGE_2__ );
		testLog::sharedtestLog() -> L(__BACK_GROUND_IMAGE_1__);
		break;
	case 3:
		userDefaultInstance -> setStringForKey( __BACKGROUND_IMAGE_NAME__,__BACK_GROUND_IMAGE_3__ );
		testLog::sharedtestLog() -> L(__BACK_GROUND_IMAGE_1__);
		break;
	default:
		userDefaultInstance -> setStringForKey( __BACKGROUND_IMAGE_NAME__,__BACK_GROUND_IMAGE_1__ );
		testLog::sharedtestLog() -> L(__BACK_GROUND_IMAGE_1__);
	}
	return;
	
}