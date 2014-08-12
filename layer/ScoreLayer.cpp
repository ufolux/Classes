#include "GamingLayer.h"
#include "ScoreLayer.h"

ScoreLayer::ScoreLayer(){
	m_ScoreLabel = Label::create();
	CC_SAFE_RETAIN(m_ScoreLabel);
}
ScoreLayer::~ScoreLayer(){
	CC_SAFE_RELEASE(m_ScoreLabel);
}


bool ScoreLayer::init(){

	bool sRect = false;

	do 
	{
		CC_BREAK_IF( !BaseLayer::init() );

		setupView();

		sRect = true;
	} while (0);

	return sRect;
}


void ScoreLayer::setupView(){

	do 
	{
		//add score label
		m_ScoreLabel = Label::createWithBMFont( __ARIRL_14_FNT__, "Score: 20" );
		m_ScoreLabel -> setAnchorPoint( Point::ZERO );
		m_ScoreLabel -> setPosition( Point::ZERO );
		m_ScoreLabel -> setScale( 2.0f );
		//set tag 1 for score label 
		this -> addChild( m_ScoreLabel );
	} while (0);
	
}

