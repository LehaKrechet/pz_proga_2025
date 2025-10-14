class Dinamic_arr{
    protected:
        int* array;
        int size;
    public:
        //Конструктор
        Dinamic_arr(int s){
            size = s;
            array = new int[size]{};
        }
        //Конструктор копирования
        Dinamic_arr(const Dinamic_arr &other){
            size = other.size;
            array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        //Вывод значений
        void show();
        //Геттеры
        int* get_array() const;
        int get_ellement(int index) const;
        //Сеттер
        void set_element(int data, int index);
        //Добваление элемента
        void add_element(int data);

        //Сложение
        void add(Dinamic_arr&arr);
        //Вычитане
        void sub(Dinamic_arr&arr);
        //Деструктор
        virtual ~Dinamic_arr(){
            delete[] array;
        }

};