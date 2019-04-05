<?php
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

// 解法一 时间复杂度 O(n^2)
// 暴力破解法，两次for循环直接遍历出结果

function twoSum($nums, $target){
	$length = count($nums);
	for ($i = 0; $i < $length; $i++) {
		for ($j = $i + 1; $j < $length; $j++) {
			if ($nums[$i] + $nums[$j] == $target) {
				return [$i,$j];
			}
		}
	}
}

// 解法二 时间复杂度 O(n)
// 枚举其中一个值即可，判断出相关结果
// 
function twoSumOn($nums, $target){
	$length = count($nums);
	$arrHash = [];	
	for($i = 0; $i < $length; $i++){
		$arrHash[$nums[$i]] = $i; 
	}
	for ($i = 0; $i < $length; $i++) {
		$findValue = $target - $nums[$i];
		if ($arrHash[$findValue] && $arrHash[$findValue] != $i) {
			return [$i, $arrHash[$findValue]];
		}
	}
}

