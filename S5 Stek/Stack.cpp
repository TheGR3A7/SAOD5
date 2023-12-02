#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"

//������������� ������� ������� n ����� � ����� ���� ������ � ������������ ������� - �������.���� �������� �������� ��
// �������, �������� �������� � ����� ������������ � ��� �� ������� ��� ������, �������������� ������.���� �������
//���������, �� ��������� ������ �������.������ ������������������ ������� ����� � ���������� �������� ���
//������.��������� �������� ������ �������, ������� ��� ���� ��������.


// ������������� �������
void InitParking(Parking* parking, int n)
{
    parking->cars = (int*)malloc(n * sizeof(int));
    parking->top = -1;   // ���������� ������� �����
    parking->capacity = n;  // ������� ����������� �������
}

// ��������, ����� �� �������
bool isFull(Parking* parking) 
{
    return parking->top == parking->capacity - 1;
}

// ��������, ����� �� �������
bool isEmpty(Parking* parking) 
{
    return parking->top == -1;
}

// ������������ ������, ���������� ��� �������
void FreeParking(Parking* parking)
{
    free(parking->cars);
}

// �������� ������
void Push(Parking* parking, int carNumber)
{
    if (isFull(parking)) 
    {
        printf("������ %d �������, �� ������� ���������. �������.\n", carNumber);
    }
    else {
        parking->cars[++(parking->top)] = carNumber;
        printf("������ %d ������� � ������� �� �������.\n", carNumber);
    }
}

// ������ ������
void Pop(Parking* parking, int carNumber)
{
    if (isEmpty(parking))
    {
        printf("������ %d �� ������� �� �������.\n", carNumber);
    }
    else
    {
        // ����� ������� ������ � ��������
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
            printf("������ %d �� ������� �� �������. ����� �� �����.\n", carNumber);
        }
        else
        {
            for (int i = position; i < parking->top; i++)
            {
                parking->cars[i] = parking->cars[i + 1];
            }
            parking->top--;

            printf("������ %d ������� �� �������.\n", carNumber);
        }
    }
}


// �������� ���������� �������
void ShowStack(Parking* parking)
{
    if (isEmpty(parking)) 
        printf("������� �����.\n");
    else 
    {
        printf("���������� �������: ");
        for (int i = 0; i <= parking->top; i++) 
            printf("%d ", parking->cars[i]);
    }
    printf("\n");
}

// ����� �������� � �����
bool FindCar(Parking* parking, int carNumber)
{
    for (int i = 0; i <= parking->top; i++) 
    {
        if (parking->cars[i] == carNumber) 
        {
            printf("������ %d ������� �� �������.\n", carNumber);
            return true;
        }
    }
    printf("������ %d �� ������� �� �������.\n", carNumber);
    return false;
}


int main()
{
    system("chcp 1251");

    int n, carNumber;

    do {
    printf("������� ����������� �������: ");
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
            printf("1 - �������� ������.\n"
                "2 - ������ ������\n"
                "3 - ����� �� �������\n"
                "4 - �����\n");
            scanf("%i", &choice);
        } while (choice < 1 || choice > 4);
        system("cls");
        switch (choice)
        {
        case 1:
            do {
                printf("������� ����� ������: ");
                scanf("%d", &carNumber);
            } while (carNumber < 0);
            Push(&parking, carNumber);
            break;
        case 2:
            do {
                printf("������� ����� ������: ");
                scanf("%d", &carNumber);
            } while (carNumber < 0);
            Pop(&parking, carNumber);
            break;
        case 3:
            do {
                printf("������� ����� ������: ");
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