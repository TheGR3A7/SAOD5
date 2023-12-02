#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"

//Автомобильная стоянка вмещает n машин и имеет одну полосу с единственным въездом - выездом.Если владелец приходит за
// машиной, временно выезжают и потом возвращаются в том же порядке все машины, загораживающие проезд.Если стоянка
//заполнена, то прибывшая машина уезжает.Задана последовательность номеров машин с признаками прибытия или
//убытия.Составить протокол работы стоянки, сообщая обо всех событиях.


// Инициализация стоянки
void InitParking(Parking* parking, int n)
{
    parking->cars = (int*)malloc(n * sizeof(int));
    parking->top = -1;   // Изначально стоянка пуста
    parking->capacity = n;  // Задание вместимости стоянки
}

// Проверка, полна ли стоянка
bool isFull(Parking* parking) 
{
    return parking->top == parking->capacity - 1;
}

// Проверка, пуста ли стоянка
bool isEmpty(Parking* parking) 
{
    return parking->top == -1;
}

// Освобождение памяти, выделенной для стоянки
void FreeParking(Parking* parking)
{
    free(parking->cars);
}

// Прибытие машины
void Push(Parking* parking, int carNumber)
{
    if (isFull(parking)) 
    {
        printf("Машина %d прибыла, но стоянка заполнена. Уезжает.\n", carNumber);
    }
    else {
        parking->cars[++(parking->top)] = carNumber;
        printf("Машина %d прибыла и въехала на стоянку.\n", carNumber);
    }
}

// Убытие машины
void Pop(Parking* parking, int carNumber)
{
    if (isEmpty(parking))
    {
        printf("Машина %d не найдена на стоянке.\n", carNumber);
    }
    else
    {
        // Найти позицию машины в парковке
        int position = -1;
        for (int i = 0; i <= parking->top; i++)
        {
            if (parking->cars[i] == carNumber)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            printf("Машина %d не найдена на стоянке. Выйти не может.\n", carNumber);
        }
        else
        {
            for (int i = position; i < parking->top; i++)
            {
                parking->cars[i] = parking->cars[i + 1];
            }
            parking->top--;

            printf("Машина %d выехала со стоянки.\n", carNumber);
        }
    }
}


// Показать содержимое стоянки
void ShowStack(Parking* parking)
{
    if (isEmpty(parking)) 
        printf("Стоянка пуста.\n");
    else 
    {
        printf("Содержимое стоянки: ");
        for (int i = 0; i <= parking->top; i++) 
            printf("%d ", parking->cars[i]);
    }
    printf("\n");
}

// Поиск элемента в стеке
bool FindCar(Parking* parking, int carNumber)
{
    for (int i = 0; i <= parking->top; i++) 
    {
        if (parking->cars[i] == carNumber) 
        {
            printf("Машина %d найдена на стоянке.\n", carNumber);
            return true;
        }
    }
    printf("Машина %d не найдена на стоянке.\n", carNumber);
    return false;
}


int main()
{
    system("chcp 1251");

    int n, carNumber;

    do {
    printf("Введите вместимость стоянки: ");
    scanf("%d", &n);
    } while (n < 1);

    Parking parking;
    InitParking(&parking, n);


    int choice;
    bool flag = true;
    while (flag)
    {
        do
        {
            printf("1 - Прибытие машины.\n"
                "2 - Убытие машины\n"
                "3 - Поиск на стоянке\n"
                "4 - выйти\n");
            scanf("%i", &choice);
        } while (choice < 1 || choice > 4);
        system("cls");
        switch (choice)
        {
        case 1:
            do {
                printf("Введите номер машины: ");
                scanf("%d", &carNumber);
            } while (carNumber < 0);
            Push(&parking, carNumber);
            break;
        case 2:
            do {
                printf("Введите номер машины: ");
                scanf("%d", &carNumber);
            } while (carNumber < 0);
            Pop(&parking, carNumber);
            break;
        case 3:
            do {
                printf("Введите номер машины: ");
                scanf("%d", &carNumber);
            } while (carNumber < 0);
            FindCar(&parking, carNumber);
            break;
        case 4:
            flag = false;
            break;
        }

        ShowStack(&parking);
    }

    FreeParking(&parking);

    return 0;
}