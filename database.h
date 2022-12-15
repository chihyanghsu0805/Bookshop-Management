// Copyright [year] <Copyright Owner>"  [legal/copyright]
// https://en.cppreference.com/w/cpp/language/friend
#ifndef DATABASE_H_
#define DATABASE_H_

#include <mysql.h>

#include <string>

namespace database {

class Database {
  MYSQL* connection;
  MYSQL_RES* result_set;
  MYSQL_ROW row;

 public:
  void connect(const std::string, const std::string, const std::string,
               const std::string, const int);

  // Generic
  void view(std::string);
  void print_row(MYSQL_ROW, std::string);
  void search(std::string);
  bool search_id(std::string, int);
  void update(std::string, std::string, std::string);
  void remove(std::string);
  bool check_errors();
  void check_insert();
  void check_update(std::string, std::string);
  void check_remove(std::string);

  // Book
  void add_book();

  // Supplier
  void add_supplier();

  // Employee
  void add_employee();
};

}  // namespace database
#endif  // DATABASE_H_
