#include<iostream>
#include<math.h>
using namespace std;
const int FILAS = 5;
const int COLUMNAS = 6;
//typedef int Mat[FILAS][COLUMNAS];
//void ordenamiento_por_columnas(Mat mat, Mat orden, int filas, int col);
void ordenamiento_por_columnas(int mat[5][6], int orden[5][6], int filas, int col);
void imprimir(int arr[5][6], int filas, int col);
void quick_sort(int arr[100], int izq, int der);
int main(){
	/*const int FILAS = 5;
	const int COLUMNAS = 6;
	typedef int Mat[FILAS][COLUMNAS];*/
	int notas[5][6] =	{{3,17,7,8,10,13},
				{20,15,4,9,6,14},
				{12,18,16,19,11,5},
				{11,14,18,20,17,18},
				{10,19,12,17,20,16}};
	int orden[5][6];
	ordenamiento_por_columnas(notas, orden, FILAS, COLUMNAS);
	imprimir(orden, FILAS, COLUMNAS);
}
	
void imprimir(int arr[5][6], int filas, int col){
	for(int i=0; i<filas; i++){
		for(int j=0; j<col; j++){
			cout<<arr[j][i]<<" ";
		}
		cout<<endl;
	}	
}
void ordenamiento_por_columnas(int mat[5][6], int orden[5][6], int filas, int col){
//void ordenamiento_por_columnas(Mat mat[5][6], Mat orden[5][6], int filas, int col){
//void ordenamiento_por_columnas(Mat mat, Mat orden, int filas, int col){
	int i, j;
	//int orden_trans[6][5];
	for(j=0; j<col; j++){
		for(i=0; i<filas; i++){
			orden[j][i]=mat[i][j];
		}
	}
	for(i=0; i<COLUMNAS; i++){
		quick_sort(orden[i], 0, FILAS-1);
	}
}
void quick_sort(int arr[100], int izq, int der){
    int i=izq, j=der, temp;
    int p=arr[(izq+der)/2];
    while(i<=j){
        while(arr[i]<p){
            i++;
        }
        while(arr[j]>p){
            j--;
        }
        if(i<=j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    if(izq<j){
        quick_sort(arr, izq, j);
    }
    if(i<der){
        quick_sort(arr, i, der);
    }
}
