#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <unordered_map>

std::vector<int> twoSum3(std::vector<int>& nums, int target) {
	std::vector<int> r;
	std::unordered_map<int, int> temp;
	for (int i = 0; nums.size(); i++)
	{
		int v = target - nums.at(i);

		if (temp.find(v) != temp.end())
		{
			r.push_back(temp[v]);
			r.push_back(i);
			return r;
		}

		temp[nums[i]] = i;
	}

	return r;
}

int main()
{
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = twoSum3(nums, target);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	//std::cout << "Answer = " << answer.c_str() << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}