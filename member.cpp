// Copyright [year] <Copyright Owner>

#include "./member.h"

#include <iostream>
#include <sstream>

#include "./database.h"

enum MemberMenuOptions {
  view = 1,
  add,
  search,
  update,
  returnToMain,
};

enum MemberUpdateMenuOptions {
  name = 1,
  address,
  phone,
  join_date,
  end_date,
  returnToMember,
};

void member::print(MYSQL_ROW row) {
  std::cout << member::table_name << " ID:" << row[0] << std::endl;
  std::cout << member::table_name << " NAME: " << row[1] << std::endl;
  std::cout << member::table_name << " ADDRESS: " << row[2] << std::endl;
  std::cout << member::table_name << " PHONE: " << row[3] << std::endl;
  std::cout << member::table_name << " JOIN DATE: " << row[4] << std::endl;
  std::cout << member::table_name << " END DATE: " << row[5] << std::endl;
  std::cout << std::endl;
}

std::string member::prompt_add() {
  std::string name;
  std::string address;
  std::string phone;
  std::string join_date;
  std::string salary;

  std::cout << "Enter the " + std::string(member::table_name) + " NAME: ";
  std::cin >> name;

  std::cout << "Enter the " + std::string(member::table_name) + " ADDRESS: ";
  std::cin >> address;

  std::cout << "Enter the " + std::string(member::table_name) + " PHONE: ";
  std::cin >> phone;

  std::cout << "Enter the " + std::string(member::table_name) +
                   " JOIN DATE (YYYY-MM-DD): ";
  std::cin >> join_date;

  std::stringstream statement("");
  statement << "INSERT INTO " + std::string(member::table_name) +
                   "(NAME, ADDRESS, PHONE, JOIN_DATE) VALUES("
            << "'" << name << "'"
            << ","
            << "'" << address << "'"
            << ","
            << "'" << phone << "'"
            << ","
            << "'" << join_date << "'"
            << ");";
  return statement.str();
}

void member::update_menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " UPDATE MEMBERS" << std::endl;
    std::cout << " 1. Name" << std::endl;
    std::cout << " 2. Address" << std::endl;
    std::cout << " 3. Phone" << std::endl;
    std::cout << " 4. Join Date" << std::endl;
    std::cout << " 5. End Date" << std::endl;
    std::cout << " 6. Return to Member Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;
    std::string column = "";
    std::string type = "";
    switch (c) {
      case MemberUpdateMenuOptions::name:
        db->update(member::table_name, "name", "string");
        break;
      case MemberUpdateMenuOptions::address:
        db->update(member::table_name, "address", "string");
        break;
      case MemberUpdateMenuOptions::phone:
        db->update(member::table_name, "phone", "string");
        break;
      case MemberUpdateMenuOptions::join_date:
        db->update(member::table_name, "join_date", "string");
        break;
      case MemberUpdateMenuOptions::end_date:
        db->update(member::table_name, "end_date", "string");
        break;
      case MemberUpdateMenuOptions::returnToMember:
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

void member::menu(database::Database* db) {
  int c;

  while (true) {
    system("cls");
    std::cout << " MEMBERS" << std::endl;
    std::cout << " 1. View" << std::endl;
    std::cout << " 2. Add" << std::endl;
    std::cout << " 3. Search" << std::endl;
    std::cout << " 4. Update" << std::endl;
    std::cout << " 5. Return to Main Menu" << std::endl;
    std::cout << "Enter Choice: ";

    std::cin >> c;

    switch (c) {
      case MemberMenuOptions::view:
        db->view(member::table_name);
        break;
      case MemberMenuOptions::add:
        db->add_member();
        break;
      case MemberMenuOptions::search:
        db->search(member::table_name);
        break;
      case MemberMenuOptions::update:
        member::update_menu(db);
        break;
      case MemberMenuOptions::returnToMain:
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
