#ifndef TEST
#define TEST
#include <iostream>

#ifndef TEST_H
#define TEST_H

template<typename T>
void equals(const T& expected, const T& actual, const std::string& testMsg)
{
    if(expected == actual) 
        std::cout << "SUCCESS: " << testMsg << std::endl;
    else
        std::cout << "FAILED: " << testMsg << std::endl;
}

#endif /* TEST_H */


#endif /* TEST */
