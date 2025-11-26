#include<iostream>
#include"Dinamic_arr.h"

int main(){
    Dinamic_arr arrA(5);
    for(int i = 0; i<5;i++){
        arrA.set_element(i, i);
    }
    try{
        arrA.set_element(100, 30);
    }catch  (std::exception& e){
        std::cout << e.what() << std::endl;
    }

}