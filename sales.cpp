// Copyright [year] <Copyright Owner>

#include "./sales.h"

#include <iostream>
#include <sstream>

#include "./book.h"
#include "./database.h"
#include "./member.h"

enum SalesMenuOptions {
  view = 1,
  add,
  summary,
  returnToMain,
};

void sales::print(MYSQL_ROW row) {
  std::cout << sales::table_name << " ID:" << row[0] << std::endl;
  std::cout << sales::table_name << " MEMBER:" << row[1] << std::endl;
  std::cout << sales::table_name << " BOOK:" << row[2] << std::endl;
  std::cout << sales::table_name << " Quantity:" << row[3] << std::endl;
  std::cout << sales::table_name << " BILL:" << row[4] << std::endl;
  std::cout << sales::table_name << " DATE:" << row[5] << std::endl;
  std::cout << std::endl;
}

void sales::menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " SALES" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Summary" << std::endl;
    std::cout << " 4. Return to Main Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;

    switch (c) {
      case SalesMenuOptions::view:
        db->view(sales::table_name);
        break;
      case SalesMenuOptions::add:
        db->add_sales();
        break;
      case SalesMenuOptions::summary:
        db->summarize_sales();
        break;
      case SalesMenuOptions::returnToMain:
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore();
    }
    getchar();
  }
  return;
}
