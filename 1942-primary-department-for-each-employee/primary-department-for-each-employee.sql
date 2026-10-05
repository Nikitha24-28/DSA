# Write your MySQL query statement below
select employee_id,department_id from employee e where primary_flag="Y" or
(select count(*) from employee e2 where e.employee_id=e2.employee_id)=1;
