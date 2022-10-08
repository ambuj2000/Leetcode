# Write your MySQL query statement below

select max(salary) AS SecondHighestSalary
from employee
where salary NOT IN (select max(salary) from Employee)
order by salary DESC
limit 1;

