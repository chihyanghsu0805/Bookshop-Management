// Copyright [year] <Copyright Owner>
#ifndef CONSTANTS_H_
#define CONSTANTS_H_

// For a static/global string constant
// use a C style string instead: "static const char host[]".
// https://www.geeksforgeeks.org/char-vs-stdstring-vs-char-c/

namespace connection_constants {
static const char host[] = "localhost";
static const char user[] = "root";
static const char password[] = "0000";
static const char database[] = "bookshop_management";
static const int port = 3306;
};  // namespace connection_constants

namespace personnel_constants {
static const int staff = 2222;
static const int manager = 1111;
static const int owner = 0000;
};  // namespace personnel_constants

#endif  // CONSTANTS_H_
