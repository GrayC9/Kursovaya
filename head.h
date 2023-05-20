#include "func.c"
void arr_create_t(float* arr, float tn, float tk, int n);
void arr_create_Uvx(float* arr ,int* Ui, float* t, int n, int kd);
void arr_create_Uvix(float* arr, float* Uvx, int n);
void arr_create_Uvx2(float* arr ,int* Ui, float* t, int n, int kd);
void output_in_terminal(float* t, float* Uvx, float* Uvix, int n);
void output_in_file(float* t, float* Uvx, float* Uvix, int n);
void preview(void);
void preview_menu(void);
int numders_of_points(int* n);
void parameter(float* t, float* Uvx, int n, char* name_of_arr);
void pogr1(float(*do_param)(float* Uvx, float* t, int n),void(*arr_create_t)(float* t, float dt, int n),void(*arr_create_Uvx2)(float* Uvx, float* Ui, float* t, int n, int kd), void(*arr_create_Uvix)(float* Uvix, float* Uvx, int n), float *t, float* Uvx, float* Uvix, int* Ui, int n, float dt);
float do_param(float* Uvx, float* t, int n);