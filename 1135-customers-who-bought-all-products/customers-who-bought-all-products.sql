-- Write your PostgreSQL query statement below
WITH T AS (
    SELECT 
    customer_id, COUNT(DISTINCT product_key) AS p_k
    FROM Customer 
    GROUP BY customer_id
)
SELECT customer_id 
FROM T 
WHERE 
p_k = (SELECT COUNT(*) FROM Product);