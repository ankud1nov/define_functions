#include <iostream>
#include <algorithm>
#include <list>
#define SQR(x) x*x
#define CUBE(X) (SQR(X)*(X))
#define ABS(X) (((X) < 0)? -(X) : X)

using namespace std;

constexpr int NOTFOUND = -1;;

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
void InitArray(T mass[], int lenght, int max, int min) {
    srand(time(0));
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
    int finishSort = finish ? finish : length ;

    for (size_t i = start; i < finishSort -1; i++)
    {
        T temp = arr[i];
        int position = i;
        for (size_t j = i+1; j < finishSort; j++)
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
    BubbleSort(arr, lenght, false, first, last+1);
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


int main()
{
    setlocale(0, "ru");
    int arr[10]{ 8,3,2,9,8,2,3,5,9,8 };
    quickSortR(arr, 10, 0, 10);
    ShowArray(arr, 10);
}
