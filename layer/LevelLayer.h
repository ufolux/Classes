#pragma once
#include "BaseLayer.h"

class LevelLayer: public BaseLayer
{
public:
	LevelLayer();
	~LevelLayer();

	virtual bool init();

	void setupView();

	CREATE_FUNC( LevelLayer );
private:
	Label*  m_LevelLabel;

};

