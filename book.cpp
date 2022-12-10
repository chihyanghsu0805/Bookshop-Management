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
  UPDATE_NAME,
  UPDATE_AUTHOR,
  UPDATE_PRICE,
  UPDATE_QUANTITY,
  RETURN,
};

void book::menu(database::Database* db) {
  system("cls");

  std::cout << " Books" << std::endl;
  std::cout << " 1. VIEW" << std::endl;
  std::cout << " 2. ADD" << std::endl;
  std::cout << " 3. SEARCH" << std::endl;
  std::cout << " 4. UPDATE NAME" << std::endl;
  std::cout << " 5. UPDATE AUTHOR" << std::endl;
  std::cout << " 6. UPDATE PRICE" << std::endl;
  std::cout << " 7. UPDATE QUANTITY" << std::endl;
  std::cout << " 8. RETURN TO MAIN MENU" << std::endl;
  std::cout << "Enter Choice: ";

  int c;
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

    // Update menu?
    case UPDATE_NAME:
      db->search_book();
      getchar();
      break;

    case UPDATE_AUTHOR:
      db->search_book();
      getchar();
      break;

    case UPDATE_PRICE:
      db->search_book();
      getchar();
      break;

    case UPDATE_QUANTITY:
      db->search_book();
      getchar();
      break;

    case RETURN:
      db->search_book();
      getchar();
      break;

    default:
      std::cout << "Wrong Input" << std::endl;
      getchar();
      return;
  }
  return;
}
