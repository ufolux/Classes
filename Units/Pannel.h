#pragma once

#include "Units/Units.h"
#include <iostream>

class Pannel:public Units
{
public:
	Pannel();
	~Pannel();

	virtual bool init();

	void setupView();

	CREATE_FUNC( Pannel );
	

private:
	Point m_appearPosition;

	bool m_canApplyImpuse;

};

