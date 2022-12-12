// Copyright [year] <Copyright Owner>"  [legal/copyright]
// https://en.cppreference.com/w/cpp/language/friend
// https://stackoverflow.com/questions/67877469/cpp-inheritance-parent-function-child-variable
#ifndef TABLE_H_
#define TABLE_H_

#include <mysql.h>

#include <string>

namespace table {

class Table {
 public:
  std::string table_name;
  virtual void menu(MYSQL*) = 0;
  void view(MYSQL*);
  virtual void add(MYSQL*) = 0;
  void search(MYSQL*);
  void update(MYSQL*, std::string, std::string);
  virtual void update_menu(MYSQL*) = 0;
  void remove(MYSQL*);
  // Customize key
  bool search_id(MYSQL*, int);
  virtual void print(MYSQL_ROW) = 0;
};

class Book : public Table {
 public:
  Book() : Table() { table_name = "BOOK"; }
  void menu(MYSQL*);
  void update_menu(MYSQL*);
  void add(MYSQL*);
  void print(MYSQL_ROW);
};

class Supplier : public Table {
 public:
  Supplier() : Table() { table_name = "SUPPLIER"; }
  void menu(MYSQL*);
  void update_menu(MYSQL*);
  void add(MYSQL*);
  void print(MYSQL_ROW);
};

}  // namespace table
#endif  // TABLE_H_
