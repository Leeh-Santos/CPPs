# pragma once

# include <iostream>
# include <stack>
#include <bits/stdc++.h>

class rpn{
 
    public:
    
    static void validString(const std::string);
    //bool charCheck(const std::string);
    static bool isOp(const char c);
    static void   dale(const std::string);
    static int calculator(int, int, char);
};