#pragma once
#include "BaseLayer.h"


class AboutLayer:public BaseLayer
{
public:
	AboutLayer();
	~AboutLayer();
	virtual bool init();
	static cocos2d::Scene* scene();
	CREATE_FUNC(AboutLayer);
	void menuReturnCallback(cocos2d::Ref* pSender);

private:
	bool setupView();

	
	
};

