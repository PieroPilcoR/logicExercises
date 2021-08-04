#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int firstDuplicate(int arr[100], int n);
void quick_sort(int arr[100], int izq, int der);
int main(){
    int n;
	cout << "Ingrese la dimension: " <<endl; cin >> n;
	int arr[n];
	srand(time(NULL));
	for(int i=0; i<n; i++){
        arr[i]=1+rand()%n;
        cout << arr[i] << " ";	
    }
    cout<<endl;
    cout<<"El primer elemento duplicado es: "<<firstDuplicate(arr,n);
}
int firstDuplicate(int arr[100], int n){
	int dup[100],i,j,c=0;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				dup[c]=arr[j];
				c++;
			}
		}
	}
	int value=dup[0];
	if(c>0){
		return value;
	}
	else{
		return -1;
	}
}
