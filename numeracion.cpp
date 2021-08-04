#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
int cambio(int n, int b, int c);
int main(){
    int n,b;
    do{
    	cout << "Ingrese un numero: "<<endl; cin >> n;
    }while(n<=0);
    do{
    	cout << "Ingrese la base: "<<endl; cin >> b;
    }while(b<2&& b>9);
	cout<<"El numero "<<n<<" en base "<<b<<" es: "<<cambio(n,b,-1);
	/*cout << "Ingrese la dimension: "<<endl; cin >> n;
	srand(time(NULL));
	for(int i=0; i<n; i++){
        arr[i]=1+rand()%n;
        cout << arr[i] << " ";	
    }
    cout<<endl;
    subvector(arr,n);*/
}
int cambio(int n, int b, int c){
	int r,nt=0;
	n=n/b;
	r=n%b;
	c++;
	if(n<b){
		return cambio(n*b,b,c-1)+pow(10,c)*n;
	}
	return cambio(n,b,c)+r*pow(10,c);
	
}
