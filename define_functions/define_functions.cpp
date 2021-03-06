#include <format>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <cstdarg>
#include <windows.h>
#include <map>
#define SQR(x) x*x
#define CUBE(X) (SQR(X)*(X))
#define ABS(X) (((X) < 0)? -(X) : X)

using namespace std;

constexpr int NOTFOUND = -1;;
#pragma region Standart Array functions


/// <summary>
/// Вывод массива на экран
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="SIZE">Длинна массива</param>
template <typename T>
void ShowArray(T arr[], const int SIZE, char delimetr = '\t') {
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i];
        cout << delimetr;
    }
    cout << endl;
}

/// <summary>
/// Инициализирует массив нужными значениями
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="mass"></param>
/// <param name="lenght"></param>
/// <param name="max"></param>
/// <param name="min"></param>
template <typename T>
void InitArray(T* mass, int lenght, int max, int min) {
    //srand(time(nullptr));
    for (int i = 0; i < lenght; i++) {
        mass[i] = ((rand() % (max - min + 1)) + min);
    }
}

//template <typename T>
void Init2DArray(int** mass, int row, int columns, int max, int min)
{
    mass = new int* [row];
    for (int i = 0; i < row; i++)
    {
        mass[i] = new int[i+1];
        InitArray(mass[i], i + 1, max, min);
    }
}

/// <summary>
/// Сортирует массив
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">массив</param>
/// <param name="length">длинна</param>
/// <param name="reverse">Сортировать в обратном направлении</param>
/// <param name="start">начальная позиция</param>
/// <param name="finish">конечная позиция</param>
template <typename T>
void BubbleSort(T arr[], int length, bool reverse, int start, int finish);


#pragma endregion

#pragma region До указателей


/// <summary>
/// Сортирует половину массива по убванию, а вторую половину по возрастанию
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr">Сортируемый массив</param>
/// <param name="lenght">Длинна массива</param>
template <typename T>
void SortHalf(T arr[], int lenght);

/// <summary>
/// Пузырьковая сортировка
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
/// <param name="length"></param>
/// <param name="reverse"></param>
/// <param name="start"></param>
/// <param name="finish"></param>
template <typename T>
void BubbleSort(T arr[], int length, bool reverse = false, int start = 0, int finish = 0)
{
    int finishSort = finish ? finish : length;

    for (size_t i = start; i < finishSort - 1; i++)
    {
        T temp = arr[i];
        int position = i;
        for (size_t j = i + 1; j < finishSort; j++)
        {
            bool comparer = reverse ? temp < arr[j] : temp > arr[j];
            if (comparer)
            {
                temp = arr[j];
                position = j;
            }
        }
        arr[position] = arr[i];
        arr[i] = temp;
    }
}

template <typename T>
void SortHalf(T arr[], int lenght)
{
    int halfLenght = lenght / 2;
    BubbleSort(arr, lenght, true, 0, halfLenght);
    BubbleSort(arr, lenght, false, halfLenght, lenght);
}

/// <summary>
/// Поиск первого или последнего отрицательного элемента массива
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
/// <param name="lenght"></param>
/// <param name="serachFirst"></param>
/// <returns>Индекс найденого элемаента</returns>
template <typename T>
short SearchNegative(T arr[], int lenght, bool serachFirst)
{
    short negativeIndex = NOTFOUND;
    for (int i = 0; i < lenght; i++)
    {
        if (arr[i] < 0)
        {
            negativeIndex = i;
            if (serachFirst)
            {
                break;
            }
        }
    }
    return negativeIndex;
}

/// <summary>
/// Находит все нули сдвигает остальные элементы и заполняет последние значения "-1"
/// </summary>
/// <param name="arr"></param>
/// <param name="lenght"></param>
void ReplaceZero(int arr[], int lenght)
{
    int _lenght = lenght;
    lenght - 1;
    int i = 0, j = 0;
    while (i < lenght)
    {
        if (arr[i] != 0)
            j++;

        i++;
        arr[j] = arr[i];
    }

    while (j < lenght)
    {
        arr[j] = -1;
        j++;
    }
}

/// <summary>
/// Сортирует массив от первого отрицательного до последнего отрицательного
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="arr"></param>
/// <param name="lenght"></param>
template <typename T>
void SortFromFirstNegativeToLastNegative(T arr[], int lenght)
{
    int first = SearchNegative(arr, lenght, true);
    cout << first << endl;
    int last = SearchNegative(arr, lenght, false);
    cout << last << endl;
    if (first == NOTFOUND || last == NOTFOUND)
    {
        cout << "Не найдено первого или последнего отрицательного эелемента" << endl;
    }
    BubbleSort(arr, lenght, false, first, last + 1);
}

