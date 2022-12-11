// Copyright [year] <Copyright Owner>

#include "./supplier.h"

#include <iostream>

#include "./database.h"

enum Options {
  VIEW = 1,
  ADD,
  REMOVE,
  SEARCH,
  UPDATE,
  RETURN,
};

void supplier::update_menu(database::Database* db) {
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

    switch (c) {
      case 1:
        db->update_supplier("name");
        getchar();
        break;

      case 2:
        db->update_supplier("phone");
        getchar();
        break;

      case 3:
        db->update_supplier("address");
        getchar();
        break;

      case 4:
        return;

      default:
        std::cout << "Wrong Input." << std::endl;
        getchar();
    }
  }
  return;
}

void supplier::menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " SUPPLIERS" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Remove" << std::endl;
    std::cout << " 4. Search" << std::endl;
    std::cout << " 5. Update" << std::endl;
    std::cout << " 6. Return to Main Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;

    switch (c) {
      case VIEW:
        db->view_supplier();
        getchar();
        break;

      case ADD:
        db->add_supplier();
        getchar();
        break;

      case REMOVE:
        db->remove_supplier();
        getchar();
        break;

      case SEARCH:
        db->search_supplier();
        getchar();
        break;

      case UPDATE:
        supplier::update_menu(db);
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
