#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
//int initial[50],aux[50],final[50];
void no_repeat(int n, int z, int arr[100], int final[50]);
int main(){
	int arr[100]={6,2,5,6,1,2,6,7,3,6,2,3,6,8,9,1};
	int i, n, z=0;
	int final[50];
	no_repeat(16, z, arr, final);
	
	/*for(i=0;i<16;i++){
		cout<<final[i]<<" ";
		//cout<<arr[i]<<" ";
	}*/
}
void no_repeat(int n, int z, int arr[100], int final[50]){
	int initial[50],aux[50];
	int i,j,k=0,cont,num;
	bool flag;
	//cout<<arr[7]<<endl;
	for(i=0;i<n;i++){
		/*cont=0;
		num=initial[i];	
		aux[j]=num;	
		j++;	
		for(k=0;k<n;k++){
			if(aux[k]==num){
				cont++;
			}					
		}
		if(cont==1){
			final[z]=num;		
			z++;
		}	*/	
		cont=0, flag=1;
		for(k=0; k<z; k++){
				if(final[k]==arr[i]){
					flag=0;
					break;
				}
			}
		for(j=0;j<n;j++){
			/*for(k=0; k<z; k++){
				if(final[k]==arr[i]){
					flag=0;
					break;
				}
			}*/
			if(arr[i]==arr[j]){
				cont++;
			}
			if(cont==2&&flag==1){
				final[z]=arr[i];
				z++;
				break;	
			}					
		}	
		
	}
	for(i=0;i<z;i++){
		cout<<final[i]<<" ";
	}
}
