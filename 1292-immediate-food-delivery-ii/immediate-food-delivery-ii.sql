-- Write your PostgreSQL query statement below

WITH dub AS (SELECT customer_id, MIN(order_date) AS o_d, MIN(customer_pref_delivery_date) AS p_d FROM Delivery GROUP BY customer_id) 
SELECT ROUND(AVG(CASE WHEN o_d = p_d THEN 1 ELSE 0 END)::NUMERIC * 100,2) AS immediate_percentage FROM dub;