#include "GamingLayer.h"



using namespace cocos2d;



GamingLayer::GamingLayer(){

	m_pauseLayer = PauseLayer::create();
	CC_SAFE_RETAIN( m_pauseLayer );

}
GamingLayer::~GamingLayer(){

	CC_SAFE_RELEASE(m_pannel);
	CC_SAFE_RELEASE(m_ball);
	CC_SAFE_RELEASE( m_pauseLayer );
	CC_SAFE_DELETE(m_world);
}

bool GamingLayer::init(){
	bool sRect = false;

	do
	{
		CC_BREAK_IF( !BaseLayer::init() );
		initPhysics();
		CC_BREAK_IF( !setUpView() );
		

		sRect = true;
	} while (0);

	return sRect;
}

void GamingLayer::initPhysics(){
	//create phy world
	//set gravity 
	b2Vec2 gravity = b2Vec2(0.0f, -10.0f);
	m_world = new b2World(gravity);
	//set allow sleeping
	m_world->SetAllowSleeping(true);
	//continuously detect collision
	m_world->SetContinuousPhysics(true);
	
	//debug
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_pairBit;
	debugDraw = new GLESDebugDraw(PTM_RATIO);
	m_world->SetDebugDraw(debugDraw);
	debugDraw->SetFlags(flags);
	//debug end

	//add floor body
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);
	m_groundBody = m_world->CreateBody(&groundBodyDef);
	
	b2EdgeShape groundBox;


	// bottom
	groundBox.Set(b2Vec2(VisibleRect::leftBottom().x / PTM_RATIO, (VisibleRect::leftBottom().y+95) / PTM_RATIO), b2Vec2(VisibleRect::rightBottom().x / PTM_RATIO, (VisibleRect::rightBottom().y+95) / PTM_RATIO));
	m_groundBody->CreateFixture(&groundBox,0);

	// top
	groundBox.Set(b2Vec2(VisibleRect::leftTop().x / PTM_RATIO, (VisibleRect::leftTop().y-10) / PTM_RATIO), b2Vec2(VisibleRect::rightTop().x / PTM_RATIO, (VisibleRect::rightTop().y-10) / PTM_RATIO));
	m_groundBody->CreateFixture(&groundBox, 0);

	// left
	groundBox.Set(b2Vec2(VisibleRect::leftTop().x / PTM_RATIO, VisibleRect::leftTop().y / PTM_RATIO), b2Vec2(VisibleRect::leftBottom().x / PTM_RATIO, VisibleRect::leftBottom().y / PTM_RATIO));
	m_groundBody->CreateFixture(&groundBox, 0);

	// right
	groundBox.Set(b2Vec2(VisibleRect::rightBottom().x / PTM_RATIO, VisibleRect::rightBottom().y / PTM_RATIO), b2Vec2(VisibleRect::rightTop().x / PTM_RATIO, VisibleRect::rightTop().y / PTM_RATIO));
	m_groundBody->CreateFixture(&groundBox, 0);

}


Scene* GamingLayer::scene(){
	Scene* sc;

	do 
	{
		sc = Scene::create();
		CC_BREAK_IF( !sc );
		
		auto layer = GamingLayer::create();
		CC_BREAK_IF( !layer );
		sc -> getPhysicsWorld();

		sc -> addChild( layer );
		
	} while (0);

	return sc;
}


bool GamingLayer::setUpView(){
	bool sRect = false;

	do 
	{
		//setbackground
		//setBackgroundImage( UserDefault::getInstance() -> getStringForKey( __BACKGROUND_IMAGE_NAME__,__BACK_GROUND_IMAGE_1__ ).c_str() );
		//set pause menu
		auto pPause = MenuItemImage::create( __PAUSE_GAME_NORMAL__,__PAUSE_GAME_SELECTED__, CC_CALLBACK_1( GamingLayer::pauseGameCallback,this ));

		//set m_footer
		m_footer = Sprite::create(__FOOTER_IMAGE__ , Rect(0,0,400,84));
		m_footer -> setAnchorPoint(Point(0.5f,0));
		m_footer -> setPosition(winSize.width / 2, origin.y + 0);
		this -> addChild(m_footer,1);

		//set menu 
		m_pauseMenu = Menu::create( pPause,nullptr );
		m_pauseMenu -> setAnchorPoint( Point(1,1));
		m_pauseMenu -> setPosition(Point( winSize.width - 25 , winSize.height - 25 ));

					
		this -> addChild( m_pauseMenu,2 );
		

		//set label
			//score
		auto score_layer = ScoreLayer::create();
		score_layer -> setAnchorPoint( Point::ZERO );
		score_layer -> setPosition( origin.x + 10, origin.y + 15 );

		this -> addChild( score_layer,2,1 );
			
			//level
		auto level_layer = LevelLayer::create();
        level_layer -> setAnchorPoint( Point(1, 0));
		level_layer -> setPosition( winSize.width - 150,origin.y + 15);

		this -> addChild( level_layer,2,2 );

		//add pannel
		m_pannel = Pannel::create();
		m_pannel->setAnchorPoint(Point(0.5f, 0.5f));
		m_pannel->setPosition(winSize.width / 2, origin.y + 105.0f);
		this -> addChild( m_pannel,1 );
		this->definePannel();
		
		//add ball
		m_ball = Ball::create();
		m_ball->setAnchorPoint(Point(0.5f, 0.5f));
		m_ball->setPosition(Point(winSize.width / 2, origin.y + 134));
		this->addChild(m_ball, 1);
		this->defineBall();

		//call update
		this->scheduleUpdate();


		//touch listener
		EventListener* listener = EventListenerTouchOneByOne::create();



		sRect = true;
	} while (0);

	return sRect;
}

