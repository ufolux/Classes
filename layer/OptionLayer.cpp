#include "OptionLayer.h"
#include "cocos2d.h"
#include "WelcomeGameLayer.h"

//struct 
//{
//	const char* videoName;
//	std::function<Scene*()> callback;
//}gVideoNames[]={  };


OptionLayer::OptionLayer()
{
	
}

OptionLayer::~OptionLayer()
{
}

bool OptionLayer::init(){

	bool sRect = false;

	do
	{
		CC_BREAK_IF( !BaseLayer::init() );
		CC_BREAK_IF( !setUpView() );

		sRect = true;
	} while (0);
	
	return sRect;
}



bool OptionLayer::setUpView(){
	bool sRect = false;
	do 
	{

		//1.set background
		setBackgroundImage( UserDefault::getInstance() -> getStringForKey( __BACKGROUND_IMAGE_NAME__,__BACK_GROUND_IMAGE_1__ ).c_str() );
		
		//2.add a title

		auto pOptionTitle = MenuItemFont::create( "Option" );

		pOptionTitle -> setPosition( Point( winSize.width / 2, winSize.height - 40 ));

		this -> addChild( pOptionTitle );
		//3.add menu

		//a.sound switch
		

		MenuItemFont::setFontName(__ARIRL_14_FNT__);
		MenuItemFont::setFontSize(24);
		auto titleSound = MenuItemFont::create("Sound");
		titleSound -> setEnabled(false);
		MenuItemFont::setFontName( __ARIRL_14_FNT__ );
		MenuItemFont::setFontSize(34);
		auto pTrigger = MenuItemToggle::createWithCallback( CC_CALLBACK_1( OptionLayer::music_trigger_callback,this ),
			MenuItemFont::create( "Music: Off" ),
			MenuItemFont::create( "Music: On"),
			NULL );
		/**********setFont based on background music stats*******************************/
		if( !UserDefault::getInstance() -> getBoolForKey( __MUSIC_NOT_PLAYING__ ))
		{
			pTrigger -> setSelectedIndex(0);
		}else
		{
			pTrigger -> setSelectedIndex(1);
		}

		/******************************************************************************/
		pTrigger -> setPosition( Point( winSize.width / 2,winSize.height / 2 + 50));
		
		//b.exchange background pic
			//title
		MenuItemFont::setFontName( __ARIRL_14_FNT__ );
		MenuItemFont::setFontSize( 24 );
		auto titleSettingBackground = MenuItemFont::create( "Setting Background");
		titleSettingBackground -> setEnabled(false);

			//create 3 item 

		auto pBg1Item = MenuItemImage::create( __BACK_GROUND_IMAGE_1_NORMAL__,__BACK_GROUND_IMAGE_1_SELECTED__, [&](Ref *pSender){
			SettingManagement::changeBackgroundImage( BACK_GROUND_IMAGE_1 );
			setUpView();
		});
		
		auto pBg2Item = MenuItemImage::create( __BACK_GROUND_IMAGE_2_NORMAL__,__BACK_GROUND_IMAGE_2_SELECTED__, [&](Ref *pSender){
			SettingManagement::changeBackgroundImage( BACK_GROUND_IMAGE_2 );
			setUpView();
		});

		auto pBg3Item = MenuItemImage::create( __BACK_GROUND_IMAGE_3_NORMAL__,__BACK_GROUND_IMAGE_3_SELECTED__, [&](Ref *pSender){
			SettingManagement::changeBackgroundImage( BACK_GROUND_IMAGE_3 );
			setUpView();
		});

		//set button size
		pBg1Item -> setScaleX( 0.2f );
		pBg2Item -> setScaleX( 0.2f );
		pBg3Item -> setScaleX( 0.2f );
		pBg1Item -> setScaleY( 0.1f );
		pBg2Item -> setScaleY( 0.1f );
		pBg3Item -> setScaleY( 0.1f );


		//setPosition

		//c.GoBack
		
		MenuItemFont::setFontName( __ARIRL_14_FNT__ );
		MenuItemFont::setFontSize( 34 );
		auto pGoBack = MenuItemFont::create("Go Back",CC_CALLBACK_1(OptionLayer::menuReturnCallback ,this));

		pGoBack -> setPosition( Point(winSize.width / 2, origin.y + 40 ));



		//add above into menu
		auto MainMenu = Menu::create(titleSound, pTrigger ,pGoBack, nullptr );
		auto ViceMenu = Menu::create(pBg1Item, pBg2Item, pBg3Item, nullptr);
		ViceMenu -> alignItemsHorizontallyWithPadding( 10.0f );
		
		
		//set anchor point
		ViceMenu -> setAnchorPoint( Point( 0 , 0.5 ) );

		//set position
		MainMenu -> setPosition( Point::ZERO );
		ViceMenu -> setPosition( Point(winSize.width / 2, origin.y + 150 ));

		//add child 
		addChild( MainMenu );
		addChild( ViceMenu );

		sRect = true;
	} while (0);
	
	return sRect;
}

Scene* OptionLayer::scene(){
	Scene* sc;
	
	do 
	{
		sc =Scene::create();
		CC_BREAK_IF( !sc );
		auto layer = OptionLayer::create();
		CC_BREAK_IF( !layer );
		
		sc -> addChild( layer );
	} while (0);
	
	return sc;
}


void OptionLayer::menuReturnCallback( Ref* pSender ){
	auto scene = WelcomeGameLayer::scene();

	Director::getInstance() -> replaceScene( CCTransitionSlideInL::create( 0.1f,scene ));

}




void OptionLayer::music_trigger_callback( Ref* pSender ){
	
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

