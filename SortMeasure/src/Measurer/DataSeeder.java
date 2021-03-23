package Measurer;

import java.util.Random;

class DataSeeder {
    private Random generator = new Random();
    private int length;

    public DataSeeder(int length) {
        this.length = length;
    }

    public int[] seed() {
        int[] array = new int[length];

        for (int i = 0; i < length; i++) {
            array[i] = generator.nextInt();
        }

        return array;
    }
}
