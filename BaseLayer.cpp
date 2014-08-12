#include "BaseLayer.h"

USING_NS_CC;

BaseLayer::BaseLayer()
{
	origin  = getWinOrigin();
	winSize = getWinSize();
	visibleSize = getVisibleSize();
}

BaseLayer::~BaseLayer()
{
}


cocos2d::Scene* BaseLayer::scene(){
	Scene* scene = Scene::create();
	BaseLayer* layer = BaseLayer::create();
	scene -> addChild( layer );
	return scene;
}

bool BaseLayer::init(){
	bool sRect = false;
	do 
	{
		CC_BREAK_IF( !Layer::init() );
		sRect = true;

	} while (0);
	return sRect;
}


cocos2d::Size BaseLayer::getVisibleSize(){
	return Director::getInstance() -> getVisibleSize();
}

cocos2d::Size BaseLayer::getWinSize(){
	return Director::getInstance() -> getWinSize();
}

cocos2d::Point BaseLayer::getWinOrigin(){
	return Director::getInstance() -> getVisibleOrigin();
}

cocos2d::Point BaseLayer::getWinCenter(){
	return Point(getWinSize().width/2 + getWinOrigin().x,getWinSize().height/2 + getWinOrigin().y);
}

cocos2d::Point BaseLayer::convertSpriteRel(float x, float y){
	return Point(x + getWinOrigin().x, y + getWinOrigin().y);
}

void BaseLayer::setBackgroundImage( const char* back_image_name ){
	Sprite *sp = Sprite::create( back_image_name );
	Size winSize = getWinSize();
	//sp -> setPosition( Point( getWinSize().width/2, getWinSize().height/2 ));
	sp -> setScaleX( winSize.width / sp -> getContentSize().width );
	sp -> setScaleY( winSize.height / sp -> getContentSize().height );

	sp -> setAnchorPoint( Point::ZERO );

	this -> addChild( sp );
}