/*
Ollivander's Inventory
https://www.hackerrank.com/challenges/harry-potter-and-wands
*/

select W.id, WP.age, W.coins_needed, W.power
from Wands W
join Wands_Property WP on W.code = WP.code
where WP.is_evil = 0
and W.coins_needed = (select min(coins_needed) from Wands W2 where W2.code = W.code and W2.power = W.power)
order by W.power desc, WP.age desc
