package Sorters;

class BubbleSorter extends Sorter {
    public int[] sort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - i; j++) {
                if (array[i] > array[j]) {
                    swap(array, i, j);
                }
            }
        }

        return array;
    }

    public String getName() {
        return "Bubble sort";
    }
}
