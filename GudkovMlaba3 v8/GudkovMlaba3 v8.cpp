#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <list>
#include <cmath>

using namespace std;

struct Recipe { // создаем структуру которую будем использовать. в структуре находятся 3 строчки
    string name;
    string ingredients;
    string instructions;
};

list<Recipe> RecipeBook{ //создали список
      {"Шашлык по-грузински", "Свиная шея - 1 кг, лук - 0.5 кг, соль, перец", "Маринуем мясо, жарим на углях - PROFIT!"},
      {"Борщ", "Говядина на косточке - 1 кг, картофель - 1 кг, лук - 1 шт, морковь - 1 шт, свекла - 1 шт", "Варим бульон, крошим овощи, варим 3 часа - PROFIT!"},
      {"Яичница", "Яйцо куриное - 2 шт, масло сливочное - 10 г", "Растапливаем масло на сковороде, вбиваем яйца, жарим 3 минуты"} };


int menu() {

    cout << "\n Выберите действие: \n";
    cout << "0. Вывести список на экран \n";
    cout << "1. Включить новый элемент в конец списка \n";
    cout << "2. Включить новый элемент в заданное место \n";
    cout << "3. Включить новый элемент ПОСЛЕ элемента с заданной информацией \n";
    cout << "4. Включить новый элемент ПЕРЕД элементом с заданной информацией \n";
    cout << "5. Включить новый элемент в середину списка \n";
    cout << "6. Исключить элемент из середины списка \n";
    cout << "7. Исключить элемент с заданной информацией \n";
    cout << "8. Исключить элемент из конца списка \n";
    cout << "9. Исключить элемент из заданного места \n";
    cout << "10. Исключить элемент из головы списка \n";
    cout << "11. Выход. \n";

    int a; //ввести в a
    cin >> a;
    return a; // для работы меню все эти 3 строки(типа чел ввёл какую-то цифру)

}



