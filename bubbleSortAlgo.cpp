//In bubble short algo we repeatdly swap the elememts till they are not arranged in a correct order.
// 20 50 40 10 30
// 20 40 50 10 30
// 20 40 10 50 30 
// 20 40 10 30 50
//pass 1 complete
// 20 40 10 30 50
// 20 10 40 30 50
// 20 10 30 40 50
//pass 2 complete
// 20 10 30 40 50 
// 10 20 30 40 50
//pass 3 complete
// 10 20 30 40 50
//pass 4 complete


//***[n(n-1)/2] swaps needed in worst case // (when arr is in decending order then it will be the worst case)
// time complexity of the code is  O(n.^2)


/*
Types of bubble sort algorithm
1. Stable:- Does not disturb the order of elements with same value.
2. Unstable:- It disturbs all the elements (we usually avoids it.)
*/
#include<iostream>
using namespace std;
void bubblesort(int *arr,int n){
    
    for(int i=0;i<=n-1;i++){
        bool flag = false;
        for(int j=0;j<=n-2-i;j++){
            if(arr[j]>arr[j+1]){
                flag = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!flag){
            break;
        }
    }
    return ;
}
int main(){
    int arr[]={20,50,40,10,30};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubblesort(arr,n);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
