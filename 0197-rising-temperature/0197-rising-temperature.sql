# Write your MySQL query statement below
select t1.id from weather as t1, weather as t2 where DATEDIFF(t1.recordDate , t2.recordDate)=1 and t1.temperature > t2.temperature