void Question22()
{
    const int SIZE = 10;
    int arr[SIZE];
    InitArray(arr, SIZE, 5, 0);
    ShowArray(arr, SIZE);
    ReplaceZero(arr, SIZE);
    ShowArray(arr, SIZE);
}

long int Fact(long int N)
{
    // если произведена попытка вычислить
    // факториал нуля
    if (N < 1) return 0;
    /* если вычисляется факториал единицы
    именно здесь производится выход из рекурсии
    */
    else if (N == 1) return 1;
    // любое другое число вызывает функцию заново
// с формулой N-1
    else return N * Fact(N - 1);
}

template <class T>
void quickSortR(T a[], long N, int start, int finish) {
    T summ = 0;
    for (size_t i = 0; i < N; i++)
    {
        summ += a[i];
    }
    int value = summ / N;
    int minIndex = 0, maxIndex = 0;
    list<T> less;
    list<T> more;
    for (size_t i = 0; i < N; i++)
    {
        if (a[i] >= value)
        {
            more.push_back(a[i]);
            maxIndex++;
        }
        else
        {
            less.push_back(a[i]);
            minIndex++;
        }
    }
    T* lessArray = new T[less.size()];
    T* moreArray = new T[more.size()];
    if (less.size() > 1)
    {
        for (size_t i = 0; i < less.size(); i++)
        {
            auto l_front = less.begin();
            std::advance(l_front, i);
            lessArray[i] = *l_front;
        }
        quickSortR(lessArray, minIndex, 0, minIndex);
    }
    if (more.size() > 1)
    {
        for (size_t i = 0; i < less.size(); i++)
        {
            auto l_front = more.begin();
            std::advance(l_front, i);
            moreArray[i] = *l_front;
        }
        quickSortR(moreArray, maxIndex, 0, maxIndex);
    }
    for (size_t i = 0; i < minIndex; i++)
    {
        a[i] = lessArray[i];
    }
    for (size_t i = minIndex; i < N; i++)
    {
        a[i] = moreArray[i - minIndex];
    }

}


#pragma endregion

#pragma region Указатели начало

/*
 Для указания того, что функция принимает
 неограниченное количество параметров нужно
 указать ...
 У нашей функции один известный параметр это
 numOfArgs. Этот параметр содержит число,
 переданных переменных параметров
*/
int _GetMin(int numOfArgs, ...) {
    int minVal;
    va_list va;
    // инициализируем va для прохода по списку параметров
    // numOfArgs - самый правый известный параметр
    va_start(va, numOfArgs);
    // получаем первое значение из списка
    minVal = va_arg(va, int);
    int tempVal = 0;
    /*
 Мы получили уже первое значение из списка.
 Именно поэтому мы ведем цикл до numOfArgs - 1
 */
    for (int i = 0; i < numOfArgs - 1; i++) {
        // В цикле получаем одно значение за другим
        tempVal = va_arg(va, int);
        if (minVal > tempVal)
            minVal = tempVal;
    }
    // корректное завершение работы с переменными списка
    va_end(va);
    return minVal;
}

int GetMin(int n, ...) {
    int minVal = *((&n) + 1);

    // получаем указатель на параметр n
    for (int* ptr = (&n) + 1; (n - 1) > 0; n--)
    {
        if (*(ptr) < minVal)
        {
            minVal = *ptr;
        }
        ++ptr;
    }
    return minVal;
}

void Add(int& a)
{
    a++;
}

