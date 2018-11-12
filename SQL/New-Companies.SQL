/*
New Companies
https://www.hackerrank.com/challenges/the-company
*/

select 
    C.company_code, 
    min(C.founder), 
    count(DISTINCT LM.lead_manager_code),
    count(DISTINCT SM.senior_manager_code),
    count(DISTINCT M.manager_code),
    count(DISTINCT E.employee_code)
from Company C
join Lead_Manager LM on LM.company_code = C.company_code 
join Senior_Manager SM on SM.lead_manager_code = LM.lead_manager_code
join Manager M on M.senior_manager_code = SM.senior_manager_code
join Employee E on E.manager_code = M.manager_code
group by C.company_code
order by company_code;
