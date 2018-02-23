/* AUTHOR -- code_blooded */

/**
*
*   This program aims at implementing iterative ceil binary search.
* 
*   Ceil binary search returns the index(0-indexed) of element greater than x in a sorted array.
*   eg: arr = [10, 22, 29, 33, 50, 60, 80] then if x = 32 returns 3.
* 
*/

#include <bits/stdc++.h>
using namespace std;

// returns the index of element greater than x in the array 
// if all elements are greater than x returns high+1
int ceilBinarySearch(int arr[],int low,int high,int x){
    if(x<arr[low]){
        return low;
    }else if(x>arr[high]){
        return high+1;
    }
    int l = low;
    int r = high;
    int m = low;
    while(l<r){
        m = l + (r-l)/2;
        if(arr[m]<x)                  l = m+1;
        else if(arr[m]>x)             r = m;
        else                          l = m+1;
    }
    return r;
}

int main(){
    
    // Scanning Input
    int n,x;
    cout<<"Enter the no of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter x\n";
    cin>>x;
    
    cout<<"The index of the element greater than x is ";
    cout<<ceilBinarySearch(arr,0,n-1,x);
    cout<<"\n";
    
    return 0;
}
