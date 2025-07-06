int removeElement(int* nums, int numsSize, int val) {
    int count=0;
    int i;
    for( i=0;i<numsSize;i++){
        if(nums[i]!=val){
            nums[count]=nums[i];
            count++;
        }
    }
    return count;
}
