
#include "Game.h"
#include "GraphicEngine.h"
#include "PhysicEngine.h"
#include "GameEntity.h"

Game::Game() 
	:game_world_(),
	entity_manager_(this, &game_world_)
{
  // Bouml preserved body begin 0001F964
	LoadLevel();
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
	return true;
  // Bouml preserved body end 0001F864
}

bool Game::UpdateFrame() 
{
  // Bouml preserved body begin 0001F8E4
	entity_manager_.CreateGameEntity("kik", core::vector3df(0,0,0));
	entity_manager_.CreateGameEntity("kik", core::vector3df(0,0,50));
	entity_manager_.CreateGameEntity("kik", core::vector3df(50,0,0));
	
	while(graphic_engine_->UpdateFrame())
	{
		physic_engine_->UpdateFrame();
	};
	
	return true;
  // Bouml preserved body end 0001F8E4
}

