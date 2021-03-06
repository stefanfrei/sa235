#include <iostream>
#include <string>

class Banker {

    private:
        int age;
        std::string name;


    public:

        int getAge() { return age; }

        void setAge(int a) {
            age = a;
        }


        std::string getName() { return name; }

        void setName(std::string n) {
            name = n;
        }
        
};


template <class T>
T sum (T a, T b) {
    return a + b;
}

int main() {
    Banker rothschild;
    rothschild.setName("Rothschild");
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(1.2f, 2.2f) << std::endl;
}