// Copyright [year] <Copyright Owner>"  [legal/copyright]
// For a static/global string constant, use a C style string instead.
#ifndef BOOK_H_
#define BOOK_H_

#include "./database.h"

namespace book {

void menu(database::Database*);
void update_menu(database::Database*);
const char table_name[] = "book";

}  // namespace book
#endif  // BOOK_H_
