/**
* Title: Project Euler #13: Large sum
* Input: First line contains N , next N lines contain a 50 digit number each. 
* Output: first ten digit of sum.
*
* Description:  Use math/big package for arbitrary-precision arithmetic 
*
*/

package main

import ( "fmt"
         "math/big" )

func main(){

        var strnum string
        var sum big.Int;
        var count int;
        fmt.Scanf("%d",&count)
        for i:=0 ; i< count ; i++ {
                _ , err := fmt.Scanf("%s",&strnum)
                if err !=nil {
                        break;
                }
                var num, tmp  big.Int
                num.SetString(strnum,10)
                tmp=sum;
                sum.Add(&tmp,&num)

        }

        // Result contain Sum , print only first 10 digit
        result := sum.String();
        if len(result) >= 10 {
                fmt.Println(result[0:10]);
        }

}
