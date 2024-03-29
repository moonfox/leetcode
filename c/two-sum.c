#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);
void print_ary(int ary[], int n);

int main(int argc, char const *argv[])
{
  int nums[] = {16, 2, 7, 11, 15};
  int nums_size = 5;
  int *resault, returnSize = 0;

  resault = twoSum(nums, nums_size, 9, &returnSize);
  print_ary(resault, 2);
  free(resault);
  return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  // 不能直接写多少字节是因为int型占用字节数由机器决定，所以要使用sizeof得到当前机器int
  // 所分配的字节数。int最少为16字节
  int *result = (int *)malloc(sizeof(int) * 2);

  for (int i = 0; i < numsSize; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        result[0] = i;
        result[1] = j;
        *returnSize = 2;
        break;
      }
    }
  }

  return result;
}

// 打印数组
void print_ary(int ary[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", ary[i]);
  printf("\n");
}