// Copyright [year] <Copyright Owner>
#ifndef SUPPLIER_H_
#define SUPPLIER_H_

#include "./database.h"

namespace supplier {

void menu(database::Database*);
void update_menu(database::Database*);
const char table_name[] = "supplier";

}  // namespace supplier
#endif  // SUPPLIER_H_
