// Copyright [year] <Copyright Owner>"  [legal/copyright]
// This work is inspired by the following:
// https://github.com/Aryan-Khanijo/Bookshop-Management-System-CPP-Project
// https://www.codeguru.com/database/database-programming-with-c-c/

#include <iostream>

#include "./book.h"
#include "./constants.h"
#include "./database.h"
#include "./employee.h"
#include "./supplier.h"

enum MenuOptions {
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
/*
void prompt_password() {
  std::string user;
  std::string password;

  std:: cout << "User: ";
  std:: cin >> user;

  std:: cout << "Password: ";
  std:: cin >> password;
}
*/
int main() {
  system("cls");
  // Login
  /*

  */
  // Database should already exists
  database::Database* db = new database::Database();
  bool connected =
      db->connect(connection_constants::host, connection_constants::user,
                  connection_constants::password,
                  connection_constants::database, connection_constants::port);

  while (connected) {
    int menu_choice = menu();
    switch (menu_choice) {
      case MenuOptions::books:
        book::menu(db);
        break;
      case MenuOptions::suppliers:
        supplier::menu(db);
        break;
      /*
      case PURCHASES:
        menu::book();
      */
      case employees:
        // Should we use abstract class for manager/employee permission?
        // Or password is good enough?
        employee::menu(db);
        break;
        /*
        if (prompt_manager())
          employee::menu(db);
        else
          std::cout << "Manager Only." << std::endl;
        */
      /*
      case MEMBERS:
        menu::book();

      case SALES:
        menu::book();

      */
      case MenuOptions::exitMenu:
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
