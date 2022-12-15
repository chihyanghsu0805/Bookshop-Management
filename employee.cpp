// Copyright [year] <Copyright Owner>

#include "./employee.h"

#include <iostream>
#include <sstream>

#include "./database.h"

enum EmployeeMenuOptions {
  view = 1,
  add,
  search,
  update,
  returnToMain,
};

enum EmployeeUpdateMenuOptions {
  name = 1,
  address,
  phone,
  join_date,
  end_date,
  salary,
  manager,
  returnToEmployee,
};

void employee::print(MYSQL_ROW row) {
  std::cout << employee::table_name << " ID:" << row[0] << std::endl;
  std::cout << employee::table_name << " NAME: " << row[1] << std::endl;
  std::cout << employee::table_name << " ADDRESS: " << row[2] << std::endl;
  std::cout << employee::table_name << " PHONE: " << row[3] << std::endl;
  std::cout << employee::table_name << " JOIN DATE: " << row[4] << std::endl;
  std::cout << employee::table_name << " END DATE: " << row[5] << std::endl;
  std::cout << employee::table_name << " SALARY: " << row[6] << std::endl;
  std::cout << employee::table_name << " MANAGER: " << row[7] << std::endl;
  std::cout << std::endl;
}

void employee::update_menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " UPDATE EMPLOYEES" << std::endl;
    std::cout << " 1. Name" << std::endl;
    std::cout << " 2. Address" << std::endl;
    std::cout << " 3. Phone" << std::endl;
    std::cout << " 4. Join Date" << std::endl;
    std::cout << " 5. End Date" << std::endl;
    std::cout << " 6. Salary" << std::endl;
    std::cout << " 7. Manager" << std::endl;
    std::cout << " 8. Return to Employee Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;
    std::string column = "";
    std::string type = "";
    switch (c) {
      case EmployeeUpdateMenuOptions::name:
        db->update(employee::table_name, "name", "string");
        break;
      case EmployeeUpdateMenuOptions::address:
        db->update(employee::table_name, "address", "string");
        break;
      case EmployeeUpdateMenuOptions::phone:
        db->update(employee::table_name, "phone", "string");
        break;
      case EmployeeUpdateMenuOptions::join_date:
        db->update(employee::table_name, "join_date", "string");
        break;
      case EmployeeUpdateMenuOptions::end_date:
        db->update(employee::table_name, "end_date", "string");
        break;
      case EmployeeUpdateMenuOptions::salary:
        db->update(employee::table_name, "salary", "integer");
        break;
      case EmployeeUpdateMenuOptions::manager:
        db->update(employee::table_name, "manager", "boolean");
        break;
      case EmployeeUpdateMenuOptions::returnToEmployee:
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

void employee::menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " EMPLOYEES" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Search" << std::endl;
    std::cout << " 4. Update" << std::endl;
    std::cout << " 5. Return to Main Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;

    switch (c) {
      case EmployeeMenuOptions::view:
        db->view(employee::table_name);
        break;
      case EmployeeMenuOptions::add:
        db->add_employee();
        break;
      case EmployeeMenuOptions::search:
        db->search(employee::table_name);
        break;
      case EmployeeMenuOptions::update:
        employee::update_menu(db);
        break;
      case EmployeeMenuOptions::returnToMain:
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
