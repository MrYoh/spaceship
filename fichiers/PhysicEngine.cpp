
#include "PhysicEngine.h"
#include "GraphicEngine.h"
#include "SqlEngine.h"

PhysicEngine::~PhysicEngine() 
{
  // Bouml preserved body begin 00022F64
	if(world_)
		delete world_;
  // Bouml preserved body end 00022F64
}

IRigidBody* PhysicEngine::CreateRigidBody(irr::scene::ISceneNode* node, u32 mass, bool margin) 
{
  // Bouml preserved body begin 0001F6E4
	ICollisionShape* shape = new IBoxShape(node, mass, margin);
	IRigidBody* body= world_->addRigidBody(shape);
	
	
	
	//body->setLinearVelocity(rot);
	
	
	
	//body->setLinearVelocity(irr::core::vector3df(0,10,0));
	//body->applyCentralImpulse(irr::core::vector3df((0,-1000,10)));
	return body;
  // Bouml preserved body end 0001F6E4
}

bool PhysicEngine::Initialize() 
{
  // Bouml preserved body begin 0001FA64
	bool debugDraw = true;

	
	world_ = createIrrBulletWorld(GraphicEngine::GetInstance()->device() , true, debugDraw);
	world_->setDebugMode(EPDM_DrawAabb |
            EPDM_DrawContactPoints);
	world_->setGravity(irr::core::vector3df(0,0,0));
	if (world_)
		return true;

	return false;
  // Bouml preserved body end 0001FA64
}

bool PhysicEngine::UpdateFrame() 
{
  // Bouml preserved body begin 0001FAE4
		// Step the simulation with our delta time
		
	f32 delta_time = GraphicEngine::GetInstance()->frame_delta_time();

		//world_->stepSimulation(delta_time*0.001f, 120);
		world_->stepSimulation(delta_time, 120);


        world_->debugDrawWorld(true);
        // This call will draw the technical properties of the physics simulation
        // to the GUI environment.
        world_->debugDrawProperties(true);

		return true;

  // Bouml preserved body end 0001FAE4
}

