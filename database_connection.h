// Copyright [year] <Copyright Owner>"  [legal/copyright]
#ifndef DATABASE_CONNECTION_H_
#define DATABASE_CONNECTION_H_

#include <mysql.h>

#include <string>

namespace database {

class Connection {
  MYSQL* db_conn;

 public:
  Connection(const std::string,  // host
             const std::string,  // user
             const std::string,  // password
             const std::string,  // database
             const int);         // port

  ~Connection();
};

}  // namespace database
#endif  // DATABASE_CONNECTION_H_
