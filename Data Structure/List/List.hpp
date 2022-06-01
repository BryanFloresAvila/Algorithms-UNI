#include<iostream>
#include "Node.hpp"
class List{
    private:
        Node* first;
    public:
        List(){
            this->first = NULL;
        }
        void createList(){
            int data;
            do{
                cout<<"Enter a value: ";
                cin>>data;
                if(data!=-1) insertInOrden(data);

            }while(data!=-1);
        }
        void printList(){
            Node* indice = first;
            cout<<"Node adress \tData \tWhere it points\n";
            while(indice->getNext()!=indice){
                cout<<indice<<"\t"<<indice->getData()<<"\t"<<indice->getNext()<<endl;
                indice = indice->getNext();
            }
            cout<<endl;
        }
        void insertInOrden(int data){
            Node* newNode = new Node(data);
            Node* indice = first, *previous = NULL;
            if(first==NULL){
                first = newNode;
                return;
            }
            if(data<first->getData()){
                insertFirst(data);
                return;
            }
            while(indice!=NULL){
                if(data>=indice->getData()){
                    previous = indice;
                    indice = indice->getNext();
                }
                else break;
            }
            newNode->setNext(previous->getNext());
            previous->setNext(newNode); 
        }
        void insertFirst(int data){
            Node *newNode = new Node(data);
            newNode->setNext(first);
            first = newNode;
        }
        void insertLast(int data){
            Node *newNode = new Node(data);
            Node *last = lastNode();
            if(first==NULL) first = newNode;
            else last -> setNext(newNode); 
        }
        void insertAfter(int prevData, int data){
            Node *newNode = new Node(data);
            Node *previous = findNode(prevData);
            if(previous==NULL) return;
            newNode->setNext(previous->getNext());
            previous->setNext(newNode);
        }
        Node* lastNode (){
            Node *indice = first;
            if(first==NULL) return NULL;
            while(indice->getNext()!=NULL){
                indice = indice->getNext();
            }
            return indice;
        }
        Node* findNode(int data){
            Node *indice;
            for(indice = first ; indice!=NULL ; indice = indice->getNext()){
                if(indice->getData()==data) return indice;
            }
            return NULL;
        }
        Node* findPreviousNode(int data){
            Node *previous;
            for(previous = first ; previous!=NULL ; previous = previous->getNext()){
                if(previous->getNext()->getData()==data)  return previous;
                if(previous->getNext()==NULL) return NULL;
            }
            return NULL;
        }
        void deleteNode(int data){
            if(first==NULL) return;
            if(first->getData()==data){
                Node *temp = first;
                first = first->getNext();
                delete temp;
            }
            else{
                Node *previous = findPreviousNode(data);
                if(previous==NULL) return;
                Node *temp = findNode(data);
                previous->setNext(temp->getNext());
                delete temp;
            }
        }
};