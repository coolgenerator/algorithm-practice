#include <iostream>
#ifndef TEST_H
#define TEST_H
#define RED_ON "\033[1;31m"
#define GREEN_ON "\033[1;32m"
#define COLOR_OFF "\033[0m"
template <typename T>
void testEquals(const T &expected, const T &actual, const std::string
&testMsg)
{
if (expected == actual)
std::cout << '\t' << GREEN_ON << "SUCCESS: " << COLOR_OFF <<
testMsg << std::endl;
else
std::cout << '\t' << RED_ON << "FAILED: " << COLOR_OFF << testMsg
<< std::endl;
}
void testTrue(bool expected, const std::string &testMsg)
{
if (expected)
std::cout << '\t' << GREEN_ON << "SUCCESS: " << COLOR_OFF <<
testMsg << std::endl;
else
std::cout << '\t' << RED_ON << "ERROE: " << COLOR_OFF << testMsg
<< std::endl;
}
void testFalse(bool expected, const std::string &testMsg)
{
if (!expected)
std::cout << '\t' << GREEN_ON << "SUCCESS: " << COLOR_OFF <<
testMsg << std::endl;
else
std::cout << '\t' << RED_ON << "ERROE: " << COLOR_OFF << testMsg
<< std::endl;
}
void testSuccess(const std::string &testMsg)
{
std::cout << '\t' << GREEN_ON << "SUCCESS: " << COLOR_OFF << testMsg
<< std::endl;
}
void testFail(const std::string &testMsg)
{
std::cout << '\t' << RED_ON << "ERROE: " << COLOR_OFF << testMsg << std::endl;
}
#endif /* TEST_H */