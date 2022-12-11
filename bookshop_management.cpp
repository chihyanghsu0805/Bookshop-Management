// Copyright [year] <Copyright Owner>"  [legal/copyright]
// If cin extract fails
// https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
// https://www.quora.com/What-is-the-difference-between-stdio-h-and-conio-h
// https://stackoverflow.com/questions/29915854/why-does-c-require-breaks-in-switch-statements
// https://github.com/Aryan-Khanijo/Bookshop-Management-System-CPP-Project
// https://www.codeguru.com/database/database-programming-with-c-c/
// g++ -o bookshop_management.exe bookshop_management.cpp database.cpp book.cpp
// supplier.cpp -I "C:/Program Files/MySQL/MySQL Server 8.0/include/" -L
// "C:/Program Files/MySQL/MySQL Server 8.0/lib/" -l libmysql
// constants.cpp

#include <iostream>

#include "./book.h"
#include "./constants.h"
#include "./database.h"
#include "./supplier.h"

enum Options {
  BOOKS = 1,
  SUPPLIERS,
  PURCHASES,
  EMPLOYEES,
  MEMBERS,
  SALES,
  EXIT
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
      case BOOKS:
        book::menu(db);
        break;  // Fall through

      case SUPPLIERS:
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
      case EXIT:
        system("cls");
        return 0;
    }
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore();
    }
  }
  // Should we return?
  return 0;
}
