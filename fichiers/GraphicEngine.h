#ifndef _GRAPHICENGINE_H
#define _GRAPHICENGINE_H


#include <irrlicht.h>
using namespace irr;
#include <Singleton.h>


class SqlEngine;
class EngineEvent;
class EntityManager;

class GraphicEngine : public Singleton<GraphicEngine> 
{
  public:
    bool CreateWindow();

    bool CreateSetupWindow();

    irr::scene::ISceneNode* CreateSceneNode(irr::core::stringc name, u32 id = 0, irr::core::vector3df& position = irr::core::vector3df(0,0,0));

    bool UpdateFrame();

    irr::scene::ISceneNode* CreateCamera();

    inline  irr::IrrlichtDevice* device();


  private:
    irr::IrrlichtDevice* device_;

    irr::video::IVideoDriver* driver_;

    irr::scene::ISceneManager* scene_manager_;

    f32 last_frame_time_;

    f32 frame_delta_time_;

    f32 last_fps_;

    EntityManager * _;


  public:
    inline const f32 frame_delta_time() const;

};
inline  irr::IrrlichtDevice* GraphicEngine::device() 
{
  return device_;
}

inline const f32 GraphicEngine::frame_delta_time() const 
{
  return frame_delta_time_;
}

#endif
