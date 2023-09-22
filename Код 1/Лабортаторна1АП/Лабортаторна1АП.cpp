#include <stdio.h> // Виклик головних модулів
#include <math.h>

int main()
{
    int taskNum;
    printf("Choose the task: "); // Вибір задачі
    scanf_s("%i", &taskNum);
    printf("Variant 7. Task %i:\n", taskNum);

    if (taskNum == 1) // Якщо обрана задача 1
    {
        float a, b, c, k, x, y; // Створення змінних
        
        while(true)
        {
            printf("Enter the value of variable a: "); // Запит на введення значень аргументів
            scanf_s("%g", &a);
            printf("Enter the value of variable b: ");
            scanf_s("%g", &b);
            printf("Enter the value of variable c: ");
            scanf_s("%g", &c);
            printf("Enter the value of variable k: ");
            scanf_s("%g", &k);

            if (a == 0 || k == 0 || b == 0 || c == 0 || pow(4 * k / pow(a, 2) * c, -1) < 0) // Перевірка аргументів за ОДЗ
            {
                printf("Please, enter another values for variables (a, b, c, k != 0 and k/c > 0).\n"); // Запит на повторне введення, якщо аргументи не входять в ОДЗ
            }
            else 
            {
                break;
            }
        }

        x = pow(a, 2) * exp(-pow(a / b, 2)); // Виконання розрахунків за формулами
        y = atan(sqrt(pow((4 * k) / (pow(a, 2) * c), -1)));
        
        printf("If a = %g, b = %g, c = %g, k = %g, \nthen x = %g, y = %g", a, b, c, k, x, y); // Виведення результатів
    }
    else if (taskNum == 2) // Якщо обрана задача 2
    {
        float firstBorder, lastBorder, a, delta, x, y; // Створення змінних
        
        printf("Enter the value of variable a: "); // Запит на введення значень аргументів
        scanf_s("%g", &a);
        wrongVariables: 
        printf("Enter the value of the first border: ");
        scanf_s("%g", &firstBorder);
        printf("Enter the value of the last border: ");
        scanf_s("%g", &lastBorder);
        if (firstBorder > lastBorder) // Перевірка меж інтервалу
        {
            printf("Wrong values of borders. Please, enter again.\n"); // Повторний запит на введення аргументів при недопустимих значеннях
            goto wrongVariables;
        }
        printf("Enter the value of delta x: ");
        scanf_s("%g", &delta);

        printf("If x belongs to [%f ; %f], delta x = %f, a = %f:\n", firstBorder, lastBorder, delta, a);
        for (x = firstBorder; x <= lastBorder; x += delta) // Виклик циклу для визначення значень змінних x i y
        {
            if (x <= 0.5) 
            {
                y = (pow(x, 2) - 5 * x + 6) / (pow(x, 2) + 1); // Застосування першої формули при певних значеннях x
            }
            else
            {
                y = pow(x, 2.0 / 3) - pow((pow(x, 2) - 1), 1.0 / 3) + exp(a); // Застосування другої формули у інших випадках
            }
            printf("x = %f, y = %f\n", x, y); // Виведення результатів
        }
    }
    else // Якщо обрана задача, якої не існує
    {
        printf("This task doesn't exist."); 
    }
    return 0;
}
