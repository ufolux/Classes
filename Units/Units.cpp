#include "Units.h"

Units::Units(){
	winSize = Director::getInstance() -> getWinSize();
	visibleSize = Director::getInstance() -> getVisibleSize();
	origin = Director::getInstance() -> getVisibleOrigin();
}
Units::~Units(){}

