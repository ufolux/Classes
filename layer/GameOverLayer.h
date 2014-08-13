#pragma  once

#include "BaseLayer.h"
#include "WelcomeGameLayer.h"
#include "GamingLayer.h"
#include "util\VisibleRect.h"

class GameOverLayer:public LayerColor
{
public:
	GameOverLayer();
	~GameOverLayer();

	virtual bool init();

	static Scene* scene();

	void setupViews();

	CREATE_FUNC(GameOverLayer);



	void menuReturnCallback( Ref* pSender );

	void to_return_mainmenu_logic( Ref* pSender );

	void restart_game_logic( Ref* pSender );

private:
	VisibleRect visibleRect;

	bool setUpView();

};
