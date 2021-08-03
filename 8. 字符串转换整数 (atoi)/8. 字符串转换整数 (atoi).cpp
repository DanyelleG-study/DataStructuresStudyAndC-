﻿// 8. 字符串转换整数 (atoi).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C / C++ 中的 atoi 函数）。
//
//函数 myAtoi(string s) 的算法如下：
//
//读入字符串并丢弃无用的前导空格
//检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
//读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
//将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
//如果整数数超过 32 位有符号整数范围[−231, 231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
//返回整数作为最终结果。
//注意：
//
//本题中的空白字符只包括空格字符 ' ' 。
//除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
#include <iostream>
#include<string>
using namespace std;
int myAtoi(string s)
{
	int i = 0;
	int flag = 1;
	int res = 0;
	while (s[i] == ' ')
	{
		i++;
	}
	if (s[i] == '-')
		flag = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (i < s.length() && s[i] >= '0'&&s[i] <= '9')
	{
		int temp = s[i] - '0';
		if (res > INT_MAX / 10 || (i == res / 10 && temp>7))
			return flag > 0 ? INT_MAX : INT_MIN;
		res = res * 10 + temp;
		i++;
	}
	return flag * res;
}
int main()
{
	int t = myAtoi("-2147483648");
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
