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

| Field | Type | Null | Key | Default | Extra |
| --- | --- | --- | --- | --- | --- |
| id | int | NO | PRI | NULL | auto_increment |
| name | varchar(255) | NO | | name | |
| author | varchar(255) | NO | | author | |
| price | int | NO | | 0 | |
| quantity | int | NO | | 0 | |

- Supplier

| Field | Type | Null | Key | Default | Extra |
| --- | --- | --- | --- | --- | --- |
| id | int | NO | PRI | NULL | auto_increment |
| name | varchar(255) | NO | | name | |
| phone | varchar(255) | NO | | phone | |
| address | varchar(255) | NO | | address | |

- Employee

| Field | Type | Null | Key | Default | Extra |
| --- | --- | --- | --- | --- | --- |
| id | int | NO | PRI | NULL | auto_increment |
| name | varchar(255) | NO | | phone | |
| phone | varchar(255) | NO | | phone | |
| address | varchar(255) | NO | | address | |
| join_date | date | NO | | 1900-01-01 | |
| end_date | date | NO | | 1900-01-01 | |
| salary | int | NO | | 0 | |
| manager | tinyint(1)  | NO | | false | |

- Member

| Field | Type | Null | Key | Default | Extra |
| --- | --- | --- | --- | --- | --- |
| id | int | NO | PRI | NULL | auto_increment |
| name | varchar(255) | NO | | name | |
| phone | varchar(255) | NO | | phone | |
| address | varchar(255) | NO | | address | |
| join_date | date | NO | | 1900-01-01 | |
| end_date | date | NO | | 1900-01-01 | |

## Notes

* [C++ Notes](./CPP.md)
* [SQL Commands](./SQL.md)
