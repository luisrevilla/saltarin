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
	float anchobtn=60.0;
	float altobtn=60.0;
	float menufondoancho=800;
	float menufondoalto=480;
	float posicionxbtn=0.0;
	float posicionybtn=0.0;
	
    if (!Layer::init())return false;
            
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//Creacion de las capas del juego
	//Capas[0]=menu y opciones
	//Capas[1]=area del juego
	for(int ciclo=0;ciclo<4;ciclo++)
	{			
		Capas[ciclo]=new Layer();
		Capas[ciclo]->setPosition(Vec2::ZERO);
		Capas[ciclo]->setVisible(false);		
		this->addChild(Capas[ciclo],ciclo);
	}
	//
	
	//Fondo del menu y opciones
    auto fondomenu = Sprite::create("menufondo.png");
	fondomenu->setScaleX(menufondoancho/fondomenu->getContentSize().width);  
	fondomenu->setScaleY(menufondoalto/fondomenu->getContentSize().height); 
	posicionxbtn=400.0;
	posicionybtn=240.0;
    fondomenu->setPosition(Vec2(posicionxbtn,posicionybtn));  	
	Capas[MENUOPCIONES]->addChild(fondomenu,0);

	//Creacion de los botones quit y play
    auto quitItem = MenuItemImage::create("botonexitnormal.png","botonexitpress.png",CC_CALLBACK_1(Saltarin::quitCallback, this));    
	quitItem->setScaleX(anchobtn/quitItem->getContentSize().width);  
	quitItem->setScaleY(altobtn/quitItem->getContentSize().height); 
	posicionxbtn=40.0;
	posicionybtn=50.0;
	quitItem->setPosition(Vec2(posicionxbtn,posicionybtn));

	anchobtn=200.0;
	altobtn=200.0;
    auto playItem = MenuItemImage::create("botonplaynormal.png","botonplaypress.png",CC_CALLBACK_1(Saltarin::playCallback, this));    
	playItem->setScaleX(anchobtn/playItem->getContentSize().width);  
	playItem->setScaleY(altobtn/playItem->getContentSize().height); 
	posicionxbtn=660.0;
	posicionybtn=120.0;
	playItem->setPosition(Vec2(posicionxbtn,posicionybtn));

    auto menuopciones = Menu::create();
    menuopciones->setVisible(true); 
    menuopciones->setPosition(Vec2::ZERO);
    menuopciones->addChild(quitItem,0);
    menuopciones->addChild(playItem,0);
    Capas[MENUOPCIONES]->addChild(menuopciones, 1);
    //
    
    auto titulo = Label::createWithTTF("Saltarin","fonts/arial.ttf",26);    
    titulo->setPosition(Vec2(400,380));
    Capas[MENUOPCIONES]->addChild(titulo, 1);
    
	//Creacion de los botones pausa
	anchobtn=50.0;
	altobtn=50.0;	
    auto pausaItem = MenuItemImage::create("botonpausanormal.png","botonpausapress.png",CC_CALLBACK_1(Saltarin::pausaCallback, this));    
	pausaItem->setScaleX(anchobtn/pausaItem->getContentSize().width);  
	pausaItem->setScaleY(altobtn/pausaItem->getContentSize().height); 
	posicionxbtn=800.0-((pausaItem->getContentSize().width*pausaItem->getScaleX())/2);
	posicionybtn=480.0-((pausaItem->getContentSize().height*pausaItem->getScaleY())/2);
	pausaItem->setPosition(Vec2(posicionxbtn,posicionybtn));

    auto menuareanivel = Menu::create();
    menuareanivel->setVisible(true); 
    menuareanivel->setPosition(Vec2::ZERO);
    menuareanivel->addChild(pausaItem,0);
    Capas[AREAJUEGO]->addChild(menuareanivel, 2);
    //    
    
    crearNivel();
    Capas[MENUOPCIONES]->setVisible(true); 
       
    return true;
}

void Saltarin::crearNivel()
{
	float anchobtn=0.0;
	float altobtn=0.0;
	float posicionxbtn=0.0;
	float posicionybtn=0.0;

	//Fondo del nivel
	anchobtn=800.0;
	altobtn=480.0;	
    auto fondonivel = Sprite::create("fondonivel.png");
	fondonivel->setScaleX(anchobtn/fondonivel->getContentSize().width);  
	fondonivel->setScaleY(altobtn/fondonivel->getContentSize().height); 
	posicionxbtn=400.0;
	posicionybtn=240.0;
    fondonivel->setPosition(Vec2(posicionxbtn,posicionybtn));  	
	Capas[AREAJUEGO]->addChild(fondonivel,0);   
    //    	
    
	//Piso
	anchobtn=800.0;
	altobtn=50.0;		
    auto pisonivel = Sprite::create("pisonivel.png");
	pisonivel->setScaleX(anchobtn/pisonivel->getContentSize().width);  
	pisonivel->setScaleY(altobtn/pisonivel->getContentSize().height); 
	posicionxbtn=400.0;
	posicionybtn=100.0;
    pisonivel->setPosition(Vec2(posicionxbtn,posicionybtn));  	
    pisonivel->setOpacity(0);
	Capas[AREAJUEGO]->addChild(pisonivel,1);   
	auto bodypn = PhysicsBody::createBox(pisonivel->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	bodypn->setDynamic(false);	
	pisonivel->setPhysicsBody(bodypn);
    //         

    //Personaje 
	anchobtn=100.0;
	altobtn=100.0;	    
	pp3D=Sprite3D::create("model3d/personajep.c3b");
	pp3D->setTexture("model3d/personajep.png"); 
	pp3D->setRotation3D(Vec3(0,0,0)); 
	pp3D->setScaleX(anchobtn/pp3D->getContentSize().width);
	pp3D->setScaleY(altobtn/pp3D->getContentSize().height);
	pp3D->setScaleZ(altobtn/pp3D->getContentSize().height);
	posicionxbtn=400.0;
	posicionybtn=240.0;	
	pp3D->setPosition3D(Vec3(posicionxbtn,posicionybtn,0));
	pp3D->setGlobalZOrder(1);   
	pp3D->setVisible(true);	 
	auto bodypp = PhysicsBody::createBox(pp3D->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	bodypp->setDynamic(true);	
	pp3D->setPhysicsBody(bodypp);		
	Capas[AREAJUEGO]->addChild(pp3D,2);     
    //
    
    
}

void Saltarin::quitCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

void Saltarin::playCallback(Ref* pSender)
{
	Capas[MENUOPCIONES]->setVisible(false);
	Capas[AREAJUEGO]->setVisible(true);  
}

void Saltarin::pausaCallback(Ref* pSender)
{
	Capas[MENUOPCIONES]->setVisible(true);
	Capas[AREAJUEGO]->setVisible(false);  
}
