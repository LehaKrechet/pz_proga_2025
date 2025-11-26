#include<iostream>
#include"Dinamic_arr.h"

int main(){
    Dinamic_arr arrA(5);
    for(int i = 0; i<5;i++){
        arrA.set_element(i, i);
    }
    arrA.set_element(500, 3);
    std::cout << arrA.get_ellement(1);


}