#ifndef __SALTARIN_SCENE_H__
#define __SALTARIN_SCENE_H__

#include "cocos2d.h"
#include "physics3d/CCPhysics3D.h"
#include "extensions/Particle3D/PU/CCPUParticleSystem3D.h"

class Saltarin : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

	#define MENUOPCIONES	0
	#define AREAJUEGO	1
	
    virtual bool init();
    cocos2d::Layer *Capas[4];
    void quitCallback(cocos2d::Ref* pSender);
    void playCallback(Ref* pSender);
    void pausaCallback(Ref* pSender);
    
    CREATE_FUNC(Saltarin);
};

#endif 
