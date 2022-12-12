// Copyright [year] <Copyright Owner>"  [legal/copyright]
// https://stackoverflow.com/questions/7970617/how-can-i-check-if-char-variable-points-to-empty-string
#include <mysql.h>

#include <iostream>
#include <sstream>

#include "./table.h"

void table::Book::update_menu(MYSQL* db_conn) {
  int c;

  while (true) {
    system("cls");
    std::cout << " UPDATE BOOKS" << std::endl;
    std::cout << " 1. Name" << std::endl;
    std::cout << " 2. Author" << std::endl;
    std::cout << " 3. Price" << std::endl;
    std::cout << " 4. Quantity" << std::endl;
    std::cout << " 5. Return to Book Menu" << std::endl;
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
        column = "AUTHOR";
        type = "string";
        break;

      case 3:
        column = "PRICE";
        type = "integer";
        break;

      case 4:
        column = "QUANTITY";
        type = "integer";
        break;

      case 5:
        return;

      default:
        std::cout << "Wrong Input." << std::endl;
    }

    if (column != "") {
      update(db_conn, column, type);
    }
    getchar();
  }
  return;
}

void table::Book::add(MYSQL* db_conn) {
  system("cls");

  std::string name;
  std::string author;
  int price;
  int quantity;

  std::cout << "Enter the BOOK NAME: ";
  std::cin >> name;

  std::cout << "Enter the BOOK AUTHOR: ";
  std::cin >> author;

  // Check input type
  std::cout << "Enter the BOOK PRICE: ";
  std::cin >> price;

  std::cout << "Enter the BOOK QUANTITY: ";
  std::cin >> quantity;

  std::stringstream statement("");  // #include <sstream>
  statement << "INSERT INTO " + table_name +
                   "(NAME, AUTHOR, PRICE, QUANTITY) VALUES('"
            << name << "','" << author << "'," << price << "," << quantity
            << ");";
  mysql_query(db_conn, statement.str().c_str());
  MYSQL_RES* res_set = mysql_store_result(db_conn);

  // Error Check
  if (!std::string(mysql_error(db_conn)).empty()) {
    std::cout << "MySQL Error:" << std::endl;
    std::cout << mysql_error(db_conn) << std::endl;
  }

  if (mysql_errno(db_conn) != 0) {
    std::cout << "MySQL Error Number:" << std::endl;
    std::cout << mysql_errno(db_conn) << std::endl;
  }

  if (!res_set && (mysql_field_count(db_conn) == 0)) {
    std::cout << "MySQL Field Count:" << std::endl;
    std::cout << mysql_field_count(db_conn) << std::endl;
  }

  std::cout << "BOOK ADDED." << std::endl;

  getchar();
  return;
}

void table::Book::menu(MYSQL* db_conn) {
  int c;

  while (true) {
    system("cls");
    std::cout << " BOOKS" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Search" << std::endl;
    std::cout << " 4. Update" << std::endl;
    std::cout << " 5. Return to Main Menu" << std::endl;
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
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    getchar();
  }
  return;
}

void table::Book::print(MYSQL_ROW row) {
  std::cout << "BOOK ID:" << row[0] << std::endl;
  std::cout << "BOOK NAME: " << row[1] << std::endl;
  std::cout << "BOOK AUTHOR: " << row[2] << std::endl;
  std::cout << "BOOK PRICE: " << row[3] << std::endl;
  std::cout << "BOOK QUANTITY: " << row[4] << std::endl;
  std::cout << std::endl;
  return;
}
