#ifndef _SQLENGINE_H
#define _SQLENGINE_H


#include <Singleton.h>

#include <sqlite3.h>


class SqlEngine : public Singleton<SqlEngine> 
{
  public:
    SqlEngine();


  private:
    sqlite3* data_base_;

    int rc_;

};
#endif
