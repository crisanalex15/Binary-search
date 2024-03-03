#include <stdlib.h>
#include <stdio.h>

int cmpfunction(const void* a, const void* b)
{
	return ((*(int*)b) - *(int*)a);
}

int cautareLiniara(int* v, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (v[i] == x) {
			printf("S-a gasit elementul i = ");
			return i;
		}
	}
	printf("Nu s-a gasit elementul,verdict:");
	return -1;
}

int cautareBinara(int* v, int n, int x) {
	int li = 0, lf = n - 1;

	while (li <= lf) {
		int k = (li + lf) / 2;

		if (x == v[k]) {
			printf("S-a gasit elementul %d: ", x);
			return 1;
		}
		else if (x < v[k]) {
			lf = k - 1;
		}
		else {
			li = k + 1;
		}
	}

	printf("Elementul %d nu a fost gasit in vectorul v.\n", x);
	return 0;
}


int main()
{
	int vector[100], n = 0, i = 0, x = 0;
	printf("Dimensiunea vectorului = ");
	scanf("%d", &n);
	for (i=0; i < n; i++)
	{
		printf("v[%d] = ", i);
		scanf("%d", &vector[i]);
	}
	printf("\n");
	printf("Elementul x = ");
	scanf("%d", &x);
	qsort(vector, n, sizeof(int), cmpfunction);
	for (i=0; i < n; i++)
	{
		printf("v[%d] = %d\n", i, vector[i]);
	}
	printf("%d\n", cautareLiniara(vector, n, x));
	cautareBinara(vector, n, x);
	printf("\n");
	system("pause");
	return 0;
}

/*
Realizati un program ce contine urmatoarele:

- vector `v` de dimensiunea `n` cu numere intregi ordonate descrescator

- functie cautare liniara a elementului `x` in vectorul `v`

- functie cautare binara a elementului `x` in vectorul `v`
*/