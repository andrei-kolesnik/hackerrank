<?php
/*
Quicksort 1 - Partition
https://www.hackerrank.com/challenges/quicksort1

Input:
4 5 3 7 2

Output:
3 2 4 5 7
*/

function quickSort($arr) {
    $result = array();
	if (!count($arr)) return $result;
	$pivot = $arr[0];
    $left = array();
    $right = array(); 
    $equal = array($pivot);
	for ($i = 1; $i < count($arr); $i++)
		if ($arr[$i] < $pivot) $left[] = $arr[$i];
		elseif ($arr[$i] > $pivot) $right[] = $arr[$i];
		else $equal[] = $arr[$i];
	$result = array_merge(quickSort($left), $equal, quickSort($right));
	return $result;
}

$arr = array(4, 5, 3, 7, 2);

$result = quickSort($arr);

echo(implode(" ", $result) . "\n");
