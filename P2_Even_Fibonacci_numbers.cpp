/*
* Title: Project Euler #2: Even Fibonacci numbers
* Input: 
*
* First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N . 
* Refer: https://www.hackerrank.com/contests/projecteuler/challenges/euler002
*
* 
*/
#include <iostream>
#include <stdint.h>
using namespace std;
int main(){

        int count;
        cin>>count;

        
        for(int idx=0;idx<count; idx ++ ) {

                uint64_t max  , f1 =1 ,f2=1, sum =0 ;
                cin>> max;
                for (;;){
                        uint64_t tmp=f2+ f1;
                        f1=f2;
                        f2=tmp;
                        if(tmp  >  max )
                                break;
                        if( (tmp %2 ) == 0) {
                                sum =sum + tmp;
                        }

                }
                cout<<sum<<endl;

        }


}
