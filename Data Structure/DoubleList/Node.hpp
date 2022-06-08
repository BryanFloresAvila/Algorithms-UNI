#include <iostream>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
        Node *prev;
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
        void setData(int data){
            this->data = data;
        }
        int getData(){
            return this->data;
        }
        void setNext(Node *next){
            this->next = next;
        }
        Node* getNext(){
            return this->next;
        }
        void setPrev(Node *prev){
            this->prev = prev;
        }
        Node* getPrev(){
            return this->prev;
        }
};