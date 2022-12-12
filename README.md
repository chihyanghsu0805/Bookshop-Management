# Bookshop-Management

Manage various bookshop objects in a MySQL database.

## Database Design

- Book

| Field | Type | Null | Key | Default | Extra |
| --- | --- | --- | --- | --- | --- |
| id | int | NO | PRI | NULL | auto_increment |
| name | varchar(255) | YES | | NULL | |
| author | varchar(255) | YES | | NULL | |
| price | int | YES | | NULL | |
| quantity | int | YES | | NULL | |

- Supplier

| Field | Type | Null | Key | Default | Extra |
| --- | --- | --- | --- | --- | --- |
| id | int | NO | PRI | NULL | auto_increment |
| name | varchar(255) | YES | | NULL | |
| phone | varchar(255) | YES | | NULL | |
| address | varchar(255) | YES | | NULL | |



* [SQL Commands](./SQL.md)
