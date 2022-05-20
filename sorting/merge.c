#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int *arr, int size);
void sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void swap(int *arr, int aIndex, int bIndex);
void insert(int *arr, int val, int size);
int compare(const void *a, const void *b);

int main(int argc, char **argv)
{
    int *arr;
    int size;
    // if arg array populate arr with args
    if (argc > 2)
    {
        size = argc - 1;
        // allocate mem for array
        arr = malloc(sizeof(int) * size);
        // populate array
        for (int i = 1; i < argc; i++)
        {
            arr[i - 1] = atoi(argv[i]);
        }
    }
    else
    {
        // size = atoi(argv[1]);
        size = 7;
        //   alloc mem for array
        arr = malloc(sizeof(int) * size);
        // populate array
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    // print array
    printf("Start Array:\n");
    printArr(arr, size);
    // sort array
    printf("Sorting...\n");

    sort(arr, 0, size - 1);
    // print sorted
    printf("Sorted Array:\n");
    printArr(arr, size);

    printf("Expected Array:\n");
    int *expected = malloc(sizeof(int) * size);
    memcpy(expected, arr, sizeof(int) * size);
    qsort(expected, size, sizeof(int), (int (*)(const void *, const void *))compare);
    printArr(expected, size);
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int *arr, int start, int end)
{
    // recursive break statement
    if (start >= end)
        return;

    int mid = ((start + end) / 2);
    sort(arr, start, mid);
    sort(arr, mid + 1, end);
    // printf("Merging from %d to %d\n", start, end);
    // printArr(arr, end - start + 1);
    merge(arr, start, mid, end);
}

void merge(int *arr, int start, int mid, int end)
{
    // if array is small just swap and return
    if (start == mid)
    {
        if (arr[start] > arr[end])
            swap(arr, start, end);
        return;
    }
    // temp array
    int *temp = malloc(sizeof(int) * (end - start + 1));
    // fill temp array with values greater than original max
    int max = 0;
    for (int i = start; i <= end; i++)
    {
        max = (arr[i] > max) ? arr[i] : max;
    }
    // fill temp with max + 1
    for (int i = 0; i < end - start + 1; i++)
    {
        temp[i] = max + 1;
    }

    int l = 0, r = 0, step = 0;
    while (l + r < end - start + 1)
    {
        // if left is greater add to array and step
        if (arr[start + l] < arr[mid + r])
        {
            temp[step] = arr[start + l];
            l++, step++;
        }
        else if (arr[mid + r] < arr[start + l]) // if right is greater add to array and step
        {
            temp[step] = arr[mid + r];
            r++, step++;
        }
        else if ((start + l) != mid) // if equal add both to array and step both
        {
            temp[step] = arr[start + l];
            temp[++step] = arr[mid + r];
            l++, r++, step++;
        }

        // if either count has finished add the rest of the remaining vals to temp
        if ((start + l) == mid)
        {
            while ((mid + r) <= end)
            {
                insert(temp, arr[mid + r], end - start + 1);
                // printf("inserted\n");
                // printArr(temp, end - start + 1);
                r++;
            }
            break;
        }
        else if ((mid + r) == end)
        {
            while ((start + l) <= mid)
            {
                insert(temp, arr[start + l], end - start + l);
                // printf("inserted\n");
                // printArr(temp, end - start + 1);
                l++;
            }
            break;
        }
    }

    // transfer temp back to arr
    for (int i = 0, l = 0, r = ((end - start + 1) / 2); i < end - start + 1; i++)
    {
        // add left and right sorted instead of all at once
        if (temp[l] < temp[r] && start + l <= mid)
        {
            arr[start + i] = temp[l];
            l++;
        }
        else
        {
            arr[start + i] = temp[r];
            r++;
            l = (start + l == mid) ? l + 1 : l;
        }
    }
    // printf("finished merge results\n");
    // printArr(arr, end + 1);
    // printArr(temp, end + 1);

    // free(temp);
}

void swap(int *arr, int aIndex, int bIndex)
{
    int temp = arr[aIndex];
    arr[aIndex] = arr[bIndex];
    arr[bIndex] = temp;
}

void insert(int *arr, int val, int size)
{
    int i = 0;
    // find insert index
    while (arr[i] < val && i < size)
    {
        i++;
    }
    // shift array right
    for (int j = size; j > i; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[i] = val;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}