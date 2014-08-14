#pragma  once

#include "BaseLayer.h"
#include "WelcomeGameLayer.h"
#include "GameOverLayer.h"
#include "PauseLayer.h"
#include "GameWinLayer.h"
#include "Units/Pannel.h"
#include "ScoreLayer.h"
#include "LevelLayer.h"
#include "Units/Ball.h"
#include "Management/MyContactListener.h"

#include "Box2D/Box2D.h"

class GamingLayer:public BaseLayer
{
public:
	GamingLayer();
	~GamingLayer();

	virtual bool init();
	//box2d
	
	static Scene* scene();
	
	CREATE_FUNC( GamingLayer );

	virtual void onExit();


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
	void addBlocks();
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
	b2MouseJoint *m_mouseJoint;// Û±Í¡¥Ω”

	Menu* m_pauseMenu;
	PauseLayer* m_pauseLayer;
	Pannel* m_pannel;
	Ball* m_ball;
	Sprite* m_footer;
	//world
	b2World* m_world;
	//ball
	b2Body *m_ballBody;
	b2Fixture *m_ballFixtrue;
	//pannel
	b2Body *m_pannelBody;
	b2Fixture *m_pannelFixtrue;
	//ground
	b2Body *m_groundBody;
	
	//bottom fixtrue
	b2Fixture *m_bottomFixtrue;

	//contact listener
	MyContactListener*m_contactListener;
};
