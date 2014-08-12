#pragma  once

#include "BaseLayer.h"
#include "WelcomeGameLayer.h"


class PauseLayer:public LayerColor
{
public:
	PauseLayer();
	~PauseLayer();

	virtual bool init();

	static Scene* scene();

	void setupViews();

	CREATE_FUNC( PauseLayer );



	void menuReturnCallback( Ref* pSender );

	void to_return_mainmenu_logic( Ref* pSender );

	void resume_game_logic( Ref* pSender );

	void musicTriggerCallback( Ref* pSender );

private:


	bool setUpView();

};
