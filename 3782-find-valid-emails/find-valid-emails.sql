# Write your MySQL query statement below
select user_id,email from users where email REGEXP '^[a-z0-9_]+@[^@0-9]+\\.com$'
order by user_id;