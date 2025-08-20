#ifndef SHUNTING_YARD_ALGORITHM_H
#define SHUNTING_YARD_ALGORITHM_H

#include <string>

class Solution
{
public:
    int predecesence(char ch);
    std::string infixToPostfix(std::string str);
};

#endif
