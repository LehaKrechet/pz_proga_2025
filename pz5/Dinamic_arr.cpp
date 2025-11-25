#include"Dinamic_arr.h"
#include<iostream>
#include<chrono>
#include<fstream>
#include<ctime>


void Dinamic_arr::show(){
    for (int i=0;i<size;i++){
        std::cout << array[i] << std::endl;
    }
}

int* Dinamic_arr::get_array() const{
    return array;
}
int Dinamic_arr::get_ellement(int index) const{
    if (index>=0 && index<size){
        return array[index];
    }else{
        return -1;
    }
}
void Dinamic_arr::set_element(int data, int index){
    if (index>=0 && index<size && data > -100 && data < 100){
        array[index] = data;
    }
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

int ArrTxt::save_to_file(){
    if (size > 0){
        std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%d.%m.%y_%H:%M:%S",std::localtime(&now_time));
        std::string name = std::string(buffer)+ (std::string)".txt";

        std::ofstream file(name);
        if (file.is_open()){
            for (int i=0;i<size;i++){
                file << array[i] << std::endl;
            }
        }else{
            return 1;
        }
    }
    return 0;
}

int ArrCSV::save_to_file(){
    if (size > 0){
        std::time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%d.%m.%y_%H:%M:%S",std::localtime(&now_time));
        std::string name = std::string(buffer)+ (std::string)".csv";

        std::ofstream file(name);
        if (file.is_open()){
            for (int i=0;i<size;i++){
                file << array[i] << ";";
            }
        }else{
            return 1;
        }
    }
    return 0;
}