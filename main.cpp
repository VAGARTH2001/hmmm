#include <iostream>
using namespace std;

int findInVector(int* vec, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (vec[i] == val) return 1;
    }
    return 0;
}

int longestConsecutive(int* nums, int size) {
    int maxLen = 0;

    for (int i = 0; i < size; i++) {
        int currentNum = nums[i];
        int prevExists = 0;

        for (int j = 0; j < size; j++) {
            if (nums[j] == currentNum - 1) {
                prevExists = 1;
                break;
            }
        }

        if (!prevExists) {
            int len = 1;
            int next = currentNum + 1;
            while (findInVector(nums, size, next)) {
                len++;
                next++;
            }
            if (len > maxLen) maxLen = len;
        }
    }

    return maxLen;
}

int main() {
    int nums1[] = {100, 4, 200, 1, 3, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << longestConsecutive(nums1, size1) << endl;

    int nums2[] = {1, 0, 1, 2};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << longestConsecutive(nums2, size2) << endl;
    cout<<"hello world"<<endl;

    return 0;
}
