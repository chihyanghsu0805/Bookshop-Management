// Copyright [year] <Copyright Owner>"  [legal/copyright]

#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>

#include "./database.h"

namespace member {

void menu(database::Database*);
void update_menu(database::Database*);
void print(MYSQL_ROW);
const char table_name[] = "member";
std::string prompt_add();

}  // namespace member
#endif  // MEMBER_H_
