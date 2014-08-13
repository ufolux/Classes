//
//  GameOverLayer.cpp


#include "GameOverLayer.h"



GameOverLayer::GameOverLayer(){
	
}
GameOverLayer::~GameOverLayer(){

}

bool GameOverLayer::init(){

	bool sRect = false; 

	do 
	{
		CC_BREAK_IF( !LayerColor::initWithColor( Color4B(0, 0, 0, 40)));

		setupViews();

		sRect = true;
		
	} while (0);


	return sRect;
}

void GameOverLayer::setupViews(){


	do {

		//   创建menu
		//get size
		auto size = CCDirector::getInstance()->getWinSize();
		
		//create resume and return menuItem
		auto resumeItem = MenuItemImage::create( __RESUME_GAME_NORMAL__, __RESUME_GAME_SELECTED__, CC_CALLBACK_1( GameOverLayer::restart_game_logic, this));

		auto to_return_mainmenu_font = Label::create( "Main Menu",__ARIRL__,40);
		auto to_return_mainmenu = MenuItemLabel::create( to_return_mainmenu_font,CC_CALLBACK_1(GameOverLayer::to_return_mainmenu_logic,this) );

		//set menu position

		resumeItem -> setPosition( Point(visibleRect.leftBottom().x + 80, visibleRect.leftBottom().y+150));
		to_return_mainmenu->setPosition(Point(visibleRect.rightBottom().x - 150, visibleRect.rightBottom().y + 150));

		//create Menu
		auto menu = Menu::create( resumeItem, to_return_mainmenu,nullptr);

		menu -> setPosition( Point::ZERO);

		this -> addChild( menu );

//
//
	} while (0);
//
}

void GameOverLayer::to_return_mainmenu_logic( Ref *pSender ){

	//  todo 调用gameworld 的返回菜单的逻辑

	GamingLayer* father =   static_cast<GamingLayer*>(this->getParent());
	
	father -> to_return_mainmenu();
	
	this->removeFromParentAndCleanup( true );
}


//  恢复逻辑
void GameOverLayer::restart_game_logic( Ref* pSender ){

	GamingLayer* father = static_cast<GamingLayer*>(this->getParent());

	father-> removeAllChildrenWithCleanup(true);
	father->release();
	Director::getInstance()->replaceScene(GamingLayer::scene());
	

	//Director::getInstance() -> resume();

}



