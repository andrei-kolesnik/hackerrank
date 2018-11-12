/*
Weather Observation Station 8
https://www.hackerrank.com/challenges/weather-observation-station-8
*/
select distinct CITY from STATION where 
	(CITY like 'a%' or CITY like 'e%' or CITY like 'i%' or CITY like 'o%' or CITY like 'u%') and
	(CITY like '%a' or CITY like '%e' or CITY like '%i' or CITY like '%o' or CITY like '%u');
