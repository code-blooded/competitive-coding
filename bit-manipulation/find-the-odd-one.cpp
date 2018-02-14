/* AUTHOR -- code_blooded */

/**
*
*	This program aims at finding the element that occurs only once in an array, given all others occur twice.
*
*/

/**
*
*   HINT: Use the property a^a=0 and b^0=b.
*   Where ^ represents XOR operation.
* 
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int temp,n,ans=0;
    
    cout<<"Enter the no of numbers: \n";
    cin>>n;
    cout<<"Enter the numbers \n";
    for(int i=0;i<n;i++){
        cin>>temp;
        ans^=temp;
    }
    cout<<ans<<endl;
    
    return 0;
}
