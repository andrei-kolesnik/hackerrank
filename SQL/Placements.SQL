/*
Placements
https://www.hackerrank.com/challenges/placements
*/
select 
	S.Name
from
	Students S
	join Packages PS on S.ID = PS.ID
	join Friends F on S.ID = F.ID
	join Packages FS on F.Friend_ID = FS.ID
where 
	PS.Salary < FS.Salary
order by 
	FS.Salary