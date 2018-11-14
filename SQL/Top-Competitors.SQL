/*
Top Competitors
https://www.hackerrank.com/challenges/full-score
*/
select H.hacker_id, H.name
from 
Submissions S
join Hackers H on S.hacker_id = H.hacker_id
join Challenges C on S.challenge_id = C.challenge_id
join Difficulty D on C.difficulty_level = D.difficulty_level
where D.score = S.score
group by H.hacker_id, H.name
having count(*) > 1
order by count(*) desc, 1