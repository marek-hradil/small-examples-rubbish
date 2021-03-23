package Sorters;

class SelectionSorter extends Sorter {
    public int[] sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int maxIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] > array[maxIndex]) {
                    maxIndex = j;
                }
            }

            swap(array, maxIndex, i);
        }

        return array;
    }

    public String getName() {
        return "Selection sort";
    }
}
