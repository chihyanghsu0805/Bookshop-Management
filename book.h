// Copyright [year] <Copyright Owner>"  [legal/copyright]

#ifndef BOOK_H_
#define BOOK_H_

#include <string>

#include "./database.h"

namespace book {

void menu(database::Database*);
void update_menu(database::Database*);
void print(MYSQL_ROW);
const char table_name[] = "book";
std::string prompt_add();

}  // namespace book
#endif  // BOOK_H_
