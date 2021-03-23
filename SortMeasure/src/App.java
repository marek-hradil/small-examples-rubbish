import java.util.ArrayList;

import Measurer.Measurer;
import Presenter.Result;
import Presenter.Presenter;

/**
 * @author marek hradil
 */
public class App {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int seedLength = Presenter.scanSeedLength();
        int iterations = Presenter.scanIterations();

        Measurer measurer = new Measurer(seedLength, iterations);

        ArrayList<Result> results = measurer.measure();

        Presenter.printResults(results);
    }
}