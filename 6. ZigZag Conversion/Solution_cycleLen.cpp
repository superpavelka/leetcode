#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <unordered_map> 

std::string convert(std::string s, int numRows) {

	if (numRows == 1)
		return s;

	std::string sout;
	int n = (int)s.size();
	int cycleLen = 2 * numRows - 2;

	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j + i < n; j += cycleLen)
		{
			sout += s[j + i];
			if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
				sout += s[j + cycleLen - i];
		}
	}

	return sout;
}


int main()
{
	std::string s = "PAYPALISHIRING";
	int numRows = 3;
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = convert(s, numRows);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}