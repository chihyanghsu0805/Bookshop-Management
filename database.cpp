// Copyright [year] <Copyright Owner>
#include "./database.h"

#include <mysql.h>

#include <iostream>
#include <sstream>

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

  std::stringstream statement("");  // #include <sstream>

  std::cout << "Enter the BOOK NAME: ";
  std::cin >> name;

  std::cout << "Enter the BOOK AUTHOR: ";
  std::cin >> author;

  std::cout << "Enter the BOOK PRICE: ";
  std::cin >> price;

  std::cout << "Enter the BOOK QUANTITY: ";
  std::cin >> quantity;

  statement << "INSERT INTO book (NAME, AUTHOR, PRICE, QUANTITY) VALUES('"
            << name << "','" << author << "'," << price << "," << quantity
            << ");";
  mysql_query(db_conn, statement.str().c_str());
  res_set = mysql_store_result(db_conn);

  if (!(res_set))
    std::cout << "Entry added." << std::endl;
  else
    std::cout << "Entry error." << std::endl;

  getchar();  // Ignore enter
  return;
}

void database::Database::view_book() {
  system("cls");
  std::stringstream statement("");  // #include <sstream>
  statement << "SELECT * from book;";
  mysql_query(db_conn, statement.str().c_str());
  res_set = mysql_store_result(db_conn);

  int i = 0;

  while ((row = mysql_fetch_row(res_set)) != NULL) {
    std::cout << "BOOK ID: " << ++i << std::endl;
    std::cout << "BOOK NAME: " << row[1] << std::endl;
    std::cout << "BOOK AUTHOR: " << row[2] << std::endl;
    std::cout << "BOOK PRICE: " << row[3] << std::endl;
    std::cout << "BOOK QUANTITY: " << row[4] << std::endl;
    std::cout << std::endl;
  }
  getchar();  // Ignore enter
  return;
}

void database::Database::search_book() {
  system("cls");

  int id;

  std::cout << "Enter BOOK ID to search: ";
  std::cin >> id;

  std::stringstream statement("");  // #include <sstream>
  statement << "SELECT * FROM book WHERE id = " << id << ";";

  mysql_query(db_conn, statement.str().c_str());
  res_set = mysql_store_result(db_conn);

  if ((row = mysql_fetch_row(res_set)) != NULL) {
    std::cout << "BOOK ID:" << row[0] << std::endl;
    std::cout << "BOOK NAME: " << row[1] << std::endl;
    std::cout << "BOOK AUTHOR: " << row[2] << std::endl;
    std::cout << "BOOK PRICE: " << row[3] << std::endl;
    std::cout << "BOOK QUANTITY: " << row[4] << std::endl;
    std::cout << std::endl;
  } else {
    std::cout << "BOOK not found." << std::endl;
  }
  getchar();  // Ignore enter
  return;
}
