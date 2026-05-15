/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {

 int *resposta = malloc(sizeof(int) * numsSize);
  *returnSize = numsSize;

for( int x = 0; x<numsSize; x++){
    int encontrou = 0;
    int y = x+1;
    while(y<numsSize && nums[x]>= nums[y]){
        y++;
    }
    if(y<numsSize && nums[y]>nums[x]){
        resposta[x] = nums[y];
        encontrou = 1;
    }
    else {
        int a = 0;
        while (a<x){
            if (nums[a]> nums[x]){
                //achei
                resposta[x] = nums[a];
                encontrou = 1;
                break;
            }
           a++;

        }
       if (encontrou != 1){
        resposta[x]=-1;
       } 
    }

}
return resposta;
    
}