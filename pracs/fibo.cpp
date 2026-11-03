#include <iostream>
using namespace std;

class Fibonacci{
    public:
    int n;

    Fibonacci(){
        n=0;
    }

    void getn(){
        cout<<"enter n"<<endl;
        cin>>n;
        if(n<0){
            cout<<"Enter Valid Number!"<<endl;
        }
    }

    void iterative(){
        int a=0;
        int b=1;
        if(n==0){
            cout<<"0"<<endl;
        }
        else if(n==1){
            cout<<"0 1"<<endl;
        }
        else{
            cout<<"0 1 ";
            for(int i=0;i<=n-2;i++){
                int c=a+b;
                cout<<c<<" ";
                a=b;
                b=c;
            }
            cout<<endl;
        }
    }

    int recursive(int num){
        if(num==0){
            return 0;
        }
        else if(num==1){
            return 1;
        }
        else{
            return recursive(num-2)+recursive(num-1);
        }
    }

    void printRecursive() {
        cout << "Fibonacci Series (Recursive): ";

        for(int i = 0; i <= n; i++) {
            cout << recursive(i) << " ";
        }

        cout << endl;
    }



};

int main(){

    Fibonacci fibo;
    fibo.getn();
    fibo.iterative();
    fibo.printRecursive();
    return 0;
}

/*
Final complexity
Approach	Time complexity	Space complexity
Iterative	O(N)	        O(1)
Recursive	O(2ⁿ)	        O(N)


iterative cals one fibo num exactly once.
Recursion is useful when a problem can naturally be divided into smaller instances of the same problem

*/