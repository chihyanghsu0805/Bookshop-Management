// Copyright [year] <Copyright Owner>

#include "./database.h"

#include <mysql.h>

#include <iostream>
#include <sstream>

#include "./book.h"
#include "./employee.h"
#include "./member.h"
#include "./purchase.h"
#include "./sales.h"
#include "./supplier.h"

bool database::Database::connect(const std::string host, const std::string user,
                                 const std::string password,
                                 const std::string database, const int port) {
  connection = mysql_init(NULL);
  if (!connection)
    std::cout << "MySQL initialization failed." << std::endl;
  else
    std::cout << "MySQL initialized." << std::endl;

  connection = mysql_real_connect(connection, host.c_str(), user.c_str(),
                                  password.c_str(), database.c_str(), port,
                                  NULL, CLIENT_MULTI_STATEMENTS);

  if (!connection)
    std::cout << "Connection Error." << std::endl;
  else
    std::cout << "Connected." << std::endl;

  getchar();
  return connection != NULL;
}

// Generic
void database::Database::view(std::string table_name) {
  system("cls");

  std::stringstream statement("");
  statement << "SELECT * FROM " + table_name + ";";

  mysql_query(connection, statement.str().c_str());
  result_set = mysql_use_result(connection);

  // Need to count 40 rows and getchar() for more
  while ((row = mysql_fetch_row(result_set)) != NULL) {
    print_row(row, table_name);
  }
  getchar();
  return;
}

void database::Database::print_row(MYSQL_ROW row, std::string table_name) {
  if (table_name == book::table_name) book::print(row);
  if (table_name == supplier::table_name) supplier::print(row);
  if (table_name == employee::table_name) employee::print(row);
  if (table_name == member::table_name) member::print(row);
  if (table_name == purchase::table_name) purchase::print(row);
  if (table_name == sales::table_name) sales::print(row);
  return;
}

void database::Database::search(std::string table_name) {
  system("cls");

  int id;

  std::cout << "Enter " + table_name + " ID to SEARCH: ";
  std::cin >> id;

  search_id(table_name, id);
  getchar();
  return;
}

bool database::Database::search_id(std::string table_name, int id) {
  std::stringstream statement("");
  statement << "SELECT * FROM " + table_name + " WHERE id = " << id << ";";

  mysql_query(connection, statement.str().c_str());
  result_set = mysql_store_result(connection);

  bool found;

  if ((row = mysql_fetch_row(result_set)) != NULL) {
    found = true;
    print_row(row, table_name);
  } else {
    std::cout << table_name + " not found." << std::endl;
    found = false;
  }
  return found;
}

void database::Database::update(std::string table_name, std::string column,
                                std::string entry_type) {
  system("cls");

  int id;
  char c;

  std::cout << "Enter " + table_name + " ID to UPDATE: ";
  std::cin >> id;
  if (search_id(table_name, id)) {
    std::cout << "Do you want to UPDATE the " + table_name + " " + column +
                     "? [Y/N]: ";
    std::cin >> c;

    if (c == 121 || c == 89) {
      std::string value;
      std::cout << "Enter the new " + table_name + " " + column + ": ";
      std::cin >> value;

      std::stringstream statement("");

      // Concatenate char[] with string
      // Convert string to integer
      if (entry_type == "integer")
        statement << "UPDATE " + table_name + " SET " + column + " = "
                  << std::stoi(value) << " WHERE id = " << id << ";";

      // Add single quotes for string
      if (entry_type == "string")
        statement << "UPDATE " + table_name + " SET " + column + " = "
                  << "'" << value << "'"
                  << " WHERE id = " << id << ";";

      if (entry_type == "boolean")
        statement << "UPDATE " + table_name + " SET " + column + " = " << value
                  << " WHERE id = " << id << ";";

      mysql_query(connection, statement.str().c_str());
      result_set = mysql_store_result(connection);

      search_id(table_name, id);
      check_update(table_name, column);

    } else {
      std::cout << table_name + " " + column + " not UPDATED.";
    }
  }
  getchar();
  return;
}

