int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j;
    for(i = 0; i < numsSize-1; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                int* ret = malloc(2*sizeof(int));
                *returnSize = 2;
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}