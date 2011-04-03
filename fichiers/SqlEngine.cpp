
#include "SqlEngine.h"

SqlEngine::SqlEngine() 
{
  // Bouml preserved body begin 00021564
	is_setup_ok_=false;;
  // Bouml preserved body end 00021564
}

SqlEngine::~SqlEngine() 
{
  // Bouml preserved body begin 00024FE4
	sqlite3_close(data_base_);
  // Bouml preserved body end 00024FE4
}

bool SqlEngine::Initialize() 
{
  // Bouml preserved body begin 00024E64
	rc_=sqlite3_open("./data/data.db",&data_base_);
    if(rc_)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(data_base_));
        sqlite3_close(data_base_);
        return false;
    }
    
	return true;
  // Bouml preserved body end 00024E64
}

sqlite3_stmt* SqlEngine::Execute(irr::core::stringc requete) 
{
  // Bouml preserved body begin 00024EE4
	if(!is_setup_ok_)
		Initialize();
	
	if(!rc_)
	{
		sqlite3_stmt* prepared_statement;
		if(sqlite3_prepare_v2(data_base_, requete.c_str(), -1, &prepared_statement, NULL) == SQLITE_OK)
			return prepared_statement;
	}

	return 0;

  // Bouml preserved body end 00024EE4
}

void SqlEngine::Test(irr::core::stringc requete) 
{
  // Bouml preserved body begin 00024F64

	
	//irr::core::stringc  a = "select ID_NODE as ID from T_NODE;";

	if(!rc_)
	{
		sqlite3_stmt *prepared_statement;
		if(sqlite3_prepare_v2(data_base_, requete.c_str(), -1, &prepared_statement, NULL) == SQLITE_OK)
		{
			// On boucle tant que l'on trouve des objets dans la BDD
			while(sqlite3_step(prepared_statement) == SQLITE_ROW)
			{
				//on recupere les resultats de la colonne coresspondante 
				irr::core::stringc lol=(char *)sqlite3_column_text(prepared_statement, 0);
				
				//irr::core::stringc a (lol.c_str());//std::cout << lol;
 				system("pause");
			}
			sqlite3_finalize(prepared_statement);
		}
    }
	
  // Bouml preserved body end 00024F64
}

EngineEvent& SqlEngine::GetNodeData(irr::core::stringc name) 
{
  // Bouml preserved body begin 00024D64
	typedef irr::core::vector3df Vector3df;
	typedef irr::core::stringc Stringc;
	typedef std::pair<Stringc, Vector3df> PairVector3df;
	typedef std::pair<Stringc, Stringc> PairStringc;

	
	if(!is_setup_ok_)
	{
		Initialize();
	}
	
	//variqble str pour requete
	irr::core::stringc requete;
	sqlite3_stmt* prepared_statement;

	

	//on recupere le type
	requete  = "select t_node_type.name ";
	requete += "from t_node_type ";
	requete += "inner join t_node ";
	requete += "on t_node_type.id_node_type = t_node.id_node_type ";
	requete += "where t_node.name = '";
	requete += name.c_str();
	requete += "';";
		
	
	prepared_statement = Execute(requete);

	while(sqlite3_step(prepared_statement) == SQLITE_ROW)
	{
		Stringc type = (char *)sqlite3_column_text(prepared_statement, 0);

		if(type == "animatedmesh")
		{
			//la requete
			/*requete  = "select MESH, TEXTURE from T_ANIMATED_MESH INNER JOIN T_NODE ";
			requete += "ON T_ANIMATED_MESH.ID_NODE = T_NODE.ID_NODE where NAME = '";
			requete += name.c_str();
			requete += "';";*/
			
			requete  = "select * from v_model where name = '";
			requete += name.c_str();
			requete += "';";


			prepared_statement = Execute(requete);
	
			// On boucle tant que l'on trouve des objets dans la BDD
			if(sqlite3_step(prepared_statement) == SQLITE_ROW)
			{
				//on recupere les resultats de la colonne coresspondante 
				Stringc mesh = (char *)sqlite3_column_text(prepared_statement, 1);
				engine_event_.string_data_.insert(PairStringc("mesh",mesh));

				Stringc texture_diffusal = (char *)sqlite3_column_text(prepared_statement, 2);
				engine_event_.string_data_.insert(PairStringc("texture_diffusal",texture_diffusal));

				Stringc texture_normal = (char *)sqlite3_column_text(prepared_statement, 3);
				engine_event_.string_data_.insert(PairStringc("texture_normal",texture_normal));
 			}
		}
		else if (type == "mesh")
		{

		}
		
	}

	
	sqlite3_finalize(prepared_statement);
	/*
	irr::u32 type(0);
	engine_event_.type_ = type;
	
	Vector3df position(0,0,0);
	engine_event_.vector3df_data_.insert(PairVector3df("position",position));
	
	Vector3df scale(0,0,0);
	engine_event_.vector3df_data_.insert(PairVector3df("scale",scale));

	Vector3df rotation(0,0,0);
	engine_event_.vector3df_data_.insert(PairVector3df("rotation",rotation));

	Stringc mesh("sydney.md2");
	engine_event_.string_data_.insert(PairStringc("mesh",mesh));

	Stringc texture("sydney.bmp");
	engine_event_.string_data_.insert(PairStringc("texture",texture));*/

		
	return engine_event_;
  // Bouml preserved body end 00024D64
}

EngineEvent& SqlEngine::GetBodyData(irr::core::stringc name) 
{
  // Bouml preserved body begin 00024DE4

	return engine_event_;
  // Bouml preserved body end 00024DE4
}

