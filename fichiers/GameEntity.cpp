
#include "GameEntity.h"
#include "Game.h"
#include "GameWorld.h"

void GameEntity::set_node(irr::scene::ISceneNode* value) 
{
  node_ = value;
}

void GameEntity::set_body(IRigidBody* value) 
{
  body_ = value;
}

void GameEntity::set_game(Game * value) 
{
  game_ = value;
}

