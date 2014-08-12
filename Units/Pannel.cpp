#include "Pannel.h"

Pannel::Pannel():m_appearPosition(winSize.width / 2,origin.y + 95),m_canApplyImpuse( false )
{}
Pannel::~Pannel(){}

bool Pannel::init(){

	bool sRect = false;

	do 
	{
		CC_BREAK_IF( !Sprite::init() );
		
		setupView();

		sRect = true;
	} while (0);

	return sRect;
}





//Scene* Pannel::scene(){
//
//	Scene* sc;
//
//	do 
//	{
//		sc = Scene::create();
//		CC_BREAK_IF( !sc );
//
//		auto layer = Pannel::create();
//		CC_BREAK_IF( !layer );
//
//		sc -> addChild( layer );
//
//	} while (0);
//
//	return sc;
//}


void Pannel::setupView(){

	//1.add textrue
	auto pannelTextrueCache = TextureCache::getInstance()->addImage(__PANNEL_TXETRUE__);
	Rect rec = Rect::Rect(0, 0, 115, 19);
	this->initWithTexture(pannelTextrueCache);

	//2.set frame
	auto frame0 = SpriteFrame::createWithTexture(pannelTextrueCache, Rect::Rect(0, 19, 115, 19));
	auto frame1 = SpriteFrame::createWithTexture(pannelTextrueCache, Rect::Rect(0, 0, 115, 19));

	Vector<SpriteFrame*> animFrames;

	animFrames.pushBack(frame0);
	animFrames.pushBack(frame1);

	//3.add animation
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	auto animate = Animate::create(animation);
	this->runAction(RepeatForever::create( animate));


	//4.add touch listener and connect them together
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	//touch began(lambda expression)
	listener->onTouchBegan = [](Touch* touch, Event* event){
		//get Current touch location
		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size size = target->getContentSize();
		Rect rect = Rect::Rect(0, 0, size.width, size.height);

		//judge whether the touch point in target range or not
		if (rect.containsPoint(locationInNode))
		{
			return true;
		}
		else
		{
			return false;
		}

	};

	//touch moved
	listener->onTouchMoved = [](Touch* touch, Event* event){

		Size m_visibleSize = Director::getInstance()->getVisibleSize();

		auto target = static_cast<Sprite*>(event->getCurrentTarget());

		auto m_target_size = target->getContentSize();
		auto m_delta = touch->getDelta();
		auto m_targetPosition = target->getPosition();


		//restrict the move range of sprite
		if (m_targetPosition.x - m_target_size.width / 2 + m_delta.x > 0 && m_targetPosition.x + m_target_size.width / 2 + m_delta.x < m_visibleSize.width)
			target->setPosition(m_targetPosition.x + m_delta.x, m_targetPosition.y + 0);

	};

	//ended
	listener->onTouchEnded = [](Touch* touch, Event* event){
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);




	//m_pannel = Sprite::create( __PANNEL_IMAGE__, Rect::Rect(0,0,120,19) );
	//m_pannel -> setAnchorPoint( Point(0.5f,1) );
	//m_pannel -> setPosition( Point(winSize.width / 2, origin.y + 105) );
	//this -> addChild( m_pannel );
	//
	////2.add animation
	//auto animation = Animation::create();
	//animation -> setDelayPerUnit( 0.1f );
	//
	//animation -> addSpriteFrame( SpriteFrame::create( __PANNEL_IMAGE__,Rect::Rect(0,0,120,19)) );
	//animation -> addSpriteFrame( SpriteFrame::create( __PANNEL_FLASH_IMAGE__,Rect::Rect(0,0,120,19)));
	//
	//
	//auto animate = Animate::create(animation);
	//
	//m_pannel -> runAction( RepeatForever::create(animate));
	//
	//

}