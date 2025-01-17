# Write your MySQL query statement below
select name , bonus from Employee left join bonus on employee.empId = bonus.empId where bonus<1000 or bonus is null