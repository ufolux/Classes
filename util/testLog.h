#pragma once
#include <iostream>
#include "cocos2d.h"


USING_NS_CC;

class testLog{
public:
	const static bool flag = false;
public:
	testLog();
	~testLog();
	

	void L( const char * pszFormat, ... );


	static testLog* sharedtestLog();


	void purge();
};

