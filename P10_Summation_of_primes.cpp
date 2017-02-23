/**
* Title : Get Sum of First N Primes
* Description:
* Input: First line number T ,Number of test cases. Next each line contain of number N.
* 1 < N < 10^12
*
* Refer Problem: https://projecteuler.net/problem=10 
*               https://www.hackerrank.com/contests/projecteuler/challenges/euler010
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

// Vector contain primes only.
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
                if(numbuff[idx] ==0){  
                        primes.push_back(uint64_t(idx));
                }
        }


        // find sum of prime
        for(int idx =0 ;idx < c; idx ++ ){
                        uint64_t  tmp, sum=0;
                        cin>>tmp;
                        for(vector<uint64_t>::iterator it=primes.begin() ; it != primes.end() ; it++ ){
                                if((*it) > tmp )
                                        break;
                                sum =sum + (*it);
                        }
                        cout<<sum<<endl;
                      
        }

        return 0;
}

