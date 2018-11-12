/*
The PADS
https://www.hackerrank.com/challenges/the-pads
*/

select Name+'('+LEFT(Occupation, 1)+')' 
from OCCUPATIONS 
order by Name;

select 'There are a total of '+ cast(count(Occupation) as varchar(4)) + ' ' + 
		lower(Occupation) + 's.' 
from OCCUPATIONS 
group by Occupation 
order by count(Occupation);