/// <summary>
/// 
/// </summary>
/// <param name="arr"></param>
/// <param name="length"></param>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
bool SearchMinAndMax(int* arr, int length, int& min, int& max)
{
    int tempMin = min, tempMax = max;
    min = arr[0];
    max = arr[0];
    for (size_t i = 1; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min < tempMin || max > tempMax;
}

void RefernceAdd(int* a)
{
    (*a)++;
}

void GetSummAndMuliply(int* arr, int SIZE, int* summ, long* mult)
{
    *summ = arr[0];
    *mult = arr[0];
    for (size_t i = 1; i < SIZE; i++)
    {
        *summ += arr[i];
        *mult *= arr[i];
    }
}

void GetCountNegativPositivAndZero(int* arr, int SIZE, int* negtive, int* positive, int* zero)
{
    for (size_t i = 0; i < SIZE; i++)
    {
        if (arr[i] == 0) zero[0]++;
        else if (arr[i] > 0) positive[0]++;
        else negtive[0]++;
    }
}

bool SerachPodmojestvo(int* arr1, int SIZE1, int* arr2, int SIZE2, int** index)
{
    for (size_t i = 0; i < (SIZE1 - SIZE2) + 1; i++)
    {
        if (arr1[i] == arr2[0])
        {
            bool secondInFirst = true;
            for (size_t j = 1; j < SIZE2; j++)
            {
                if (arr1[j + i] != arr2[j])
                {
                    secondInFirst = false;
                    break;
                }
            }
            if (secondInFirst)
            {
                *index = &arr1[i];
                return true;
            }
        }
    }
    return false;
}


#pragma endregion

#pragma region FP_14_1

//Задание 1. Написать функцию, которая получает указатель на массив и его размер,
//и возвращает сумму и произведение его элементов в двух параметрах - указателях.
void Quetion1_14()
{
    int size = 10, summ = 0;
    long mult = 1;
    int* arr = new int[size] { 0 };
    InitArray(arr, size, 9, -9);
    ShowArray(arr, size);
    GetSummAndMuliply(arr, size, &summ, &mult);
    cout << "Сумма = " << summ << " Произведение = " << mult << endl;
}

//Задание 2. Написать функцию, которая получает указатель
//на массив и его размер, и возвращает количество отрицательных,
//положительных и нулевых элементов массива.
void Quetion2_14()
{
    int size = 10, negative = 0, positive = 0, zero = 0;
    int* arr = new int[size] { 0 };
    InitArray(arr, size, 9, -9);
    ShowArray(arr, size);
    GetCountNegativPositivAndZero(arr, size, &negative, &positive, &zero);
    cout << "Положительных: " << positive << " Отрицательных: " << negative << " Нулевых: " << zero;
}


//Задание 3. Написать функцию, принимающую в качестве аргумента,
//указатели на два массива(А и В) и размеры массивов.
//Функция проверяет, является ли массив В подмножеством
//массива А и возвращает указатель на начало найденного
//фрагмента, либо возвращает 0 в противном случае.
void Quetion3_14()
{
    int* arr1 = new int[] { 1, 2, 3, 4, 5, 6, 7, 8};
    int* arr2 = new int[] { 5, 6, 7, 8};
    int* index = NULL;
    if (SerachPodmojestvo(arr1, 8, arr2, 4, &index))
    {
        cout << index << endl;
    }
    else
    {
        cout << "Подмоножество не найдено" << endl;
    }
    InitArray(arr1, 8, 2, 1);
    ShowArray(arr1, 8);
    InitArray(arr2, 4, 3, 2);
    ShowArray(arr2, 4);
    if (SerachPodmojestvo(arr1, 8, arr2, 4, &index))
    {
        cout << index << endl;
    }
    else
    {
        cout << "Подмоножество не найдено" << endl;
    }
}

#pragma endregion

#pragma region Задачи указатели (Владимир)

#pragma region Task1

int* Max(int* a, int* b)
{
    if ((*a) > (*b))
        return a;
    else
        return b;
    //return ((*a) > (*b) ? a : b );
}

void Indexes1()
{
    int a = 5;
    int b = 10;
    int* max = Max(&a, &b);
    cout << *max;
}

#pragma endregion

#pragma region Task2

void ShowZnak(int* a)
{
    if (a > 0)
    {
        cout << "+";
    }
    else if (a == 0)
    {
        cout << "Отсутствует";
    }
    else
    {
        cout << "-";
    }
}

void Indexes2()
{
    int a;
    cin >> a;
}

#pragma endregion

#pragma region Task11

void Copy(int* from, int* to, int length)
{
    for (size_t i = 0; i < length; i++)
    {
        to[i] = from[i];
    }
}

void PushBack(int** arr, int& size, int value)
{
    int* temp = *arr;
    size++;
    *arr = new int[size] {0};
    Copy(temp, *arr, size - 1);
    (*arr)[size - 1] = value;
    delete[] temp;
}

void Indexes11()
{
    int input = 0;
    int size = 1;
    int* arr = new int[size] {0};
    cin >> input;

    if (input < 0)
        return;

    arr[0] = input;
    ShowArray(arr, size);
    cin >> input;
    while (input > 0)
    {
        PushBack(&arr, size, input);
        ShowArray(arr, size);
        cin >> input;
    }
    ShowArray(arr, size);
    delete[] arr;
}

#pragma endregion

#pragma region Task12

int** ConvertTo2DArray(int* arr, int size, int rows, int columns)
{
    if (size != rows * columns)
        return nullptr;

    int** arr2d = new int* [rows];

    for (size_t i = 0; i < rows; i++)
        arr2d[i] = new int[columns];

    int k = 0;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            arr2d[i][j] = arr[k++];
        }
    }
    return arr2d;
}

