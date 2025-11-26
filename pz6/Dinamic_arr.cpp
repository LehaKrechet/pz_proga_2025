#include"Dinamic_arr.h"
#include<iostream>
#include<exception>

void Dinamic_arr::show(){
    for (int i=0;i<size;i++){
        std::cout << array[i] << std::endl;
    }
}

int* Dinamic_arr::get_array() const{
    return array;
}
int Dinamic_arr::get_ellement(int index) const{
    if (index<0 || index>size){
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

void Dinamic_arr::set_element(int data, int index){
    if (index<0 || index>size){
        throw std::out_of_range("Index out of range");
    }else if (data < -100 || data > 100){
        throw std::invalid_argument("Invalid argument");
    }
    array[index] = data;
}
void Dinamic_arr::add_element(int data){
    if (data > -100 && data < 100){
        int new_size = size+1;
        int* new_arr = new int[new_size]{};
        for (int i=0;i<size;i++){
            new_arr[i] = array[i];
        }
        new_arr[new_size-1] = data;
        delete[] array;
        array = new_arr;
        size = new_size;
    }

}
void Dinamic_arr::add(Dinamic_arr&arr){
    for (int i = 0;i < size;i++){
        if(arr.get_ellement(i) != -1){
            array[i] = array[i] + arr.get_ellement(i);
        }
    }
}
void Dinamic_arr::sub(Dinamic_arr&arr){
    for (int i = 0;i < size;i++){
        if(arr.get_ellement(i) != -1){
            array[i] = array[i] - arr.get_ellement(i);
        }
    }
}