#ifndef Ordenador_h
#define Ordenador_h
#include <cstdlib>
#include <cmath>
class Ordenador{
	private:
    // Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos métodos quiera.
		void mergeSortPrivate(int *A, int p, int r) {
			if (p >= r) {
				return;
			}
			int q = ((p+r)/2);
			mergeSortPrivate(A, p, q);
			mergeSortPrivate(A, q+1, r);
			merge(A, p, q, r);
	    }

		void merge(int *A, int p, int q, int r) {
			int nl = (q - p) + 1;
			int nr = r - q;
			
			int* L = new int[nl];
			int* R = new int[nr];

			for (int i = 0; i < nl; ++i) {
				L[i] = A[p + i];
			}
			for (int j = 0; j < nr; ++j) {
				R[j] = A[q+j+1];
			}

			int i = 0;
			int j = 0;
			int k = p;

			while (i < nl && j < nr) {
				if (L[i] <= R[j]){
					A[k] = L[i];
					++i;
				} else {
					A[k] = R[j];
					++j;
				}
				++k;
			}
			
			while (i < nl) {
				A[k] = L[i];
				++i;
				++k;
			}
			while (j < nr) {
				A[k] = R[j];
				++j;
				++k;
			}

			//
			delete[] L;
			delete[] R;
		}

		int searchMax(int* A, int n){
			int maxNumber = A[0];
			for (int i = 1; i < n; ++i) {
				if (A[i] > maxNumber) {
					maxNumber = A[i];
				}
			}
			return maxNumber;
		}
		void changeEle(int* a, int* b) {
			int aux = *a;
			*a = *b;
			*b = aux;
		}
		int partition (int* A, int left, int right) {
			int pivot = A[right];
			int i = (left - 1);

			for (int j = left; j <= right - 1; ++j) { 
				if (A[j] <= pivot) {
					++i;
					changeEle(&A[i], &A[j]);
				}
			}
			changeEle(&A[i + 1], &A[right]);
			return (i + 1);

		}
		void quickSort(int* A, int left, int right) {
			if (left < right) {
				int pivot = partition(A, left, right);

				quickSort(A, left, pivot - 1);
				quickSort(A, pivot + 1, right);
			}
		}


		void heapUp(int* A, int n, int i) {
			int mayor = i;
			int left = 2 * i + 1;
			int right = 2 * i +2;

			if (left < n && A[left] > A[mayor]) {
				mayor = left;
			}

			if (right < n && A[right] > A[mayor]) {
				mayor = right;
			}

			if (mayor != i) {
				changeEle(&A[i], &A[mayor]);
				heapUp(A, n, mayor);
			}
		}

		void countingSort(int* A, int n, int exponent, int const base) {
			/*cumulativeCount tiene un tamanio n solamente por evitar un 
			segmentation fault, pero solo se usan las primeras 10 posiciones*/
			int cumulativeCount[n] = {0};
			int* orderdedArray = new int[n];

			//Conteo de elementos en array auxiliar
			for (int i = 0; i < n; ++i) {
				cumulativeCount[(A[i]/ exponent) % base]++;
			}
			//suma acumulativa
			for (int i = 1; i < n; ++i) {
				cumulativeCount[i] += cumulativeCount [i - 1];
			}
			//areglo resultado
			for (int i = n - 1; i >= 0; --i) {
				orderdedArray[cumulativeCount[(A[i]/exponent) % base] - 1 ] = A[i];
				cumulativeCount[(A[i]/exponent) % base]--;
			}

			for (int i = 0; i < n; ++i) {
				A[i] = orderdedArray[i];
			}

			delete[] orderdedArray;

		}
	public:
	Ordenador(){};
	~Ordenador(){};
    // Si no implementa algunos de los métodos de ordenamiento no lo borre;
    // déjelo con el cuerpo vacío para evitar errores de compilación, ya
    // que se va a ejecutar el mismo «main» para todas las tareas.
    // Implemente los algoritmos en este archivo, no en un CPP.

	void seleccion(int *A, int n) {
		A = A-1; 
		for(int i = 1; i <= n; ++i) {
			int minIndex = i;
			for (int j = i + 1; j <= n; ++j) {
				if (A[j] < A[minIndex]) {
					minIndex = j;
				}
			}
			//INTERCAMBIO DE ELEMENTO MENOR CON PRIMERA POSICION DEL ARRAY SIN ORDENAR
			int temporal = A[i];
			A[i] = A[minIndex];
			A[minIndex] = temporal;
		}
	}
	
	void insercion(int *A, int n) {
		A = A-1;
		for (int i = 2; i <= n; ++i) {
			int key = A[i];
			int j = i-1;
			while (j > 0 && A[j] > key) {
				A[j+1] = A[j];
				--j;
			}
			A[j+1] = key;
		}
	
	}

	void mergesort(int *A, int n) {
		mergeSortPrivate(A, 0, n - 1);
	}

	void radixsort(int *A, int n) {
		int base = static_cast<int>(floor(log2(n)));
		int maxNumber = searchMax(A, n);
		for(int exponent = 1; maxNumber / exponent > 0; exponent *= base) {
			countingSort(A, n,  exponent, base);
		}

	}

	void quicksort(int *A, int n) {
		quickSort(A, 0, n - 1);
	}

	void heapsort(int *A, int n) {
		for (int i = n / 2 -1; i>=0; --i) {
			heapUp(A, n, i);
		}
		for (int i =n - 1; i>=0; --i){
			changeEle(&A[0],&A[i]);
			heapUp(A, i, 0);
		}

	}
	

	
};
#endif
