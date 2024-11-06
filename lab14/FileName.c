#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 1000

double* fill_elems(double* ptr_array, int n) {
	double y = 0;
	double z = 0;
	z = 2.1 / n;
	for (int i = 0; i < n; i++) {
		y += z;
		ptr_array[i] = pow(y, 2) - pow(cos(y + 1), 2);
	}
	return ptr_array;
}

int put_elems(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("a[%d] = %lf\n", i, ptr_array[i]);
	}
}

double calc_elems(double* ptr_array, int n) {
	double first_positive = -1;
	double last_positive = -1;
	double sm = 0;
	for (int i = 0; i < n; i++) {
		if (ptr_array[i] > 0) {
			if (first_positive == -1) {
				first_positive = ptr_array[i];
			}
			last_positive = ptr_array[i];
		}
	}
	if (first_positive != -1 && last_positive != -1) {
		for (int i = 0; i < n; i++) {
			sm += ptr_array[i];
		}
	}
	return sm;
}

double sum_elems(double* ptr_array, int begin, int end) {
	double sm = 0;
	if (begin >= end) {
		return -1;
	}
	for (int i = begin; i < end; i++) {
		sm += ptr_array[i];
	}
	return sm;
}

int find_elem(double* ptr_array, int n, double elem) {
	double eps = 1e-6;
	for (int i = 0; i < n; i++) {
		if (fabs(ptr_array[i] - elem) < eps) {
			return i;
		}
	}
	return -1;
}

double max_elem(double* ptr_array, int k) {
	double mx = -1e-11;
	for (int i = 0; i <= k; i++) {
		if (ptr_array[i] > mx) {
			mx = ptr_array[i];
		}
	}
	return mx;
}

int main() {
	double array[N];
	int size;
	int begin;
	int end;
	double elem;
	int k;
	setlocale(LC_CTYPE, "RUS");
	printf("Введите размер массива\n");
	scanf("%d", &size);
	getchar();
	fill_elems(array, size);
	put_elems(array, size);
	printf("Сумма между первым и последним элементов равна %lf\n", calc_elems(array, size));
	printf("Введите индекс элемента, с которого начать сумму\n");
	scanf("%d", &begin);
	getchar();
	printf("Введите индекс элемента, на котором окончить сумму\n");
	scanf("%d", &end);
	getchar();
	if (sum_elems(array, begin, end) == -1) {
		printf("Начальный индекс должен быть меньше/не совпадать с последним!\n");
	}
	else {
		printf("Сумма с %d до %d равна %lf\n", begin, end, sum_elems(array, begin, end));
	}
	printf("Введите значение элемента, который хотите найти\n");
	scanf("%lf", &elem);
	getchar();
	printf("Индекс элемента - %d\n", find_elem(array, size, elem));
	printf("Введите индекс элемента, до которого будет находится максимальное значение\n");
	scanf("%d", &k);
	getchar();
	printf("Максимальное значение до %d элемента включительно - %lf\n", k, max_elem(array, k));
}