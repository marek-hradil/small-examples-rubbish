#!/bin/sh

javac Main.java
jar cfm Main.jar manifest.mf Main.class
java -jar Main.jar +