void database::Database::remove(std::string table_name) {
  system("cls");

  int id;
  char c;

  std::cout << "Enter " + table_name + " ID to REMOVE: ";
  std::cin >> id;
  if (search_id(table_name, id)) {
    std::cout << "Do you want to REMOVE " + table_name + " " +
                     std::to_string(id) + "? [Y/N]: ";
    std::cin >> c;

    if (c == 121 || c == 89) {
      std::stringstream statement("");

      statement << "DELETE FROM " + table_name + " WHERE id = " << id << ";";
      mysql_query(connection, statement.str().c_str());
      result_set = mysql_store_result(connection);

      // Dont reset id due to other references
      check_remove(table_name);

    } else {
      std::cout << table_name + " not REMOVED.";
    }
  }
  getchar();  // Ignore enter
  return;
}

bool database::Database::check_errors() {
  bool errors = false;
  if (!std::string(mysql_error(connection)).empty()) {
    std::cout << "MySQL Error:" << std::endl;
    std::cout << mysql_error(connection) << std::endl;
    errors = true;
  } else if (mysql_errno(connection) != 0) {
    std::cout << "MySQL Error Number:" << std::endl;
    std::cout << mysql_errno(connection) << std::endl;
    errors = true;
  } else if (mysql_field_count(connection) != 0) {
    std::cout << "MySQL Field Count:" << std::endl;
    std::cout << mysql_field_count(connection) << std::endl;
    errors = true;
  }
  return errors;
}

void database::Database::check_insert() {
  if (result_set == NULL) {  // Insert successful returns NULL
    std::cout << "Entry added." << std::endl;
  } else if (!check_errors()) {
    std::cout << "Entry added?" << std::endl;
  }
}

void database::Database::check_update(std::string table_name,
                                      std::string column) {
  if (result_set != NULL) {  // Update successfuly returns pointer
    std::cout << table_name + " " + column + " UPDATED." << std::endl;
  } else if (!check_errors()) {
    std::cout << table_name + " " + column + " UPDATED?" << std::endl;
  }
}

void database::Database::check_remove(std::string table_name) {
  if (result_set != NULL) {  // Update successfuly returns pointer
    std::cout << table_name + " REMOVED." << std::endl;
  } else if (!check_errors()) {
    std::cout << table_name + " REMOVED?" << std::endl;
  }
}

// Book
void database::Database::add_book() {
  system("cls");

  std::string s = book::prompt_add();
  mysql_query(connection, s.c_str());
  result_set = mysql_store_result(connection);

  check_insert();

  getchar();
  return;
}

// Supplier
void database::Database::add_supplier() {
  system("cls");

  std::string s = supplier::prompt_add();
  mysql_query(connection, s.c_str());
  result_set = mysql_store_result(connection);

  check_insert();

  getchar();
  return;
}

// Employee
void database::Database::add_employee() {
  system("cls");

  std::string s = employee::prompt_add();
  mysql_query(connection, s.c_str());
  result_set = mysql_store_result(connection);

  check_insert();

  getchar();
  return;
}

// Member
void database::Database::add_member() {
  system("cls");

  std::string s = member::prompt_add();
  mysql_query(connection, s.c_str());
  result_set = mysql_store_result(connection);

  check_insert();

  getchar();
  return;
}
void database::Database::update_valid() {
  std::stringstream statement("");
  statement << "UPDATE " + std::string(member::table_name) +
                   " SET valid = false WHERE end_date <= curdate();";
  mysql_query(connection, statement.str().c_str());
  result_set = mysql_store_result(connection);
  check_update(member::table_name, "valid");
  return;
}

// Purchase
void database::Database::add_purchase() {
  system("cls");

  std::string s = purchase::prompt_add();

  mysql_query(connection, s.c_str());
  result_set = mysql_store_result(connection);

  check_insert();

  getchar();
  return;
}

