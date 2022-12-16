// Copyright [year] <Copyright Owner>"  [legal/copyright]
#ifndef PERSONNEL_H_
#define PERSONNEL_H_

#include <string>

#include "./database.h"

namespace identification {

class Personnel {
  virtual void manage_book(database::Database*);
  virtual void manage_supplier(database::Database*);
  virtual void manage_employee(database::Database*);

 public:
  void manage_bookshop();
};

class Owner : public Personnel {
  // void manage_book(database::Database*);
  // void manage_supplier(database::Database*);
  // void manage_employee(database::Database*);
};

class Manager : public Personnel {
  // void manage_books(database::Database*);
  // void manage_supplier(database::Database*);
  void manage_employee(database::Database*);
};

class Staff : public Personnel {
  // void manage_book(database::Database*);
  void manage_supplier(database::Database*);
  void manage_employee(database::Database*);
};

}  // namespace identification
#endif  // PERSONNEL_H_
