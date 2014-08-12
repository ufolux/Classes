#include "DirectorTest.h"

DirectorTest::DirectorTest(){}
DirectorTest::~DirectorTest(){}

void DirectorTest::onEnter(){
	BaseLayer::onEnter();
}

bool DirectorTest::init(){

	bool sRect = false;
	do 
	{
		CC_BREAK_IF( !BaseLayer::init() );

		sRect = true;
	} while (0);

	return sRect;
}
