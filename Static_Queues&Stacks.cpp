/******************************************************************************
Static queue and stacks implementation 

*******************************************************************************/

#include <iostream>
using namespace std;

#define MAX 100

class queue{
    int arr[MAX], start, rear;
    
    public:
    queue(){
        start=rear=-1;
    }
    
    bool isFull(){
        return rear==MAX-1;
    }
    
    bool isEmpty(){
        if(rear==-1 || start>rear)
            return true;
        else
            return false;
    }
    
    void enqueue(int x){
        if(isFull())
            cout<<"Queue Overflow!"<<endl;
        else{
            start=0;
            rear++;
            arr[rear]=x;
        }
    }
    
    void dequeue(){
        if(isEmpty())
            cout<<"Queue Underflow!"<<endl;
        else{
            for(int i=0; i<rear; i++){
                arr[i]=arr[i+1];
            }
            rear--;
        }
    }
    
    void display(){
        if(isEmpty())
            cout<<"Queue Empty!"<<endl;
        else{
            for(int i=0; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    void peek(){
        if(isEmpty())
            cout<<"Queue Empty!"<<endl;
        else
            cout<<"Top element: "<<arr[start]<<endl;
        
    }
    
    void size(){
        cout<<"Queue size: "<<rear+1<<endl;
    }
    
    
    
};

class stack{
    int arr[MAX], top;
    
    public:
    
    stack(){
        top=-1;
    }
    
    bool isFull(){
        return top==MAX-1;
    }
    
    bool isEmpty(){
        return top==-1;
    }
    
    void push(int x){
        if(isFull())
            cout<<"Stack Overflow!"<<endl;
        else{
            top++;
            arr[top]=x;
        }
    }
    
    void pop(){
        if(isEmpty())
            cout<<"Stack Underflow!"<<endl;
        else
            top--;
        
    }
    
    void peek(){
        if(isEmpty())
            cout<<"Stack Empty!"<<endl;
        else
            cout<<"Last Element: "<<arr[top]<<endl;
    }
    
    void display(){
        if(isEmpty())
            cout<<"Stack Empty!"<<endl;
        else{
            for(int i=0; i<=top; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    };
};


int main()
{
    cout<<"---Queues---"<<endl;
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
    
    cout<<"---Stacks---"<<endl;
    stack s;
    s.push(4);
    s.push(48);
    s.peek();
    s.pop();
    s.peek();
    s.push(54);
    s.push(87);
    s.display();
    
    
    return 0;
}
