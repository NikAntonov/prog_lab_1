#include <iostream>
#include <cmath>

using namespace std;

//
// Created by Nick on 11.09.2018.
//

double a, b, c, x_start, x_end, dx, result;                                                                 //Глобальные переменные

double F(double x) {
    if (x + 5 < 0 && c == 0) return 1/(a*x)-b;                                                              //Функция, заданная по условию задачи
    else if (x + 5 > 0 && c != 0) return (x-a)/x;
    else return (10*x)/(c-4);
}

void print(int number) {                                                                                    //Печать римских цифр
    char result[1000]{'\0'};                                                                                //Массив для хранения результата (вместо String)
    const int values[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };                          //Позиции для римских цифр
    const char *symbols[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };      //Алфавит символов
    int counter = sizeof(symbols) / sizeof(symbols[0]) - 1;                                                 //Выбор последнего элемента массива
    while(counter >= 0) {                                                                                   //Цикл для перебора цифр числа и их замены
        while(number >= values[counter]) {                                                                  //Постепенное уменьшение числа по разрядам для подмены римской системоой счисления
            number -= values[counter];
            strcat(result, symbols[counter]);                                                               //Вставка в массив result буквы, подходящей к разряду и номеру данного числа
        }
        counter--;
    }
    cout << result;                                                                                         //Вывод римских цифр
}

void output() {                                                                                             //Обработка функции и вывод значения
    if (x_start > x_end) {                                                                                  //При стартовой позиции промежутка, большей, чем конечная
        double temp = x_start;
        x_start = x_end;                                                                                    //Смена местами стартовой и конечной позиции
        x_end = temp;
    }
    for (double i = x_start; i <= x_end; i+=abs(dx)) {                                                      //Прогон цикла по отрезку функции с нужным шагом

        //Проверка на условие с возвратом целых или вещественных чисел в функцию
        if ((int(a) && int(c)) || (int(b) && int(c)) != 0) result = F(i); else result = F(int(i));


        double result_forRome;
        if (result > 0) result_forRome = floor(result + 0.5); else result_forRome = ceil(result - 0.5);

        cout<<"["<<i<<"; "<<result<<"] : (";                                                                //Печать результата в арабских цифрах

        if (i < 0) cout<<"-";
        print(int(abs(i)));                                                                                      //Печать римских цифр
        cout<<"; ";
        print(int(result_forRome));                                                                         //Печать римских цифр
        cout<<")"<<endl;                                                                                    //Сброс строки
    }
}

int main(){
    cout<<"INPUT: a -> b -> c -> x_start -> x_end -> dx"<<endl;
    cin>>a>>b>>c>>x_start>>x_end>>dx;
    cout<<"OUTPUT: X -> Y"<<endl;
    if (dx == 0) cout<<"ERROR: null dx";                                                                    //Обработка ошибки с бесконечным циклом
    output();
    return 0;
}

