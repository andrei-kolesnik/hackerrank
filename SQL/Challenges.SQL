/*
Challenges
https://www.hackerrank.com/challenges/challenges
*/
select 
	H.hacker_id, 
	H.name, 
	count(*)
from 
	Hackers H 
	join Challenges C on H.hacker_id = C.hacker_id
group by 
	H.hacker_id, H.name 
having count(*) = (
	select max(cnt) from 
	(select count(*) as cnt
	from Hackers H join Challenges C on H.hacker_id = C.hacker_id
	group by H.hacker_id) Totals
)
or count(*) in
(
	select cnt2 from
	(select count(*) as cnt2
	from Hackers H join Challenges C on H.hacker_id = C.hacker_id
	group by H.hacker_id) Totals2
	group by cnt2
	having count(*) = 1
)
order by 3 desc, 1;
