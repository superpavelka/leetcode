#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;

int myAtoi(string s) {
	long long ret = 0;
	long long reverseRet = 0;
	bool neg = false;
	bool stringBeg = false;
	int digitsCount = 0;
	if (!s.size())
		return ret;
	auto it = s.begin();
	for ( ;it != s.end(); it = next(it, 1))
	{
		if (*it == ' ' && !stringBeg)
			continue;
		else if ((*it == '+' || *it == '-') && !digitsCount)
		{
			if (stringBeg)
				return 0;
			if (*it == '-') neg = true;
			stringBeg = true;
		}
		else if (*it == '0' && !digitsCount)
		{
			stringBeg = true;
			continue;
		}			
		else if (*it >= '0' && *it <= '9')
		{
			reverseRet += (*it - '0') * pow(10, digitsCount);
			digitsCount++;
			stringBeg = true;
			if (digitsCount > 10)
			{
				if (neg)
					ret = INT_MIN;
				else
					ret = INT_MAX;
				return ret;
			}
		}
		else if (digitsCount)
			break;
		else
			return 0;		
	}

	for (int i = 0; i < digitsCount; ++i)
	{
		ret += (reverseRet % 10) * pow(10, digitsCount - i - 1);
		reverseRet /= 10;
	}

	if (neg) ret *= -1;

	if (ret <= INT_MIN)
		return INT_MIN;
	else if (ret >= INT_MAX)
		return INT_MAX;
	else
		return ret;
}

int main1()
{
	string s1 = "   -42";
	string s2 = "4193 with words";
	string s3 = "-91283472332";
	string s4 = "+-12";
	string s5 = "123 456";
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = myAtoi(s5);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}