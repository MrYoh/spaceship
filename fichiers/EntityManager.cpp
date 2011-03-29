
#include "EntityManager.h"
#include "Game.h"
#include "GameWorld.h"
#include "GameEntity.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"

EntityManager::EntityManager(Game* game, GameWorld* game_world) 
	:game_(game),
	game_world_(game_world)
	
{
  // Bouml preserved body begin 00023164
  // Bouml preserved body end 00023164
}

shared_ptr<GameEntity> EntityManager::CreateGameEntity(irr::core::stringc name, irr::core::vector3df& position) 
{
  // Bouml preserved body begin 0001F7E4
	//TODO
	
	//on crée le gameentity
	shared_ptr<GameEntity> game_entity = make_shared<GameEntity>();

	game_entity->set_game(game_);
	
	//on cree le node et body
	irr::scene::ISceneNode* node = GraphicEngine::GetInstance()->CreateSceneNode("lol");

	if (node)
	{
		node->setPosition(position);
		game_entity->set_node(node);

		IRigidBody* body = PhysicEngine::GetInstance()->CreateRigidBody(node,10,true);
		if(body)
		{
			game_entity->set_body(body);
		}

	}
	
	
	//On rajoute game_entity dans le gameworld	
	game_world_->addGameEntity(game_entity);

	
	return game_entity;
	
  // Bouml preserved body end 0001F7E4
}

bool EntityManager::RemoveGameEntity(shared_ptr<GameEntity> game_entity) 
{
  // Bouml preserved body begin 00022FE4
	//TODO remove
	return false;
  // Bouml preserved body end 00022FE4
}

bool EntityManager::RemoveAll() 
{
  // Bouml preserved body begin 00023064
	//TODO remove
	return false;
  // Bouml preserved body end 00023064
}

