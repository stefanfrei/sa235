#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>

#include "sandbox.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::setw;
using std::string;
using std::vector;


Task getFirstRecurringCharBruteForce(Task task) { //brute force

    task.funcName = __func__;

    char result;
    int srcLength = task.src.length();
    for(int i = 0; i < srcLength-1; i++) { // last char is irrelevant
        result = task.src.at(i);
        for(int j = i + 1; j < srcLength; j++) {
            if (result == task.src.at(j)) {
                task.result = result;
                break;
            }
        }

        if (task.result != '\0') break;
    }

    return task;
}


Task getFirstRecurringCharUsingMap(Task task) {

    task.funcName = __func__;

    task.result = 'G';

    return task;
}


Task profiler(Task (*func)(Task), Task task) {
    cout << "mes start\n";
    task = func(task);
    cout << "mes end\n";
    return task;
}


vector<Task> initTasks(vector<string> sources) {

    vector<Task> tasks;

    for (string src : sources) {

        Task task = {
            "",
            "",
            src,
            '\0'
        };

        tasks.push_back(task);
    }

    return tasks;
}


void printResult(Task task) {
    cout << "############################################################################################################\n"
            << "Testing function << " << task.funcName << "() >>\n"
            << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
            << "Source -> " << task.src << "\n"
            << "Result -> " << task.result << "\n"
            << "Task took " << std::setprecision(6) << task.duration << "ms\n\n";
}


int main() {

    vector<Task(*)(Task)> funcs = {
        getFirstRecurringCharBruteForce,
        getFirstRecurringCharUsingMap
    };

    vector<string> sources = {
        "ABAC", //expected result: A
        "abcdefghijklmk", //expected result: k
        "exwlzgfkuerzcmumczemhouczmeriuczoaucmraucoreuzacmuzcgeiuezcrmrecziuzeg" //expected result: e
    };

    vector<Task> tasks = initTasks(sources);
    /* Task task;
    task = profiler(&core, task);*/

    for(int i = 0; i < funcs.size(); i++) {

        for (Task task : tasks) {
            task = funcs[i](task);
            /* task = profiler(&funcs[i], task); */
            printResult(task);
        }

    }

    return 0;
}