void Indexes12()
{
    int size = 12;
    int* arr = new int[size] {0};
    InitArray(arr, size, 9, 1);
    ShowArray(arr, size);
    int** arr2d = ConvertTo2DArray(arr, size, 2, 5);
    if (arr2d != nullptr)
    {
        //cout << arr2d[0][0] << endl;
        //cout << arr2d[0][4] << endl;
        //cout << arr2d[1][0] << endl;
        //cout << arr2d[1][4] << endl;
        cout << "Конвертация завершена" << endl;
    }
    else
    {
        cout << "Конвертация не возможна" << endl;
    }
    
}

#pragma endregion

#pragma region Task13

void AddRowTo2dArr(int*** arr, int *rows, int columns, bool inStart = false)
{
    int** temp = (*arr);
    (*rows)++;
    (*arr) = new int*[(*rows)];

    int start = inStart ? 1 : 0;
    int finish = inStart ? (*rows) : (*rows) - 1;

    if (inStart)
        (*arr)[0] = new int[columns] {0};

    for (size_t i = start; i < finish; i++)
    {
        
        (*arr)[i] = temp[i-inStart];
    }

    delete[] temp;
    if (!inStart)
        (*arr)[(*rows) - 1] = new int[columns]{0};
}

void Indexes13()
{
    int rows = 3, columns = 10;
    int** arr2d = new int* [3]{ nullptr };

    for (size_t i = 0; i < rows; i++)
    {
        arr2d[i] = new int[columns];
        InitArray(arr2d[i], columns, 9, 1);
        ShowArray(arr2d[i], columns);
    }

    AddRowTo2dArr(&arr2d, &rows, columns);
    ShowArray(arr2d[rows-1], columns);
}

#pragma endregion

#pragma region Task14

void Indexes14()
{
    int rows = 3, columns = 10;
    int** arr2d = new int* [3]{ nullptr };

    for (size_t i = 0; i < rows; i++)
    {
        arr2d[i] = new int[columns];
        InitArray(arr2d[i], columns, 9, 1);
        ShowArray(arr2d[i], columns);
    }

    AddRowTo2dArr(&arr2d, &rows, columns, true);

    cout << "\n\n";

    for (size_t i = 0; i < rows; i++)
    {
        ShowArray(arr2d[i], columns);
    }

}

#pragma endregion

#pragma endregion

#pragma string 

string InitStr()
{
    string str{};
    getline(cin, str);
    return str;
}

string InitStrWithMsg(string message)
{
    cout << message;
    return InitStr();
}

void Task1()
{
    string str = InitStr();
    cout << str.length();
}

string AddToString(string str, int length)
{
    if (str.length() < length)
    {
        str.append((length - str.length()) - 1, ' ');
    }
    str.push_back('*');
    return str;
}

void Task2()
{
    string str1 = "* Лабораторная работа № 1";
    string str2 = "* Выполнил(а): ст. гр. ";
    string str3 = "* ";
    string name{};
    string surname{};
    string thirdname{};
    string gr{};
    int lenght = 0;
    surname = InitStrWithMsg("Введите фамилию : ");
    name = InitStrWithMsg("Введите Имя : ");
    thirdname =InitStrWithMsg("Введите отчество : ");
    gr = InitStrWithMsg("Введите группу : ");
    str2 += (" " + gr);
    str3 += (surname + " " + name + " " + thirdname);
    lenght = (str3.length() >= str2.length() ? str3.length() : str2.length()) + 2;
    string ramka (lenght, '*');

    str1 = AddToString(str1, lenght);
    str2 = AddToString(str2, lenght);
    str3 = AddToString(str3, lenght);

    cout << ramka << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    cout << ramka << endl;
}

