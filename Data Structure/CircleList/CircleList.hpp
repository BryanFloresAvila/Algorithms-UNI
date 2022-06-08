#include <iostream>
#include "Node.hpp"
using namespace std;
class CircleList{
    private:
        Node* access;
    public:
        CircleList(){
            access = NULL;
        }
        void createList(){
            int data;
            do{
                cout<<"Enter data: ";
                cin>>data;
                if(data!=-1){
                    insert(data);
                }
            }while(data!=-1);

        }
        void insert(int data){
            Node* newNode = new Node(data);
            if(access!=NULL){
                newNode->setNext(access->getNext());
                access->setNext(newNode);
            }
            else access = newNode;
        }
        void printList(){
            Node* temp = access;
            do{
                cout<<temp->getData()<<" ";
                temp = temp->getNext();
            }while(temp!=access);
            cout<<endl;
        }
};