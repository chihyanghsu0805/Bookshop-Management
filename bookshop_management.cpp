// Copyright [year] <Copyright Owner>"  [legal/copyright]
// This work is inspired by the following:
// https://github.com/Aryan-Khanijo/Bookshop-Management-System-CPP-Project
// https://www.codeguru.com/database/database-programming-with-c-c/

#include <iostream>

#include "./book.h"
#include "./constants.h"
#include "./database.h"
#include "./supplier.h"

enum SupplierMenuOptions {
  books = 1,
  suppliers,
  purchases,
  employees,
  members,
  sales,
  exitMenu
};

int menu() {
  system("cls");
  std::cout << " BOOKSHOP MANGEMENT SYSTEM" << std::endl;
  std::cout << " 1. Books" << std::endl;
  std::cout << " 2. Suppliers" << std::endl;
  std::cout << " 3. Purchases" << std::endl;
  std::cout << " 4. Employees" << std::endl;
  std::cout << " 5. Members" << std::endl;
  std::cout << " 6. Sales" << std::endl;
  std::cout << " 7. Exit" << std::endl;
  std::cout << "Enter Choice: ";

  int c;
  std::cin >> c;

  return c;
}

int main() {
  system("cls");
  // Database should already exists.
  database::Database* db = new database::Database();
  db->connect(connection_constants::host, connection_constants::user,
              connection_constants::password, connection_constants::database,
              connection_constants::port);

  int menu_choice;
  while (true) {
    menu_choice = menu();
    switch (menu_choice) {
      case SupplierMenuOptions::books:
        book::menu(db);
        break;
      case SupplierMenuOptions::suppliers:
        supplier::menu(db);
        break;
      /*
      case PURCHASES:
        menu::book();

      case EMPLOYEES:
        menu::book();

      case MEMBERS:
        menu::book();

      case SALES:
        menu::book();

      */
      case SupplierMenuOptions::exitMenu:
        system("cls");
        return 0;
    }
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore();
    }
  }
  system("cls");
  return 0;
}
