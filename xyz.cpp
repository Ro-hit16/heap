#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class heapp{
    public:
    int arr[100];
    int size;

    heapp(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1;
        int index =size;
        arr[index]=val;
     
        if(index > 1){
          int parent = index/2;
          if(arr[parent] < arr[index]){
            swap(arr[parent],arr[index]);
            index = parent;
          } 
          else{
            return ;

          }
        }
    }

    void deleteEle(){
        if(size ==0){
            return ;
        }
        arr[1] =arr[size];

        int i =1;
        while (i<=size){
          int left =2*1;
          int right =2*i+1;

          if(left <= size && arr[left]>arr[i]){
           swap(arr[left],arr[i]);
           i=left; 
          }
          else if(right <= size && arr[right]> arr[i]){
            swap(arr[right],arr[i]);
            i=right;
          }
          else{
            return;
          }
        }
    }

    void heapify(int arr[],int n,int i){
        int largest = i;
        int left =2*i;
        int right = 2*i+1;

        if(left <n && arr[left]>arr[i]){
            largest = left;

        }
        if(right < n && arr[right]>arr[i]){
            largest = right;
        }

        if(largest  != i){
            swap(arr[i],arr[largest]);
        }
    }
}
int main(){

return 0;
}