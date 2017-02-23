/**
* Title: Multiples of 3 and 5
* Description: Solve problem using Inclusion Exclusion principle 
*              Refer: https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle
*              S = SumOfDivisibleBy(3) +  SumOfDivisibleBy(5) -  SumOfDivisibleBy(15)
*
*              Compute Sum using arithmetic progression
*              S(n) = n(n+1) / 2
*
* Input:
*     First line T contains that denotes the number of test cases. This is followed by T lines, each containing an integer, N . 
*  
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   
    uint64_t  count;
    cin>>count;
    for (int i=0;i<count;i++){
        uint64_t num;
        cin>>num;
        num--;
        uint64_t tmp;

        uint64_t mul3 ,mul5 , mul15;

        // SumOfDivisibleBy(3)
        tmp= num/3;
        mul3= 3 * ( ( tmp * (tmp +1) ) / 2) ;

        // SumOfDivisibleBy(5)
        tmp= num/5;
        mul5= 5  * ( ( tmp * (tmp +1) ) / 2) ;

        // SumOfDivisibleBy(15)
        tmp= num/15;
        mul15= 15 *( ( tmp * (tmp +1) ) / 2);

        cout <<mul3+mul5 -mul15 <<endl;
    }
    return 0;

}
