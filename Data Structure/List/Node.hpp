#include<iostream>
using namespace std;
class Node{
    private:
        int data;
        Node *next;
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node *next){
            this->data = data;
            this->next = next;
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
        Node *getNext(){
            return this->next;
        }
};
