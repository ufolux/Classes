//
//  PauseLayer.cpp
//  MyMoonWarrior
//
//  Created by cesc on 13-3-10.
//
//

#include "PauseLayer.h"
#include "GamingLayer.h"


PauseLayer::PauseLayer(){}
PauseLayer::~PauseLayer(){}

bool PauseLayer::init(){

	bool sRect = false; 

	do 
	{
		CC_BREAK_IF( !LayerColor::initWithColor( Color4B(0, 0, 0, 40)));

		setupViews();

		sRect = true;
		
	} while (0);


	return sRect;
}

void PauseLayer::setupViews(){


	do {

		//   创建menu
		//get size
		auto size = CCDirector::getInstance()->getWinSize();
		
		//create resume and return menuItem
		auto resumeItem = MenuItemImage::create( __RESUME_GAME_NORMAL__, __RESUME_GAME_SELECTED__, CC_CALLBACK_1( PauseLayer::resume_game_logic, this));
/*****************************toggle********************/
		auto music_trigger = MenuItemToggle::createWithCallback(CC_CALLBACK_1(PauseLayer::musicTriggerCallback,this),
			MenuItemImage::create(__BACKGROUND_MUSIC_PLAY__,__BACKGROUND_MUSIC_PLAY__),
			MenuItemImage::create(__BACKGROUND_MUSIC_PAUSE__,__BACKGROUND_MUSIC_PAUSE__),
			nullptr);

		if ( !UserDefault::getInstance() -> getBoolForKey( __MUSIC_NOT_PLAYING__ ))
			music_trigger -> setSelectedIndex(1);
		else
			music_trigger -> setSelectedIndex(0);
/********************************************************/

		auto to_return_mainmenu_font = Label::create( "Main Menu",__ARIRL__,40);
		auto to_return_mainmenu = MenuItemLabel::create( to_return_mainmenu_font,CC_CALLBACK_1(PauseLayer::to_return_mainmenu_logic,this) );

		//set menu position
		music_trigger -> setPosition( Point(size.width / 2 , size.height / 2 + 80));
		resumeItem -> setPosition( Point(size.width / 2,size.height / 2));
		to_return_mainmenu -> setPosition( Point(size.width / 2, size.height / 2 - 80));

		//create Menu
		auto menu = Menu::create( resumeItem, to_return_mainmenu,music_trigger,nullptr);

		menu -> setPosition( Point::ZERO);

		this -> addChild( menu );

//
//
	} while (0);
//
}

void PauseLayer::to_return_mainmenu_logic( Ref *pSender ){

	//  todo 调用gameworld 的返回菜单的逻辑

	GamingLayer* father =   static_cast<GamingLayer*>(this->getParent());
	
	father -> to_return_mainmenu();
	
	this->removeFromParentAndCleanup( true );
}


//  恢复逻辑
void PauseLayer::resume_game_logic( Ref* pSender ){

	GamingLayer* father = static_cast<GamingLayer*>(this->getParent());

	father -> resumeGameCallback( pSender );

	this->removeFromParentAndCleanup( true );

	Director::getInstance() -> resume();

}


//void pauselayer::registerwithtouchdispatcher(void){    
//
//
//	cclayer::registerwithtouchdispatcher();
//
//
//	ccdirector::shareddirector()->gettouchdispatcher()->addtargeteddelegate(this,-129 ,true	);
//
//}

//music trigger
void PauseLayer::musicTriggerCallback( Ref* pSender ){
	if (UserDefault::getInstance() -> getBoolForKey(__MUSIC_NOT_PLAYING__))
	{
		CocosDenshion::SimpleAudioEngine::getInstance() -> resumeBackgroundMusic();
		UserDefault::getInstance() -> setBoolForKey(__MUSIC_NOT_PLAYING__,false);
		CCLOG("music is playing");
	}else
	{

		CocosDenshion::SimpleAudioEngine::getInstance() -> pauseBackgroundMusic();
		CCLOG("music stop");
		UserDefault::getInstance() -> setBoolForKey(__MUSIC_NOT_PLAYING__,true);
	}
}