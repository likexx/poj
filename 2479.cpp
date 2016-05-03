//
//  main.cpp
//  test1
//
//  Created by Zhang Like on 2/6/16.
//  Copyright © 2016 Zhang Like. All rights reserved.
//




#include <iostream>
#include <vector>
using namespace std;

int findSum(vector<int> nums) {
    int n = nums.size();
    
    if (n==0) {
        return 0;
    }
    
    vector<int> left(n,0);
    vector<int> right(n,0);
    
    int maxSum = nums[0];
    int cur = nums[0];
    left[0]=cur;
    for(int i=1;i<n;++i) {
//        left[i] = max(left[i-1]+nums[i], nums[i]);
        cur = max(nums[i], cur+nums[i]);
        maxSum = max(cur, maxSum);
        if (cur<0) {
            cur=0;
        }
        left[i] = maxSum;
    }
    
    right[n-1]=nums[n-1];
    maxSum = right[n-1];
    cur = right[n-1];
    for(int i=n-2;i>=0;i--) {
//        right[i] = max(right[i+1]+nums[i], nums[i]);
        cur = max(nums[i], cur+nums[i]);
        maxSum = max(cur, maxSum);
        if (cur<0) {
            cur=0;
        }
        right[i] = maxSum;
    }
    
    maxSum = INT_MIN;
    for(int i=0;i<n-1;++i) {
        maxSum = max(maxSum, left[i]+right[i+1]);
    }
    
    return maxSum;
}

int main() {
    int tests;
    cin>>tests;
    for(int k=0;k<tests;++k) {
        int n;
        scanf("%d", &n);
        vector<int> nums(n,0);
        for(int i=0;i<n;++i) {
//            cin>>nums[i];
            scanf("%d", &nums[i]);
        }
        int result = findSum(nums);
        printf("%d\n", result);
    }
    
//    cout<<findSum({-5,9,-5,11,20})<<endl;
    return 1;
}
