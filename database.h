// Copyright [year] <Copyright Owner>"  [legal/copyright]
#ifndef DATABASE_H_
#define DATABASE_H_

#include <mysql.h>

#include <string>

namespace database {

class Database {
  MYSQL* db_conn;
  MYSQL_RES* res_set;
  MYSQL_ROW row;

 public:
  void connect(const std::string,  // host
               const std::string,  // user
               const std::string,  // password
               const std::string,  // database
               const int);         // port
  // Table Object?
  void add_book();
  void view_book();
  void search_book();
  bool search_book_id(int);
  void update_book(std::string);
  void print_book();
};

}  // namespace database
#endif  // DATABASE_H_
