
#include "GraphicEngine.h"
#include "SqlEngine.h"
#include "EngineEvent.h"
#include "EntityManager.h"

GraphicEngine::GraphicEngine() 
{
  // Bouml preserved body begin 00026A64
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
                        key_is_down_[i] = false;
  // Bouml preserved body end 00026A64
}

bool GraphicEngine::CreateWindow() 
{
  // Bouml preserved body begin 0001F464
  
  	device_=createDevice(video::EDT_DIRECT3D9,
  				core::dimension2d<u32>(800,600),
  				32,
  				false,
  				false,
  				false,
  				0);
  
  
  	if (!device_)
  		return false; //Pb de génération du device
  
  
  	driver_=device_->getVideoDriver();
	//TODO: a voir pour performance
	driver_->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);

  	scene_manager_=device_->getSceneManager();
	
  	//guiEnv=device->getGUIEnvironment();

	device_->getFileSystem()->addFolderFileArchive("./asset/");
  
	device_->setEventReceiver(this);

	last_frame_time_ = 0;
  	
  	return true;
  // Bouml preserved body end 0001F464
}

bool GraphicEngine::CreateSetupWindow() 
{
  // Bouml preserved body begin 0001F4E4
  
  	//TODO: setupwindows
  	return true;
  // Bouml preserved body end 0001F4E4
}

irr::scene::ISceneNode* GraphicEngine::CreateSceneNode(irr::core::stringc name, u32 id, irr::core::vector3df& position) 
{
  // Bouml preserved body begin 0001F5E4
	//TODO: create scene node

	/*bool is_mesh(false), is_node(false);
	
	bool is_position(false), is_scale(false), is_rotation(false);*/


	//on recupere les données de la base SQL
	SqlEngine sql;
	EngineEvent node_data = sql.GetNodeData(name);

	irr::scene::ISceneNode* node = CreateModelNode(node_data);
	if(node)
	{
		node->setID(id);
		node->setPosition(position);
		return node;
	}
		
	return 0;

  // Bouml preserved body end 0001F5E4
}

bool GraphicEngine::UpdateFrame() 
{
  // Bouml preserved body begin 0001F764
	if(!last_frame_time_)
	{
		last_frame_time_=device_->getTimer()->getTime();
	}
	






	if(device_->run())
	{
		if (device_->isWindowActive())
		{
            //Le timer
			const f32 now = device_->getTimer()->getTime();
            frame_delta_time_ = (f32)(now - last_frame_time_) / 1000.f; // Time in seconds
            last_frame_time_ = now;

			

			//On commence la scene
			driver_->beginScene(true,
					true,
					video::SColor(255,100,101,140));
			scene_manager_->drawAll();
			//guiEnv->drawAll();




			driver_->endScene();

			f32 fps = driver_->getFPS();

            if (last_fps_ != fps)
            {
                    core::stringw str = L"Irrlicht Engine - Quake 3 Map example [";
                    str += driver_->getName();
                    str += "] FPS:";
                    //str += fps;.
					str += frame_delta_time_;

                    //device_->setWindowCaption(str.c_str());
                    last_fps_ = fps;
            }
		}
	}else return false;//on stop le programme
	

	return true;
  // Bouml preserved body end 0001F764
}

irr::scene::ISceneNode* GraphicEngine::CreateCamera() 
{
  // Bouml preserved body begin 0001FBE4

	//irr::scene::ISceneNode* node = scene_manager_->addCameraSceneNodeFPS();
	irr::scene::ISceneNode* node = scene_manager_->addCameraSceneNode(
		0,
		irr::core::vector3df(0,500,0), 
		irr::core::vector3df(0,0,0),
		0);

	return node;
  // Bouml preserved body end 0001FBE4
}

irr::core::vector3df GraphicEngine::CalculMousePositionY(f32 position_y) 
{
  // Bouml preserved body begin 00028664
	using namespace irr;

	using namespace core;
	using namespace scene;
	using namespace video;

	using namespace io;
	using namespace gui;
	
	ISceneCollisionManager* collisionManager = 
		scene_manager_->getSceneCollisionManager();

	ICursorControl *cursor = device_->getCursorControl();
	core::position2d<s32> pos = cursor->getPosition();
	core::vector3df point;
  core::triangle3df triangle;

  const ISceneNode *node = 0;
  const core::line3d<f32> ray = collisionManager->getRayFromScreenCoordinates(pos);

  vector3df ray_vector = ray.getVector();
  
  //distance camera avec point0
  /*f32 y= 1;


  f32 x = (y*ray_vector.X)/ray_vector.Y;
  f32 z = (y*ray_vector.Z)/ray_vector.Y;*/

  //distance
  f32 y = -500;

  f32 x = (y*ray_vector.X)/ray_vector.Y;
  f32 z = (y*ray_vector.Z)/ray_vector.Y;
  
  //vector camera flemme de chercher la camera
  vector3df camera(0,500,0);


  
  return (vector3df(x,y,z)+camera);
  
  
  /*if (collisionManager->getCollisionPoint
    (ray, selector, point, triangle, node))*/


  // Bouml preserved body end 00028664
}

