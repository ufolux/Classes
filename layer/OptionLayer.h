#pragma  once

#include "BaseLayer.h"


class OptionLayer:public BaseLayer
{
public:
	OptionLayer();
	~OptionLayer();

	virtual bool init();
	
	static Scene* scene();

	CREATE_FUNC( OptionLayer );

	void menuReturnCallback( Ref* pSender );

	void music_trigger_callback( Ref* pSender );


private:
	
	bool setUpView();

	enum backgroundPics
	{
		BACK_GROUND_IMAGE_1 = 1,
		BACK_GROUND_IMAGE_2,
		BACK_GROUND_IMAGE_3
	};
	
};

