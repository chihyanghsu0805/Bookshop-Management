// Copyright [year] <Copyright Owner>

#include "./purchase.h"

#include <iostream>
#include <sstream>

#include "./book.h"
#include "./database.h"
#include "./supplier.h"

enum PurchaseMenuOptions {
  view = 1,
  add,
  update,
  returnToMain,
};

void purchase::print(MYSQL_ROW row) {
  std::cout << purchase::table_name << " ID:" << row[0] << std::endl;
  std::cout << purchase::table_name << " QUANTITY:" << row[1] << std::endl;
  std::cout << purchase::table_name << " ORDER DATE:" << row[2] << std::endl;
  std::cout << purchase::table_name << " EXPECT DATE:" << row[3] << std::endl;
  std::cout << purchase::table_name << " RECEIVED:" << row[4] << std::endl;
  std::cout << purchase::table_name << " BOOK ID:" << row[5] << std::endl;
  std::cout << purchase::table_name << " SUPPLIER ID:" << row[6] << std::endl;
  std::cout << purchase::table_name << " INVENTORY:" << row[7] << std::endl;
  std::cout << std::endl;
}

std::string purchase::prompt_add() {
  std::string book_id;
  std::string supplier_id;
  int quantity;
  std::string expect_date;
  std::string join_date;
  std::string salary;

  std::cout << "Enter the " + std::string(book::table_name) + " ID: ";
  std::cin >> book_id;

  std::cout << "Enter the " + std::string(supplier::table_name) + " ID: ";
  std::cin >> supplier_id;

  std::cout << "Enter the " + std::string(purchase::table_name) + " QUANTITY: ";
  std::cin >> quantity;

  std::cout << "Enter the " + std::string(purchase::table_name) +
                   " EXPECT DAYS: ";
  std::cin >> expect_date;

  std::stringstream statement("");
  statement
      << "INSERT INTO " + std::string(purchase::table_name) +
             "(BOOK_ID, SUPPLIER_ID, QUANTITY, ORDER_DATE, EXPECT_DATE) VALUES("
      << "'" << book_id << "'"
      << ","
      << "'" << supplier_id << "'"
      << "," << quantity << ","
      << "curdate()"
      << ","
      << "Date_add(curdate(), INTERVAL " << expect_date << " DAY)"
      << ");";
  return statement.str();
}

void purchase::menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " PURCHASES" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Update" << std::endl;
    std::cout << " 4. Return to Main Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;

    switch (c) {
      case PurchaseMenuOptions::view:
        db->view(purchase::table_name);
        break;
      case PurchaseMenuOptions::add:
        db->add_purchase();
        break;
      case PurchaseMenuOptions::update:
        db->update(purchase::table_name, "received", "string");
        db->update_inventory();
        break;
      case PurchaseMenuOptions::returnToMain:
        return;
      default:
        std::cout << "Wrong Input." << std::endl;
    }
    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore();
    }
    getchar();
  }
  return;
}
