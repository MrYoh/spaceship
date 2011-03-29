
#include "GraphicEngine.h"
#include "SqlEngine.h"
#include "EngineEvent.h"
#include "EntityManager.h"

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
  	scene_manager_=device_->getSceneManager();
  	//guiEnv=device->getGUIEnvironment();
  
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




	
	
		//irr::scene::IAnimatedMesh* mesh = sceneManager->getMesh(pathModele.c_str());
		scene::IAnimatedMesh* mesh = scene_manager_->getMesh("./media/sydney.md2");
			if (!mesh)
			{
				//TODO si on ne trouve pas le mesh   
				//device->drop();
					//return 1;
			}

		
			scene::IAnimatedMeshSceneNode* node = scene_manager_->addAnimatedMeshSceneNode( mesh);

		if (node)
			{
				 node->setID(id);
			
					node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					node->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
					
					node->setMD2Animation(irr::scene::EMAT_STAND);
					node->setMaterialTexture( 0, driver_->getTexture("./media/sydney.bmp") );
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
            const f32 now = device_->getTimer()->getTime();
            frame_delta_time_ = (f32)(now - last_frame_time_) / 1000.f; // Time in seconds
            last_frame_time_ = now;

			
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

                    device_->setWindowCaption(str.c_str());
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

	irr::scene::ISceneNode* node = scene_manager_->addCameraSceneNodeFPS();
	/*irr::scene::ISceneNode* node = scene_manager_->addCameraSceneNode(
		0,
		irr::core::vector3df(0,500,0), 
		irr::core::vector3df(0,0,0),
		0);*/

	return node;
  // Bouml preserved body end 0001FBE4
}

