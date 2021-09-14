
#include <iostream>
using namespace std;
struct Stek
{
    int num;
};
struct List
{
    Stek d;
    List* next;
};

void dobaBlenue(int*& arr, int& i, int& n, const int& pt)
{
    if (i % pt == 0)
    {
        n++;
    }
    int* stackm = new int[pt * n];
    for (int L = 0; L < i; L++) {
        stackm[L] = arr[L];
    }
    cout << "Введите число." << endl;
    cin >> stackm[i];
    delete[] arr;
    arr = stackm;
    i++;
}
//удаление для стэка через массив
void remove(int*& arr, int& i, int& n, const int& pt)
{
    if (i >= 1)
    {
        int* stackm = new int[pt * n];

        for (int L = 0; L < i; L++) {
            stackm[L] = arr[L];
        }
        arr[i] = 0;
        i--;
    }
    else
    {
        cout << "А удалять то нечего." << endl;
    }
}
//общие функции для стэка и масива
void print(int*& arr, int& i)
{
    if (i >= 1)
    {
        for (int y = 0; y < i; y++)
            cout << arr[y] << " ";
        cout << endl;
    }
    else
    {
        cout << "Нечего выводить." << endl;
    }
}
void Berh(int*& arr, int& i)
{
    if (i >= 1)
    {
        cout << arr[i - 1] << endl;
    }
    else
    {
        cout << "Стэк пуст" << endl;
    }
}
void clean(int*& arr, int& i, int& n, int& l)
{
    if (i >= 1)
    {
        for (int L = 0; L < i; L++) {
            arr[L] = 0;
        }
        i = 0;
        n = 1;
        l = 0;
    }
    else
    {
        cout << "Стэк и так пуст" << endl;
    }
}
void pysto(int& i)
{
    if (i >= 1)
    {
        cout << "Не пусто" << endl;
    }
    else
    {
        cout << "Пустота" << endl;
    }
}
//функция для выхода из меню
void clean1(int*& arr, int& i, int& n, int& l)
{
    if (i >= 1)
    {
        for (int L = 0; L < i; L++) {
            arr[L] = 0;
        }
        i = 0;
        n = 1;
        l = 0;
    }
}
//Удаление для очереди через массив
void ydalsnachala(int*& arr, int& i, int& n, const int& pt, int& l)
{
    if (i >= 1)
    {
        int* stackm = new int[pt * n];

        for (int L = 0; L < i; L++) {
            stackm[L] = arr[L];
        }
        arr[l] = 0;
        l++;
    }
    else
    {
        cout << "А удалять то нечего." << endl;
    }
}
//Функции для стэка и очереди со списками
void printList(List* u)
{
    List* p = u;
    if (p == NULL)
    {
        cout << "Стэк пуст" << endl;
    }
    else
    {
        while (p)
        {
            cout << p->d.num << " ";
            p = p->next;
        }
        cout << endl;
    }
}
void addtobeginoflist(List** u)
{
    List* t = new List;
    cin >> t->d.num;
    t->next = *u;
    *u = t;
}
void addtoendoflist(List** u)
{
    List* p = *u;
    List* L = new List;
    cin >> L->d.num;
    L->next = NULL;
    if (p == NULL)
    {
        *u = L;
    }
    else
    {
        while (1)
        {
            if (!p->next)
            {
                p->next = L;
                break;
            }
            p = p->next;
        }
    }
}
void Berxlist(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "Стэк пуст" << endl;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        cout << p->d.num << endl;
    }
}
void delstek(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "Стэк пуст" << endl;
    }
    else
    {
        p = p->next;
        *u = p;
    }
}
void ocher(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "Стэк пуст" << endl;
    }
    else
    {
        p = p->next;
        *u = p;
    }
}
void pystolist(List* u)
{
    List* p = u;
    if (p == NULL)
    {
        cout << "Пустота" << endl;
    }
    else
    {
        cout << "Не пусто" << endl;
    }
}
void cleanstek(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "Стэк пуст" << endl;
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }

    }
}
void cleanstek1(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }
    }
}
void cleanocher(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
        cout << "Стэк пуст" << endl;
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }

    }
}
void cleanocher1(List** u)
{
    List* p = *u;
    if (p == NULL)
    {
    }
    else
    {
        while (p != NULL)
        {
            p = p->next;
            *u = p;
        }

    }
}
int main()
{
    setlocale(LC_ALL, "ru");
    int i = 0;//последний елмент массива
    int n = 1;//число которое будем увеличивать если подтверждается кратность
    const int pt = 5;
    int* arr = new int[0];
    int f;
    int l = 0;
    int pos = 0;//позиция
    int sst = 0;
    List* u = NULL;
    do
    {
        cout << "1.Стек через массив" << endl << "2.Стэк списком" << endl << "3.Очередь через массив" << endl << "4.Очередь списком" << endl;
        cin >> f;
        if ((f >= 1) && (f <= 4))
        {
            switch (f)
            {
            case 1:
                //массив стэк
                do
                {
                    cout << "1.Вставить(в конец)" << endl << "2.Удалить(из конца)" << endl <<

                    "3.Распечатать" << endl << "4.Показать верхний" << endl << "5.Очистить" << endl << "6.Проверить пусто ли" << endl << "7.Выход из пункта" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        dobaBlenue(arr, i, n, pt);
                        break;
                    case 2:
                        remove(arr, i, n, pt);
                        break;
                    case 3:
                        print(arr, i);
                        break;
                    case 4:
                        Berh(arr, i);
                        break;
                    case 5:
                        clean(arr, i, n, l);
                        break;
                    case 6:
                        pysto(i);
                        break;
                    case 7:
                        clean1(arr, i, n, l);
                        break;
                    }
                } while (f != 7);
            case 2:
                //стэк списком
                do
                {
                    cout << "1.Вставить(в начало)" << endl << "2.Удалить(с начала)" << endl << "3.Распечатать" << endl << "4.Показать верхний" << endl << "5.Очистить стэк" << endl << "6.Проверить пусто ли" << endl << "7.Выход из пункта" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        addtobeginoflist(&u);
                        break;
                    case 2:
                        delstek(&u);
                        break;
                    case 3:
                        printList(u);
                        break;
                    case 4:
                        Berxlist(&u);
                        break;
                    case 5:
                        cleanstek(&u);
                        break;
                    case 6:
                        pystolist(u);
                        break;
                    case 7:
                        //exit
                        cleanstek1(&u);
                        break;
                    }
                } while (f != 7);
                break;
            case 3:
                do
                {
                    //массив очередь
                    cout << "1.Вставить(в конец)" << endl << "2.Удалить(из начала)" << endl << "3.Распечатать" << endl << "4.Показать верхний" << endl << "5.Очистить" << endl << "6.Проверить пусто ли" << endl << "7.Выход из пункта" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        dobaBlenue(arr, i, n, pt);
                        break;
                    case 2:
                        ydalsnachala(arr, i, n, pt, l);
                        break;
                    case 3:
                        print(arr, i);
                        break;
                    case 4:
                        Berh(arr, i);
                        break;
                    case 5:
                        clean(arr, i, n, l);
                        break;
                    case 6:
                        pysto(i);
                        break;
                    case 7:
                        clean1(arr, i, n, l);
                        break;
                    }
                } while (f != 7);
            case 4:
                //очередь списком
                do
                {
                    cout << "1.Вставить(в конец)" << endl << "2.Удалить(из начала)" << endl << "3.Распечатать" << endl << "4.Показать верхний" << endl << "5.Очистить" << endl << "6.Проверить пусто ли" << endl << "7.Выход из пункта" << endl;
                    cin >> f;
                    switch (f)
                    {
                    case 1:
                        addtoendoflist(&u);
                        break;
                    case 2:
                        ocher(&u);
                        break;
                    case 3:
                        printList(u);
                        break;
                    case 4:
                        Berxlist(&u);
                        break;
                    case 5:
                        cleanocher(&u);
                        break;
                    case 6:
                        pystolist(u);
                        break;
                    case 7:
                        //exit
                        cleanocher1(&u);
                        break;
                    }
                } while (f != 7);
                break;
            }
        }
        else
        {
            cout << "Пункта меню с заданым номером не существет";
        }
    } while (1);
}