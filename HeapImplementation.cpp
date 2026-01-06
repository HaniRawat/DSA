#include<iostream>
#include<algorithm>
using namespace std;

class Heap{
    public:
    int size;
    int arr[100];

    Heap(){
        size = 0;
        arr[0] = -1;
    }
    
    void InsertInHeap(int val){
        size++;

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
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;  
    }

};

int main(){
    Heap hp;
    hp.InsertInHeap(50);
    hp.InsertInHeap(55);
    hp.InsertInHeap(53);
    hp.InsertInHeap(52);
    hp.InsertInHeap(54);

    hp.print();
    return 0;
}