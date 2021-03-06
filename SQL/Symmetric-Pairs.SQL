/*
Symmetric Pairs
https://www.hackerrank.com/challenges/symmetric-pairs

Sample Output
20 20
20 21
22 23
*/
with FunctionsNumbered as
(
	select 
		X,
		Y,
		row_number() over (order by X, Y) as RN
	from Functions
)
select distinct 
	F1.X, 
	F1.Y
from 
	FunctionsNumbered F1 
	join FunctionsNumbered F2 on F1.X = F2.Y and F1.Y = F2.X
where 
	F1.RN < F2.RN
order by
	F1.X;


