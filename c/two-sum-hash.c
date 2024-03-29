#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

#define HASHSIZE 100

typedef struct hash_table *TablePtr;
typedef struct hash_node *NodePtr;

typedef struct hash_node
{
  int key;
  int value;
  NodePtr next;
} HashNode;

typedef struct hash_table
{
  int size;
  NodePtr *header;
} HashTable;

unsigned hash(int key, int size);

TablePtr init_hashtable(int size);
NodePtr insert_node(TablePtr hashtab, int key, int index);
NodePtr find_node(TablePtr hashtab, int key);
void free_hashtable(TablePtr hashtab);

void print_node(NodePtr np);
void print_ary(int ary[], int n);
void read_by_char(NodePtr np);

TablePtr init_hashtable(int size)
{
  TablePtr hashtab;
  hashtab = (TablePtr)malloc(sizeof(HashTable));

  if (hashtab == NULL)
    return NULL;

  hashtab->size = size;
  hashtab->header = (NodePtr *)malloc(sizeof(NodePtr) * size);

  memset(hashtab->header, 0, (sizeof(NodePtr) * size));

  if (hashtab->header == NULL)
    return NULL;

  return hashtab;
}

unsigned hash(int key, int size)
{
  return abs(key) % size;
}

NodePtr find_node(TablePtr hashtab, int key)
{
  NodePtr np;
  unsigned hashval = hash(key, hashtab->size);

  np = hashtab->header[hashval];
  for (; np != NULL; np = np->next)
  {
    if (np->key == key)
    {
      return np;
    }
  }

  return NULL;
}

NodePtr insert_node(TablePtr hashtab, int key, int index)
{
  NodePtr np;
  np = (NodePtr)malloc(sizeof(HashNode));

  if (np == NULL)
  {
    printf("malloc HashNode is fail\n");
    return NULL;
  }

  np->next = NULL;
  np->key = key;
  np->value = index;

  unsigned hashval = hash(key, hashtab->size);

  np->next = hashtab->header[hashval];
  hashtab->header[hashval] = np;

  return np;
}

void free_hashtable(TablePtr hashtab)
{
  NodePtr np, tmp;

  for (int i = 0; i < hashtab->size; i++)
  {
    np = hashtab->header[i];
    while (np != NULL)
    {
      tmp = np->next;
      free(np);
      np = tmp;
    }
  }

  free(hashtab);
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
  int *result = (int *)malloc(sizeof(int) * 2);

  TablePtr hashtab;
  NodePtr np;

  if ((hashtab = init_hashtable(HASHSIZE)) == NULL)
  {
    printf("init hashtable fail\n");
    return NULL;
  }

  for (int i = 0; i < numsSize; i++)
  {
    np = find_node(hashtab, target - nums[i]);
    if (np != NULL)
    {

      result[0] = np->value;
      result[1] = i;
      *returnSize = 2;
      break;
    }
    insert_node(hashtab, nums[i], i);
  }

  free_hashtable(hashtab);
  return result;
}

void print_node(NodePtr np)
{
  for (; np != NULL; np = np->next)
  {
    printf("%d:%d\n", np->key, np->value);
  }
}

void read_by_char(NodePtr np)
{
  int len = sizeof(*np);
  printf("ss:%d\n", len);

  int *ptr;
  ptr = (int *)(np);
  printf("ss:%d\n", len);

  // printf("value_ptr:%d\n", *ptr);

  for (size_t i = 0; i < len; i++)
  {
    printf("byte:%d\n", *ptr);
  }
}

// 打印数组
void print_ary(int ary[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", ary[i]);
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int nums[] = {16, 15, 2, 7, 11};

  int len = 5; //sizeof(nums);

  TablePtr hashtab;

  if ((hashtab = init_hashtable(HASHSIZE)) == NULL)
  {
    printf("malloc init_hashtable is fail\n");
    return -1;
  }

  int *resault, *returnSize;

  resault = twoSum(nums, len, 9, returnSize);
  print_ary(resault, 2);
  free(resault);
  return 0;
}
