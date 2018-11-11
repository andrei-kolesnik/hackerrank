/*
Weather Observation Station 4
https://www.hackerrank.com/challenges/weather-observation-station-4/problem
*/
select count(CITY) - count(distinct CITY) from STATION;
