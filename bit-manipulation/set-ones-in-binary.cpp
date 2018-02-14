/* AUTHOR -- code_blooded */

/**
*
*	This program aims at counting the no of set bits of an integer in binary representation.
*
*/

/**
*
*   HINT: x & (x-1) unsets the rightmost bit. Why ? 
*   Where & represents AND operation.
* 
*/

int count_set_bits(int n){
    if(n==0)                            // base case
        return 0;
    return 1+count_set_bits(n&(n-1));
}

#include <bits/stdc++.h>
using namespace std;

int main(){

    int temp,n,ans=0;
    
    cout<<"Enter the number \n";
    cin>>n;
    
    cout<<"No of set bits in "<<n<<" is "<<count_set_bits(n)<<endl;
    
    // NOTE: You can also use the inbuilt GCC function __builtin_popcount()
    cout<<"No of set bits(using inbuilt func) is "<<__builtin_popcount(n)<<endl;
    
    return 0;
}