#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
	srand(time(NULL));
	float sum_pos=0, sum_neg=0;
	int pos=0, neg=0, i, n, num;
	int val[1000];
	cout<<"Dame el numero de elementos a evaluar: "<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		num=-250+rand()%(421+250);
		if(num==0){
			continue;
		}else{
			val[i]=num;
		}
		cout<<val[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<n;i++){
		if(val[i]>0){
			sum_pos+=val[i];
			pos++;
		}else{
			sum_neg+=val[i];
			neg++;
		}
	}
	cout<<"El promedio de valores positivos es: "<<(sum_pos/pos)<<endl;
	cout<<"El promedio de valores negativos es: "<<(sum_neg/neg)<<endl;	
}
