#include"mod_dinamic_arr.h"
#include<algorithm>

double Mod_dinamic_arr::average(){
    int summ = 0;
    for (int i=0;i<size;i++){
        summ += array[i];
    }
    return (double)summ / size;
}
double Mod_dinamic_arr::median(){
    int* temp = new int[size];
    double result;
    for (int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    std::sort(temp, temp+size);
    if (size == 0){
        return 0.0;
    }else if (size % 2 == 1){
        result = temp[size / 2];
    }else{
        result = (temp[size/2-1] + temp[size/2])/2;
    }
    delete[] temp;
    return result;
}
int Mod_dinamic_arr::min(){
    int min = array[0];
    for (int i=0;i<size;i++){
        if (min > array[i]){
            min = array[i];
        }
    }
    return min;

}
int Mod_dinamic_arr::max(){
    int max = array[0];
    for (int i=0;i<size;i++){
        if (max < array[i]){
            max = array[i];
        }
    }
    return max;
}