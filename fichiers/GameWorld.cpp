
#include "GameWorld.h"
#include "GameEntity.h"

void GameWorld::addGameEntity(shared_ptr<GameEntity> game_entity) 
{
  // Bouml preserved body begin 000231E4
	game_entities_.push_back(game_entity);
  // Bouml preserved body end 000231E4
}

