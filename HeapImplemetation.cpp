#include<iostream>
#include<vector>

using namespace std;

class heap{
    public:
    int arr[100];
    int size=0;
    
    // Insert function to insert elements into the heap
    void insert(int val){
       size = size + 1;
       int index = size; 
       arr[index] = val;
 
       
       while(index > 1){
           int parent = index / 2;
           if(arr[parent] < arr[index]){
               swap(arr[parent], arr[index]);
               index = parent;
           }            
           else{
               return;
           }
       }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }

   
    void deletefromHeap(){
        if(size == 0){
            return ;
        }
        arr[1] = arr[size];
        size--;
 
        int i = 1;                                       
       
        while(i <= size){
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if(leftindex <= size && arr[i] < arr[leftindex]){
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex <= size && arr[i] < arr[rightindex]){
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }
        }
    }
};


void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main(){ 
    heap h;
    
    // Insert elements into the heap and print the heap after each insertion
    h.insert(50);
    h.insert(55);
    h.insert(52);
    h.insert(59);
    h.insert(49);
    cout << "Heap after insertions: ";
    h.print(); 
   
    // Delete the root element and print the heap after deletion
    h.deletefromHeap();
    cout << "Heap after deletion: ";
    h.print();

    // Array to demonstrate heapify (index 0 is ignored)
    int arr[10] = {-1, 10, 50, 80, 90, 40, 10,11,110,120 };
    int n = 10;

    // Apply heapify to the array and print the result
    for(int i = n/2 - 1; i >= 1; i--){
        heapify(arr, n, i);
      
    }

    cout << "Array after applying heapify: ";
    for(int i = 1; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
