/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author marek
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Cannot determine result, operator not passed");
            return;
        }

        char sign = args[0].charAt(0);
        OperationStrategy strategy = new OperationStrategy(sign);
        float result = strategy.run();
        System.out.println("Result is: " + result);
    }

}

abstract class OperationInterpreter {
    protected ArrayList<Float> values = new ArrayList<>();

    public void pushValue(float value) {
        this.values.add(value);
    }

    public float getResult() {

        float result = this.values.get(0);
        for (float value : this.values.subList(1, this.values.size())) {
            result = this.reduce(result, value);
        }

        return result;
    };

    protected abstract float reduce(float a, float b);
}

class AdditionInterpreter extends OperationInterpreter {
    @Override
    protected float reduce(float a, float b) {
        return a + b;
    }
}

class SubtractionInterpreter extends OperationInterpreter {
    @Override
    protected float reduce(float a, float b) {
        return a - b;
    }
}

class MultiplicationInterpreter extends OperationInterpreter {
    @Override
    protected float reduce(float a, float b) {
        return a * b;
    }
}

class DivisionInterpreter extends OperationInterpreter {
    @Override
    protected float reduce(float a, float b) {
        if (b == 0) {
            return a / 1;
        }

        return a / b;
    }
}

class OperationStrategy {
    private final OperationInterpreter interpreter;
    private final Scanner scanner;

    public OperationStrategy(char sign) {
        this.interpreter = OperationStrategy.createInterpreter(sign);
        this.scanner = new Scanner(System.in);
    }

    public float run() {
        if (this.interpreter == null) {
            throw new Error("Cannot run, no suitable interpreter");
        }

        while (scanner.hasNextFloat()) {
            this.interpreter.pushValue(scanner.nextFloat());
        }

        return this.interpreter.getResult();
    }

    private static OperationInterpreter createInterpreter(char sign) {
        switch (sign) {
            case '+':
                return new AdditionInterpreter();
            case '-':
                return new SubtractionInterpreter();
            case '*':
                return new MultiplicationInterpreter();
            case '/':
                return new DivisionInterpreter();
            default:
                return null;
        }
    }
}