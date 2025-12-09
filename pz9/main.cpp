#include<iostream>
#include"Dinamic_arr.h"

int main() {
    try {
        Dinamic_arr<double> arr1(3);
        arr1.set_numeric_element(1.0, 0);
        arr1.set_numeric_element(2.0, 1);
        arr1.set_numeric_element(3.0, 2);
        
        Dinamic_arr<double> arr2(3);
        arr2.set_element(4.0, 0);
        arr2.set_element(5.0, 1);
        arr2.set_element(6.0, 2);

        
        
        double dist = arr1.euclidean_distance(arr2);
        std::cout << "Евклидова метрика: " << dist << std::endl;

        Dinamic_arr<std::string> str_arr(3);
        str_arr.set_element("Hello", 0);
        str_arr.set_element("Word", 1);
        str_arr.set_element("!", 2);
        std::cout << str_arr;
        
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}