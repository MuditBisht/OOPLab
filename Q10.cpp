#include <iostream>
using namespace std;

template <class T>
class LinkedList{
    template <class T1>
    class LinkedListNode{
        public:
            T1 data;
            LinkedListNode<T1>* nxt;
    };
    LinkedListNode<T>* start;
public:
    LinkedList(){
        start = NULL;
    }
    void insert_Beginning(T data){
        LinkedListNode<T>* node = new LinkedListNode<T>;
        node->data = data;
        node->nxt = start;
        start = node;
    }
    void insert_End(T data){
        LinkedListNode<T>* node = new LinkedListNode<T>;
        node->data = data;
        if(start==NULL)
            start = node;
        else{
            LinkedListNode<T>* tmp  = start;
            while(tmp->nxt!=NULL)
                tmp = tmp->nxt;
            tmp->nxt = node;
        }
    }
    void insert_Index(T data,int index){
        LinkedListNode<T>* node = new LinkedListNode<T>;
        node->data = data;

        if(index==0){
            insert_Beginning(data);
            return;
        }

        index--;

        LinkedListNode<T>* tmp = start;
        while(index && tmp!=NULL){
            tmp=tmp->nxt;
            index--;
        }

        if(tmp==NULL){
            cout << "\nInvalid position\n";
            return;
        }
        
        node->nxt = tmp->nxt;
        tmp->nxt = node;   
    }
    T at_start(){
        if(start!=NULL)
            return start->data;
        return (T)-1;
    }
    void delete_Beginning(){
        if(start!=NULL){
            LinkedListNode<T>* tmp =  start;
            start = start->nxt;
            delete tmp;
        }else
            cout << "LinkedList is empty.";
    }
    void delete_End(){
        if(start==NULL)
            cout << "LinkedList is empty.";
        else if(start->nxt==NULL)
            delete_Beginning();
        else{
            LinkedListNode<T>* tmp =  start;
            while(tmp->nxt->nxt!=NULL)
                tmp = tmp->nxt;
            delete tmp->nxt;
            tmp->nxt = NULL;
        }
    }
    void delete_Index(int index){
        if(start==NULL){
            cout << "\nLinked list is empty.\n";
            return;
        }

        if(index==0)
            delete_Beginning();
        else{
            index--;
            LinkedListNode<T>* tmp = start;
            LinkedListNode<T>* t;
            while(index && tmp->nxt!=NULL){
                tmp = tmp->nxt;
                index--;
            }
            if(tmp->nxt==NULL){
                cout << "\nEnter valid index to delete from.\n";
                return;
            }
            t = tmp->nxt;
            tmp->nxt = tmp->nxt->nxt;
            delete t;
        }
    }
    int size(){
        int c = 0;
        LinkedListNode<T>* tmp =  start;
        while(tmp!=NULL){
            c++;
            tmp = tmp->nxt;
        }
        return c;
    }
    void print(){
        LinkedListNode<T>* tmp = start;
        cout << "\nData in Linked List - ";
        while(tmp!=NULL){
            cout << tmp->data << "  ";
            tmp = tmp->nxt;
        }
        cout << endl;
    }
};


int main(){
    LinkedList<int> L;
    
    int C=1;
    while(C){
        int data,index;
        cout << "\n\n0. Exit.\n1. Insert at beginning.\n2. Insert at end.\n3. Insert at any index\n4.Delete from beginning.\n5. Delete from end.\n6. Delete from any index.\n7. Print data at start.\n8. Print Linked List.";
        cout << "\nEnter Choice - ";
        cin >> C;

        switch(C){
            case 0:
                break;
            case 1:
                cout << "\nEnter data - ";
                cin >> data;
                L.insert_Beginning(data);
                break;
            case 2:
                cout << "\nEnter data - ";
                cin >> data;
                L.insert_End(data);
                break;
            case 3:
                cout << "\nEnter data and index -";
                cin >> data >> index;
                L.insert_Index(data, index);
                break;
            case 4:
                L.delete_Beginning();
                break;
            case 5:
                L.delete_End();
                break;
            case 6:
                cout << "\nEnter index to delete from - ";
                cin >> index;
                L.delete_Index(index);
                break;
            case 7:
                cout << "\nData at start - " << L.at_start();
                break;
            case 8:
                L.print();
                break;
            default:
                cout << "\nInvalid choice. Enter valid choice.\n";
                break;
        }
    }
    return 0;
}