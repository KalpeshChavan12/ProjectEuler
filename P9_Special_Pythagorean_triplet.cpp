/*****************

Description: Special Pythagorean triplet

Problem: https://projecteuler.net/problem=9
         A Pythagorean triplet is a set of three natural numbers a, b ,c  where a+b+c=1000 and a^2 + b^2 = c^2


Answer: 200 375 425

*******************/

#include <iostream>
#include <map>

#define M 1000

using namespace std;

map<int,int> perfsq;

// Mark Perfect square
void init(){
        for(int i =0;i<M;i++){
                perfsq[i*i]=i;
        }
}

int main(){
        init();
        
        // find triplate using
        for(int i=1;i<M;i++){
                for(int j=1; j<M ; j++){
                   int sq = perfsq[(i*i)+(j*j)];
                   if(sq) {
                        
                         // check sum is 1000
                         if((i+j+sq) ==1000)
                             cout<<" "<<i<<" " <<j<<" "<<sq<<endl;

                   }
                }
        }

}
