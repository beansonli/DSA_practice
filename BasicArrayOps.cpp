/*******************************************************************************
 Basic Arrays stoof

*******************************************************************************/

#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX], n;

void insertBeg(){
    int val;
    cout<<"Enter element to insert: ";
    cin>>val;
    
    n++;
    for(int i=n-1; i>0; i--){
        arr[i]=arr[i-1];
    }
    arr[0]=val;

}

void insertPos(){
    int val, pos;
    cout<<"Enter element to insert: ";
    cin>>val;
    cout<<"Enter position to insert: ";
    cin>>pos;
    
    n++;
    for(int i=n-2; i>=pos-1; i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=val;
}

void insertEnd(){
    int val;
    cout<<"Enter element to insert: ";
    cin>>val;
    n++;
    arr[n-1]=val;
}

void deleteBeg(){
    for(int i=0; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void deletePos(){
    int pos;
    cout<<"Enter position to delete: ";
    cin>>pos;
    
    for(int i=pos-1; i<n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void deleteEnd(){
    n--;
}

void search(){
    int key;
    cout<<"Enter element to search: ";
    cin>>key;
    
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            cout<<"Element found at position "<<i+1<<endl;
        }
    }
}

void Sort(){
    int temp;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void display(){
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int choice;
    cout<<"Enter no. of elements: ";
    cin>>n;
    
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    
    do{
        cout<<"------MENU-----\n> INSERT\n 1. Beginning\n 2. End\n 3. At specific Index\n> DELETE\n 4. Beginning\n 5. End\n 6. At specific Index\n7 > Search\n8 > Sort\n9 > Display\n10 > EXIT"<<endl;;
        cin>>choice;
        
        switch(choice){
            case 1:
                insertBeg();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertPos();
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deletePos();
                break;
            case 7:
                search();
                break;
            case 8:
                Sort();
                break;
            case 9:
                display();
                break;
        }
    }while(choice!=10);
    
    
    return 0;
}
