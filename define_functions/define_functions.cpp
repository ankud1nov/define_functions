#include <iostream>
#include <algorithm>
#include <list>
#include <cstdarg>
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
void ShowArray(int arr[], const int SIZE) {
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i];
        cout << "\t";
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

int main()
{
    srand(time(nullptr));
    setlocale(0, "ru");
    Indexes14();
    return 0;
}
