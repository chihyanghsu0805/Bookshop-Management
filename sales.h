// Copyright [year] <Copyright Owner>"  [legal/copyright]

#ifndef SALES_H_
#define SALES_H_

#include <string>

#include "./database.h"

namespace sales {

void menu(database::Database*);
void update_menu(database::Database*);
void print(MYSQL_ROW);
const char table_name[] = "sales";

}  // namespace sales
#endif  // SALES_H_
