#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define k 3
 
void arr_create_t(float* arr, float dt, int n)
{
    dt = 1.0/(n - 1);
    for(int i = 0; i < n; i++) // массив времени t
    {
        arr[i] = i*dt;
    }
}
 
void arr_create_Uvx(float* arr ,int* Ui, float* t, int n, int kd)
{
    for(int i = 15; i < n; i++)
    {
        if (t[i] <= t1)
        {
            arr[i] = a * (1 - exp(-b * (t[i] - tn)));
        }
        else if(t[i] <= t2 && t[i] >= t1)
        {
            arr[i] = a * (1 - exp(-b * (t1 - tn))) * exp(-c * (t[i] - t2));
        }
        else
        {
            arr[i] = 0;
        }
    }
}

 
void arr_create_Uvx2(float* arr ,int* Ui, float* t, int n, int kd)
{
    for(int i = 0; i < n; i++) // массив входного сигнала Uvx
    {
        arr[i] = 5 * cos(0 * 2 * M_PI * t[i]) + 80 * cos(1 * 2 * M_PI * t[i]) + 10 * cos(2 * 2 * M_PI * t[i]) + 5 * cos(3 * 2 * M_PI * t[i]);
    }
}
 
void arr_create_Uvix(float* arr, float* Uvx, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = a * Uvx[i] * Uvx[i] + b * Uvx[i] + c;
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
 
void preview(void)
{
    printf("Курсовая работа по информатике\nТема: Анализ сигнала на выходе электрической  цепи.\nСтудента гр. ИКПИ-12 Соколова Никиты.\n\n");
}
 
void preview_menu(void)
{
    printf("Меню:\n0)Таблица с графиками\n1)Расчёт данных введённых с клавиатуры\n2)Запись данных в файл\n3)Вывод в данных в терминал\n4)График Uvx\n5)График Uvix\n6)Параметр для Uvx\n7)Параметр при Uvix\n81)Параметр с погрешностью Uvx\n82)Параметр с погрешностью Uvix\n9)Выход\n");
}
 
int numders_of_points(int* n)
{
    printf("Введите кол-во точек: ");
    scanf("%d", &*n);
    return *n;
}
 
float parameter(float* t, float* Uvx, int n, char* name_of_arr)
{
    float min = Uvx[0];
    int min_index = 0;
    int vvod = 0;
    for(int i = 0; i < n; i++)
    {
        if(min > Uvx[i])
        {
            min = Uvx[i];
            min_index = i;
        }
    }
    printf("Минимальное значение %s принимает при времени t = %f\n", name_of_arr, t[min_index]);
    printf("Записать в файл(1-Да,2-Нет): ");
    scanf("%d", &vvod);
 
    if(vvod == 1)
    {
        FILE* f = fopen("results.txt", "a");
        fprintf(f, "Минимальное значение %s принимает при времени t = %f\n", name_of_arr, t[min_index]);
        fclose(f);
        printf("Запись прошла успешно!\n");
    }
    return 0;
}
 
void clear_file(void)
{
    FILE* f = fopen("results.txt", "w");
    fclose(f);
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
 
void pogr1(float(*do_param)(float* Uvx, float* t, int n),void(*arr_create_t)(float* t, float dt, int n),void(*arr_create_Uvx2)(float* Uvx, float* Ui, float* t, int n, int kd), void(*arr_create_Uvix)(float* Uvix, float* Uvx, int n), float *t, float* Uvx, float* Uvix, int* Ui, int n, float dt)
{
    float p = 1, par = 1000, par1 = 0;
 
    while(p > 0.001)
    {
        arr_create_t(t, dt, n);
        arr_create_Uvx2(Uvx, Ui, t, n, k);
        arr_create_Uvix(Uvix, Uvx, n);
        par1 = do_param(Uvix, t, n);
        p = fabs(par - par1) / par1;
        printf("n = %3d, t(Uvx) = %f,погр. = %f\n",n , do_param(Uvx, t, n), p);
        par = par1;
        n *= 2;
    }
}
 
void pogr2(float(*do_param)(float* Uvx, float* t, int n),void(*arr_create_t)(float* t, float dt, int n),void(*arr_create_Uvx2)(float* Uvx, float* Ui, float* t, int n, int kd), void(*arr_create_Uvix)(float* Uvix, float* Uvx, int n), float *t, float* Uvx, float* Uvix, int* Ui, int n, float dt)
{
    float p = 1, par = 1000, par1 = 0;
 
    while(p > 0.001)
    {
        arr_create_t(t, dt, n);
        arr_create_Uvx2(Uvx, Ui, t, n, k);
        arr_create_Uvix(Uvix, Uvx, n);
        par1 = do_param(Uvix, t, n);
        p = fabs(par - par1) / par1;
        printf("n = %3d, t(Uvix) = %f,погр. = %f\n",n , do_param(Uvix, t, n), p);
        par = par1;
        n *= 2;
    }
}