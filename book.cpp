// Copyright [year] <Copyright Owner>
// https://stackoverflow.com/questions/41407242/declaring-the-getch-function
// https://cplusplus.com/reference/cstdio/getchar/
// https://www.quora.com/Why-dont-we-use-include-stdio-h-in-C
// https://www.freecodecamp.org/news/getline-in-cpp-cin-getline-function-example/

#include "./book.h"

#include <iostream>

#include "./database.h"

enum Options {
  VIEW = 1,
  ADD,
  SEARCH,
  UPDATE,
  RETURN,
};

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
      case 1:
        db->update_book("name");
        getchar();
        break;

      case 2:
        db->update_book("author");
        getchar();
        break;

      case 3:
        db->update_book("price");
        getchar();
        break;

      case 4:
        db->update_book("quantity");
        getchar();
        break;

      case 5:
        return;

      default:
        std::cout << "Wrong Input." << std::endl;
        getchar();
    }
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
      case VIEW:
        db->view_book();
        getchar();
        break;

      case ADD:
        db->add_book();
        getchar();
        break;

      case SEARCH:
        db->search_book();
        getchar();
        break;

      case UPDATE:
        book::update_menu(db);
        getchar();
        break;

      case RETURN:
        return;

      default:
        std::cout << "Wrong Input" << std::endl;
        getchar();
    }
  }
  return;
}
