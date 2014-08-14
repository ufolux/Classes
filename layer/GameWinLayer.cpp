//
//  GameWinLayer.cpp


#include "GameWinLayer.h"



GameWinLayer::GameWinLayer(){
	
}
GameWinLayer::~GameWinLayer(){

}

bool GameWinLayer::init(){

	bool sRect = false; 

	do 
	{
		CC_BREAK_IF( !LayerColor::initWithColor( Color4B(0, 0, 0, 40)));

		setupViews();

		sRect = true;
		
	} while (0);


	return sRect;
}

void GameWinLayer::setupViews(){


	do {

		//   创建menu
		//get size
		auto size = CCDirector::getInstance()->getWinSize();
		
		//Create a font label
		auto winLabel = Label::create("You WIn!", __ARIRL__, 50);
		auto scoreLabel = Label::create("Your Score is 300", __ARIRL__, 40);
		winLabel->setPosition(visibleRect.center().x, visibleRect.center().y + 20);
		scoreLabel->setPosition(visibleRect.center().x, visibleRect.center().y - 20);
		this->addChild(winLabel);
		this->addChild(scoreLabel);

		//create resume and return menuItem
		auto resumeItem = MenuItemImage::create( __RESUME_GAME_NORMAL__, __RESUME_GAME_SELECTED__, CC_CALLBACK_1( GameWinLayer::restart_game_logic, this));

		auto to_return_mainmenu_font = Label::create( "Main Menu",__ARIRL__,40);
		auto to_return_mainmenu = MenuItemLabel::create( to_return_mainmenu_font,CC_CALLBACK_1(GameWinLayer::to_return_mainmenu_logic,this) );

		//set menu position

		resumeItem -> setPosition( Point(visibleRect.leftBottom().x + 80, visibleRect.leftBottom().y+150));
		to_return_mainmenu->setPosition(Point(visibleRect.rightBottom().x - 150, visibleRect.rightBottom().y + 150));

		//create Menu
		auto menu = Menu::create( resumeItem, to_return_mainmenu,nullptr);

		menu -> setPosition( Point::ZERO);

		this -> addChild( menu, 99 );

//
//
	} while (0);
//
}

void GameWinLayer::to_return_mainmenu_logic( Ref *pSender ){

	//  todo 调用gameworld 的返回菜单的逻辑

	GamingLayer* father =   static_cast<GamingLayer*>(this->getParent());
	
	father -> to_return_mainmenu();
	
	this->removeFromParentAndCleanup( true );
}


//  恢复逻辑
void GameWinLayer::restart_game_logic( Ref* pSender ){

	Director::getInstance()->replaceScene(GamingLayer::scene());
	

	//Director::getInstance() -> resume();

}



