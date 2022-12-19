// Copyright [year] <Copyright Owner>"  [legal/copyright]

#include <iostream>

#include "./book.h"
#include "./constants.h"
#include "./database.h"
#include "./employee.h"
#include "./personnel.h"
#include "./supplier.h"

std::string prompt_password() {
  std::string user;
  int password;

  std::cout << "Password: ";
  std::cin >> password;

  if (password == personnel_constants::staff) {
    user = "staff";
  } else if (password == personnel_constants::manager) {
    user = "manager";
  } else if (password == personnel_constants::owner) {
    user = "owner";
  }

  return user;
}

int main() {
  system("cls");
  // Login
  std::string user = prompt_password();

  if (user.empty()) return 0;

  std::cout << "Login Successful." << std::endl;
  getchar();

  if (user == "staff") {
    identification::Staff* p = new identification::Staff();
    p->manage_bookshop();
  }

  if (user == "manager") {
    identification::Manager* p = new identification::Manager();
    p->manage_bookshop();
  }

  if (user == "owner") {
    identification::Owner* p = new identification::Owner();
    p->manage_bookshop();
  }

  system("cls");
  return 0;
}
