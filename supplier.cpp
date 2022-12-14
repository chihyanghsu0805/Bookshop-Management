// Copyright [year] <Copyright Owner>"  [legal/copyright]

#include "./supplier.h"

#include <mysql.h>

#include <iostream>
#include <sstream>

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
    std::string column = "";
    std::string type = "";
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

void supplier::add(MYSQL* db_conn) {
  system("cls");

  std::string name;
  std::string phone;
  std::string address;

  std::cout << "Enter the SUPPLIER NAME: ";
  std::cin >> name;

  std::cout << "Enter the SUPPLIER PHONE: ";
  std::cin >> phone;

  std::cout << "Enter the SUPPLIER ADDRESS: ";
  std::cin >> address;

  std::stringstream statement("");  // #include <sstream>
  statement << "INSERT INTO " + table_name + "(NAME, PHONE, ADDRESS) VALUES("
            << "'" << name << "'"
            << ","
            << "'" << phone << "'"
            << ","
            << "'" << address << "'"
            << ");";
  mysql_query(db_conn, statement.str().c_str());
  MYSQL_RES* res_set = mysql_store_result(db_conn);

  if (!std::string(mysql_error(db_conn)).empty()) {
    std::cout << "MySQL Error:" << std::endl;
    std::cout << mysql_error(db_conn) << std::endl;
  }

  if (mysql_errno(db_conn) != 0) {
    std::cout << "MySQL Error Number:" << std::endl;
    std::cout << mysql_errno(db_conn) << std::endl;
  }

  if (mysql_field_count(db_conn) == 0) {
    std::cout << "MySQL Field Count:" << std::endl;
    std::cout << mysql_field_count(db_conn) << std::endl;
  }

  std::cout << "SUPPLIER ADDED." << std::endl;

  getchar();
  return;
}

void supplier::menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " SUPPLIERS" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Search" << std::endl;
    std::cout << " 4. Update" << std::endl;
    std::cout << " 5. Remove" << std::endl;
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
