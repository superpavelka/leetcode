#include <iostream>
#include <string>
#include <chrono>


bool isPalindrome(int x) 
{
	std::string s = std::to_string(x);
	std::string s_copy = std::to_string(x);
	std::reverse(s_copy.begin(), s_copy.end());
	return (s == s_copy);
}

int main()
{
	int x = 121;
	auto now = std::chrono::high_resolution_clock::now();
	bool answer = isPalindrome(x);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer = " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}