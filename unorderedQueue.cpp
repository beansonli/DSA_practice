/******************************************************************************
Static queue implementation for unordered stuff

*******************************************************************************/

#include <iostream>
using namespace std;

#define MAX 100

class queue{
    int arr[MAX], start;
    
    public:
    queue(){
        start=-1;
    }
    
    bool isFull(){
        return start==MAX;
    }
    
    bool isEmpty(){
        return start==-1;
    }
    
    void enqueue(int x){
        if(isFull())
            cout<<"Queue Overflow!"<<endl;
        else{
            start+=1;
            arr[start]=x;
        }
    }
    
    void dequeue(){
        if(isEmpty())
            cout<<"Queue Underflow!"<<endl;
        else{
            for(int i=0; i<start; i++){
                arr[i]=arr[i+1];
            }
            start--;
        }
    }
    
    void display(){
        if(isEmpty())
            cout<<"Queue Empty!"<<endl;
        else{
            for(int i=0; i<=start; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    void peek(){
        if(isEmpty())
            cout<<"Queue Empty!"<<endl;
        else
            cout<<"Top element: "<<arr[0]<<endl;
        
    }
    
    void size(){
        cout<<"Queue size: "<<start+1<<endl;
    }
    
    
    
};

int main()
{
    queue q1;
    q1.enqueue(2);
    q1.enqueue(5);
    q1.enqueue(212);
    q1.size();
    q1.peek();
    q1.dequeue();
    q1.size();
    q1.peek();
    q1.enqueue(54);
    q1.display();
    
    return 0;
}
