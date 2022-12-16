#include <iostream>
#include <algorithm>




bool isPrime(int a) {
    bool flag = true;
    if (a < 2) {
        return false;
    }
    for (int i = 2; i < std::sqrt(a); i++) {
        if (a % i == 0) {
            flag = false;
        }
    }
    return flag;
}
void insertionSort(int list[], int listLength)
{
    for (int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while (j >= 0 && list[j] > list[j + 1])
        {
            std::swap(list[j], list[j + 1]);
            
            std::cout << "";
            j--;
        }
    }
}

void insertionSort1(int list[], int list0[], int list1[], int listLength)
{
    for (int i = 1; i < listLength; i++)
    {
        int j = i - 1;
        while (j >= 0 && list[j] > list[j + 1])
        {
            std::swap(list[j], list[j + 1]);
            std::swap(list0[j], list0[j + 1]);
            std::swap(list1[j], list1[j + 1]);
            std::cout << "";
            j--;
        }
    }
}


int main()
{
    int no;
    std::cin >> no;
    switch (no)
    {
    case 1:
    {
        int l;
        int array[10000];
        std::cout << "Enter the amount of numbers in your sequence: ";
        std::cin >> l;
        std::cout << "Enter numbers." << std::endl;
        bool flag = false;
        for (int i = 0; i < l; i++) {
            std::cin >> array[i];
            if (isPrime(array[i])) {
                flag = true;
            }
        }
        if (flag == true) {
            insertionSort(array, l);
        }
        for (int i = 0; i < l; i++) {
            std::cout << array[i] << " ";
        }
        break;
    }

    case 2:
    {
        int n, chislo, proizv = 1;
        std::cout << "Enter the amount of numbers in your sequence: ";
        std::cin >> n;
        int mas[1000];
        int masmult[1000];
        int evenmult[1000];
        for (int i = 0; i < n; i++)
        {
            std::cin >> chislo;
            mas[i] = chislo;
            for (proizv = 1; chislo; chislo /= 10)
                proizv *= chislo % 10;
            masmult[i] = proizv;
        }

        for (int i = 0; i < n; i++)
        {
            int s = mas[i];
            for (int j = 0; s > 9;)
                s /= 10;
            evenmult[i] = s;
        }
        insertionSort1(evenmult, mas, masmult, n);
        insertionSort1(masmult, mas, evenmult, n);
        for (int i = 0; i < n - 1; i++)
        {
            if (masmult[i] == masmult[i + 1])
                if (evenmult[i] > evenmult[i + 1])
                {
                    int c = mas[i];
                    mas[i] = mas[i + 1];
                    mas[i + 1] = c;
                    c = evenmult[i];
                    evenmult[i] = evenmult[i + 1];
                    evenmult[i + 1] = c;
                }
                else if (evenmult[i] == evenmult[i + 1])
                    if (mas[i] > mas[i + 1])
                    {
                        int c = mas[i];
                        mas[i] = mas[i + 1];
                        mas[i + 1] = c;
                    }
        }



        for (int i = 0; i < n; i++)
            std::cout << mas[i] << " ";
        break;
    }
    case 3:
    {
        int a[100][100];
        int n, m;
        std::cout << "Enter amount of rows and columns." << std::endl;
        std::cin >> n >> m;
        int max = 100000000;
        int max_ind = -1;
        std::cout << "Enter numbers." << std::endl;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                std::cin >> a[i][j];
                if (a[i][j] % 2 != 0) {
                    count++;
                }
            }
            if (count > max) {
                max = count;
                max_ind = i;
            }
        }
        std::cout << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == max_ind && max_ind != -1) {
                    std::cout << a[i][j] * a[i][j] << " ";
                }
                else
                {
                    std::cout << a[i][j] << " ";
                }
            }
            std::cout << '\n';
        }
        break;
    }
    }
}



