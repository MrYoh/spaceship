#ifndef _GAMEWORLD_H
#define _GAMEWORLD_H



#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
using boost::shared_ptr;
using boost::make_shared;
#include <vector>
using std::vector;

class GameEntity;

class GameWorld 
{
  public:
    void addGameEntity(shared_ptr<GameEntity> game_entity);


  private:
    vector<shared_ptr<GameEntity > > game_entities_;
    


  public:
    inline  vector<shared_ptr<GameEntity > > & game_entities();

};
inline  vector<shared_ptr<GameEntity > > & GameWorld::game_entities() 
{
  return game_entities_;
}

#endif
