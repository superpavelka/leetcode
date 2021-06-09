#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <string>

int reverse(int x) {
	int rev = 0;
	while (x != 0) {
		int pop = x % 10;
		x /= 10;
		if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;
	}
	return rev;
}

int main()
{
	int x = -2147483412;
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = reverse(x);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}

