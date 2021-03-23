package Sorters;

public abstract class Sorter {
    public abstract int[] sort(int[] array);

    public abstract String getName();

    protected void swap(int[] array, int left, int right) {
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }
}