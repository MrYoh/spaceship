#ifndef _GRAPHICENGINE_H
#define _GRAPHICENGINE_H


#include <irrlicht.h>
using namespace irr;
#include <Singleton.h>


class SqlEngine;
class EngineEvent;
class EntityManager;

class GraphicEngine : public Singleton<GraphicEngine>, public IEventReceiver 
{
  public:
    GraphicEngine();

    bool CreateWindow();

    bool CreateSetupWindow();

    irr::scene::ISceneNode* CreateSceneNode(irr::core::stringc name, u32 id = 0, irr::core::vector3df& position = irr::core::vector3df(0,0,0));

    bool UpdateFrame();

    irr::scene::ISceneNode* CreateCamera();

    inline  irr::IrrlichtDevice* device();

    inline const f32 frame_delta_time() const;


  private:
    irr::IrrlichtDevice* device_;

    irr::video::IVideoDriver* driver_;

    irr::scene::ISceneManager* scene_manager_;

    f32 last_frame_time_;

    f32 frame_delta_time_;

    f32 last_fps_;

    EntityManager * _;


  public:
    virtual bool OnEvent(const SEvent& event);

    virtual bool IsKeyDown(irr::EKEY_CODE key_code);


  private:
    bool key_is_down_[KEY_KEY_CODES_COUNT];

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
