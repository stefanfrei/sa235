#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

#include "fixture.h"

using std::cout;
using std::endl;

using fixtureConstants::chars;

Fixture::Fixture() {
    cout << "instance alive" << endl;
    
}

Fixture::~Fixture() {
    cout << "instance disposed" << endl;
}

string genString(int len, std::mt19937 &gen) {
    
    std::uniform_int_distribution<> distrib(0, chars.length());
    for(int i = 0; i < len; i++) {
        cout << chars[distrib(gen)];
    }
    cout << endl;
    return "blaa";
}

string Fixture::genNumber(int len) {
    return "blaa";
}



int main() {
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    Fixture fixture;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    for (int i = 0; i < 1000; i++) {
        genString(100, gen);
    }

    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << endl << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms" << endl << endl;
    return 0;
}
