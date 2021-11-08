#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct scan_info {
    string model; // наименование модели
    int price; // цена
        double x_s1ze; // горизонтальный размер области сканирования
        double y__s1ze; // вертикальный размер области сканирования
    int optr; // оптическое разрешение
        int grey; // число градаций серого
};

/*
- динамически выделяет память под массив структур (не менее 6 эл-тов)
- заполняет его данными в режиме диалога
- записывает массив в бинарный файл
*/

bool get_answer(){
    string answer;
    bool stop = false;
    while (stop == false) {
        cin >> answer;
        if ((answer == "Y") or (answer == "y")) {
            stop = true;
            return true;
        }
        else
            if ((answer == "N") or (answer == "n")) {
                stop = true;
                return false;
            }
            else
                cout << "Y/N?\n";
    }
}

void sth() {
    int counter = 1;
    scan_info temp;
    bool stop = false;
    bool err;
    bool ready = false;
    int N;
    while (ready == false) {
        cout << "Введите число элементов массива (не менее 6): ";
        cin >> N;
        cin.get();
        if (std::cin.fail()) {
            std::cin.clear();
            cin.ignore(100000,'\n');
            cout << "Введите целочисленное число\n";
        }
        else {
            if (N < 2) {
                cout << "Сказано же, не менее 6\n";
            }
            else {
                ready = true;
            }
        }
    }
    unique_ptr<scan_info[]> arr(new scan_info[N]);

    //цикл заполнения массива
    while (counter <= N) {

        err = false;
        cout << "Введите наименование модели номер " << counter << ": ";
        cin >> temp.model;
        if (std::cin.fail()) {
            std::cin.clear();
            cin.ignore(100000, '\n');
            std::cout << "Ошибка при заполнении\n";
            err = true;
        }
        else {
            cout << "Введите цену модели номер " << counter << ": ";
            cin >> temp.price;
            if (std::cin.fail()) {
                std::cin.clear();
                cin.ignore(100000, '\n');
                std::cout << "Ошибка при заполнении\n";
                err = true;
            }
            else {
                cout << "Введите горизонтальный размер области сканирования модели номер " << counter << ": ";
                cin >> temp.x_s1ze;
                if (std::cin.fail()) {
                    std::cin.clear();
                    cin.ignore(100000, '\n');
                    std::cout << "Ошибка при заполнении\n";
                    err = true;
                }
                else {
                    cout << "Введите вертикальный размер области сканирования модели номер " << counter << ": ";
                    cin >> temp.y__s1ze;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        cin.ignore(100000, '\n');
                        std::cout << "Ошибка при заполнении\n";
                        err = true;
                    }
                    else {
                        cout << "Введите оптическое разрешение модели номер " << counter << ": ";
                        cin >> temp.optr;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            cin.ignore(100000, '\n');
                            std::cout << "Ошибка при заполнении\n";
                            err = true;
                        }
                        else {
                            cout << "Введите число градаций серого модели номер " << counter << ": ";
                            cin >> temp.grey;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                cin.ignore(100000, '\n');
                                std::cout << "Ошибка при заполнении элемента\n";
                                err = true;
                            }
                        } //сильно много вложенных ифов, но работает же?
                    }
                }
            }
        }

        if (err == false) {
            arr[counter-1] = temp;
            counter++; //если не было ошибок, то увеличиваю счетчик
        }
    }
    fstream F;
    F.open("test.txt", fstream::in | fstream::out | fstream::ate | fstream::binary);
    if (!(F.is_open())) {
        cout << "Ошибка при открытии файла";
    };
        F << N;
        for (int i = 0; i < N; i++) {
            F << arr[i].model << arr[i].price << arr[i].x_s1ze << arr[i].y__s1ze << arr[i].optr << arr[i].grey;
        }
        F.close();


        cout << "Вы уверены, что хотите переписать запись? (Y/N)\n";
        if (get_answer() == true) {
            err = false;
            cout << "Введите наименование модели: ";
            cin >> temp.model;
            cout << "Введите цену модели: ";
            cin >> temp.price;
            if (std::cin.fail()) {
                std::cin.clear();
                cin.ignore(100000, '\n');
                std::cout << "Ошибка при заполнении\n";
                err = true;
            }
            else {
                cout << "Введите горизонтальный размер области сканирования модели: ";
                cin >> temp.x_s1ze;
                if (std::cin.fail()) {
                    std::cin.clear();
                    cin.ignore(100000, '\n');
                    std::cout << "Ошибка при заполнении\n";
                    err = true;
                }
                else {
                    cout << "Введите вертикальный размер области сканирования модели: ";
                    cin >> temp.y__s1ze;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        cin.ignore(100000, '\n');
                        std::cout << "Ошибка при заполнении\n";
                        err = true;
                    }
                    else {
                        cout << "Введите оптическое разрешение модели: ";
                        cin >> temp.optr;
                        if (std::cin.fail()) {
                            std::cin.clear();
                            cin.ignore(100000, '\n');
                            std::cout << "Ошибка при заполнении\n";
                            err = true;
                        }
                        else {
                            cout << "Введите число градаций серого модели: ";
                            cin >> temp.grey;
                            if (std::cin.fail()) {
                                std::cin.clear();
                                cin.ignore(100000, '\n');
                                std::cout << "Ошибка при заполнении элемента\n";
                                err = true;
                            }
                        }
                    }
                }
            }
            if (err == true) return;

            int num;
            cout << "Введите номер записи, которую желаете переписать: ";
            cin >> num;
            if ((std::cin.fail()) and (num <= N)) {
                std::cout << "Ошибка при заполнении\n";
                return;
            }
            string temp_str;

            temp_str = arr[num].model + to_string(arr[num].price) + to_string(arr[num].x_s1ze) + to_string(arr[num].y__s1ze)
                + to_string(arr[num].optr) + to_string(arr[num].grey);
            //создаю строку, которую нужно найти
            fstream F;
            F.open("test.txt", fstream::out | fstream::binary);
            if (!(F.is_open())) {
                cout << "Ошибка при открытии файла";
            };
            string line;
            bool err_str = false;
            for (int i = 0; i < sizeof(getline(F, line)); i++) {
                if (line[i] == temp_str[1]) {  //ищу по файлу первый символ нужной строки
                    for (int j = 0; j < sizeof(temp_str); j++) { //проверяю, если нашлось
                        if (line[i + j] != temp_str[j])  //если не совпадают, то ошибка
                            err_str = true;
                    }
                    if (err_str == false) {
                        F.open("test.txt", fstream::in | fstream::out | fstream::ate | fstream::binary);
                        line.erase(i, sizeof(temp_str));
                        F << line;
                        F.seekg(i);
                        F << temp.model << temp.price << temp.x_s1ze << temp.y__s1ze << temp.optr << temp.grey;

                    }
                }
            }
        }
}

int main()
{
    setlocale(LC_ALL, "ru");
    sth();
}
