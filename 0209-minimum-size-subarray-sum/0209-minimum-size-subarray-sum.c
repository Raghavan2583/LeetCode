int minSubArrayLen(int target, int* nums, int numsSize) {
    int pt1 = 0;
    int sum = 0;
    int cur=0;
    int min=INT_MAX;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        cur++;
        if(sum>=target){
            while(sum-nums[pt1]>=target){
                sum-=nums[pt1];
                pt1++;
                cur--;
            }
            min = (cur<min?cur:min);
        }

    }
    if(sum<target){
        return 0;
    }
    return numsSize>min?min:numsSize;
}