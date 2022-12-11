// Copyright [year] <Copyright Owner>
#include "./database.h"

#include <mysql.h>

#include <iostream>
#include <sstream>

#include "./book.h"

void database::Database::connect(const std::string host, const std::string user,
                                 const std::string password,
                                 const std::string database, const int port) {
  db_conn = mysql_init(NULL);
  if (!db_conn)
    std::cout << "MySQL initialization failed." << std::endl;
  else
    std::cout << "MySQL initialized." << std::endl;

  db_conn =
      mysql_real_connect(db_conn, host.c_str(), user.c_str(), password.c_str(),
                         database.c_str(), port, NULL, 0);

  if (!db_conn)
    std::cout << "Connection Error." << std::endl;
  else
    std::cout << "Connected." << std::endl;

  getchar();
  return;
}

// Table name
void database::Database::add_book() {
  system("cls");

  std::string name;
  std::string author;
  int price;
  int quantity;

  std::cout << "Enter the BOOK NAME: ";
  std::cin >> name;

  std::cout << "Enter the BOOK AUTHOR: ";
  std::cin >> author;

  std::cout << "Enter the BOOK PRICE: ";
  std::cin >> price;

  std::cout << "Enter the BOOK QUANTITY: ";
  std::cin >> quantity;

  std::stringstream statement("");  // #include <sstream>
  statement << "INSERT INTO " + book::table_name +
                   "(NAME, AUTHOR, PRICE, QUANTITY) VALUES('"
            << name << "','" << author << "'," << price << "," << quantity
            << ");";
  mysql_query(db_conn, statement.str().c_str());
  res_set = mysql_store_result(db_conn);

  if (res_set == NULL)  // Insert successful returns NULL
    std::cout << "Entry added." << std::endl;
  else
    std::cout << "Entry error." << std::endl;

  getchar();  // Ignore enter
  return;
}

void database::Database::view_book() {
  system("cls");

  std::stringstream statement("");  // #include <sstream>
  statement << "SELECT * from " + book::table_name + ";";
  mysql_query(db_conn, statement.str().c_str());
  res_set = mysql_store_result(db_conn);

  while ((row = mysql_fetch_row(res_set)) != NULL) {
    print_book();
  }
  getchar();  // Ignore enter
  return;
}

void database::Database::search_book() {
  system("cls");

  int id;

  std::cout << "Enter BOOK ID to search: ";
  std::cin >> id;

  search_book_id(id);
  getchar();  // Ignore enter
  return;
}

bool database::Database::search_book_id(int id) {
  std::stringstream statement("");  // #include <sstream>
  statement << "SELECT * FROM " + book::table_name + " WHERE id = " << id
            << ";";
  mysql_query(db_conn, statement.str().c_str());
  res_set = mysql_store_result(db_conn);

  bool found;

  if ((row = mysql_fetch_row(res_set)) != NULL) {
    found = true;
    print_book();
  } else {
    std::cout << "BOOK not found." << std::endl;
    found = false;
  }
  return found;
}

void database::Database::print_book() {
  std::cout << "BOOK ID:" << row[0] << std::endl;
  std::cout << "BOOK NAME: " << row[1] << std::endl;
  std::cout << "BOOK AUTHOR: " << row[2] << std::endl;
  std::cout << "BOOK PRICE: " << row[3] << std::endl;
  std::cout << "BOOK QUANTITY: " << row[4] << std::endl;
  std::cout << std::endl;
  return;
}

void database::Database::update_book(std::string field) {
  system("cls");

  int id;
  char c;

  std::cout << "Enter BOOK ID to update: ";
  std::cin >> id;
  if (search_book_id(id)) {
    std::cout << "Do you want to update the BOOK " + field + "? [Y/N]: ";
    std::cin >> c;

    if (c == 121 || c == 89) {
      std::string value;
      std::cout << "Enter the new BOOK " + field + ": ";
      std::cin >> value;

      std::stringstream statement("");  // #include <sstream>
      if (field == "price")
        statement << "UPDATE " + book::table_name + " SET " + field + " = "
                  << std::stoi(value) << " WHERE id = " << id << ";";

      if (field == "quantity")
        statement << "UPDATE " + book::table_name + " SET " + field + " = "
                  << std::stoi(value) << " WHERE id = " << id << ";";

      if (field == "author")
        statement << "UPDATE " + book::table_name + " SET " + field + " = "
                  << "'" << value << "'"
                  << " WHERE id = " << id << ";";

      if (field == "name")
        statement << "UPDATE " + book::table_name + " SET " + field + " = "
                  << "'" << value << "'"
                  << " WHERE id = " << id << ";";

      mysql_query(db_conn, statement.str().c_str());
      res_set = mysql_store_result(db_conn);

      search_book_id(id);

      if (res_set != NULL)  // Update successfuly returns pointer
        std::cout << "BOOK " + field + " updated." << std::endl;
      else
        std::cout << "Entry Error." << std::endl;

    } else {
      std::cout << "BOOK " + field + " not updated.";
    }
  }
  getchar();  // Ignore enter
  return;
}
