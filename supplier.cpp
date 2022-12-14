// Copyright [year] <Copyright Owner>

#include "./supplier.h"

#include <iostream>

#include "./database.h"

enum SupplierMenuOptions {
  view = 1,
  add,
  remove,
  search,
  update,
  returnToMain,
};

enum SupplierUpdateMenuOptions {
  name = 1,
  phone,
  address,
  returnToSupplier,
};

void supplier::print(MYSQL_ROW row) {
  std::cout << supplier::table_name << " ID:" << row[0] << std::endl;
  std::cout << supplier::table_name << " NAME: " << row[1] << std::endl;
  std::cout << supplier::table_name << " PHONE: " << row[2] << std::endl;
  std::cout << supplier::table_name << " NUMBER: " << row[3] << std::endl;
  std::cout << std::endl;
  return;
}

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
      case SupplierUpdateMenuOptions::name:
        db->update(supplier::table_name, "name", "string");
        break;
      case SupplierUpdateMenuOptions::phone:
        db->update(supplier::table_name, "phone", "string");
        break;
      case SupplierUpdateMenuOptions::address:
        db->update(supplier::table_name, "address", "string");
        break;
      case SupplierUpdateMenuOptions::returnToSupplier:
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    getchar();
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
      case SupplierMenuOptions::view:
        db->view(supplier::table_name);
        break;
      case SupplierMenuOptions::add:
        db->add_supplier();
        break;
      case SupplierMenuOptions::remove:
        db->remove(supplier::table_name);
        break;
      case SupplierMenuOptions::search:
        db->search(supplier::table_name);
        break;
      case SupplierMenuOptions::update:
        supplier::update_menu(db);
        break;
      case SupplierMenuOptions::returnToMain:
        return;
      default:
        std::cout << "Wrong Input" << std::endl;
    }
    getchar();
  }
  return;
}
