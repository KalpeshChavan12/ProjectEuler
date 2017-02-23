/**
* Build
* gcc -c P3_Largest_prime_factor.cpp -o P3_Largest_prime_factor
*
* Run
* $ ./P3_Largest_prime_factor
*
* Description: 
* First line contains 'T' , the number of test cases. This is followed by 'T' lines each containing an integer N
* 
* 1 < N < 10^12
*
* e.g.
* Input
* 2
* 15
* 13
* Output 
* 5
* 13
*
*
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <stdint.h>
#include <algorithm>
using namespace std;
#define MAX_PRIME 1000010

/* buffer to compute primes using sieve of Eratosthenes 
*  Refer: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
*/
char numbuff[MAX_PRIME];

// vector constist of primes only
vector<int> primes;

/** 
* Function: getfactors
* Args: 
*     num  : input number
*     facts:  return the factors for number
*
*/
void getfactors(uint64_t num, vector<uint64_t> &facts){
        uint64_t sq=sqrt(num);
        sq=sq+1;
        int flag = 0;
        for(vector<int>::iterator it=primes.begin() ; it != primes.end() ; it++ ){
                if( (num%(*it)) == 0 ) {
                        uint64_t fact2 = num / (*it);

                        if(fact2 < MAX_PRIME && numbuff[fact2] == 0 )
                                facts.push_back(fact2);
                        else
                                getfactors(fact2, facts);
                        facts.push_back(*it);
                        flag = 1;
                        break;

                }
                if(((int)sq) < *it) {
                        break;
                }

        }
        if(flag == 0)
                facts.push_back(num);

}
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
                        /*cout<<idx<<endl; */
                        primes.push_back(idx); 
                        }
        }

        /*
        * compute  factors for each number and find max from factors
        */
        for(int idx =0 ;idx < c; idx ++ ){
               uint64_t tmp;
               cin>>tmp;
               vector<uint64_t> v;
               getfactors(tmp,v);
               if(v.size() != 0)
                  std::make_heap(v.begin(),v.end());
               else
                  v.push_back(tmp);
               cout<<v.front()<<endl;
       }

        return 0;
}
