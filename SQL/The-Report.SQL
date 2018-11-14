/*
The Report
https://www.hackerrank.com/challenges/the-report
*/

select 
    case when G.Grade >= 8 then S.Name else 'NULL' end, 
    G.Grade, 
    S.Marks
from Students S 
    JOIN Grades G 
        ON S.Marks >= G.Min_Mark and S.Marks <= Max_Mark
order by 2 desc, 1, 3;
