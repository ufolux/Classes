#pragma once
#include "GamingLayer.h"
#include "LevelLayer.h"

LevelLayer::LevelLayer(){
	m_LevelLabel = Label::create();
	CC_SAFE_RETAIN(m_LevelLabel);
}
LevelLayer::~LevelLayer(){
	CC_SAFE_RELEASE(m_LevelLabel);
}


bool LevelLayer::init(){

	bool sRect = false;

	do 
	{
		CC_BREAK_IF( !BaseLayer::init() );

		setupView();

		sRect = true;
	} while (0);

	return sRect;
}


void LevelLayer::setupView(){

	do 
	{
		//add score label
		m_LevelLabel = Label::createWithBMFont( __ARIRL_14_FNT__, "Level: 1" );
		m_LevelLabel -> setAnchorPoint( Point::ZERO );
		m_LevelLabel -> setPosition( Point::ZERO );
		m_LevelLabel -> setScale( 2.0f );
		//set tag 1 for score label 
		this -> addChild( m_LevelLabel );
	} while (0);
	
}

