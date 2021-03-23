#!/bin/sh

javac Main.java
jar cfm Main.jar manifest.mf ./**.class
java -jar Main.jar +
rm -rf ./**.class