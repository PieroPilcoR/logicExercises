#include<iostream>
using namespace std;
int var(int n);
bool impar(int n);
void print(int n, int tramos);
int main(){
	int n, tramos;
	cout<<"Dame el numero de elementos en cada tramo: "<<endl;
	cin>>n;
	cout<<"Dame el numero de tramosxx: "<<endl;
	cin>>tramos;
	print(n, tramos);
}
void print(int n, int tramos){
	int i, j, k, val=var(tramos), flag=0, c=0;
	int arr[2*(n-1)*val];
	for(i=0, k=0; i<=2*(n-1)*val; i++){
		if(i%2==0)	arr[k++]=i;
	}
	cout<<endl;
	for(i=0, k=0; i<n*tramos-val; i++){
		if(i>0 && i%(n-1)==0){
			c++;
			flag=impar(c);
		}
		for(j=0; j<i+1; j++){
			if(i+j==arr[k])
				cout<<"*";
			cout<<" ";	
		}
		if(!flag){
			k++;
		}
		cout<<endl;
	}
}
int var(int n){
	if(n%2==0)
		return n/2;
	return n/2+1;
}
bool impar(int n){
	if(n%2!=0)
		return 1;
	return 0;
}
