#include<iostream>
#include"mod_dinamic_arr.h"


int main(){
    Mod_dinamic_arr arr(5);
    arr.set_element(1, 0);
    arr.set_element(4, 1);
    arr.set_element(5, 2);
    arr.set_element(17, 3);
    arr.set_element(9, 4);
    arr.add_element(7);
    std::cout << arr.average() << std::endl;
    std::cout << arr.median() << std::endl;
    std::cout << arr.min() << std::endl;
    std::cout << arr.max() << std::endl;

}