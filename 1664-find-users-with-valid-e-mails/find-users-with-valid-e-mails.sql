-- Write your PostgreSQL query statement below
SELECT * FROM Users WHERE mail ~ '^[A-Za-z][a-zA-Z0-9._-]*@leetcode\.com$';