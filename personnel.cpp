// Copyright [year] <Copyright Owner>

#include "./personnel.h"

#include <iostream>

#include "./book.h"
#include "./constants.h"
#include "./database.h"
#include "./employee.h"
#include "./member.h"
#include "./supplier.h"

enum MainMenuOptions {
  books = 1,
  suppliers,
  purchases,
  employees,
  members,
  sales,
  exitMenu
};

int main_menu() {
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

// Override
void identification::Personnel::manage_book(database::Database* db) {
  book::menu(db);
}

void identification::Personnel::manage_supplier(database::Database* db) {
  supplier::menu(db);
}

void identification::Personnel::manage_employee(database::Database* db) {
  employee::menu(db);
}
void identification::Personnel::manage_member(database::Database* db) {
  member::menu(db);
}

void identification::Personnel::manage_bookshop() {
  // Database should already exists
  database::Database* db = new database::Database();
  bool connected =
      db->connect(connection_constants::host, connection_constants::user,
                  connection_constants::password,
                  connection_constants::database, connection_constants::port);

  while (connected) {
    int menu_choice = main_menu();
    switch (menu_choice) {
      case MainMenuOptions::books:
        this->manage_book(db);
        break;
      case MainMenuOptions::suppliers:
        this->manage_supplier(db);
        break;
      /*
      case PURCHASES:
        menu::book();
      */
      case employees:
        this->manage_employee(db);
        break;

      case members:
        this->manage_member(db);
      /*
      case SALES:
        menu::book();

      */
      case MainMenuOptions::exitMenu:
        system("cls");
        return;
    }
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore();
    }
  }
}

// Prompt override
void identification::Manager::manage_employee(database::Database* db) {
  std::cout << "Access Denied." << std::endl;
}

void identification::Staff::manage_supplier(database::Database* db) {
  std::cout << "Access Denied." << std::endl;
}

void identification::Staff::manage_employee(database::Database* db) {
  std::cout << "Access Denied." << std::endl;
}
