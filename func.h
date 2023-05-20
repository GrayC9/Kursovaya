#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define k 3
#define tn 15
#define tk 100
#define t1 30
#define t2 60
#define a 2
#define b 4
#define c -1
#define N 50

float dt = (tk - tn) / (N - 1);

void arr_create_t(float* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = tn + i * dt;
    }
}

void arr_create_Uvx(float* arr, float* t, int n)
{
    for(int i = 0; i < n; i++)
    {
        if (t[i] <= t1)
        {
            arr[i] += a * (1 - exp(-b*(t[i] - tn)));
        }
        else if(t[i] <= t2)
        {
            arr[i] += a * (1 - exp(-b*(t1 - tn)));
        }
        else
        {
            arr[i] = 0;
        }
    }
}

float do_param(float* Uvx, float* t, int n)
{
    int min_index = 0;
    float min = Uvx[0];
    for(int i = 0; i < n; i++)
    {
        if(min > Uvx[i])
        {
            min = Uvx[i];
            min_index = i;
        }
    }
    return t[min_index];
}


void arr_create_Uvix(float* arr, float* Uvx, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] += a * Uvx[i] * Uvx[i] + b * Uvx[i] + c;
    }
}

void output_in_terminal(float* t, float* Uvx, float* Uvix, int n)
{
    printf("\n №        time   |     Uvx    |    Uvix\n"); // вывод таблицы
    for (int i = 0; i < n; i++)
    {
        printf("%2d      %3.3f       %7.3f     %7.3f\n", i+1, t[i], Uvx[i], Uvix[i]);
    }
    printf("\n");
}

void output_in_file(float* t, float* Uvx, float* Uvix, int n)
{
    FILE* f = fopen("results.txt", "a");
    fprintf(f,"\n №   |   time   |     Uvx    |    Uvix\n"); // вывод таблицы
    for (int i = 0; i < n; i++)
    {
        fprintf(f,"%2d      %3.3f       %7.3f     %7.3f\n", i+1, t[i], Uvx[i], Uvix[i]);
    }
    printf("Запись прошла успешно!\n");
    fclose(f);
}

int main(void)
{
    int n = N; // количество точек
    float* t = malloc(n * sizeof(float));
    float* Uvx = malloc(n * sizeof(float));
    float* Uvix = malloc(n * sizeof(float));

    arr_create_t(t, n);
    arr_create_Uvx(Uvx, t, n);
    arr_create_Uvix(Uvix, Uvx, n);

    output_in_terminal(t, Uvx, Uvix, n);
    output_in_file(t, Uvx, Uvix, n);

    free(t);
    free(Uvx);
    free(Uvix);

    return 0;
}
