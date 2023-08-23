/*
Given an array A[] of N integers, where A[i] denotes the height of ith tree. 
Geek needs to cut down M meters of wood. He has a woodcutting machine that works as follows:  
Set the blade at a height parameter H, and the machine cuts off all trees having a height greater than H. 
The trees having less than height H remains intact.
Since Geek is an environmentalist, he doesn't want to cut woods more than necessary, so he set the height H as high as possible.
Find the maximum height H of the blade that still allows to cutoff at least M meters of wood.
A[] = {20, 15, 10, 17}
M = 7
Output: 15
Explanation: 
Set the height parameter to 15, then Geek can chop:
  1.5 metres from first tree
  2. 0 metres from second tree
  3. 0 metres from third tree
  4. 2 metres from fourth tree
  So in total Geek chopped 5 + 2 = 7 metres of wood.

Input:
A[] = {4, 42, 40, 26, 46}
M = 20
Output: 36
*/

#include <iostream>
#include <algorithm>

int wood_collector( int arr[] , int size , int max_height )
{
    int sum = 0 , wood_collected ;
    for( int i=0 ; i<size ; i++ )
    {
        wood_collected = arr[i] - max_height ;
        if ( wood_collected <= 0 )
            continue ;
        sum += wood_collected ;
    }
    return sum ; 
}

int main()
{
    //int arr[] = {20, 15, 10, 17},target = 7 ;
    int arr[] = {4, 42, 40, 26, 46}, target = 20 ;
    int size = sizeof(arr)/sizeof(int) ;

//Solution 1 
//Time Complexity: O(n^2) , Space Complexity: O(1)
    
    int sum , max_height=0  ;
    std :: sort ( arr , arr + size ) ;
    do
    {
        if( wood_collector( arr , size , max_height )  <= target )
            break ;
        
    } while (++max_height <=  arr[size-1]);

    std :: cout << "Maximum Required Height is: " << max_height ;

//Solution 2
//Time Complexity: O(nlogn) , Space Complexity: O(1)
    
    int start = 0 , end = arr[size-1] ; max_height = start + ((end-start)/2) ;

    while ( start <= end )
    {
        if ( wood_collector( arr , size , max_height )  == target )
        {
            std :: cout << "\nMaximum Required Height is: " << max_height ; 
            break;
        }
        else if( wood_collector( arr , size , max_height )  > target)
            start = max_height + 1 ;
        else 
            end = max_height - 1; 
        max_height = start + ((end-start)/2) ; 
        //std :: cout << "\n" <<start << " " << max_height << " " << wood_collected  ;  
    }


}