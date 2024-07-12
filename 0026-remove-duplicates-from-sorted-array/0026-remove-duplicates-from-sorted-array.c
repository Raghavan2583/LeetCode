int removeDuplicates(int* nums, int numsSize) 
{
    int f=0;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[f]!=nums[i])
        {
            nums[f+1]=nums[i];
            f++;
        }
        
    }
    return f+1;
}