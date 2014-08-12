#pragma once
#include "BaseLayer.h"

class ScoreLayer: public BaseLayer
{
public:
	ScoreLayer();
	~ScoreLayer();

	virtual bool init();

	void setupView();

	CREATE_FUNC( ScoreLayer );
private:
	Label*  m_ScoreLabel;

};

