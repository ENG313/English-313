
/* 
 * File:   main.cpp
 * Author: chengb
 * 
 * Copyright 2018 chengb@miamiOH.edu
 * Created on September 26, 2018, 6:06 PM
 */

#include <cstdlib>

#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

// Short cut to a vector of strings used to pass command-line arguments
using StrVec = std::vector<std::string>;

/**
 * A helper class to fork and have the child process execute a
 * command.  The parent process waits for the child to finish and
 * returns the exit code.
 *
 * NOTE: Normally, a class should be broken into header and source
 * file. For this exercise we combine the two merely for convenience.
 */
class Process {
public:
    int forkExec(const StrVec& argList) const {
        const int pid = fork();
        if (pid == 0) {
            myExec(argList);
        }
        int exitCode = 0;
        waitpid(pid, &exitCode, 0);
        return exitCode;
    }

private:
    void myExec(StrVec argList) const {
        std::vector<char*> args;
        for (size_t i = 0; (i < argList.size()); i++) {
            args.push_back(&argList[i][0]);
        }
        args.push_back(nullptr);
        execvp(args[0], &args[0]);
    }
};

int main() {
    const std::string dataFile = "/tmp/oui.txt";
    Process proc;
    // Print general statistics
    std::cout << "General stats about " << dataFile << std::endl;
    proc.forkExec({"wc", dataFile});
    
    // Print total number of companies
    std::cout << "Total number of companies in " << dataFile << std::endl;
    proc.forkExec({"grep", "-c", "-i", "(hex)", dataFile});
    
    // Print number of US companies
    std::cout << "Number of US companies in " << dataFile << std::endl;
    proc.forkExec({"grep", "-c", "-i", "united states", dataFile});
    return 0;
}

