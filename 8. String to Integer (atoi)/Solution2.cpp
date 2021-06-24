#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>
#include <vector>

using namespace std;


/*int myAtoi(string s) {
	int i = 0;
	int sign = 1;
	int res = 0;

	if (s.length() == 0)
		return 0;
	while (i < s.length() && s[i] == ' ')
		i++;
	if (i < s.length() && (s[i] == '+' || s[i] == '-'))
		sign = (s[i++] == '-') ? -1 : 1;
	while (i < s.length() && s[i] >= '0' && s[i] <= '9')
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
			return (sign == 1) ? INT_MAX : INT_MIN;
		else
		{
			res = res * 10 + (s[i++] - '0');
		}
	}
	return res*sign;
}*/

int myAtoi2(string s)
{
	int sign = 1;
	int ret = 0;

	if (s.size() == 0)
		return 0;

	auto it = s.begin();
	for (; it != s.end(); it = next(it, 1))
		if (*it != ' ')	break;
	if (it != s.end() && (*it == '+' || *it == '-'))
	{
		sign = *it == '+' ? 1 : -1;
		it = next(it, 1);
	}
	
	while (it != s.end() && *it >= '0' && *it <= '9')
	{
		if (ret > INT_MAX / 10 || ((ret == INT_MAX / 10) && (*it - '0' > INT_MAX % 10)))
			return (sign == 1) ? INT_MAX : INT_MIN;
		else
		{
			ret = ret * 10 + (*it - '0');
		}
		it = next(it, 1);
	}
	return ret*sign;
 }

int main()
{
	string s1 = "   -42";
	string s2 = "4193 with words";
	string s3 = "-91283472332";
	string s4 = "+-12";
	string s5 = "123 456";
	vector<string> ss{ s1, s2, s3, s4, s5 };
	for (auto s : ss)
	{
		auto now = std::chrono::high_resolution_clock::now();
		auto answer = myAtoi2(s);
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
		std::cout << "Answer= " << answer << "\n";
		std::cout << "Time : " << elapsed.count() << "ns.\n";
	}
	return 0;
}