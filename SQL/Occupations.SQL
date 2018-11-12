/*
Occupations
https://www.hackerrank.com/challenges/occupations
*/

select [Doctor], [Professor], [Singer], [Actor] from
(select 
    NAME, 
    OCCUPATION,
    rank() over (partition by OCCUPATION order by NAME asc) as RANK
from OCCUPATIONS) as RANKED_OCCUPATIONS
pivot 
(max(NAME) for OCCUPATION in ([Doctor], [Professor], [Singer], [Actor])) as PIVOT_OCCUPATIONS;
