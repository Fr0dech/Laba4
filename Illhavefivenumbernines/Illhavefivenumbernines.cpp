#include <iostream>
#include <algorithm>




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
        bool isPrime = false;
        int n, chislo;
        std::cout << "Enter the amount of numbers in your sequence: ";
        std::cin >> n;
        int mas[10000];
        for (int i = 0; i < n; i++)
        {
            std::cin >> chislo;
            for (int chi = 2; chi <= sqrt(chislo); chi++)
                if (chislo % chi == 0)
                {
                    isPrime = true;
                    break;
                }
                else
                {

                    break;
                }
            mas[i] = chislo;
        }
        if (isPrime)
        {
            insertionSort(mas, n);

            for (int i = 0; i < n; i++)
            {
                std::cout << mas[i] << " ";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << mas[i] << " ";
            }
        }
    }
    case 2:
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
        insertionSort1(evenmult,mas, masmult, n);
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
                else if (evenmult[i] == evenmult[i+1])
                    if (mas[i] > mas[i + 1])
                    {
                        int c = mas[i];
                        mas[i] = mas[i + 1];
                        mas[i + 1] = c;
                    }
        }
        


        for (int i = 0; i < n; i++)
            std::cout << mas[i] << " ";
    }
}



