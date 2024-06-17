
#include <iostream>
using namespace std;
void bitmanupulation(int start,int goal){
    int number = start ^ goal;
    int count=0;
    while(number!=0){
        if(number%2==1){
            count++;
        }
        number = number/2;
    }
    cout<<"Number of bits to flip is : "<<count<<endl;
}
int main() {
    int start = 10;
    int goal = 22;
    bitmanupulation(start,goal);
    return 0;
}
