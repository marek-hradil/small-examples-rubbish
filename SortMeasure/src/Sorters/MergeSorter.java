package Sorters;

class MergeSorter extends Sorter {
    public int[] sort(int[] array) {
        return sort(array, 0, array.length - 1);
    }

    public int[] sort(int[] array, int begin, int end) {
        if (begin >= end) {
            return array;
        }

        int middle = (begin + end) / 2;
        sort(array, begin, middle);
        sort(array, middle + 1, end);
        merge(array, begin, middle, end);

        return array;
    }

    private void merge(int[] array, int begin, int middle, int end) {
        int leftSize = middle - begin + 1;
        int rightSize = end - middle;

        int L[] = new int[leftSize];
        int R[] = new int[rightSize];

        for (int i = 0; i < leftSize; i++)
            L[i] = array[begin + i];
        for (int j = 0; j < rightSize; j++)
            R[j] = array[middle + 1 + j];

        int leftArrayIndex = 0;
        int rightArrayIndex = 0;
        int mergedArrayIndex = begin;

        while (leftArrayIndex < leftSize && rightArrayIndex < rightSize) {
            if (L[leftArrayIndex] <= R[rightArrayIndex]) {
                array[mergedArrayIndex] = L[leftArrayIndex];
                leftArrayIndex += 1;
            } else {
                array[mergedArrayIndex] = R[rightArrayIndex];
                rightArrayIndex += 1;
            }

            mergedArrayIndex += 1;
        }

        while (leftArrayIndex < leftSize) {
            array[mergedArrayIndex] = L[leftArrayIndex];
            leftArrayIndex += 1;
            mergedArrayIndex += 1;
        }

        while (rightArrayIndex < rightSize) {
            array[mergedArrayIndex] = R[rightArrayIndex];
            rightArrayIndex += 1;
            mergedArrayIndex += 1;
        }
    }

    public String getName() {
        return "Merge sort";
    }
}
