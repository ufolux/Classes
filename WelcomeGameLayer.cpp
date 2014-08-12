#include "WelcomeGameLayer.h"
#include "SimpleAudioEngine.h"
#include "layer/AboutLayer.h"
#include "layer/GamingLayer.h"
#include "layer/OptionLayer.h"





WelcomeGameLayer::WelcomeGameLayer(){
	
}
WelcomeGameLayer::~WelcomeGameLayer(){
}

bool WelcomeGameLayer::init(){
	bool sRect = false;

	do 
	{
		CC_BREAK_IF( !BaseLayer::init());
		CC_BREAK_IF( !setupView() );

		sRect = true;
	} while (0);

	return sRect;
}

void WelcomeGameLayer::onEnter(){
	BaseLayer::onEnter();
	
	
	bool flag = isFirstLoad;
 
	if (flag)
	{
		//play music when first time run
		CocosDenshion::SimpleAudioEngine::getInstance() -> playBackgroundMusic(__BACKGROUND_MUSIC__,true );
		UserDefault::getInstance() -> setBoolForKey( __MUSIC_NOT_PLAYING__,false );
		isFirstLoad = false;
	}
}

Scene* WelcomeGameLayer::scene(){
	auto sc = Scene::create();
	WelcomeGameLayer* layer = WelcomeGameLayer::create();
	sc->addChild(layer);

	return sc;
}

bool WelcomeGameLayer::setupView(){
	bool sRect = false;
	//option manager
	
	
	do 
	{

	
			//	//setting background pic by option
		testLog::sharedtestLog() -> L( __BACK_GROUND_IMAGE_1__ );
		setBackgroundImage( UserDefault::getInstance() -> getStringForKey( __BACKGROUND_IMAGE_NAME__, __BACK_GROUND_IMAGE_1__ ).c_str());

	
		
		//add logo into scene
		auto pLogo = Sprite::create( __LOGO_IMAGE__ );
		pLogo -> setAnchorPoint( Point( 0.5,1 ) );
		pLogo -> setPosition( Point(winSize.width/2, winSize.height/2 +150 ) );


  		
		this -> addChild( pLogo );
	
		
		//setting game menu
			//1.setting start game menu
		auto startGameItem = MenuItemImage::create( __START_GAME_NORMAL__ , __START_GAME_SELECTED__, CC_CALLBACK_1( WelcomeGameLayer::startGameCallback,this ));
		
			//2.setting option game menu
		auto optionGameItem = MenuItemImage::create( __OPTION_GAME_NORMAL__, __OPTION_GAME_SELECTED__, CC_CALLBACK_1( WelcomeGameLayer::optionGameCallback,this ));
		
			//3.setting aboout game menu
		auto aboutGameItem = MenuItemImage::create( __ABOUT_GAME_NORMAL__, __ABOUT_GAME_SELECTED__, CC_CALLBACK_1( WelcomeGameLayer::aboutGameCallback,this ));

		////add menu into scene
		//	//a.create menu
		auto pMenu = Menu::create( startGameItem,optionGameItem,aboutGameItem,nullptr );

		
		pMenu -> setPosition( Point( winSize.width / 2,winSize.height / 2 - 100 ));
		pMenu -> alignItemsVerticallyWithPadding( 10 );

		
			//b.add into scene
		this -> addChild( pMenu,1 );
		


		sRect = true;
	} while (0);
	
	return sRect;
}



void  WelcomeGameLayer::startGameCallback(cocos2d::Ref* pSender){
	Scene*  sc = GamingLayer::scene();
	Director::getInstance() -> replaceScene(CCTransitionSlideInR::create(0.1,sc));
}

void  WelcomeGameLayer::optionGameCallback(cocos2d::Ref* pSender){
	Scene*  sc = OptionLayer::scene();
	Director::getInstance() -> replaceScene(CCTransitionSlideInR::create(0.1,sc));
}

void  WelcomeGameLayer::aboutGameCallback(cocos2d::Ref* pSender){
	Scene*  sc = AboutLayer::scene();
	Director::getInstance() -> replaceScene(CCTransitionSlideInR::create(0.1,sc));
}


