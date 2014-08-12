#pragma once

#include "cocos2d.h"
#include "util/KeyString.h"
#include "util/Resources.h"
#include <iostream>

USING_NS_CC;

//class CustomKeyPadDelegate

class Units:public Sprite
{
public:
	Units();
	~Units();

public:
	Size winSize;
	Size visibleSize;
	Point origin;

};

