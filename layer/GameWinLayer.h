#pragma  once

#include "BaseLayer.h"
#include "WelcomeGameLayer.h"
#include "GamingLayer.h"
#include "util\VisibleRect.h"

class GameWinLayer:public LayerColor
{
public:
	GameWinLayer();
	~GameWinLayer();

	virtual bool init();

	static Scene* scene();

	void setupViews();

	CREATE_FUNC(GameWinLayer);



	void menuReturnCallback( Ref* pSender );

	void to_return_mainmenu_logic( Ref* pSender );

	void restart_game_logic( Ref* pSender );

private:
	VisibleRect visibleRect;

	bool setUpView();

};
