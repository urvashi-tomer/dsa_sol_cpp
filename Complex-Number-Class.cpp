#include<iostream>
using namespace std;
//#include "ComplexNumbers.h"

class ComplexNumbers {
    int real;
    int img;
    
    public:
    	ComplexNumbers(int real, int img){
            this->real=real;
            this->img=img;
        }
    	
    	void plus(ComplexNumbers C){
            real=real+C.real;
            img=img+C.img;
        }
    
    	void multiply(ComplexNumbers C){
            int r=(real*C.real)-(img*C.img);
            int i=(real*C.img)+(img*C.real);
            real=r;
            img=i;
        }
    
    	void print(){
            cout<<real<<" + "<<"i"<<img<<endl;
        }
    
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}