// Copyright [year] <Copyright Owner>"  [legal/copyright]
// https://dev.mysql.com/doc/c-api/8.0/en/mysql-use-result.html
// https://dev.mysql.com/doc/c-api/5.7/en/mysql-store-result.html
#include "./table.h"

#include <mysql.h>

#include <iostream>
#include <sstream>

void table::Table::view(MYSQL* db_conn) {
  system("cls");

  std::stringstream statement("");  // #include <sstream>
  statement << "SELECT * from " + std::string(table_name) + ";";
  mysql_query(db_conn, statement.str().c_str());
  MYSQL_RES* res_set = mysql_use_result(db_conn);
  MYSQL_ROW row;

  while ((row = mysql_fetch_row(res_set)) != NULL) {
    print(row);
  }
  getchar();
  return;
}

void table::Table::search(MYSQL* db_conn) {
  system("cls");

  int id;

  std::cout << "Enter " + table_name + " ID to search: ";
  std::cin >> id;

  search_id(db_conn, id);
  getchar();
  return;
}

void table::Table::update(MYSQL* db_conn, std::string column,
                          std::string type) {
  system("cls");

  int id;
  char c;

  std::cout << "Enter " + table_name + " ID to update: ";
  std::cin >> id;

  if (search_id(db_conn, id)) {
    std::cout << "Do you want to update the " + table_name + " " + column +
                     "? [Y/N]: ";
    std::cin >> c;

    if (c == 121 || c == 89) {
      std::string value;
      std::cout << "Enter the new " + table_name + " " + column + ": ";
      std::cin >> value;

      std::stringstream statement("");  // #include <sstream>

      // Convert string to integer
      if (type == "integer")
        statement << "UPDATE " + table_name + " SET " + column + " = "
                  << std::stoi(value) << " WHERE id = " << id << ";";

      // Add single quotes for string
      if (type == "string")
        statement << "UPDATE " + table_name + " SET " + column + " = "
                  << "'" << value << "'"
                  << " WHERE id = " << id << ";";

      mysql_query(db_conn, statement.str().c_str());
      MYSQL_RES* res_set = mysql_store_result(db_conn);

      if (!std::string(mysql_error(db_conn)).empty()) {
        std::cout << "MySQL Error:" << std::endl;
        std::cout << mysql_error(db_conn) << std::endl;
      }

      if (mysql_errno(db_conn) != 0) {
        std::cout << "MySQL Error Number:" << std::endl;
        std::cout << mysql_errno(db_conn) << std::endl;
      }

      if (!res_set && (mysql_field_count(db_conn) != 0)) {
        std::cout << "MySQL Field Count:" << std::endl;
        std::cout << mysql_field_count(db_conn) << std::endl;
      }

      search_id(db_conn, id);
      std::cout << table_name + " " + column + " UPDATED." << std::endl;

    } else {
      std::cout << table_name + " " + column + " not UPDATED.";
    }
  }
  getchar();
  return;
}

void table::Table::remove(MYSQL* db_conn) {
  system("cls");

  int id;
  char c;

  std::cout << "Enter " + table_name + " ID to REMOVE: ";
  std::cin >> id;
  if (search_id(db_conn, id)) {
    std::cout << "Do you want to REMOVE the " + table_name + "? [Y/N]: ";
    std::cin >> c;

    if (c == 121 || c == 89) {
      std::stringstream statement("");  // #include <sstream>

      statement << "DELETE FROM " + table_name + " WHERE id = " << id << ";";

      mysql_query(db_conn, statement.str().c_str());
      MYSQL_RES* res_set = mysql_store_result(db_conn);

      if (!std::string(mysql_error(db_conn)).empty()) {
        std::cout << "MySQL Error:" << std::endl;
        std::cout << mysql_error(db_conn) << std::endl;
      }

      if (mysql_errno(db_conn) != 0) {
        std::cout << "MySQL Error Number:" << std::endl;
        std::cout << mysql_errno(db_conn) << std::endl;
      }

      if (mysql_field_count(db_conn) == 0) {
        std::cout << "MySQL Field Count:" << std::endl;
        std::cout << mysql_field_count(db_conn) << std::endl;
      }

      std::cout << table_name + " REMOVED." << std::endl;
    }
  }
  getchar();
  return;
}

bool table::Table::search_id(MYSQL* db_conn, int id) {
  std::stringstream statement("");  // #include <sstream>
  statement << "SELECT * FROM " + table_name + " WHERE id = " << id << ";";
  mysql_query(db_conn, statement.str().c_str());
  MYSQL_RES* res_set = mysql_store_result(db_conn);
  MYSQL_ROW row;

  bool found;

  if ((row = mysql_fetch_row(res_set)) != NULL) {
    found = true;
    print(row);
  } else {
    std::cout << table_name + " not found." << std::endl;
    found = false;
  }
  return found;
}
