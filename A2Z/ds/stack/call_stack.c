// in a program the compiler keeps track of functions by putting them on a stack when a function is called say A()
// it's pushed to the stack then B() then C(). Now when the function C() finishes then it's popped then B() and 
// finally A(). The functions get over in that order cause if A() is running and we call B() then it's essentailly
// like saying pause A() first go finish B() then return to A(). the stack in which these are stored is called the 
// CALL STACK -> stack of STACK FRAMES 

// STACK FRAMES -
// stores everything a function needs while running - 1. arguments 2. local variables 3. return address(where to go 
// after funciton finishes executing)

#include <stdio.h>

int factorial(int n) {
    int result;  // allocated on stack for each call
    if (n == 0) {
        return 1;
    }
    result = n * factorial(n - 1);
    return result;
}

int main() {
    printf("%d\n", factorial(3));
    return 0;
}
 
/*

  stack frame pushed in call stack -> factorial(0) (when fact(1) calls fact(0)) contains 
  argument = 0 | result = = uninitilized  

returns 1 and top gets popped 

  stack frame pushed in call stack -> factorial(1) (when fact(2) calls fact(1)) contains 
  argument = 1 | result = uninitilized 

gets result 1 from above then result = 1 * 1 returns result = 1 and get's popped 

  stack frame pushed in call stack -> factorial(2) (when fact(3) calls fact(2)) contains
  argument = 2 | result = uninitilized

gets result 1 from above then result = 2 * 1 returns result = 2 and get's popped 

  stack frame pushed in call stack -> factorial(3) (when main calls factorial 3) contians 
  argument = 3 | result= uninitilized

gets result 2 from above then result = 3 * 2 returns result = 6 and get's popped 
*/