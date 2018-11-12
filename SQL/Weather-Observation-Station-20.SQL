/*
Weather Observation Station 20
https://www.hackerrank.com/challenges/weather-observation-station-20
*/

declare @CNT int, @CNT1 int, @CNT2 int;
declare @LAT_N_TOP decimal (14, 4), @LAT_N_BOT decimal (14, 4);
select @CNT = count(*) from STATION;
select @CNT1 = iif(@CNT % 2 = 0, @CNT / 2, @CNT / 2 + 1);
select @CNT2 = iif(@CNT % 2 = 0, @CNT1 + 1, @CNT1);
select @LAT_N_BOT = max(LAT_N) from (select TOP(@CNT1) LAT_N from STATION order by LAT_N) B;
select @LAT_N_TOP = max(LAT_N) from (select TOP(@CNT2) LAT_N from STATION order by LAT_N) T;
select cast((@LAT_N_BOT + @LAT_N_TOP) / 2 as decimal (14, 4));