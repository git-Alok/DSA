-- Write your PostgreSQL query statement below
WITH T AS (
    SELECT num, COUNT(num) AS count_num FROM MyNumbers
    GROUP BY num HAVING COUNT(num) =1
)
SELECT MAX(num) AS num FROM T ;
