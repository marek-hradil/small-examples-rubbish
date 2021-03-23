package Measurer;

import Presenter.Result;

class MeasureResult implements Result {
    private String name;
    private long result;

    public MeasureResult(String name, long result) {
        this.name = name;
        this.result = result;
    }

    public String getName() {
        return this.name;
    }

    public String getResult() {
        return this.result + "ms";
    }
}
