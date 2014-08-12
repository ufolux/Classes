#pragma once

#include "cocos2d.h"
#include "BaseLayer.h"

class DirectorTest:public BaseLayer
{
public:
	DirectorTest();
	~DirectorTest();

	virtual bool init();

	virtual void onEnter();

	CREATE_FUNC( DirectorTest );

private:

};