void Task3()
{
    string str{};
    int number = 0;
    getline(cin, str);
    cin >> number;
    if (number > str.length())
        cout << "Введенный номер больше кол-ва символов";
    else
        cout << str[number - 1];    
}

void Task4()
{
    string str = InitStr();
    replace(str.begin(), str.end(), ' ', '\t');
    cout << str;
}

void Task5()
{
    string str = InitStrWithMsg("Введите строку\n");
    int digit = 0, sym = 0, other = 0;
    for (auto symbol : str)
    {
        if (symbol >= '0' && symbol <= '9') digit++;
        else if ((symbol >= 'a' && symbol <= 'z')
            || (symbol >= 'A' && symbol <= 'Z')
            || (symbol >= 'А' && symbol <= 'Я')
            || (symbol >= 'а' && symbol <= 'я')) sym++;
        else other++;

    }
    cout << "Символов: " << sym << endl;
    cout << "Цифр: " << digit << endl;
    cout << "Другое: " << other << endl;
}

//Напишите программу, которая удаляет из строки, 
//введенной пользователем, все пробелы и знаки препинания.
void Task6()
{
    string str = InitStrWithMsg("Введите строку\n");
    for (int i = 0; i < str.length(); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'А' && str[i] <= 'Я')
            || (str[i] >= 'а' && str[i] <= 'я')
            || (str[i] >= '0' && str[i] <= '9')))
        {
            str.erase(i, 1);
            i--;
        }
    }
    cout << str;
}

void Task7()
{
    string str = InitStrWithMsg("Введите строку\n");
    string copy = str;
    reverse(str.begin(), str.end());
    if (str == copy)
    {
        cout << "Полиндром";
    }
    else
    {
        cout << "Не Полиндром";
    }
}

bool IsIsecreamSandwich(string str)
{
    string sandwich{};
    char sandwichChar = str[0];
    char isecreamChar{};
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != sandwichChar)
        {
            isecreamChar = str[i];
            sandwich = str.substr(0, i);
            for (size_t j = i; j < str.length(); j++)
            {
                if (str[j] != isecreamChar)
                {
                    string sandwich2 = str.substr(j, (str.length() - 1));
                    return (sandwich2 == sandwich ? true : false) ;
                }
            }

            return false;
        }
    }

    return false;
}

void Task8()
{
    string str = InitStrWithMsg("Введите строку\n");
    bool is = IsIsecreamSandwich(str);
    if (is)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}

int GetMaxLenghtInStrArray(string strs[], int count, int& postion)
{
    int maxLen = 0;
    for (int i = 0; i < count; i++)
    {
        if (strs[i].length() > maxLen)
        {
            maxLen = strs[i].length();
            postion = i;
        }
    }
    return maxLen;
}

int GetMaxLenghtInStrArray(string strs[], int count)
{
    int a = 0;
    return GetMaxLenghtInStrArray(strs, count, a);
}

void Task9()
{
    string surnames[5]{};
    for (int i = 0; i < 5; i++)
    {
        surnames[i] = InitStrWithMsg(("Введите " + to_string(i+1) + " фамилию\n"));
    }
    cout << GetMaxLenghtInStrArray(surnames, 5);
}

int CountSybolsInStr(string str, char symbol)
{
    return (count_if(str.begin(), str.end(), [&](char c) {return c == symbol; }));
}

string* SplitStr(string str, char symbol)
{
    int spaceCount = CountSybolsInStr(str, symbol) + 1;
    string* strs = new string[spaceCount];

    //Заполение массива слова разделенными символами
    int position = 0;
    for (size_t i = 0; i < spaceCount; i++)
    {
        strs[i] = str.substr(position, str.find_first_of(symbol, position) - position);
        position = (str.find(symbol, position)) + 1;
    }
    return strs;
}
//Вывести самое длинное слово и его порядковый номер.
void Task10()
{
    //Строка
    string str = "QWE asd aff цываыв а daf s wsf sd fwg sgsfgwsfsefwef";

    //Поиск пробелов в строке и их подсчет (+1) с помощью функции count_if
    int spaceCount = CountSybolsInStr(str, ' ') + 1;
    
    //Создание массива строк нужной длинны
    string* strs = SplitStr(str, ' ');

    //Вывод массива на экран
    ShowArray(strs, spaceCount, '\n');
    int numberInArr = int();
    int maxLen = GetMaxLenghtInStrArray(strs, spaceCount, numberInArr);
    cout << "Максимальная длинна: " << maxLen << " на " << numberInArr+1 << " месте";
}

