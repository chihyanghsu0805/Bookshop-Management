// Copyright [year] <Copyright Owner>"  [legal/copyright]

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "./database.h"

namespace employee {

void menu(database::Database*);
void update_menu(database::Database*);
void print(MYSQL_ROW);
const char table_name[] = "employee";

}  // namespace employee
#endif  // EMPLOYEE_H_
