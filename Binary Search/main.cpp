#include<iostream>
using namespace std;

int binary_search(int a[],int n,int x);                     // Find element through iterative
int binary_search(int a[],int n,int x,int high,int low);    // Find element through recursive
int first_last_search(int a[],int n,int x,bool search);     // Find first and last occurence of element
int count_binary_search(int a[],int n,int x);               // Find the no. of occurence of elements
int circular_rotated_binary_search(int a[],int n);          // Find the no. of times array is rotated

int main()
{
    int i=-1,n,x;
    cout<<"Enter numbers of elements ";
    cin>>n;
    int a[n];
    cout<<"\nEnter number in array ";
    
    for(i=0;i<n;++i)
    {
        cin>>a[i];
    }
    
   /* cout<<"\nEnter number to be searched ";
    cin>>x;
    
    int mid=first_last_search(a,n,x,0);
    
    if(mid>=0)
        cout<<"Element found in position "<<mid;
    else 
        cout<<"Element does not found ";
    */
    
   /* int c=count_binary_search(a,n,x);
    if(c>0)
        cout<<"Elements occurence is "<<c;
    else
        cout<<"Element does not found ";
     */
    
    int r=circular_rotated_binary_search(a,n);
    cout<<"Array is rotated "<<r<<" times ";
    return 0;
}


int binary_search(int a[],int n,int x)
{
    int mid,low=0,high=n-1;
    
    while(low<=high)
    {
        mid=low+(high-low)/2;
        
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            high=mid-1;
        else    
            low=mid+1;
    }   
        return -1;
}



int binary_search(int a[],int n,int x,int high,int low)
{
    int mid=low+(high-low)/2;
    
    if(low>high)
        return -1;
    
    if(a[mid]==x)
        return mid;
    
    else if(a[mid]>x)
        return binary_search(a,n,x,mid-1,low);
    
    else    
        return binary_search(a,n,x,high,mid+1);
}


int first_last_search(int a[],int n,int x,bool search)
{
    int mid,low=0,high=n-1,result=-1;
    
    while(low<=high)
    {
        mid=low+(high-low)/2;
        
        if(a[mid]==x)
        {
            result=mid;
            if(search)
                low=mid+1;
            else
                high=mid-1;
        }
        else if(a[mid]>x)
            high=mid-1;
        else    
            low=mid+1;
    }   
        return result;   
}


int count_binary_search(int a[],int n,int x)
{
    int high=first_last_search(a,n,x,1);
    if(high>=0)
    {    
        int low=first_last_search(a,n,x,0);
        return (high-low+1);
    }
    return -1;
}


int circular_rotated_binary_search(int a[],int n)
{
    int mid;
    int low=0,high=n-1;
    
    
    
    int first,next;
    
    while(low<=high)
    {
        mid=low+(high-low)/2;
        first=(mid-1+n)%n;
        next=(mid+1)%n;
        
        if(a[mid]<a[first] && a[mid]<a[next])
            return mid;
        
        else if(a[mid]>=a[low] && a[mid]>=a[high])
            low=mid+1;
        
        else if(a[mid]<=a[high] && a[mid]<=a[low])
            high=mid-1;
        
        else return 0;
    }
}