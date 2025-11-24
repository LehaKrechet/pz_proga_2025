#include<iostream>
#include"Dinamic_arr.h"

int main(){
    Dinamic_arr* arrays[2];
    arrays[0] = new ArrTxt(5);
    arrays[1] = new ArrCSV(5);

    for(int i = 0; i<5;i++){
        arrays[0]->set_element(i, i);
        arrays[1]->set_element(i, i);
    }

    for (int i = 0; i < 2; i++){
        arrays[i]->save_to_file();
        delete arrays[i];
    }


    
    

}