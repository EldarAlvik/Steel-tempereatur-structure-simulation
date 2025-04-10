//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "test.h"
#include "animation/animation.h"
#include "simulationControl.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main() {
    // Show a nice message in the Terminal window
    //carbonTest();
    runSimulation();
    // This lets the operating system (Windows, Mac, Linux, etc.) know that the program
    // did not encounter any errors
    return 0;
}

//------------------------------------------------------------------------------
