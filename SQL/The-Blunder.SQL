/*
The Blunder
https://www.hackerrank.com/challenges/the-blunder
*/

select 
	cast(ceiling(
		avg(cast(SALARY as money)) - 
		avg(cast(replace(cast(SALARY as varchar(4)), '0', '') as money))
	) as int) from EMPLOYEES;
