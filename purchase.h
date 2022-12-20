// Copyright [year] <Copyright Owner>"  [legal/copyright]

#ifndef PURCHASE_H_
#define PURCHASE_H_

#include <string>

#include "./database.h"

namespace purchase {

void menu(database::Database*);
void update_menu(database::Database*);
void print(MYSQL_ROW);
const char table_name[] = "purchase";
std::string prompt_add();

}  // namespace purchase
#endif  // PURCHASE_H_
