<?php


//题目：要求：一个字符串含有”([{}])”，大中小三种括号；要求判断该字符串的括号是否合法匹配。
//判断一个字符的合法性，括号匹配的题目，使用数据结构中栈的思想
//实现思路：使用数据来模拟栈
//1、建立一个栈空数组，用来模拟栈
//2、建立一个映射关系，要验证的括号类型配对映射
//3、判断对应字符是否在映射关系中，在的就进行入栈操作；不在进行出栈操作
//4、最后判断栈是否为空，空则合法，不空则不合法。
function strValidityCheck($str){
    $stack = [];
    $map = [
        ']'=>'[',
        ')'=>'(',
        '}'=>'{',
    ];
    for($i=0;$i<strlen($str);$i++){
        if(in_array($str[$i],array_values($map))){
            array_push($stack,$str[$i]);
        }else if(in_array($str[$i],array_keys($map))){
            if($stack && $map[$str[$i]] == end($stack)){
                array_pop($stack);
			}else{
				return false;
			}

		}
    }       

    return empty($stack) ? true : false;     
}

//$str = '[12+23][]]sjsjsj{}';  
//$str = '[]12121[{]}';  
//$str = '11';  
//$str = '([]))';  
var_dump(strValidityCheck($str));





