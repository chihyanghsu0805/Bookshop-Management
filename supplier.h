// Copyright [year] <Copyright Owner>

#ifndef SUPPLIER_H_
#define SUPPLIER_H_

#include <string>

#include "./database.h"

namespace supplier {

void menu(database::Database*);
void update_menu(database::Database*);
void print(MYSQL_ROW);
const char table_name[] = "supplier";
std::string prompt_add();

}  // namespace supplier
#endif  // SUPPLIER_H_
