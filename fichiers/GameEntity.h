#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H



#include <irrlicht.h>
using namespace irr;
#include <irrBullet.h>


class Game;
class GameWorld;

class GameEntity 
{
  public:
    void set_node(irr::scene::ISceneNode* value);

    void set_body(IRigidBody* value);

    void set_game(Game * value);


  private:
    Game * game_;


  protected:
    irr::scene::ISceneNode* node_;

    IRigidBody* body_;


  private:
    GameWorld * game_world_;


  public:
    virtual void UpdateFrame();

};
#endif
