```
SHOW DATABASES;
DROP DATABASE database;
CREATE DATABASE database;
USE database;

SELECT * from table;
SELECT * FROM table WHERE id = x;

DESC table;
DROP TABLE table;

CREATE TABLE IF NOT EXISTS table (
  id INT NOT NULL AUTO_INCREMENT, `PRIMARY KEY`
  name varchar(255) DEFAULT 'x',
  author varchar(255) DEFAULT 'x',
  price INT DEFAULT x,
  quantity INT DEFAULT x,
  PRIMARY KEY (id)
);

CREATE TABLE IF NOT exists table (
  id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
  foreign_id INT,
  FOREIGN KEY (book_id) REFERENCES book(id),
)

ALTER TABLE table_name ADD column_name datatype;
ALTER TABLE table_name MODIFY column_name column_type AFTER address;
ALTER TABLE table_name MODIFY column_name column_type DEFAULT default;
ALTER TABLE table_name CHANGE old_name new_name datatype;

INSERT INTO table (args) VALUES('strings', int);
UPDATE table SET column = int [WHERE condition];
UPDATE table SET column = 'string' [WHERE condition];
UPDATE table SET column = column+integerValueToAdd [WHERE condition];
DELETE FROM table [WHERE condition];

CREATE ROLE 'role1', 'role2';
GRANT ALL ON database.* TO role;
CREATE USER 'user'@'localhost' IDENTIFIED BY 'password';
GRANT role TO 'user'@'localhost';
```
