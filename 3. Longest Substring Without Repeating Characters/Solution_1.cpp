#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
	int start = 0;
	int result = 0;
	std::unordered_map<char, int> letters;

	for (auto i = 0; i < s.size(); ++i)
	{
		const auto symb = letters.find(s[i]);

		if (symb != letters.end())
		{
			const int index = symb->second;
			result = std::max(result, i - start);
			start = std::max(start, index + 1);
		}
		letters[s[i]] = i;
	}

	if ((s.size() - start) > result)
		result = s.size() - start;

	return result;
}

int main()
{
	std::string s = "abcabcbb";
	auto now = std::chrono::high_resolution_clock::now();
	int answer = lengthOfLongestSubstring(s);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer = " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}