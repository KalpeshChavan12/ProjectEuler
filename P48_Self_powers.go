/*

Description: Compute the sum of self power
             e.g. 
             S = 1^1 + 2^2 + 3^3 ....... + N^N

Problem: https://projecteuler.net/problem=48

Input: 
   first line Contain N.

*/
package main

import ( "fmt"
         "math/big" )

/*
 Function : Power
 Description : Compute X^Y using recurssion. 
 
*/
func Power(base, p big.Int) big.Int{

        zero := big.NewInt(0);
        result := big.NewInt(1);
        tmp := big.NewInt(0);
        tmp1 := big.NewInt(0);
        two := big.NewInt(2);
        one := big.NewInt(1);
        mod_ := big.NewInt(0);

        if one.Cmp(&p) == 0 {
                return base;
        }

        if zero.Cmp(&p) == 0 {
                return *result
        }

        tmp1.Div(&p,two)

        *tmp=Power(base, *tmp1)

        result.Mul(tmp,tmp);

        if mod_.Mod(&p ,two).Cmp(one) == 0 {

                result.Mul(result,&base)
        }

        return *result;



}

func main(){

        var num int
        var sum big.Int;
        _ , err := fmt.Scanf("%d",&num)
        if err !=nil {

        }
        
        // Compute Sum
        for i:= 1; i<= num ; i++ {
                bigN := big.NewInt(int64(i))
                tmp := Power(*bigN,*bigN);
                sum.Add(&sum,&tmp);
        }

        fmt.Println("sum=",sum.String());

}
