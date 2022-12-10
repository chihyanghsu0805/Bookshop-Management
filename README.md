# Bookshop-Management

```
SHOW DATABASES;
DROP DATABASE database;
CREATE DATABASE database;
USE database;
SELECT * from table;

CREATE TABLE IF NOT EXISTS table (
  id INT NOT NULL AUTO_INCREMENT, `PRIMARY KEY`
  name varchar(255),
  author varchar(255),
  price INT,
  quantity INT,
  PRIMARY KEY (id)
);

CREATE TABLE table (
    id INT,
    foreign_id INT,
    INDEX par_ind (foreign_id,),
    FOREIGN KEY (foreign_id)
        REFERENCES foreign(id)
)
```