//return to WelcomeGameLayerl
void GamingLayer::to_return_mainmenu(){

	Director::getInstance() -> resume();

	auto sc = WelcomeGameLayer::scene();

	Director::getInstance() -> replaceScene( CCTransitionSlideInL::create(0.1f, sc) );

}



//pause game 
void GamingLayer::pauseGameCallback( Ref* pSender ){
	//
	

	//add pause layer
	this -> addChild( PauseLayer::create(),99,99 );
	//pause game
	Director::getInstance() -> pause();

	if (Director::getInstance()->isPaused())
	{
		m_pauseMenu -> setEnabled(false);
	}else{
		m_pauseMenu -> setEnabled(true);
	}
}
//return game callback
void GamingLayer::resumeGameCallback( Ref* pSender ){
	

	Director::getInstance() -> resume();

	if (Director::getInstance()->isPaused())
	{
		m_pauseMenu -> setEnabled(false);
	}else{
		m_pauseMenu -> setEnabled(true);
	}

	testLog::sharedtestLog()->L("resume");
}

 



void GamingLayer::defineBall(){
	b2CircleShape ballShape;
	b2BodyDef ballBodyDef;
	//define the chracteristic for the ball
	ballShape.m_radius = 20 / PTM_RATIO; 
	b2FixtureDef ballFixtrue;
	ballFixtrue.density = 10;
	ballFixtrue.friction = 0.1f;
	ballFixtrue.restitution = 1.0f;
	ballFixtrue.shape = &ballShape;

	
	ballBodyDef.type = b2_dynamicBody;
	ballBodyDef.userData = m_ball;
			   
	ballBodyDef.position.Set((m_ball->getPosition().x / PTM_RATIO), (m_ball->getPosition().y / PTM_RATIO) );

	ballBody = m_world->CreateBody(&ballBodyDef);
	ballBody->CreateFixture(&ballFixtrue);
	ballBody->SetGravityScale(10);

}


void GamingLayer::definePannel(){
	b2PolygonShape pannelShape;//rectangle
	b2BodyDef pannelBodyDef;
	pannelShape.SetAsBox(57.5f / PTM_RATIO, 9.5f / PTM_RATIO);//half w and h of body
	
	b2FixtureDef pannelFixtrue;
	pannelFixtrue.density = 10;
	pannelFixtrue.friction = 0.3f;
	pannelFixtrue.restitution = 0;
	pannelFixtrue.shape = &pannelShape;
	
	pannelBodyDef.type = b2_dynamicBody;
	pannelBodyDef.userData = m_pannel;
	pannelBodyDef.position.Set((m_pannel->getPosition().x / PTM_RATIO), (m_pannel->getPosition().y / PTM_RATIO));

	pannelBody = m_world->CreateBody(&pannelBodyDef);
	pannelBody->CreateFixture(&pannelFixtrue);
	pannelBody->SetGravityScale(10);
}

void GamingLayer::update(float dt){
	int positionIterations = 10;
	int velocityIterations = 10;
	deltaTime = dt;
	m_world->Step(deltaTime, velocityIterations, positionIterations);
	for (b2Body *body = m_world->GetBodyList(); body != nullptr; body = body->GetNext())
	{
		if ( body -> GetUserData() )
		{
			auto sprite = (Sprite*)body->GetUserData();
			sprite->setPosition(Point::Point(body->GetPosition().x * PTM_RATIO, body->GetPosition().y * PTM_RATIO));
			
		}
	}

	m_world->ClearForces();
	m_world->DrawDebugData();
}



//debug
void GamingLayer::draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated)
{
	    //glDisable(GL_TEXTURE_2D);
	    //glDisableClientState(GL_COLOR_ARRAY);
	    //glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	
	    //m_world->DrawDebugData();   //这个一定要写  
	
	    //glEnable(GL_TEXTURE_2D);
	    //glEnableClientState(GL_COLOR_ARRAY);
	    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	    Layer::draw(renderer, transform, transformUpdated);

		GL::enableVertexAttribs(cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION);

		kmGLPushMatrix();
		kmGLGetMatrix(KM_GL_MODELVIEW, &_modelViewMV);

		_customCommand.init(_globalZOrder);
		_customCommand.func = CC_CALLBACK_0(GamingLayer::onDraw, this);
		renderer->addCommand(&_customCommand);

		kmGLPopMatrix();
	}

void GamingLayer::onDraw()
{
	kmMat4 oldMV;
	kmGLGetMatrix(KM_GL_MODELVIEW, &oldMV);
	kmGLLoadMatrix(&_modelViewMV);
	m_world->DrawDebugData();
	kmGLLoadMatrix(&oldMV);
}
//debug end