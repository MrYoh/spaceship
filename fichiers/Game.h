#ifndef _GAME_H
#define _GAME_H



#include "EntityManager.h"
#include <irrlicht.h>
using namespace irr;
#include <irrBullet.h>

#include "GameWorld.h"

class GraphicEngine;
class PhysicEngine;
class GameEntity;

class Game 
{
  public:
    Game();

    ~Game();

    bool LoadLevel();

    bool UpdateFrame();


  private:
    GraphicEngine * graphic_engine_;

    PhysicEngine * physic_engine_;

    EntityManager entity_manager_;

    GameWorld game_world_;

};
#endif
