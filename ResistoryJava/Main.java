import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author marek hradil
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SolutionStrategy strategy = new SolutionStrategy();

        if (!strategy.execute()) {
            System.exit(1);
        }

        System.exit(0);
    }

}

abstract class ResistorException extends Exception {
    protected ResistorException(String message) {
        super(message);
    }
}

class ResistorErrorOutOfBoundsException extends ResistorException {
    public ResistorErrorOutOfBoundsException() {
        super("Resistor error should be between 0 and 1");
    }
}

class ResistorValueOutOfBoundsException extends ResistorException {
    public ResistorValueOutOfBoundsException() {
        super("Value should be more than 0");
    }
}

class Resistor {
    public final Float maxValue;
    public final Float minValue;

    public Resistor(Float minValue, Float maxValue) {
        this.maxValue = maxValue;
        this.minValue = minValue;
    }

    public String toString() {
        return "<" + minValue + "," + maxValue + ">";
    }
}

class ResistorBuilder {
    public static Resistor build(Float value) {
        return new Resistor(value, value);
    }

    public static Resistor build(Float value, Float error) throws ResistorException {
        if (error > 1 || error < 0) {
            throw new ResistorErrorOutOfBoundsException();
        }

        if (value <= 0) {
            throw new ResistorValueOutOfBoundsException();
        }

        Float maxValue = value * (1 + error);
        Float minValue = value * (1 - error);

        return new Resistor(minValue, maxValue);
    }
}

class SolutionStrategy {
    private InputScanner scanner;
    private ArrayList<Resistor> resistors;

    public SolutionStrategy() {
        this.scanner = new InputScanner();
        this.resistors = new ArrayList<>();
    }

    public boolean execute() {
        ArrayList<Float[]> items = scanner.read();

        for (Float[] item : items) {
            try {
                Resistor resistor = ResistorBuilder.build(item[0], item[1]);

                resistors.add(resistor);
            } catch (ResistorException e) {
                System.err.println("Wrong resistor value.");

                return false;
            }
        }

        if (items.isEmpty()) {
            System.out.println("No resistors were provided.");

            return false;
        }

        ResistorOperationsResult result = ResistorOperationsStrategy.execute(resistors);

        String output = String.format("Series: (min: %f, max: %f)%nParallel: (min: %f, max: %f)",
                result.seriesResistor.minValue, result.seriesResistor.maxValue, result.parallelResistor.minValue,
                result.parallelResistor.maxValue);

        System.out.println(output);

        return true;
    }
}

class InputScanner {
    private Scanner scanner;
    private ArrayList<Float[]> items;

    private Pattern inputPattern = Pattern.compile("([0-9]+)\\s+\\+\\-\\s*([0-9]+)\\s*%");

    public InputScanner() {
        scanner = new Scanner(System.in);
        items = new ArrayList<>();
    }

    public ArrayList<Float[]> read() {
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            Matcher matcher = inputPattern.matcher(line);

            if (!matcher.find()) {
                break;
            }

            Float value = Float.parseFloat(matcher.group(1));
            Float error = Float.parseFloat(matcher.group(2));

            Float[] item = { value, error / 100 };

            items.add(item);
        }

        return items;
    }
}

class ResistorOperationsResult {
    public final Resistor seriesResistor;
    public final Resistor parallelResistor;

    public ResistorOperationsResult(Resistor seriesResistor, Resistor parallelResistor) {
        this.seriesResistor = seriesResistor;
        this.parallelResistor = parallelResistor;
    }
}

class ResistorOperationsStrategy {
    public static ResistorOperationsResult execute(ArrayList<Resistor> resistors) {
        Resistor seriesResistor = calculateSeries(resistors);
        Resistor parallelResistor = calculateParallel(resistors);

        return new ResistorOperationsResult(seriesResistor, parallelResistor);
    }

    private static Resistor calculateSeries(ArrayList<Resistor> resistors) {
        Resistor accumulator = resistors.get(0);
        if (resistors.size() == 1) {
            return accumulator;
        }

        for (Resistor resistor : resistors.subList(1, resistors.size())) {
            accumulator = ResistorOperationsInterpreter.add(accumulator, resistor);
        }

        return accumulator;
    }

    private static Resistor calculateParallel(ArrayList<Resistor> resistors) {
        Resistor accumulator = ResistorOperationsInterpreter.flip(resistors.get(0));
        if (resistors.size() == 1) {
            return resistors.get(0);
        }

        for (Resistor resistor : resistors.subList(1, resistors.size())) {
            accumulator = ResistorOperationsInterpreter.add(accumulator, ResistorOperationsInterpreter.flip(resistor));
        }

        return ResistorOperationsInterpreter.flip(accumulator);
    }
}

class ResistorOperationsInterpreter {
    private static Resistor oneResistor = ResistorBuilder.build(1.0f);

    private static Float min(Float[] values) {
        Float min = values[0];
        for (Float value : values) {
            if (value < min) {
                min = value;
            }
        }

        return min;
    }

    private static Float max(Float[] values) {
        Float max = values[0];
        for (Float value : values) {
            if (value > max) {
                max = value;
            }
        }

        return max;
    }

    public static Resistor add(Resistor r1, Resistor r2) {
        return new Resistor(r1.minValue + r2.minValue, r1.maxValue + r2.maxValue);
    }

    public static Resistor divide(Resistor r1, Resistor r2) {
        Float[] product = { r1.minValue / r2.minValue, r1.minValue / r2.maxValue, r1.maxValue / r2.minValue,
                r1.maxValue / r2.maxValue };

        return new Resistor(min(product), max(product));
    }

    public static Resistor flip(Resistor r) {
        return divide(oneResistor, r);
    }
}