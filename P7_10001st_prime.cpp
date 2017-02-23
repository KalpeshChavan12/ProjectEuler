/**
*
* Description: 
* First line contains 'T' , the number of test cases. This is followed by 'T' lines each containing an integer N
* 
* Problem: https://projecteuler.net/problem=7
*          https://www.hackerrank.com/contests/projecteuler/challenges/euler007
* 
*
*/


#include <iostream>
#include <cmath>
#include <vector>
#include <stdint.h>
using namespace std;
#define MAX_PRIME 1000010

/* buffer to compute primes using sieve of Eratosthenes 
*  Refer: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/
char numbuff[MAX_PRIME];

// vector constist of primes only
vector<uint64_t> primes;

int main(int argc , char ** argv){

        int count=MAX_PRIME;

        int c;
        cin>> c;
        
        // mark non primes as 1        
        for(int idx=2;idx < count ;idx++){
                int tmp=count/idx;
                for (int j=2; j<=tmp  ;j++ ){
                        numbuff[j*idx]=1;
                }
        }
        
        // extract prime and push them to primes vector
        for(int idx=2;idx < count ;idx++) {
                if(numbuff[idx] ==0)
                        {  primes.push_back(uint64_t(idx)); }
        }

       //  Get Nth prime number
       for(int idx =0 ;idx < c; idx ++ ){
                        int  tmp;
                        cin>>tmp;
                        if(tmp < primes.size())
                            cout<<primes[tmp-1]<<endl;
                        
       }

        return 0;
}

