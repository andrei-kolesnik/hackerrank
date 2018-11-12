/*
Weather Observation Station 19
https://www.hackerrank.com/challenges/weather-observation-station-19
*/

select cast
    (
     sqrt(
      square(max(LAT_N)  - min(LAT_N)) + 
      square(max(LONG_W) - min(LONG_W))
    ) 
    as decimal(14, 4))
from STATION;
