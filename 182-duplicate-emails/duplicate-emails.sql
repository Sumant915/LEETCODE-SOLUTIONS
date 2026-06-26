# Write your MySQL query statement below
with cte as(
select email,count(email) from Person 
group by email having count(email)>1)
select email from cte ;