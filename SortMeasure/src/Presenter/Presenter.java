package Presenter;

import java.util.ArrayList;
import java.util.Scanner;

public class Presenter {
    private static Scanner scanner = new Scanner(System.in);

    public static int scanSeedLength() {
        System.out.print("Please, type length of data array to sort: ");
        int seedLength = 0;

        if (scanner.hasNextInt()) {
            seedLength = scanner.nextInt();
            System.out.println();
        } else {
            System.out.println("Wrong type entered. Exiting.");
            System.exit(1);
        }

        return seedLength;
    }

    public static int scanIterations() {
        System.out.print("Please, type number of iterations for each sort to perform: ");
        int iterations = 0;

        if (scanner.hasNextInt()) {
            iterations = scanner.nextInt();
            System.out.println();
        } else {
            System.out.println("Wrong type entered. Exiting.");
            System.exit(1);
        }

        return iterations;
    }

    public static void printResults(ArrayList<Result> results) {
        for (Result result : results) {
            System.out.println("|\t" + result.getName() + '\t' + result.getResult() + "\t|");
        }

        System.out.println();
    }
}
