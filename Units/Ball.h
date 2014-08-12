#pragma once

#include "Units/Units.h"
#include <iostream>

class Ball:public Units{
public:
	Ball();
	~Ball();

	virtual bool init();
	void setupView();
	
	bool isBallActive();
	void setBallActive( bool isActive );

	CREATE_FUNC( Ball );

	

private:
	Sprite* m_ball;
	bool _isBallActive;
};

