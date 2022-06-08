#include <iostream>
#include "Node.hpp"
using namespace std;
class DoubleList{
    Node* head;
    Node* tail;
    public:
        DoubleList(){
            this->head = NULL;
            this->tail = NULL;
        }
        void createList(){
            int data;
            do{
                cout<<"Enter the data: ";
                cin>>data;
                if(data != -1) insertAtHead(data);
            }while(data != -1);
        }
        void insertAtHead(int data){
            Node* newNode = new Node(data);
            if(head!=NULL){
                newNode->setNext(head);
                head->setPrev(newNode);
                head = newNode;
            }
            else{
                head = newNode;
                tail = newNode;
            }
        }
        void insertAtTail(int data){
            Node* newNode = new Node(data);
            if(tail!=NULL){
                tail->setNext(newNode);
                newNode->setPrev(tail);
                tail = newNode;
            }
            else{
                head = newNode;
                tail = newNode;
            }
        }
        void printList(){
            Node* indice = this->head;
            for (indice=head;indice!=NULL;indice=indice->getNext())
                cout<<indice->getPrev()<<"\t"<<indice<<"\t"<<indice->getData()<<"\t"<<indice->getNext()<<endl;
        }
        Node* findNode(int data){
            Node* indice;
            for (indice=head;indice!=NULL;indice=indice->getNext())
                if(indice->getData()==data) return indice;
            return NULL;
        }
        void insertAfter(int prevData,int data){
            Node* newNode = new Node(data);
            Node* previous = findNode(prevData);
            if(previous==NULL) return;
            if(previous->getNext()!=NULL){
                newNode->setNext(previous->getNext());
                previous->getNext()->setPrev(newNode);
                previous->setNext(newNode);
                newNode->setPrev(previous);
            }
            else{
                newNode->setPrev(previous);
                previous->setNext(newNode);
                tail = newNode;
            }
        }
        void deleteNode(int data){
            Node* indice = findNode(data);
            if(indice!=NULL){
                if(indice==head){
                    head = indice->getNext();
                    head->setPrev(NULL);
                }
                else if(indice==tail){
                    tail = indice->getPrev();
                    tail->setNext(NULL);
                }
                else{
                    indice->getPrev()->setNext(indice->getNext());
                    indice->getNext()->setPrev(indice->getPrev());
                }
            }
            delete indice;
        }
        void insertBefore(int nextData,int data){
            Node* newNode = new Node(data);
            Node* next = findNode(nextData);
            if(next==NULL) return;
            if(next->getPrev()!=NULL){
                newNode->setNext(next);
                newNode->setPrev(next->getPrev());
                next->getPrev()->setNext(newNode);
                next->setPrev(newNode);
            }
            else{
                newNode->setNext(next);
                next->setPrev(newNode);
                head = newNode;
            }
        }
        void inverseList(){
           /**/
        }
        void sortList(){
            int temp;
            Node* first = head;
            Node* indice;
            Node* last = tail;

            while (first!=last){
                for (indice=first;indice!=last;indice=indice->getNext())
                    if(indice->getData()>indice->getNext()->getData()){
                        temp = indice->getData();
                        indice->setData(indice->getNext()->getData());
                        indice->getNext()->setData(temp);
                    }
                last = last->getPrev();
            }
        }
};