//Вывести самое короткое слово и его порядковый номер.
void Task11()
{
    string str = "QWE asd aff цываыв а daf s wsf sd fwg sgsfgwsfsefwef";

    int spaceCount = CountSybolsInStr(str, ' ') + 1;

    string* strs = SplitStr(str, ' ');

    ShowArray(strs, spaceCount, '\n');
    int numberInArr = 0;
    int mixLen = strs[0].length();
    for (int i = 0; i < spaceCount; i++)
    {
        if (strs[i].length() < mixLen)
        {
            mixLen = strs[i].length();
            numberInArr = i;
        }
    }

    cout << "Минимальная длинна: " << mixLen << " на " << numberInArr + 1 << " месте";
}


//Подсчитать количество слов во введенном предложении.
void Task12()
{
    string str = "QWE asd aff цываыв а daf s wsf sd fwg sgsfgwsfsefwef.";
    int spaceCount = CountSybolsInStr(str, ' ') + 1;
    cout << spaceCount;
}

//Удалить из строки первые буквы каждого слова.
void Task13()
{
    string str = "QWE asd aff цываыв а daf s wsf sd fwg t.";

    if (!str.find('.', 0))
        return;

    int spaceCount = CountSybolsInStr(str, ' ') + 1;

    string* strs = SplitStr(str, ' ');

    str = "";
    for (size_t i = 0; i < spaceCount; i++)
    {
        if (strs[i].length() > 1)
        {
            str += strs[i].substr(1, strs[i].length()-1) + " ";
        }
    }
    if (str[str.length()-3] == ' ')
    {
        str.erase(str.length() - 3, 1);
    }    
    cout << str;
}

int CountStrInStr(string str, string search)
{
    int strLen = str.length(), searchLen = search.length();
    if (strLen < 1 || searchLen < 1 || strLen < searchLen ) return 0;

    int count = 0;
    int max = strLen - searchLen;

    for (size_t i = 0; i < max; i++)
        if (str.substr(i, searchLen) == search) count++;

    return count;
}

int sentenceCountInStr(string str)
{
    int sentenceCount = 0;
    char delimetrs[]{'!','?', '.'};
    for (size_t i = 0; i < str.length(); i++)
    {
        if ((str[i] == '!' && (str[i+1] == '!' || str[i + 1] == '.' || str[i + 1] == '?')) ||
            (str[i] == '?' && (str[i + 1] == '!' || str[i + 1] == '.' || str[i + 1] == '?')) ||
            (str[i] == '.' && (str[i + 1] == '!' || str[i + 1] == '.' || str[i + 1] == '?')))
        {
            str.erase(i, 1);
            i--;
        }
    }
    for (size_t i = 0; i < 3; i++)
        sentenceCount += CountSybolsInStr(str, delimetrs[i]);
    return sentenceCount;
}

void reverseEverySentence(string &str)
{
    int start = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if ((str[i] == '!' && (str[i + 1] == ' ' || i + 1 == str.length())) ||
            (str[i] == '?' && (str[i + 1] == ' ' || i + 1 == str.length())) ||
            (str[i] == '.' && (str[i + 1] == ' ' || i + 1 == str.length())))
        {
            string substr = str.substr(start, (i+1)-start);
            reverse(substr.begin(), substr.end());
            str.replace(start, substr.length(), substr);
            i++;
            start = str[i] == ' ' ? i + 1 : i;
        }
    }
}

void Task14()
{
    string str = "QWE, QWE!.. aff.... цываыв, а daf. s wsf sd fwg t. QWE, QWE!.. aff.";

    //Кол-во слов в строке
    cout << CountStrInStr(str, "QWE") << endl;
    cout << CountStrInStr(str, "da") << endl;
    cout << CountStrInStr(str, "s") << endl;
    cout << CountStrInStr(str, "") << endl;
    cout << CountStrInStr(str, "QWE QWE aff цываыв а daf s wsf sd fwg t.QWE QWE aff цываыв а daf s wsf sd fwg t.") << endl;
    

    //Кол-во предложений в строке
    //cout << sentenceCountInStr(str);

    //Кол-во точек и запятых в строке
    //cout << (CountSybolsInStr(str, '.') + CountSybolsInStr(str, ','));

    //Перевернуть весь текст
    //reverse(str.begin(), str.end());
    //cout << str;

    //Переверните каждое предложение в тексте.
    reverseEverySentence(str);
    cout << str;
}



