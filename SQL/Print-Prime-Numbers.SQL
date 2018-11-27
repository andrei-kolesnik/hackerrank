/*
Print Prime Numbers
https://www.hackerrank.com/challenges/print-prime-numbers

Sample Output for n = 10:
2&3&5&7
*/
declare @i int, @k int, @ok bit, @result varchar(8000)
set @i = 2
set @result = ltrim(str(@i))
set @i = 3
while @i <= 1000
begin
	set @k = 2
	set @ok  = 1
	while @k <= sqrt(@i)
	begin
		if @i % @k = 0
		begin
			set @ok = 0;
			break
		end
		set @k += 1
	end
	if @ok = 1
		set @result += '&' + ltrim(str(@i))
	set @i += 1
end
print @result;
