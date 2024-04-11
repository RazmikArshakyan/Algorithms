#include <iostream>
#include <vector>

int majority_element_helper(std::vector<int>& nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = (left + right) / 2;
    int left_majority = majority_element_helper(nums, left, mid);
    int right_majority = majority_element_helper(nums, mid + 1, right);

    if (left_majority == right_majority) {
        return right_majority;
    }

    int left_count = 0, right_count = 0;
    for (int i = left; i <= right; ++i) {
        if (nums[i] == left_majority) {
            ++left_count;
        }
        else if (nums[i] == right_majority) {
            ++right_count;
        }
    }

    if (left_count > (right - left + 1) / 2) {
        return left_majority;
    }
    else if (right_count > (right - left + 1) / 2) {
        return right_majority;
    }
    else {
        return INT_MIN;
    }
}

int majority_element(std::vector<int>& nums) {
    int maj_el = majority_element_helper(nums, 0, nums.size() - 1);
    if (maj_el == INT_MIN) {
        throw std::logic_error("No majority element found");
    }
    return maj_el;
}

int main() {
    std::vector nums = {3, 3, 3, 2, 2, 4, 2, 4, 4};
    try {
        std::cout << majority_element(nums);
    }
    catch (const std::logic_error& e) {
        std::endl(std::cerr << e.what());
    }

    return 0;
}