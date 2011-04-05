#ifndef _PHYSICENGINE_H
#define _PHYSICENGINE_H


#include <irrlicht.h>
using namespace irr;
#include <Singleton.h>

#include <irrBullet.h>


class GraphicEngine;
class SqlEngine;

class PhysicEngine : public Singleton<PhysicEngine> 
{
  public:
    ~PhysicEngine();

    IRigidBody* CreateRigidBody(irr::core::stringc name, irr::scene::ISceneNode* node);

    bool Initialize();

    bool UpdateFrame();


  private:
    irrBulletWorld* world_;

};
#endif
