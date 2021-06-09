#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>

int expandAroundCenter(std::string s, int left, int right) {
	int L = left, R = right;
	while (L >= 0 && R < s.length() && s[L] == s[R]) {
		L--;
		R++;
	}
	return R - L - 1;
}

std::string longestPalindrome(std::string s) {

	if (s.c_str() == nullptr || s.length() < 1)
		return "";
	int start = 0;
	int end = 0;
	for (int i = 0; i < s.length(); i++) {
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		int len = std::max(len1, len2);
		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	return s.substr(start, end + 1 - start);
}

int main()
{
	std::string s = "babad";
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = longestPalindrome(s);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer = " << answer.c_str() << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}