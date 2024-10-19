class Solution{
public:
    int heapHeight(int N, int arr[]){
       if(N == 0){
           return 0;
       }
       return (int)log2(N);
    }
};