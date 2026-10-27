-- Write your PostgreSQL query statement below
SELECT w_b.id 
FROM  Weather w
JOIN Weather w_b
ON w.recordDate+1 = w_b.recordDate
WHERE w_b.temperature> w.temperature;