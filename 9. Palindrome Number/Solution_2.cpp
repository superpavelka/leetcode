#include <iostream>
#include <string>
#include <chrono>

bool isPalindrome(int x) 
{
	if (x < 0) 
		return false;
	int x_copy = x;
	long ans = 0;
	while (x_copy != 0) 
	{
		ans = ans * 10 + x_copy % 10;
		x_copy = x_copy / 10;
	}
	return ans == x;
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