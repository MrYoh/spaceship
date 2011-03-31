#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H



#include <irrlicht.h>
using namespace irr;
#include <irrBullet.h>

#include "GraphicEngine.h"

class Game;
class GameWorld;

class GameEntity 
{
  public:
    void set_node(irr::scene::ISceneNode* value);

    void set_body(IRigidBody* value);

    void set_game(Game * value);


  protected:
    Game * game_;

    irr::scene::ISceneNode* node_;

    IRigidBody* body_;


  private:
    GameWorld * game_world_;


  public:
    virtual void UpdateFrame();

};
#endif