void database::Database::update_inventory() {
  int book_id;
  int quantity;

  std::stringstream purchase_statement("");
  purchase_statement << "SELECT book_id, quantity FROM " +
                            std::string(purchase::table_name) +
                            " WHERE RECEIVED = 'T' AND INVENTORY = 0;";

  mysql_query(connection, purchase_statement.str().c_str());
  result_set = mysql_use_result(connection);

  std::stringstream book_statement("");

  while ((row = mysql_fetch_row(result_set)) != NULL) {
    book_id = atoi(row[0]);
    quantity = atoi(row[1]);

    book_statement << "UPDATE " + std::string(book::table_name) +
                          " SET QUANTITY = QUANTITY+"
                   << quantity << " WHERE id = " << book_id << ";";
  }

  mysql_query(connection, book_statement.str().c_str());
  result_set = mysql_store_result(connection);

  check_update(book::table_name, "quantity");

  std::stringstream update_statement("");
  update_statement
      << "UPDATE " + std::string(purchase::table_name) +
             " SET INVENTORY = 1 WHERE RECEIVED = 'T' AND INVENTORY = 0;";

  mysql_query(connection, update_statement.str().c_str());
  result_set = mysql_store_result(connection);

  check_update(purchase::table_name, "inventory");
}

// Sales
void database::Database::add_sales() {
  system("cls");

  int book_id;
  int member_id;
  int quantity;
  int bill;
  int stock;
  int price;

  std::cout << "Enter the " + std::string(book::table_name) + " ID: ";
  std::cin >> book_id;

  if (!search_id(book::table_name, book_id)) {
    std::cout << "Book not found." << std::endl;
    getchar();
    return;
  }

  std::cout << "Enter the " + std::string(member::table_name) + " ID: ";
  std::cin >> member_id;

  if (!search_id(member::table_name, member_id)) {
    std::cout << "Member not found." << std::endl;
    getchar();
    return;
  }

  // Check valid member

  std::cout << "Enter the " + std::string(sales::table_name) + " QUANTITY: ";
  std::cin >> quantity;

  std::stringstream statement("");
  statement << "SELECT QUANTITY, PRICE FROM " + std::string(book::table_name) +
                   " WHERE id = "
            << book_id << ";";

  mysql_query(connection, statement.str().c_str());
  result_set = mysql_store_result(connection);

  if ((row = mysql_fetch_row(result_set)) != NULL) {
    stock = atoi(row[0]);
    price = atoi(row[1]);

    if (stock < quantity) {
      std::cout << "Not enough stock." << std::endl;
      getchar();
    } else {
      bill = quantity * price;

      std::stringstream sales_statement("");
      sales_statement
          << "INSERT INTO " + std::string(sales::table_name) +
                 " (member_id, book_id, quantity, bill, date) VALUES ("
          << member_id << "," << book_id << "," << quantity << "," << bill
          << ","
          << "curdate());";
      mysql_query(connection, sales_statement.str().c_str());
      result_set = mysql_store_result(connection);

      check_insert();

      std::stringstream book_statement("");
      book_statement << "UPDATE " + std::string(book::table_name) +
                            " SET QUANTITY = QUANTITY-"
                     << quantity << " WHERE id = " << book_id << ";";
      mysql_query(connection, book_statement.str().c_str());
      result_set = mysql_store_result(connection);

      check_update(book::table_name, "quantity");
    }
  }

  getchar();
  return;
}

void database::Database::summarize_sales() {
  int year_sale = 0;

  std::stringstream statement("");
  statement << "SELECT bill FROM " + std::string(sales::table_name) +
                   " WHERE year(date) = year(curdate());";
  mysql_query(connection, statement.str().c_str());
  result_set = mysql_use_result(connection);

  while ((row = mysql_fetch_row(result_set)) != NULL) {
    year_sale += atoi(row[0]);
  }

  std::cout << "Sales this year: " << year_sale << std::endl;

  getchar();
  return;
}
