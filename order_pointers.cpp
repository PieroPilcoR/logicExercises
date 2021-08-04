#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void insercion(int arr[100], int n);
void selection (int arr[100], int n);
void seleccion (int arr[100], int n);
void seleccion_pure(int arr[100], int n);
void quick_sort(int arr[100], int izq, int der);
void Merge(int arr[100],int p, int q, int r);
void MergeSort(int arr[], int l, int r);
int main(){
    int n;
	cout << "Ingrese la dimension: "; cin >> n;
	int arr[n];
	srand(time(NULL));
	for(int i=0; i<n; i++){
        arr[i]=1+rand()%n;
        cout << arr[i] << " ";	
    }
    cout << endl;
    cout<<"Insercion: ";
	insercion(arr, n);
	cout<<endl;
    cout<<"Seleccion: ";
	seleccion_pure(arr, n);
	cout<<endl;
    cout<<"Quicksort: ";
	quick_sort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<"Merge: ";
    cout<<"..."<<endl;
    cout<<"Mergesort: ";
    MergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insercion (int *parr, int n){
    for(int i=0; i<n; i++){
        int temp=*(parr+i), j=i-1;
        while(*(parr+j)>temp && j>=0){
            *(parr+j+1)=*(parr+j);
            j--;
        }
        *(parr+j+1)=temp;
    }
    for(int i=0; i<n; i++){
        cout << *(parr+i) << " ";
    }
    cout << endl;
}

void selection (int *parr, int n){
    int min, temp;
    for(int i=0; i<n; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(*(parr+j)<*(parr+min)){
                min=j;
            }
        }
        temp=*(parr+i);
        *(parr+i)=*(parr+min);
        *(parr+min)=temp;
    }
    for(int i=0; i<n; i++){
        cout << *(parr+i) << " ";
    }
    cout << endl;
}
void seleccion_pure(int *parr, int n){
    int min, temp, *pmax=parr+n, *p, *s;
    for(p=parr; p<pmax; p++){	
        min=*p;
        for(s=p+1; s<pmax; s++){
            if(*s<min)
                min=*s;
        }
        temp=*p;
        *p=min;
        min=temp;
    }
    for(p=parr; p<pmax; p++){
        cout << *p << " ";
    }
    cout << endl;
}
void seleccion (int *parr, int n){
    int min, temp, *pmax, *p, j;
    for(int i=0; i<n; i++){
        min=i;
        pmax=parr+n;
        j=i+1;
        for(p=parr+j; p<pmax; p++, j++){
            if(*p<*(parr+min))
                min=j;
        }
        temp=*(parr+i);
        *(parr+i)=*(parr+min);
        *(parr+min)=temp;
    }
    for(p=parr; p<pmax; p++){
        cout << *p << " ";
    }
    cout << endl;
}
void quick_sort(int *parr, int izq, int der){
    int i=izq, j=der, temp;
    int p=*(parr+(izq+der)/2);
    while(i<=j){
        while(*(parr+i)<p){
            i++;
        }
        while(*(parr+j)>p){
            j--;
        }
        if(i<=j){
            temp=*(parr+i);
            *(parr+i)=*(parr+j);
            *(parr+j)=temp;
            i++;
            j--;
        }
    }
    if(izq<j){
        quick_sort(parr, izq, j);
    }
    if(i<der){
        quick_sort(parr, i, der);
    }
}
void Merge(int *parr, int p, int q, int r){
	int n1=q-p+1,i,j,k;
	int n2=r-q;
	int arr_1[n1], arr_2[n2];
	for(i=0;i<n1;i++){
		arr_1[i]=*(parr+p+i);
	}
	for(j=0;j<n2;j++){
		arr_2[j]=*(parr+q+j+1);
		//arr_2[j]=arr[q+j+1];
	}
	i=0,j=0;
	for(k=p;i<n1&&j<n2;k++){
		if(arr_1[i]<arr_2[j]){
			*(parr+k)=arr_1[i++];
		}
		else{
			*(parr+k)=arr_2[j++];
		}
	}
	while(i<n1){
		//arr[k++]=arr_1[i++];
		*(parr+k++)=arr_1[i++];
	}
	
	while(j<n2){
		//arr[k++]=arr_2[j++];
		*(parr+k++)=arr_2[j++];
	}
}
void MergeSort(int *parr,int p,int r){
	int q;                                
	if(p<r){
		q=(p+r)/2;
		MergeSort(parr,p,q);
		MergeSort(parr,q+1,r);
		Merge(parr,p,q,r);
	}
}
