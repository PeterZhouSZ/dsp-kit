#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "FastMover.hpp"

dspkit::FastMover fm;
std::ofstream fs;

void beginOutput(const std::string &path) {
    fs.open(path);
    //fs << "data = [ " << std::endl;
}

void process(int count) {
    for (int i=0; i<count; ++i) {
        fs << fm.next() << std::endl;
    }
}

void finishOutput() {
    //fs << std::endl << " ]; " << std::endl;
    fs.close();
}


int main() {
    std::ofstream ofs;
    beginOutput("test-fast-mover-output.data");

    fm.setSampleRate(48000);
    fm.setTime(1.0);
    fm.setTarget(40.0);

    process(20000);

    fm.setTime(0.5);
    fm.setTarget(100);

    process(10000);

    fm.setTime(0.3);
    fm.setTarget(-28);


    process(20000);

    finishOutput();
}

