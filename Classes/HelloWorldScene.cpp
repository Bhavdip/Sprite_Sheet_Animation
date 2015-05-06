#include "HelloWorldScene.h"


using namespace cocos2d;


Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();


    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool HelloWorld::init() {
    if ( !LayerColor::initWithColor(Color4B(255, 255, 255, 255))) return false;
    return true;
}


void HelloWorld::onEnter() {
    LayerColor::onEnter();

    TimeblastSprite();

    TickingBombSprite();
}


void HelloWorld::TimeblastSprite(){

	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("timeblast.plist");

	SpriteBatchNode* spritesheet = SpriteBatchNode::create("timeblast.png");
	this->addChild(spritesheet);

	Vector<SpriteFrame*> gooberFrames(16);
	for(int i = 1; i <= 16; i++) {
		SpriteFrame* frame = frameCache->getSpriteFrameByName(StringUtils::format("Time_blast_%d.png", i));
		gooberFrames.pushBack(frame);
	}

	Animation* runAnim = Animation::createWithSpriteFrames(gooberFrames, 0.3);
	Sprite* goober = Sprite::createWithSpriteFrameName("Time_blast_1.png");

	Size winsize = Director::getInstance()->getWinSize();
	goober->setPosition(Point(winsize.width*0.5, winsize.height- goober->getContentSize().height/2));

	Action* action = RepeatForever::create( Animate::create(runAnim) );

	goober->runAction(action);

	spritesheet->addChild(goober);
}

void HelloWorld::TickingBombSprite(){

	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("tickingbomb.plist");

	SpriteBatchNode* spritesheet_tickingbomb = SpriteBatchNode::create("tickingbomb.png");
	this->addChild(spritesheet_tickingbomb);

	Vector<SpriteFrame*> spriteFrame(20);
	for(int i = 1; i <= 20; i++) {
		SpriteFrame* frame = frameCache->getSpriteFrameByName(StringUtils::format("TickingBomb_%d.png", i));
		spriteFrame.pushBack(frame);
	}

	Animation* runAnim = Animation::createWithSpriteFrames(spriteFrame, 0.3);
	Sprite* sprite_ticking_bomb = Sprite::createWithSpriteFrameName("TickingBomb_1.png");

	Size winsize = Director::getInstance()->getWinSize();
	sprite_ticking_bomb->setPosition(Point(winsize.width*0.5, winsize.height*0.5));

	Action* action = RepeatForever::create( Animate::create(runAnim) );

	sprite_ticking_bomb->runAction(action);

	spritesheet_tickingbomb->addChild(sprite_ticking_bomb);
}

void HelloWorld::menuCloseCallback()
{
	Director::getInstance()->end();


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
