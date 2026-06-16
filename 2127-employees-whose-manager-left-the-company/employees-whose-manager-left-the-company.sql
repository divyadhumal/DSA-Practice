-- Write your PostgreSQL query statement below
select employee_id from Employees 
where salary <30000 and manager_id NOT IN(select employee_id from Employees)
Order by employee_id;