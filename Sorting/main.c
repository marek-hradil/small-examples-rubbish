#include <stdio.h>
#include <stdlib.h>

void swap_ints(int *a, int *b)
{
    int sw = *a;
    *a = *b;
    *b = sw;
}
// RIPPLE SORT, the difference is, that in the second cycle, instead of testing whole array, u just test the unsorted part
void perform_bubblesort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - i); j++)
        {
            if (array[j] > array[j + 1])
            {
                swap_ints(&array[j], &array[j + 1]);
            }
        }
    }
}

void perform_merge_sort_merge(int arr[], int l, int r)
{
    int m = (l + r) / 2;

    int size_l = m - l + 1;
    int size_r = r - m;

    int L[m - l + 1];
    int R[r - m];

    for (int i = 0; i < size_l; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < size_r; i++)
        R[i] = arr[m + 1 + i];

    int li = 0;
    int ri = 0;
    int arri = l;

    while (li < size_l && ri < size_r)
    {
        if (L[li] <= R[ri])
        {
            arr[arri] = L[li];
            li += 1;
        }
        else
        {
            arr[arri] = R[ri];
            ri += 1;
        }

        arri += 1;
    }

    while (li < size_l)
    {
        arr[arri] = L[li];
        li += 1;
        arri += 1;
    }

    while (ri < size_r)
    {
        arr[arri] = R[ri];
        ri += 1;
        arri += 1;
    }
}

int main(int argc, char *argv[])
{
    FILE *f = fopen("./assets/array.txt", "r");
    if (f == NULL)
    {
        perror("couldn't open entry file");
        return EXIT_FAILURE;
    }

    int arr[100];
    int next = 0;

    for (int i = 0; fscanf(f, "%d ", &next) == 1; i++)
    {
        arr[i] = next;
    }

    int size = next + 1;

    perform_bubblesort(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return EXIT_SUCCESS;
}