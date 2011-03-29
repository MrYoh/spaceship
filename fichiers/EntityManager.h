#ifndef _ENTITYMANAGER_H
#define _ENTITYMANAGER_H



#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using boost::shared_ptr;
using boost::make_shared;
#include <vector>
using std::vector;
#include <irrlicht.h>
using namespace irr;
#include <irrBullet.h>


class Game;
class GameWorld;
class GameEntity;
class GraphicEngine;
class PhysicEngine;

class EntityManager 
{
  public:
    EntityManager(Game* game, GameWorld* game_world);

    shared_ptr<GameEntity> CreateGameEntity(irr::core::stringc name, irr::core::vector3df& position = irr::core::vector3df(0,0,0));

    bool RemoveGameEntity(shared_ptr<GameEntity> game_entity);

    bool RemoveAll();


  private:
    GraphicEngine * graphic_engine_;

    PhysicEngine * physic_engine_;

    vector<shared_ptr<GameEntity > > game_entities_;

    Game * game_;

    GameWorld * game_world_;

};
#endif
