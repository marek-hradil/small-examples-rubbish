package Sorters;

class InsertionSorter extends Sorter {
    public int[] sort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int j = i + 1;
            int current = array[j];
            while (j > 0 && current > array[j - 1]) {
                array[j] = array[j - 1];
                j--;
            }

            array[j] = current;
        }

        return array;
    }

    public String getName() {
        return "Insertion sort";
    }
}
