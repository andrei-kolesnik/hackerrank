/*
Contest Leaderboard
https://www.hackerrank.com/challenges/contest-leaderboard
*/
select 
    MS.hacker_id, 
    H.name, 
    sum(MS.max_score)
from
(
    select 
        hacker_id,
        max(score) as max_score
    from 
        Submissions
    group by
        hacker_id, challenge_id
    having 
        max(score) > 0
) MS
    join Hackers H on MS.hacker_id = H.hacker_id
group by
    MS.hacker_id, 
    H.name
order by
    3 desc, 1;
