#include "db_sqlite.h"

#include <stdio.h>

sqlite3 *
connect_to_db (char *db_name)
{
  sqlite3 *db;
  if (sqlite3_open (db_name, &db))
    {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return NULL;
    }
  return db;
}

int
disconnect_from_db (sqlite3 *db)
{
  sqlite3_close (db);
  return 0;
}
