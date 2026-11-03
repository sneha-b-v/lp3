#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class quicksort{

    public:
    int n;
    vector<int> arr1;
    vector<int> arr2;
    int comparisons;
    int random_comparisons;
    quicksort(){
        n=0;
        comparisons=0;
        random_comparisons=0;
    }

    int getter(){
        cout<<"Enter size of array:"<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cout<<"Enter element:"<<endl;
            cin>>a;
            arr1.push_back(a);
        }
        arr2=arr1;
    }

    int partition( vector<int> &arr, int low, int high){
        int pivot= arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            comparisons++;
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
                
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }

    int random_partition(vector<int> &arr, int low, int high){
        int random= low + rand() % (high-low+1);
        swap(arr[random],arr[high]);
        int pivot= arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            random_comparisons++;
            if(arr[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[high]);
        return i+1;
    }

    void rqsort(vector<int> &arr, int low, int high){
        if(low<high){
            int p= random_partition(arr,low,high);
            rqsort(arr,low,p-1);
            rqsort(arr,p+1,high);
        }              
    }
    void qsort(vector<int> &arr, int low, int high){
        if(low<high){
            int p= partition(arr,low,high);
            qsort(arr,low,p-1);
            qsort(arr,p+1,high);
        }              
    }
    void qs(){
        qsort(arr1,0,n-1);
        rqsort(arr2,0,n-1);
    }

    void print(){
        for(int i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        cout<<" deterministic comparisons "<<comparisons<<endl;
        cout<<"============"<<endl;
        for(int i=0;i<n;i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
        cout<<" randomized comparisons "<<random_comparisons<<endl;
    }

};

int main(){
    quicksort q;
    q.getter();
    q.qs();
    q.print();
    return 0;
}

    //pivot = arr[high]
    //i=low-1;
    //j=low;j<high
    //comp++
    //if(arr[j]<=pivot)
    //i++
    //swap arr[i]arr[j]

    //come outa loop
    //swap arr[i+1] arr[high]
    //return i+1

/*

Case	Deterministic	Randomized (expected)
Best	O(n log n)	O(n log n)
Average	O(n log n)	O(n log n)
Worst	O(n²)	    O(n²)

*/