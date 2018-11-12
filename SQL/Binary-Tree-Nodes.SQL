/*
Binary Tree Nodes
https://www.hackerrank.com/challenges/binary-search-tree-1
*/

select
	N, 
	case
	    when P IS null then 'Root'
	    when not exists (
	    	select N from BST Tree2 where Tree2.P = Tree.N
	    ) then 'Leaf'
	    else 'Inner'
	end
from BST Tree
order by N