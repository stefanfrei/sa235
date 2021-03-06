#pragma once

#include <string>
#include <random>


using std::string;


namespace fixtureConstants {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

class Fixture {
    private:

    public:
        Fixture();
        ~Fixture();
        string genString(int len);
        string genNumber(int len);
};


