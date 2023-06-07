.read data.sql


CREATE TABLE bluedog AS
  SELECT color, pet FROM students WHERE pet = 'dog' and color = 'blue';

CREATE TABLE bluedog_songs AS
  SELECT color, pet, song FROM students WHERE pet = 'dog' and color = 'blue';


CREATE TABLE smallest_int_having AS
  SELECT time,smallest FROM students group by smallest having count(*)=1;


CREATE TABLE matchmaker AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";


CREATE TABLE sevens AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";


CREATE TABLE average_prices AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";


CREATE TABLE lowest_prices AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";


CREATE TABLE shopping_list AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";


CREATE TABLE total_bandwidth AS
  SELECT "REPLACE THIS LINE WITH YOUR SOLUTION";
