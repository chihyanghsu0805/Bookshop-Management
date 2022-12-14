// Copyright [year] <Copyright Owner>

#include "./book.h"

#include <iostream>

#include "./database.h"

enum BookMenuOptions {
  view = 1,
  add,
  search,
  update,
  returnToMain,
};

enum BookUpdateMenuOptions {
  name = 1,
  author,
  price,
  quantity,
  returnToBook,
};

void book::print(MYSQL_ROW row) {
  std::cout << book::table_name << " ID:" << row[0] << std::endl;
  std::cout << book::table_name << " NAME: " << row[1] << std::endl;
  std::cout << book::table_name << " AUTHOR: " << row[2] << std::endl;
  std::cout << book::table_name << " PRICE: " << row[3] << std::endl;
  std::cout << book::table_name << " QUANTITY: " << row[4] << std::endl;
  std::cout << std::endl;
}

void book::update_menu(database::Database* db) {
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

    switch (c) {
      case BookUpdateMenuOptions::name:
        db->update(book::table_name, "name", "string");
        break;
      case BookUpdateMenuOptions::author:
        db->update(book::table_name, "author", "string");
        break;
      case BookUpdateMenuOptions::price:
        db->update(book::table_name, "price", "integer");
        break;
      case BookUpdateMenuOptions::quantity:
        db->update(book::table_name, "quantity", "integer");
        break;
      case BookUpdateMenuOptions::returnToBook:
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    getchar();
  }
  return;
}

void book::menu(database::Database* db) {
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
      case BookMenuOptions::view:
        db->view(book::table_name);
        break;
      case BookMenuOptions::add:
        db->add_book();
        break;
      case BookMenuOptions::search:
        db->search(book::table_name);
        break;
      case BookMenuOptions::update:
        book::update_menu(db);
        break;
      case BookMenuOptions::returnToMain:
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    getchar();
  }
  return;
}
