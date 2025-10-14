#include"Dinamic_arr.h"

class Mod_dinamic_arr : public Dinamic_arr {
    public:
        Mod_dinamic_arr(int s) : Dinamic_arr(s){
        }
        //Конструктор копирования
        Mod_dinamic_arr(const Dinamic_arr &other) : Dinamic_arr(other){
        }
        double average();
        double median();
        int min();
        int max();
};