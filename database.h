// Copyright [year] <Copyright Owner>"  [legal/copyright]
// https://en.cppreference.com/w/cpp/language/friend
#ifndef DATABASE_H_
#define DATABASE_H_

#include <mysql.h>

#include <string>

namespace database {

class Database {
 public:
  MYSQL* db_conn;

  void connect(const std::string,  // host
               const std::string,  // user
               const std::string,  // password
               const std::string,  // database
               const int);         // port
};

}  // namespace database
#endif  // DATABASE_H_
