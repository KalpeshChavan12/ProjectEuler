/**

Description: The sum of the squares of the first ten natural numbers 
             First line contains 'T' , the number of test cases. This is followed by 'T' lines each containing an integer N

             Sum of square computed using arithmetic progression
             Sq = N * ( N + 1 ) * (2N + 1) /6
             S = N * (N+1) / 2
             
Problem: https://projecteuler.net/problem=6

*/
#include <iostream>
#include <stdint.h>
using namespace std;

int main(){
        int count;
        cin>>count;
        for ( int idx=0; idx < count ;idx ++ ) {
                uint64_t num;
                cin>>num;
                uint64_t sqsum, sum;
                sqsum= ( num * (num +1 ) * (2*num + 1 ) ) / 6;
                sum = ( num * (num +1 ) ) /2;
                cout<<((sum*sum) - sqsum)<<endl;
        }
}
