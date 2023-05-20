#include "head.h"
#define N 1000
#define a 2
#define b 4
#define c -1
#define t1 30
#define t2 60
#define tn 15
#define tk 100
int main() {
    float tn = 0, tk = 1;
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
                arr_create_t(t, dt, n);
                arr_create_Uvx(Uvx, Ui, t, n, k);
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
                pogr1(do_param, arr_create_t, arr_create_Uvx2, arr_create_Uvix, t, Uvx, Uvix, Ui, n, dt);
                break;
            case 82:
                pogr2(do_param, arr_create_t, arr_create_Uvx2, arr_create_Uvix, t, Uvx, Uvix, Ui, n, dt);
                break;
            case 9:
                cycle--;
            default:
                break;
        }
    }
    return 0;
}