int main() {
    system("chcp 1251"); // настраиваем кодировку консоли
    int a = menu(); //вывели меню

    while (a != 11) {
        if (a == 0) {
            int i = 1;
            for (Recipe rec : RecipeBook) //пока в recipe что-то есть, оно работает
            {
                cout << "Номер рецепта: " << to_string(i++) << endl;
                cout << "Название блюда: " << rec.name << endl;
                cout << "Ингридиенты: " << rec.ingredients << endl;
                cout << "Инструкция по приготовлению: " << rec.instructions << endl;
            }

        }



        if (a == 1) {
            Recipe NewRecipe; // Для нового рецепта
            cout << "\n Выбран режим добавления нового блюда в конец списка" << endl;
            cout << "Введите название блюда: ";
            cin.ignore(); //нужно, чтобы после вписания рецепта enter не сохранялся
            getline(cin, NewRecipe.name);
            cout << "Введите ингридиенты для блюда через запятую: ";
            getline(cin, NewRecipe.ingredients);
            cout << "Введите вариант приготовления блюда, в конце нажмите Enter: ";
            getline(cin, NewRecipe.instructions); //запихнул рецепт в конец списка
            RecipeBook.push_back(NewRecipe);
            cout << "Рецепт успешно добавлен в конец списка!" << endl;
        }



        else if (a == 2) {
            Recipe NewRecipe; // Для нового рецепта
            int pos = 0; // Указанная позиция
            int i = 1; // Для перебора итератором
            auto iter = RecipeBook.cbegin(); // Итератор списка устанавливаем на первый элемент списка
            cout << "\n Выбран режим добавления нового блюда в произвольное место списка" << endl;
            do {
                cout << "Укажите номер в списке, на который требуется поместить новый рецепт: ";
                cin.ignore();
                cin >> pos;
                if (pos > RecipeBook.size()) //пользователь вводит новю позицию
                    cout << "Позиция находится за пределами списка! Попробуйте ещё раз" << endl;
            } while (pos > RecipeBook.size()); //нельзя выйти за пределы списка
            cout << "Введите название блюда: ";
            cin.ignore();
            getline(cin, NewRecipe.name);
            cout << "Введите ингридиенты для блюда через запятую: ";
            getline(cin, NewRecipe.ingredients);
            cout << "Введите вариант приготовления блюда, в конце нажмите Enter: ";
            getline(cin, NewRecipe.instructions);
            // Ищем нужную позицию в списке
            while (i < pos) { // Как только i станет равно pos - итератор стоит на нужном месте
                iter++; // Побежали итератором
                i++; // Наращиваем счётчик
            }
            // Вставляем новый рецепт на нужное место
            RecipeBook.insert(iter, NewRecipe); //вставили новый рецепт в книгу рецептов на место итератора
            cout << "Рецепт успешно добавлен в заданное место списка!" << endl;
        }


        else if (a == 3) {
            string str3 = ""; //новая строка для новго рецепта
            Recipe NewRecipe;
            int i = 0;
            auto iter = RecipeBook.cbegin(); //ставит итератор в начало списка

            cout << "\n Выбран режим добавления после указанного на блюдо" << endl;
            cout << "Введите НАЗВАНИЕ рецепта для поиска, новый рецпт будет добавлен ПОСЛЕ него: ";
            cin.ignore();
            getline(cin, str3);
            for (auto iter = RecipeBook.begin(); iter != RecipeBook.end(); iter++) //цикл, который проходит по всему списку(если совпадений не будет, то он просто выйдет)
            {
                if (iter->name == str3) {
                    iter++;
                    cout << "Введите название блюда: ";
                    cin.ignore();
                    getline(cin, NewRecipe.name);
                    cout << "Введите ингридиенты для блюда через запятую: ";
                    getline(cin, NewRecipe.ingredients);
                    cout << "Введите вариант приготовления блюда, в конце нажмите Enter: ";
                    getline(cin, NewRecipe.instructions);
                    RecipeBook.insert(iter, NewRecipe);
                    cout << "Рецепт успешно добавлен в заданное место списка!" << endl;
                    break;
                }
            }
        }



        else if (a == 4) {
            string str3 = "";
            Recipe NewRecipe;
            int i = 0;
            auto iter = RecipeBook.cbegin();

            cout << "\n Выбран режим добавления до указанного на блюдо" << endl;
            cout << "Введите НАЗВАНИЕ рецепта для поиска, новый рецпт будет добавлен ПЕРЕД ним: ";
            cin.ignore();
            getline(cin, str3);
            for (auto iter = RecipeBook.begin(); iter != RecipeBook.end(); iter++)
            {
                if (iter->name == str3) {
                    iter--;
                    iter++;
                    cout << "Введите название блюда: ";
                    cin.ignore();
                    getline(cin, NewRecipe.name);
                    cout << "Введите ингридиенты для блюда через запятую: ";
                    getline(cin, NewRecipe.ingredients);
                    cout << "Введите вариант приготовления блюда, в конце нажмите Enter: ";
                    getline(cin, NewRecipe.instructions);
                    RecipeBook.insert(iter, NewRecipe);
                    cout << "Рецепт успешно добавлен в заданное место списка!" << endl;
                    break;
                }
            }
        }



        else if (a == 5) {
            Recipe NewRecipe;
            auto iter = RecipeBook.cbegin();

            cout << "\n Выбран режим добавления в середину списка" << endl;
            cout << "Введите название блюда: ";
            cin.ignore();
            getline(cin, NewRecipe.name);
            cout << "Введите ингридиенты для блюда через запятую: ";
            getline(cin, NewRecipe.ingredients);
            cout << "Введите вариант приготовления блюда, в конце нажмите Enter: ";
            getline(cin, NewRecipe.instructions);

            for (int i = 1; i < ceil(RecipeBook.size() / 2.0); i++) //делит размер книги рецептов на 2 и прибавляет к итератору
            {
                iter++;
            }
            iter++;
            RecipeBook.insert(iter, NewRecipe);
        }



        else if (a == 6) {
            cout << "Рецепт успешно удален из середины списка!" << endl;
            if (RecipeBook.size() >= 4) {
                auto iter = RecipeBook.cbegin();
                for (int i = 1; i < ceil(RecipeBook.size() / 2.0); i++)
                {
                    iter++;
                }
                RecipeBook.erase(iter); //просто стереть вместо ввода
            }
            else if (RecipeBook.size() < 4) {
                auto iter = RecipeBook.cbegin();
                for (int i = 1; i < ceil(RecipeBook.size() / 2.0); i++)
                {
                    iter++;
                }
                RecipeBook.erase(iter);
            }
        }



        else if (a == 7) {
            cout << "Введите НАЗВАНИЕ рецепта для удаления: ";
            string str3 = "";
            auto iter = RecipeBook.cbegin();
            cin.ignore();
            getline(cin, str3);
            for (int i = 1; i < RecipeBook.size(); i++)
            {
                if (iter->name == str3) {
                    break;
                }
                iter++;
            }
            RecipeBook.erase(iter);
            cout << "Рецепт успешно удален из списка!" << endl;

        }



        else if (a == 8) {
            cout << "Рецепт успешно удален из конца списка!" << endl;
            auto iter = RecipeBook.cbegin();
            for (int i = 1; i < RecipeBook.size(); i++) {
                iter++;
            }
            RecipeBook.erase(iter);
        }



        else if (a == 9) {

            int pos = 0; // Указанная позиция
            int i = 1; // Для перебора итератором
            auto iter = RecipeBook.cbegin(); // Итератор списка устанавливаем на первый элемент списка
            cout << "Укажите номер в списке, который требуется удалить: ";
            cin.ignore();
            cin >> pos;
            if (pos > RecipeBook.size())
                cout << "Позиция находится за пределами списка! Попробуйте ещё раз" << endl;
            while (i < pos) {
                iter++; // Побежали итератором
                i++; // Наращиваем счётчик
            }
            // Вставляем новый рецепт на нужное место
            RecipeBook.erase(iter);
            cout << "Рецепт успешно удален из списка!" << endl;


        }
        else if (a == 10) {
            cout << "Рецепт успешно удален из головы списка!" << endl;
            auto iter = RecipeBook.cbegin();
            RecipeBook.erase(iter);
        }


        a = menu();
    }
    return 0;
}