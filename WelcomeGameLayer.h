#pragma  once
#include "BaseLayer.h"




class WelcomeGameLayer:public BaseLayer
{
public:
	WelcomeGameLayer();
	~WelcomeGameLayer();
	static cocos2d::Scene* scene();
	virtual bool init();
	CREATE_FUNC(WelcomeGameLayer);
	virtual void onEnter();

private:
	bool setupView();

	void startGameCallback(cocos2d::Ref* pSender);
	void optionGameCallback(cocos2d::Ref* pSender);
	void aboutGameCallback(cocos2d::Ref* pSender);


};

