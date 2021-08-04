#include <iostream>
#include <math.h>
using namespace std;
int main(){
	float prom=0;
	int num, cifras=0;
	do {
		cout<<"Ingrese el numero a evaluar"<<endl;
		cin>>num;
	} while(num<100 || num>9999);
	
	int numprev=num, numCopy=num, promRedondeado;
	while(num>0){
		prom+=num%10;
		num/=10;
		cifras++;
	}
	prom=prom/cifras;
	cout<<"Promedio matematico= "<<prom<<endl;
	if(prom-(int)prom>0.5){
		promRedondeado=(int)prom+1;
	}else{
		promRedondeado=(int)prom;
	}
	cout<<"Promedio grafico= "<<promRedondeado<<endl;
	int numInv=0, r, c=cifras-1;
	while(numprev>0){
		r=numprev%10;
		numprev/=10;
		numInv+=r*pow(10,c--);
	}
	numCopy=numInv;
	//cout<<"Numero invertido= "<<numInv<<endl;
	int lim, mayor=-1;
	while(numCopy>0){
		r=numCopy%10;
		if(r>mayor){
			mayor=r;
		}
		if(r<promRedondeado){
			lim=promRedondeado;
		}else{
			lim=r;
		}
		for(int i=0; i<lim; i++){
			if(i==promRedondeado-1){
				if(i==r-1){
					cout<<"*"<<" ";
				}else{
					cout<<"|"<<" ";
				}
			}else{
				if(i<r){
					cout<<"*"<<" ";
				}else{
					cout<<" "<<" ";
				}
			}
		}
		cout<<" ("<<r<<")"<<endl;
		numCopy/=10;
	}
	for(int i=0; i<mayor; i++){
		cout<<i+1<<" ";
	}
}
