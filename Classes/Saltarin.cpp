/**
   Copyright 2016 Luis Revilla (luis.revilla@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

**/

#include "Saltarin.h"

USING_NS_CC;

Scene* Saltarin::createScene()
{
    auto scene = Scene::create();    
	if (!scene->initWithPhysics())  
	{  
		//Error
    }           
    auto layer = Saltarin::create();
    scene->addChild(layer);
    return scene;
}

bool Saltarin::init()
{
    if (!Layer::init())return false;
        
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto quitItem = MenuItemImage::create("quitnormal.png","quitselected.png",CC_CALLBACK_1(Saltarin::quitCallback, this));    
	quitItem->setPosition(Vec2(origin.x + visibleSize.width - quitItem->getContentSize().width/2 ,origin.y + quitItem->getContentSize().height/2));

    auto menuopciones = Menu::create(quitItem, NULL);
    menuopciones->setPosition(Vec2::ZERO);
    this->addChild(menuopciones, 0);
    
    auto titulo = Label::createWithTTF("Saltarin","fonts/arial.ttf",26);    
    titulo->setPosition(Vec2(origin.x + visibleSize.width/2,origin.y + visibleSize.height - titulo->getContentSize().height));
    this->addChild(titulo, 0);
    
    return true;
}


void Saltarin::quitCallback(Ref* pSender)
{
    Director::getInstance()->end();
}
