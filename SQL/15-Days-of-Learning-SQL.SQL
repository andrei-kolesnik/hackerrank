/*
15 Days of Learning SQL
https://www.hackerrank.com/challenges/15-days-of-learning-sql
*/

with EveryDay as (
select 
    *
from 
	(select 
		submission_date,
		hacker_id,
		count(*) as cnt
	from 
		Submissions S1
	group by 
		submission_date,
		hacker_id) Daily
	where
		(select count(*) from 
			(select 
				submission_date,
				hacker_id
			from 
				Submissions S2
			where 
				S2.hacker_id = Daily.hacker_id
				and S2.submission_date <= Daily.submission_date
			group by 
				submission_date,
				hacker_id
			) Daily2 
		) = DATEDIFF(dd, '2016-03-01', Daily.submission_date)+1
	),

DailySummary as
(
	select 
		ED.submission_date, 
		count(*) as edcnt
	from EveryDay ED
	group by ED.submission_date
),

TopHackers as
(select 
	S3.submission_date,
	S3.hacker_id,
	H.name,
	count(*) thcnt,
	row_number() over (partition by S3.submission_date order by count(*) desc, S3.hacker_id) as thrank
from
	Submissions s3
	join Hackers H on S3.hacker_id = H.hacker_id
group by 
	S3.submission_date, S3.hacker_id, H.name)

select 
	DS.submission_date,
	DS.edcnt,
	TH.hacker_id,
	TH.name
from 
	DailySummary DS 
	join TopHackers TH on DS.submission_date = TH.submission_date
where TH.thrank = 1
order by 1;

/*
Sample Input:

create table submissions ( submission_date date, submission_id int, hacker_id int, score int );

insert into submissions values 
	('2016-03-01',  8494, 20703, 0), 
	('2016-03-01', 22403, 53473, 15), 
	('2016-03-01', 23965, 79722, 60), 
	('2016-03-01', 30173, 36396, 70), 
	('2016-03-02', 34928, 20703, 0), 
	('2016-03-02', 38740, 15758, 60), 
	('2016-03-02', 42769, 79722, 25), 
	('2016-03-02', 44364, 79722, 60), 
	('2016-03-03', 45440, 20703, 0), 
	('2016-03-03', 49050, 36396, 70), 
	('2016-03-03', 50273, 79722, 5), 
	('2016-03-04', 50344, 20703, 0), 
	('2016-03-04', 51360, 44065, 90), 
	('2016-03-04', 54404, 53473, 65), 
	('2016-03-04', 61533, 79722, 45), 
	('2016-03-05', 72852, 20703, 0), 
	('2016-03-05', 74546, 38289, 0), 
	('2016-03-05', 76487, 62529, 0), 
	('2016-03-05', 82439, 36396, 10), 
	('2016-03-05',  9006, 36396, 40), 
	('2016-03-06', 90404, 20703, 0); 

create table hackers ( hacker_id int, name varchar(255) ); 

insert into hackers values (15758, 'Rose'), (20703, 'Angela'), (36396, 'Frank'), (38289, 'Patrick'), (44065, 'Lisa'), (53473, 'Kimberly'), (62529, 'Bonnie'), (79722, 'Michael');

Sample Output:

2016-03-01 4 20703 Angela
2016-03-02 2 79722 Michael
2016-03-03 2 20703 Angela
2016-03-04 2 20703 Angela
2016-03-05 1 36396 Frank
2016-03-06 1 20703 Angela
*/