# Bookshop-Management

Manage various bookshop objects in a MySQL database.

This work is inspired by the following:
-   https://www.interviewbit.com/blog/cpp-projects/
-   https://github.com/Aryan-Khanijo/Bookshop-Management-System-CPP-Project
-   https://www.codeguru.com/database/database-programming-with-c-c/

## Compile Command

g++ -o bookshop_management.exe ./*.cpp -I "C:/Program Files/MySQL/MySQL Server 8.0/include/" -L "C:/Program Files/MySQL/MySQL Server 8.0/lib/" -l libmysql

## Database Design

Columns can not be null for viewing.

- Book

| Field    | Type         | Null | Key | Default | Extra          |
|----------|--------------|------|-----|---------|----------------|
| id       | int          | NO   | PRI | NULL    | auto_increment |
| name     | varchar(255) | YES  |     | name    |                |
| author   | varchar(255) | YES  |     | author  |                |
| price    | int          | YES  |     | 0       |                |
| quantity | int          | YES  |     | 0       |                |

- Supplier

| Field   | Type         | Null | Key | Default | Extra          |
|---------|--------------|------|-----|---------|----------------|
| id      | int          | NO   | PRI | NULL    | auto_increment |
| name    | varchar(255) | YES  |     | name    |                |
| phone   | varchar(255) | YES  |     | phone   |                |
| address | varchar(255) | YES  |     | address |                |

- Employee

| Field     | Type         | Null | Key | Default    | Extra          |
|-----------|--------------|------|-----|------------|----------------|
| id        | int          | NO   | PRI | NULL       | auto_increment |
| name      | varchar(255) | YES  |     | name       |                |
| address   | varchar(255) | YES  |     | address    |                |
| phone     | varchar(255) | YES  |     | phone      |                |
| join_date | date         | YES  |     | 1900-01-01 |                |
| end_date  | date         | YES  |     | 1900-01-01 |                |
| salary    | int          | YES  |     | 0          |                |
| manager   | tinyint(1)   | YES  |     | 0          |                |

- Member

| Field     | Type         | Null | Key | Default    | Extra          |
|-----------|--------------|------|-----|------------|----------------|
| id        | int          | NO   | PRI | NULL       | auto_increment |
| name      | varchar(255) | YES  |     | name       |                |
| address   | varchar(255) | YES  |     | address    |                |
| phone     | varchar(255) | YES  |     | phone      |                |
| join_date | date         | YES  |     | 1900-01-01 |                |
| end_date  | date         | YES  |     | 2100-12-31 |                |
| valid     | tinyint(1)   | YES  |     | 1          |                |

- Purchase

| Field       | Type       | Null | Key | Default | Extra          |
|-------------|------------|------|-----|---------|----------------|
| id          | int        | NO   | PRI | NULL    | auto_increment |
| quantity    | int        | YES  |     | NULL    |                |
| order_date  | date       | YES  |     | NULL    |                |
| expect_date | date       | YES  |     | NULL    |                |
| received    | char(1)    | YES  |     | F       |                |
| book_id     | int        | YES  | MUL | NULL    |                |
| supplier_id | int        | YES  | MUL | NULL    |                |
| inventory   | tinyint(1) | YES  |     | 0       |                |

- Sales

| Field     | Type | Null | Key | Default | Extra          |
|-----------|------|------|-----|---------|----------------|
| id        | int  | NO   | PRI | NULL    | auto_increment |
| member_id | int  | YES  | MUL | NULL    |                |
| book_id   | int  | YES  | MUL | NULL    |                |
| quantity  | int  | YES  |     | NULL    |                |
| bill      | int  | YES  |     | NULL    |                |
| date      | date | YES  |     | NULL    |                |

## Notes

- [C++ Notes](./CPP.md)
- [SQL Commands](./SQL.md)