bool GraphicEngine::OnEvent(const SEvent& event) 
{
  // Bouml preserved body begin 00026964
	// Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
	{
            key_is_down_[event.KeyInput.Key] = event.KeyInput.PressedDown;
	}

    return false;
  // Bouml preserved body end 00026964
}

bool GraphicEngine::IsKeyDown(irr::EKEY_CODE key_code) 
{
  // Bouml preserved body begin 000269E4
	return key_is_down_[key_code];
  // Bouml preserved body end 000269E4
}

irr::scene::ISceneNode* GraphicEngine::CreateModelNode(EngineEvent& node_data) 
{
  // Bouml preserved body begin 00029FE4
	//typedef
	typedef irr::core::vector3df Vector3df;
	typedef irr::core::stringc Stringc;

	//on cherche
	//dans les vector3df
	std::map<Stringc, Vector3df>::const_iterator
		it_vector3df_end(node_data.vector3df_data_.end()),
		it_position(node_data.vector3df_data_.find("position")),
		it_scale(node_data.vector3df_data_.find("scale")),
		it_rotation(node_data.vector3df_data_.find("rotation"));
		

	//dans les stringc
	std::map<Stringc, Stringc>::const_iterator
		it_string_end(node_data.string_data_.end()),
		it_mesh(node_data.string_data_.find("mesh")),
		it_texture_diffusal(node_data.string_data_.find("texture_diffusal")),
		it_texture_normal(node_data.string_data_.find("texture_normal"));
		

	//on cree le mesh
	/*if(it_mesh!=it_string_end)
	{
		scene::IAnimatedMesh* mesh = scene_manager_->getMesh(it_mesh->second);
		if(mesh)
		{
			
			scene::IAnimatedMeshSceneNode* node = scene_manager_->addAnimatedMeshSceneNode(mesh);

			if (node)
			{
					
			
				node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
				//node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
				node->setMD2Animation(irr::scene::EMAT_STAND);

				if(it_texture_diffusal!=it_string_end)
				{
					node->setMaterialTexture( 0, driver_->getTexture(it_texture_diffusal->second) );
				}
				
				//On met en place la normal map pour le bumpmap
				if(it_texture_normal!=it_string_end)
				{
					 video::ITexture* normalMap =
                        driver->getTexture("it_texture_normal->second");

					 if (normalMap)
                        driver->makeNormalMapTexture(normalMap, 9.0f);
					
					node->setMaterialTexture( 1, driver_->getTexture(normalMap) );
					node->setMaterialType(irr::video::EMT_PARALLAX_MAP_SOLID);
				}
				return node;	
			}
			
		}
	}*/


	if(it_mesh!=it_string_end)
	{
		scene::IAnimatedMesh* mesh = scene_manager_->getMesh(it_mesh->second);
		if(mesh)
		{
			
			//scene::IAnimatedMeshSceneNode* node = 0;
			
			//On met en place la normal map pour le bumpmap
			if(it_texture_normal != it_string_end)
			{
				if(it_texture_normal->second != "")
				{
					//TODO a enlever
					scene_manager_->getMeshManipulator()->makePlanarTextureMapping(
                                mesh->getMesh(0), 0.003f);
					
					irr::video::ITexture* normalMap = driver_->getTexture(it_texture_normal->second);
					//TODO texture

					if (normalMap)
						driver_->makeNormalMapTexture(normalMap, 9.0f);

					irr::scene::IMesh* tangent_mesh = 
						scene_manager_->getMeshManipulator()->createMeshWithTangents(mesh->getMesh(0));
					
					scene::ISceneNode* node = scene_manager_->addMeshSceneNode(tangent_mesh);
										
					
					node->setMaterialTexture( 1,normalMap);
					node->setMaterialType(irr::video::EMT_PARALLAX_MAP_SOLID);


					if(it_texture_diffusal!=it_string_end)
					{
						node->setMaterialTexture( 0, driver_->getTexture(it_texture_diffusal->second) );
					}

					node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);

					//TODO a enlever
					//node->setScale(irr::core::vector3df(100,100,100));

					


				}else 
				{
					scene::IAnimatedMeshSceneNode* node = scene_manager_->addAnimatedMeshSceneNode(mesh);
				
					node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					node->setMaterialFlag(irr::video::EMF_WIREFRAME, false);
					//node->setMD2Animation(irr::scene::EMAT_STAND);
					

					if(it_texture_diffusal!=it_string_end)
					{
						node->setMaterialTexture( 0, driver_->getTexture(it_texture_diffusal->second) );
					}
					return node;	
				}
			
			
			}
		}
	}
	

	return 0;


  // Bouml preserved body end 00029FE4
}

irr::scene::ISceneNode* GraphicEngine::CreateLightNode(EngineEvent& node_data) 
{
  // Bouml preserved body begin 0002A064


	return 0;
  // Bouml preserved body end 0002A064
}

irr::scene::ISceneNode* GraphicEngine::CreateBillboardNode(EngineEvent& node_data) 
{
  // Bouml preserved body begin 0002A0E4


	return 0;
  // Bouml preserved body end 0002A0E4
}

