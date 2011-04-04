
#include "Game.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "GameEntity.h"
#include "PlayerShipEntity.h"

Game::Game() 
	:game_world_(),
	entity_manager_(this, &game_world_)
{
  // Bouml preserved body begin 0001F964
	//LoadLevel();
  // Bouml preserved body end 0001F964
}

Game::~Game() 
{
  // Bouml preserved body begin 00022EE4
	//On détruit tout les singletons
	PhysicEngine::Kill();
	GraphicEngine::Kill();
  // Bouml preserved body end 00022EE4
}

bool Game::LoadLevel() 
{
  // Bouml preserved body begin 0001F864
	//On lance l'interface graphique
	graphic_engine_ = GraphicEngine::GetInstance();
	graphic_engine_->CreateWindow();
	graphic_engine_->CreateCamera();
	
	//on crée le moteur physique
	physic_engine_ = PhysicEngine::GetInstance();
	physic_engine_->Initialize();

	/*shared_ptr<PlayerShipEntity> player_ship = make_shared<PlayerShipEntity>();
	entity_manager_.CreateGameEntity(player_ship,"sydney", core::vector3df(0,0,0));*/

	shared_ptr<GameEntity> test = make_shared<GameEntity>();
	entity_manager_.CreateGameEntity(test, "sydney", core::vector3df(0,0,0));
	test = make_shared<GameEntity>();
	entity_manager_.CreateGameEntity(test, "light_white", core::vector3df(50,0,0));
	test = make_shared<GameEntity>();
	entity_manager_.CreateGameEntity(test, "light_white", core::vector3df(50,50,0));
	test = make_shared<GameEntity>();
	entity_manager_.CreateGameEntity(test, "light_white", core::vector3df(50,50,50));

	return true;
  // Bouml preserved body end 0001F864
}

bool Game::UpdateFrame() 
{
  // Bouml preserved body begin 0001F8E4

	
	while(graphic_engine_->UpdateFrame())
	{
		physic_engine_->UpdateFrame();

		//on met a jour tous les game entities
		vector<shared_ptr<GameEntity > > game_entities;
		game_entities = game_world_.game_entities();

		vector<shared_ptr<GameEntity > >::iterator it = game_entities.begin();
		for( ; it != game_entities.end(); ++it)
		{
			(*it)->UpdateFrame();
		}
	};
	
	return true;
  // Bouml preserved body end 0001F8E4
}

bool Game::IsKeyDown(irr::EKEY_CODE key_is_down) 
{
  // Bouml preserved body begin 00026AE4
	return GraphicEngine::GetInstance()->IsKeyDown(key_is_down);
  // Bouml preserved body end 00026AE4
}

