#ifndef _SQLENGINE_H
#define _SQLENGINE_H


#include "EngineEvent.h"
#include <Singleton.h>

#include <sqlite3.h>

#include <irrlicht.h>
using namespace irr;

class SqlEngine : public Singleton<SqlEngine> 
{
  public:
    SqlEngine();

    ~SqlEngine();

    bool Initialize();

    sqlite3_stmt* Execute(irr::core::stringc requete);

    void Test(irr::core::stringc requete);

    EngineEvent& GetNodeData(irr::core::stringc name);

    EngineEvent& GetBodyData(irr::core::stringc name);


  private:
    sqlite3* data_base_;

    irr::u32 rc_;

    EngineEvent engine_event_;

    bool is_setup_ok_;

};
#endif
