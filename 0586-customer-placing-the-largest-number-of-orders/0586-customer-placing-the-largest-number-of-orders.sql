# Write your MySQL query statement below
select customer_number from Orders
group by customer_number 
-- having count(customer_number)>1
ORDER BY COUNT(*) DESC 
limit 1