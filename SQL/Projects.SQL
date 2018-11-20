/*
Projects
https://www.hackerrank.com/challenges/projects

Sample Output

2015-10-28 2015-10-29
2015-10-30 2015-10-31
2015-10-13 2015-10-15
2015-10-01 2015-10-04
*/
with ProjectsOrdered as (
	select 
		Start_Date,
		End_Date,
		row_number() over (order by End_Date) as ProjectOrder -- just in case projects are not ordered by Task_ID 
	from Projects
)
select 
	P1.Start_Date, 
	P2.End_Date
from 
	ProjectsOrdered P1 cross join
	ProjectsOrdered P2 
where
	P1.Start_Date < P2.End_Date and
	not exists 	(
		select * from ProjectsOrdered P3
		where 
			dateadd(dd, -P3.ProjectOrder, P3.End_Date) != dateadd(dd, -P1.ProjectOrder, P1.End_Date)
			and P3.ProjectOrder between P1.ProjectOrder and P2.ProjectOrder
	) and
	P1.Start_Date not in (select End_Date from Projects) and 
	P2.End_Date not in (select Start_Date from Projects)
order by datediff(dd, P1.Start_Date, P2.End_Date), P1.Start_Date;