//Создание структуры с перегрузкой оператора '<<';
template <typename T>
struct KeyValuePair{
public: 
    T Key{}; 
    int Count{0};

    void AddCount()
    {
        Count++;
    }

    friend ostream& operator<<(ostream& os, const KeyValuePair& kvp)
    {
        os << "Ключ: " << kvp.Key << " Встречается - " << kvp.Count << " раз.";
        return os;
    }
};

template <typename T>
struct Dictioanry
{
private:
    int pairCount;
    int lastAddededNumber;
    KeyValuePair<T>* Pairs;
public:
    void AddCount(int pairNumber)
    {
        Pairs[pairNumber].AddCount();
    }

    void AddPair(KeyValuePair<T> kvp)
    {
        if (lastAddededNumber == pairCount)
        {
            IncreaseSize();
        }
        Pairs[lastAddededNumber] = kvp;
        lastAddededNumber++;
    }

    void AddPair(T key, int count)
    {
        if (lastAddededNumber == pairCount)
        {
            IncreaseSize();
        }
        Pairs[lastAddededNumber].Key = key;
        Pairs[lastAddededNumber].Count = count;
    }

    int PairCount(int number)
    {
        return Pairs[i].Count;
    }



    KeyValuePair<T> GetPair(size_t number)
    {
        return Pairs[number];
    }

    int Size()
    {
        return lastAddededNumber;
    }

    Dictioanry()
    {
        pairCount = 10;
        Pairs = new KeyValuePair<T>[pairCount];
        lastAddededNumber = 0;
    }

    Dictioanry(int size)
    {
        pairCount = size;
        Pairs = new KeyValuePair<T>[pairCount];
        lastAddededNumber = 0;
    }
private:
    void IncreaseSize()
    {
        KeyValuePair<T>* TempPairs = Pairs;//new KeyValuePair<T>[pairCount];
        /*for (size_t i = 0; i < pairCount; i++)
            TempPairs[i] = Pairs[i];*/

        Pairs = new KeyValuePair<T>[pairCount * 2];

        for (size_t i = 0; i < pairCount; i++)
            Pairs[i] = TempPairs[i];

        delete[] TempPairs;
    }
};

//Нужно найти самое часто встречающееся слово в тексте.
//Текст должен содержать не более 1000 символов.
//Вывод должен быть в UPPER CASE(верхний регистр).Написать функцию void mostRecent(char* text, char* word).
void Task15()
{
    string str = "Can you can the can with can the with the with the with the with?";
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    Dictioanry<string> dict2{};
    //KeyValuePair<string> dict[100];
    int size = CountSybolsInStr(str, ' ')+1;
    string* strArr = SplitStr(str, ' ');
    string mostPopular = "";
    int max = 0;
    //int searched = 0;

    dict2.AddPair(strArr[0], 1);
    //dict[0].Key = strArr[0];
    //dict[0].Count = 1;
    //searched++;
    for (size_t i = 1; i < size; i++)
    {

        bool isSearched = false;
        for (size_t j = 0; j < dict2.Size(); j++)
        {
            if (dict2.GetPair(j).Key == strArr[i])
            {
                dict2.AddCount(j);
                isSearched = true;
                break;
            }
        }

        if (!isSearched)
        {
            dict2.AddPair(strArr[i], 1);
        }
        /*bool isSearched = false;
        for (size_t j = 0; j < searched; j++)
        {
            if (dict[j].Key == strArr[i])
            {
                dict[j].AddCount();
                isSearched = true;
                break;
            }
        }

        if (!isSearched)
        {
            dict[searched].Key = strArr[i];
            dict[searched].Count = 1;
            searched++;
        }*/

        /*int countIn = CountStrInStr(str, strArr[i]);
        if (countIn > max)
        {
            mostPopular = strArr[i];
            max = countIn;
        }*/
    }

    for (size_t i = 0; i < dict2.Size(); i++)
    {
        if (int a = dict2.PairCount(i) > max)
        {
            mostPopular = strArr[i];
            max = a;
        }
    }
    cout << mostPopular;
}

#pragma endregion

int main()
{
    srand(time(nullptr));
    //setlocale(0, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    while (true)
    {
        Task15();        
        cout << "\nДля продолжения нажмите любую клавишу\n";
        cin.get();
        system("cls");
    }
    
    return 0;
}
