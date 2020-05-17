#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <easing.hpp>

#include "FastMover.hpp"
using namespace dspkit;

FastMover fm;
std::ofstream fs;

void beginOutput(const std::string &path) {
    fs.open(path);
    std::cout << path << std::endl;
    //fs << "data = [ " << std::endl;
}

void process(int count) {
    for (int i=0; i<count; ++i) {
        fs << fm.getNextValue() << std::endl;
    }
}

void finishOutput() {
    //fs << std::endl << " ]; " << std::endl;
    fs.close();
}

void testShape(int shapeIndex) {
    std::string shapeName = easing::function_info[shapeIndex];
    std::string outputFileName = "test_" + shapeName + ".data";
    beginOutput(outputFileName);
    fm.setRiseShape(shapeIndex);
    fm.setFallShape(shapeIndex);
    fm.setSampleRate(48000);

    // rise
    fm.setTime(0);
    fm.setTarget(0);
    fm.setTime(0.5);
    fm.setTarget(100.0);
    process(24000);
    // fall
    fm.setTarget(0);
    process(24000);
    // immediate jump
    fm.setTime(0.0);
    fm.setTarget(-100);
    // aborted rise
    fm.setTime(1.0);
    fm.setTarget(0.0);
    process(24000);
    // aborted fall
    fm.setTime(1.0);
    fm.setTarget(-100.0);
    process(24000);
    finishOutput();

}


int main() {
    for (int i=0; i<(int)easing::function::enum_count; ++i) {
        testShape(i);
    }
}

