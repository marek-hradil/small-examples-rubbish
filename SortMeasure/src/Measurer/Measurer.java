package Measurer;

import java.util.ArrayList;

import Presenter.Result;
import Sorters.Sorter;
import Sorters.SorterListBuilder;

public class Measurer {
    private ArrayList<Sorter> sorters;
    private DataSeeder seeder;
    private int iterations;

    public Measurer(int seedLength, int iterations) {
        this.sorters = SorterListBuilder.buildList();
        this.seeder = new DataSeeder(seedLength);
        this.iterations = iterations;
    }

    public ArrayList<Result> measure() {
        ArrayList<Result> results = new ArrayList<>();

        for (Sorter sorter : sorters) {
            results.add(measureSorter(sorter));
        }

        return results;
    }

    private Result measureSorter(Sorter sorter) {
        long sumResults = 0;

        for (int i = 0; i < iterations; i++) {
            int[] array = seeder.seed();
            long start = System.currentTimeMillis();
            sorter.sort(array);
            long finish = System.currentTimeMillis();
            long time = finish - start;

            sumResults += time;
        }

        long result = sumResults / iterations;

        return new MeasureResult(sorter.getName(), result);
    }
}