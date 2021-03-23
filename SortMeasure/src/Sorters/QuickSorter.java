package Sorters;

class QuickSorter extends Sorter {
    public int[] sort(int[] array) {
        return this.sort(array, 0, array.length - 1);
    }

    private int[] sort(int[] array, int begin, int end) {
        if (begin >= end) {
            return array;
        }

        int partitionIndex = partition(array, begin, end);

        sort(array, begin, partitionIndex - 1);
        sort(array, partitionIndex + 1, end);

        return array;
    }

    private int partition(int[] array, int begin, int end) {
        int pivot = array[end];
        int i = begin - 1;

        for (int j = begin; j < end; j++) {
            if (array[j] <= pivot) {
                i++;

                swap(array, i, j);
            }
        }

        swap(array, i + 1, end);

        return i + 1;
    }

    public String getName() {
        return "Quick sort";
    }
}