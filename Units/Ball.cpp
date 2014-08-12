#include "Ball.h"

Ball::Ball(){}
Ball::~Ball(){}

bool Ball::init(){

	bool sRect = false;

	do 
	{
		CC_BREAK_IF(!Sprite::init());

		setupView();
		
		sRect = true;
	} while (0);

	return sRect;
}







void Ball::setupView(){
	//1.add texture
	auto pannelTextrueCache = TextureCache::getInstance()->addImage(__BALL_IMAGE__);
	Rect rec = Rect::Rect(0, 0, 20, 20);
	this->initWithTexture(pannelTextrueCache);
}

bool Ball::isBallActive(){
	return _isBallActive;
}

void Ball::setBallActive( bool isActive ){
	_isBallActive = isActive;
}


