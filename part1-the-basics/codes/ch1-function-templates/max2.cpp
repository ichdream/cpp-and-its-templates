// part1 function templates
// 1.5 overloading funtion templates
#include<iostream>

// naximum of two int values
int max(int a, int b)
{
    return b < a ? a : b;
}

// maximum of two values of any type'
template<typename T>
T max(T a, T b)
{
    return b < a ? a : b;
}

int main()
{
    std::cout << "calls the nontemplate for two ints" << "\n";
    std::cout << "::max(7, 42): " << ::max(7, 42) << "\n";

    std::cout << "calls max<double>(by argument deduction)" << "\n";
    std::cout << "::max(7.1, 42.1): " << ::max(7.1, 42.2) << "\n";

    std::cout << "calls max<char>(by argument deduction)" << "\n";
    std::cout << "::max('a', 'b'):  " << ::max('a', 'b') << "\n";

    std::cout << "calls max<int>(by argument deduction)" << "\n";
    std::cout << "::max<>(7, 42):   " << ::max(7, 42) << "\n";

    std::cout << "calls max<double>(no argument deduction)" << "\n";
    std::cout << "::max<double>(7, 42): " << ::max<double>(7, 42) << "\n";

    std::cout << "calls the nontemplate for two ints" << "\n";
    std::cout << "::max('a', 42.7): " << ::max('a', 42.7) << std::endl;
}