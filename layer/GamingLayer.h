#pragma  once

#include "BaseLayer.h"
#include "WelcomeGameLayer.h"
#include "PauseLayer.h"
#include "Units/Pannel.h"
#include "ScoreLayer.h"
#include "LevelLayer.h"
#include "Units/Ball.h"

#include "Box2D/Box2D.h"

class GamingLayer:public BaseLayer,public b2ContactListener
{
public:
	GamingLayer();
	~GamingLayer();

	virtual bool init();
	//box2d
	
	static Scene* scene();
	
	CREATE_FUNC( GamingLayer );


	//pause layer
	//child layer (pauselayer) will call this func to resume game 
	//because this layer should be destroyed when user return from pauselayer to welcomelayer 
	void resumeGameCallback( Ref* pSender );
	bool setUpView();
	void pauseGameCallback( Ref* pSender );
	void musicTriggerCallback( Ref* pSender );
	void to_return_mainmenu();
	void update( float dt );
	void initPhysics();

	void defineBall();
	void definePannel();

	//debug
	GLESDebugDraw *debugDraw;
	virtual void draw(Renderer *renderer, const kmMat4& transform, bool transformUpdated)override;
protected:
	kmMat4 _modelViewMV;
	void onDraw();
	CustomCommand _customCommand;
//debug end
	//
private:

	void addWall(float x1, float y1, float x2, float y2);
	float deltaTime;


	Menu* m_pauseMenu;
	PauseLayer* m_pauseLayer;
	Pannel* m_pannel;
	Ball* m_ball;
	Sprite* m_footer;
	//world
	b2World* m_world;
	//ball
	b2Body *ballBody;

	//pannel
	b2Body *pannelBody;

	//ground
	b2Body *m_groundBody;
	
};
