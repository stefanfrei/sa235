#include <iomanip>
#include <iostream>

#include <string>

#include <asio.hpp>


int sq(int &base) {
    return base * base;
}

std::string int_fmt(int in) {
    return std::to_string( in );
}


int main() {
    char const *output = "Hello World!";
    for(int i = 0; i <= 1000; i++) {
        //std::cout << output << std::endl;
        std::cout << std::setw(20) << std::to_string( sq(i) ) << std::endl;
    }
    return 0;
}