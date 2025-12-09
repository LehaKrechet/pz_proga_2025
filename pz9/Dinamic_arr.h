#include <iostream>
#include <math.h>
template <typename T>
class Dinamic_arr{
    T* array;
    int size;
    public:
        //Конструктор
        Dinamic_arr(int s){
            size = s;
            array = new T[size]{};
        }
        //Конструктор копирования
        Dinamic_arr(const Dinamic_arr &other){
            size = other.size;
            array = new T[size];
            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }

        template<typename U = T>
        void set_numeric_element(U data, int index) {
            if constexpr (!(std::is_integral_v<U> || std::is_floating_point_v<U>)){
                throw std::bad_typeid();
            }else{
                if (index < 0 || index >= size) {
                    throw std::out_of_range("Index out of range");
                }
                array[index] = data;
            }
        }

        void set_element(T data, int index){
            if (index<0 || index>size){
                throw std::out_of_range("Index out of range");
            }
            array[index] = data;
        }

        void add_element(T data){
            int new_size = size+1;
            T* new_arr = new T[new_size]{};
            for (int i=0;i<size;i++){
                new_arr[i] = array[i];
            }
            new_arr[new_size-1] = data;
            delete[] array;
            array = new_arr;
            size = new_size;

        }

        T* get_array() const{
            return array;
        }

        T get_element(int index) const{
            if (index<0 || index>size){
                throw std::out_of_range("Index out of range");
            }
            return array[index];
        }

        template<typename U>
        double euclidean_distance(const Dinamic_arr<U>& other) const {
            if constexpr (!(std::is_integral_v<U> || std::is_floating_point_v<U>)){
                throw std::bad_typeid();
            }else{
                if (size != other.get_size()) {
                    throw std::invalid_argument("Размер должен быть одинаков");
                }
                
                // Вычисление евклидова расстояния
                double sum = 0.0;
                for (int i = 0; i < size; i++) {
                    double diff = static_cast<double>(array[i]) - static_cast<double>(other.get_element(i));
                    sum += diff * diff;
                }
                
                return std::sqrt(sum);
            }
        }
        
        int get_size() const {
            return size;
        }

        friend std::ostream& operator<<(std::ostream& os, const Dinamic_arr& obj){
            for (int i=0;i<obj.get_size();i++){
                os << obj.get_array()[i] << ";";
            }
            return os;
        }
        //Деструктор
        ~Dinamic_arr(){
            delete[] array;
        }

};

