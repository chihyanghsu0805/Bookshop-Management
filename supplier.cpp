// Copyright [year] <Copyright Owner>"  [legal/copyright]
#include <mysql.h>

#include <iostream>
#include <sstream>

#include "./table.h"

void table::Supplier::update_menu(MYSQL* db_conn) {
  int c;

  while (true) {
    system("cls");
    std::cout << " UPDATE SUPPLIERS" << std::endl;
    std::cout << " 1. Name" << std::endl;
    std::cout << " 2. Phone" << std::endl;
    std::cout << " 3. Address" << std::endl;
    std::cout << " 4. Return to Supplier Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;
    std::string column = "";
    std::string type = "";
    switch (c) {
      case 1:
        column = "NAME";
        type = "string";
        break;

      case 2:
        column = "PHONE";
        type = "string";
        break;

      case 3:
        column = "ADDRESS";
        type = "string";
        break;

      case 4:
        return;

      default:
        std::cout << "Wrong Input" << std::endl;
    }

    if (column != "") {
      update(db_conn, column, type);
    }
    getchar();
  }
  return;
}

void table::Supplier::add(MYSQL* db_conn) {
  system("cls");

  std::string name;
  std::string phone;
  std::string address;

  std::cout << "Enter the SUPPLIER NAME: ";
  std::cin >> name;

  std::cout << "Enter the SUPPLIER PHONE: ";
  std::cin >> phone;

  std::cout << "Enter the SUPPLIER ADDRESS: ";
  std::cin >> address;

  std::stringstream statement("");  // #include <sstream>
  statement << "INSERT INTO " + table_name + "(NAME, PHONE, ADDRESS) VALUES("
            << "'" << name << "'"
            << ","
            << "'" << phone << "'"
            << ","
            << "'" << address << "'"
            << ");";
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

  std::cout << "SUPPLIER ADDED." << std::endl;

  getchar();
  return;
}

void table::Supplier::menu(MYSQL* db_conn) {
  int c;

  while (true) {
    system("cls");
    std::cout << " SUPPLIERS" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Search" << std::endl;
    std::cout << " 4. Update" << std::endl;
    std::cout << " 5. Remove" << std::endl;
    std::cout << " 6. Return to Main Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;

    switch (c) {
      case 1:
        view(db_conn);
        break;
      case 2:
        add(db_conn);
        break;
      case 3:
        search(db_conn);
        break;
      case 4:
        update_menu(db_conn);
        break;
      case 5:
        remove(db_conn);
        break;
      case 6:
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    getchar();
  }
  return;
}

void table::Supplier::print(MYSQL_ROW row) {
  std::cout << "SUPPLIER ID:" << row[0] << std::endl;
  std::cout << "SUPPLIER NAME: " << row[1] << std::endl;
  std::cout << "SUPPLIER PHONE: " << row[2] << std::endl;
  std::cout << "SUPPLIER ADDRESS: " << row[3] << std::endl;
  std::cout << std::endl;
  return;
}
