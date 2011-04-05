
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

IRigidBody* PhysicEngine::CreateRigidBody(irr::core::stringc name, irr::scene::ISceneNode* node) 
{
  // Bouml preserved body begin 0001F6E4
	typedef irr::core::stringc Stringc;
	
	SqlEngine sql;
	EngineEvent body_data = sql.GetBodyData(name);

	std::map<Stringc, f32>::const_iterator 
		it_f32_end(body_data.f32_data_.end()),
		it_mass(body_data.f32_data_.find("mass"));
	
	if (it_f32_end != it_mass)
	{
		if( it_mass->second >= 0 )
		{
			ICollisionShape* shape = new IBoxShape(node, it_mass->second, false);
			IRigidBody* body= world_->addRigidBody(shape);

			return body;
		}
	}
	
	return 0;
	
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

