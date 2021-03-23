package Sorters;

import java.util.ArrayList;

public class SorterListBuilder {
    public static ArrayList<Sorter> buildList() {
        ArrayList<Sorter> sorters = new ArrayList<>();

        sorters.add(new QuickSorter());
        sorters.add(new BubbleSorter());
        sorters.add(new MergeSorter());
        sorters.add(new SelectionSorter());
        sorters.add(new InsertionSorter());

        return sorters;
    }
}
