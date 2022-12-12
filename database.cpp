// Copyright [year] <Copyright Owner>
// https://stackoverflow.com/questions/24255051/concatenate-char-arrays-in-c
#include "./database.h"

#include <mysql.h>

#include <iostream>
#include <sstream>

void database::Database::connect(const std::string host, const std::string user,
                                 const std::string password,
                                 const std::string database, const int port) {
  db_conn = mysql_init(NULL);
  if (!db_conn)
    std::cout << "MySQL initialization failed." << std::endl;
  else
    std::cout << "MySQL initialized." << std::endl;

  db_conn =
      mysql_real_connect(db_conn, host.c_str(), user.c_str(), password.c_str(),
                         database.c_str(), port, NULL, 0);

  if (!db_conn)
    std::cout << "Connection Error." << std::endl;
  else
    std::cout << "Connected." << std::endl;

  getchar();
  return;
}
