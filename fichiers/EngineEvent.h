#ifndef _ENGINEEVENT_H
#define _ENGINEEVENT_H


#include <map>
using  std::map;
#include <irrlicht.h>
using namespace irr;

class EngineEvent 
{
  public:
    u32 type_;

    map<irr::core::stringc, irr::core::stringc> string_data_;

    map<irr::core::stringc, s32> s32_data_;

    map<irr::core::stringc, u32> u32_data_;

    map<irr::core::stringc, f32> f32_data_;

    map<irr::core::stringc, irr::core::vector3df> vector3df_data_;

};
#endif
