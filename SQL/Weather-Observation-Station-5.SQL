/*
Weather Observation Station 5
https://www.hackerrank.com/challenges/weather-observation-station-5
*/
select top 1 CITY, len(CITY) from STATION order by 2, 1;
select top 1 CITY, len(CITY) from STATION order by 2 DESC, 1;
