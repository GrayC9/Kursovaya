#include "func.h"
#define N 1000

// Определение констант
#define a 2
#define b 4
#define c -1
#define t1 30
#define t2 60
#define tn 15
#define tk 100

void arr_create_t(float* arr, float tn, float tk, int n);
void arr_create_Uvx(float* arr, float* t, int n);
void arr_create_Uvix(float* arr, float* Uvx, int n);
void output_in_terminal(float* t, float* Uvx, float* Uvix, int n);
void output_in_file(float* t, float* Uvx, float* Uvix, int n);
void preview(void);
void preview_menu(void);
int numders_of_points(int* n);
void parameter(float* t, float* Uvx, int n, char* name_of_arr);
void pogr1(float(*do_param)(float* Uvx, float* t, int n),void(*arr_create_t)(float* t, float dt, int n),void(*arr_create_Uvx2)(float* Uvx, float* Ui, float* t, int n, int kd), void(*arr_create_Uvix)(float* Uvix, float* Uvx, int n), float *t, float* Uvx, float* Uvix, int* Ui, int n, float dt);
float do_param(float* Uvx, float* t, int n);

void arr_create_Uvx(float* arr, float* t, int n)
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

void arr_create_Uvix(float* arr, float* Uvx, int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = a * Uvx[i] * Uvx[i] + b * Uvx[i] + c;
    }
}

int main() {
    float dt = (tk - tn) / (N - 1);
    int n = 0, input = 0, cycle = 1;
    int Ui[4] = {5, 80, 10, 5};
    clear_file();
    preview();
    numders_of_points(&n);
    float t[N] = {0}, Uvx[N] = {0}, Uvix[N] = {0};
    preview_menu();
    while (cycle)
    {
        printf("Ввод: ");
        scanf("%d", &input);
        switch (input)
        {
            case 0:
                system("open graph.numbers");
                break;
            case 1:
                arr_create_t(t, tn, tk, n);
                arr_create_Uvx(Uvx, t, n);
                arr_create_Uvix(Uvix, Uvx, n);
                printf("Расчёт произведён\n");
                break;
            case 2:
                output_in_file(t, Uvx, Uvix, n);
                break;
            case 3:
                output_in_terminal(t, Uvx, Uvix, n);
                break;
            case 4:
                system("open Uvx.png");
                break;
            case 5:
                system("open Uvix.png");
                break;
            case 6:
                parameter(t, Uvx, n, "Uvx");
                break;
            case 7:
                parameter(t, Uvix, n, "Uvix");
                break;
            case 81:
                pogr1(do_param, arr_create_t, arr_create_Uvx, arr_create_Uvix, t, Uvx, Uvix, Ui, n, dt);
                break;
            case 82:
                pogr2(do_param, arr_create_t, arr_create_Uvx, arr_create_Uvix, t, Uvx, Uvix, Ui, n, dt);
                break;
            case 9:
                cycle--;
            default:
                break;
        }
    }
    return 0;
}
