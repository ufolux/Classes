#pragma once

#include "Units/Units.h"
#include <iostream>

class Ball:public Units{
public:
	Ball();
	~Ball();

	virtual bool init();
	void setupView();
	

	CREATE_FUNC( Ball );

	

private:
	Sprite* m_ball;
	bool _isBallActive;
};

