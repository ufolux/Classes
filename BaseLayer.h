#pragma once
#include "cocos2d.h"
#include "util/testLog.h"
#include "SimpleAudioEngine.h"
#include "util/Resources.h"
#include "util/KeyString.h"
#include "util\VisibleRect.h"
#include "Management/SettingManagement.h"
#include "util\GLES-Render.h"

USING_NS_CC;

class BaseLayer:public cocos2d::Layer
{
public:
	BaseLayer();
	~BaseLayer();
	static cocos2d::Scene* scene();
	virtual bool init();


	CREATE_FUNC(BaseLayer);
	cocos2d::Size getWinSize();
	cocos2d::Size getVisibleSize();
	cocos2d::Point getWinOrigin();
	cocos2d::Point getWinCenter();
	cocos2d::Point convertSpriteRel(float x, float y);
	void setBackgroundImage( const char* back_image_name );


protected:
	cocos2d::Point origin;
	cocos2d::Size winSize;
	cocos2d::Size visibleSize;
private:

};


