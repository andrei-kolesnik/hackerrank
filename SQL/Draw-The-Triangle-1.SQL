/*
Draw The Triangle 1
https://www.hackerrank.com/challenges/draw-the-triangle-1
*/
-- Version 1: while loop
declare @counter int;
set @counter = 20
while @counter > 0
begin
	select replicate('* ', @counter)
	set @counter = @counter - 1
end

-- Version 2: Common Table Expressions (CTE's)
with cte as
(select 1 i union all
 select i+1 i from cte where i < 20)
select REPLICATE('* ', i) from cte
order by i desc
