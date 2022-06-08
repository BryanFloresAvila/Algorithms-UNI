#include <iostream>
using namespace std;
class Stack{
    private:
        int positionTop;
        int *stack;
        int size;
    public:
        Stack(int length){
            this->positionTop = -1;
            this->stack = new int[length];
            this->size = length;
        }
        bool isEmpty(){
            return this->positionTop == -1;
        }
        bool isFull(){
            return this->positionTop + 1 == this->size;
        }
        int getPositionTop(){
            return this->positionTop;
        }
        int getSize(){
            return this->size;
        }
        int getTop(){
            return this->stack[this->positionTop];
        }
        void push(int value){
            if(!isFull()){
                this->positionTop++;
                this->stack[positionTop] = value;   
            }else{
                cout << "Stack is full" << endl;
            }
        }
        int pop(){
            if(!isEmpty()){
                int value = this->stack[this->positionTop];
                this->positionTop--;
                return value;
            }else{
                cout << "Stack is empty" << endl;
                return -1;
            }
        }
        void print(){
            int value;
            while(!isEmpty()){
                value = pop();
                cout << value << " ";
            }
        }
        void clear(){
            this->positionTop = -1;
        }

};