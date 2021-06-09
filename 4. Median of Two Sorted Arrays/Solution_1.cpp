#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdlib>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::vector<int> nums3;
	nums3.resize(nums1.size() + nums2.size());
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());
	size_t size = nums3.size();
	if (size == 0)
		return 0;
	else
	{
		if (size % 2 == 0)
			return (nums3[size / 2 - 1] + nums3[size / 2]) / 2.0;
		else
			return nums3[size / 2];
	}
}

int main()
{
	std::vector<int> nums1{ 1, 2 };
	std::vector<int> nums2{ 3, 4 };
	auto now = std::chrono::high_resolution_clock::now();
	auto answer = findMedianSortedArrays(nums1, nums2);
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - now);
	std::cout << "Answer= " << answer << "\n";
	std::cout << "Time : " << elapsed.count() << "ns.\n";
	return 0;
}