#include "AboutLayer.h"
#include "WelcomeGameLayer.h"
USING_NS_CC;

AboutLayer::AboutLayer()
{

}

AboutLayer::~AboutLayer()
{
}

bool AboutLayer::init()
{
	bool sRect = false;
	do 
	{
		CC_BREAK_IF( !BaseLayer::init() );
		CC_BREAK_IF( !setupView() );
		sRect=true;
	} while (0);
	return sRect;
}


bool AboutLayer::setupView()
{
	bool sRect = false;
	
	do 
	{
		//set bgImage
		setBackgroundImage( __BACK_GROUND_IMAGE_1__ );

		//add game logo
		auto pLogo = Sprite::create( "logo.png");

		pLogo -> setPosition( winSize.width / 2, winSize.height / 2 + 50);

		this -> addChild( pLogo );

		//add about information
		auto pLabelAbout = LabelBMFont::create( "About Game",__ARIRL_14_FNT__);

		pLabelAbout -> setPosition( winSize.width / 2,winSize.height / 2 - 20 );

		this -> addChild( pLabelAbout );

		//add a GoBack button
		auto pLabelGoBack = LabelBMFont::create( "GoBack" , __ARIRL_14_FNT__ );
		pLabelGoBack -> setScale( 2.5f );

		auto pGoBackMenu = MenuItemLabel::create( pLabelGoBack, CC_CALLBACK_1( AboutLayer::menuReturnCallback,this ));
		
		auto menu = Menu::create( pGoBackMenu,nullptr );

		menu -> setAnchorPoint( Point(0.5,1) );
		menu ->setPosition( winSize.width / 2, origin.y + 40);

		this -> addChild( menu );


		sRect = true;

	} while (0);
	return sRect;
}

cocos2d::Scene*AboutLayer:: scene(){
	
	Scene* sc;
	do 
	{
		sc = Scene::create();
		CC_BREAK_IF( !sc );
		AboutLayer* layer = AboutLayer::create();
		CC_BREAK_IF( !layer );
		sc -> addChild( layer );
	} while (0);
	

	return sc;
}

void AboutLayer::menuReturnCallback(Ref* pSender)
{
	auto scene = WelcomeGameLayer::scene();
	Director::getInstance()->replaceScene(CCTransitionSlideInL::create(0.25f,scene)); 
}

