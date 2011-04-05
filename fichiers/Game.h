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
class PlayerShipEntity;

class Game 
{
  public:
    Game();

    ~Game();

    bool LoadLevel();

    bool UpdateFrame();

    bool IsKeyDown(irr::EKEY_CODE key_is_down);


  private:
    GraphicEngine * graphic_engine_;

    PhysicEngine * physic_engine_;

    EntityManager entity_manager_;

    GameWorld game_world_;


  public:
    inline  EntityManager* entity_manager();

    bool IsMouseDown(irr::EMOUSE_INPUT_EVENT mouse_is_down);

};
inline  EntityManager* Game::entity_manager() 
{
  return &entity_manager_;
}

#endif
