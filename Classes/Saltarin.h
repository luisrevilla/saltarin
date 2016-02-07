#ifndef __SALTARIN_SCENE_H__
#define __SALTARIN_SCENE_H__

#include "cocos2d.h"
#include "physics3d/CCPhysics3D.h"
#include "extensions/Particle3D/PU/CCPUParticleSystem3D.h"

class Saltarin : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
   
    void quitCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(Saltarin);
};

#endif 
