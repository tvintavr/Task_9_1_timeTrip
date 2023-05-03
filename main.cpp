#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    std::string timeDeparture;
    std::string timeArrival;

    int hoursDep;
    int minutesDep;
    int hoursArr;
    int minutesArr;
    int hoursTrip;
    int minutesTrip;




    while (true) {

        std::cout<<"Введите время отправления (HH:MM): ";
        std::cin>>timeDeparture;
        std::cout<<"Введите время прибытия (HH:MM): ";
        std::cin>>timeArrival;

        //проверка корректности ввода данных
        if (timeDeparture[2]!=':'
            || timeDeparture[0]<'0'|| timeDeparture[0]>'9'
            || timeDeparture[1]<'0'|| timeDeparture[1]>'9'
            || timeDeparture[3]<'0'|| timeDeparture[3]>'9'
            || timeDeparture[4]<'0'|| timeDeparture[4]>'9'
            || timeArrival[2]!=':'
            || timeArrival[0]<'0'|| timeArrival[0]>'9'
            || timeArrival[1]<'0'|| timeArrival[1]>'9'
            || timeArrival[3]<'0'|| timeArrival[3]>'9'
            || timeArrival[4]<'0'|| timeArrival[4]>'9'
            || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //проверка корректности ввода данных

        } else {

            hoursDep=(timeDeparture[0]-'0')*10+timeDeparture[1]-'0';
            minutesDep=(timeDeparture[3]-'0')*10+timeDeparture[4]-'0';
            hoursArr=(timeArrival[0]-'0')*10+timeArrival[1]-'0';
            minutesArr=(timeArrival[3]-'0')*10+timeArrival[4]-'0';

            // Проверка на соответствие диапазонам часов и минут
            if (hoursDep>23 || minutesDep> 59 || hoursArr>23 || minutesArr> 59 ) {
                std::cout << "Ошибка ввода данных\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // Проверка на соответствие диапазонам часов и минут

            } else {
                hoursTrip=hoursArr-hoursDep;
                minutesTrip=minutesArr-minutesDep;
                if (hoursTrip<0) {
                    hoursTrip=24+hoursTrip;
                }
                if (minutesTrip<0) {
                    minutesTrip=60+minutesTrip;
                    hoursTrip--;
                }
                if (hoursTrip==0 & minutesTrip==0) {
                    hoursTrip=24;
                }
                std::cout<<"Поездка составила "<<hoursTrip<<" ч. "<<minutesTrip<<" мин.\n";
            }
        }
    }
}