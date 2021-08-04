#include<iostream>
using namespace std;
int mcd(int x, int y);
int main(){
	int x, y;
	cout<<"Dame el primer valor"<<endl;
	cin>>x;
	cout<<"Dame el segundo valor"<<endl;
	cin>>y;
	cout<<"El MCD es: "<<mcd(x,y)<<endl;
}
int mcd(int x, int y){
	if(y==0)	return x;
	else		return mcd(y,x%y);
}

