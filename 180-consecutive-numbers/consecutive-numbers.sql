-- Write your PostgreSQL query statement below
WITH T AS (
SELECT id, num, LEAD(num,1) OVER() AS sec, LEAD(num,2) OVER() AS thr FROM Logs
)
SELECT DISTINCT num AS ConsecutiveNums FROM T WHERE num = sec AND sec = thr;
