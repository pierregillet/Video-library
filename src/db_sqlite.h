#include <sqlite3.h>

sqlite3*
connect_to_db (char *db_name);



int
disconnect_from_db (sqlite3*);
