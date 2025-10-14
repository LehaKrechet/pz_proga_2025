#include<iostream>
#include"Dinamic_arr.h"

int main(){
    Dinamic_arr arrA(5), arrB(10);

    arrA.set_element(10, 0);
    arrB.set_element(5, 0);
    std::cout << arrA.get_ellement(0) << std::endl;
    arrA.add_element(15);
    arrB.set_element(5, 5);
    arrA.show(); std::cout << "__________"<<std::endl;
    arrB.show(); std::cout << "__________"<<std::endl;
    arrA.add(arrB);
    arrA.show(); std::cout << "__________"<<std::endl;
    arrA.sub(arrB);
    arrA.show(); std::cout << "__________"<<std::endl;

}