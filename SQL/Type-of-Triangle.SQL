/*
Type of Triangle
https://www.hackerrank.com/challenges/what-type-of-triangle
*/

select 
case
	when A + B <= C or A + C <= B or B + C <= A then 'Not A Triangle'
	when A = B and B = C and A = C THEN 'Equilateral'
	when A = B or B = C or A = C THEN 'Isosceles'
	else 'Scalene'
end
from TRIANGLES;
