#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void MergeSort(int *p,int N);
void Merge(int *p,int n1,int *q,int n2);

int main(){
    int T,N,H;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&H);
        int A[N];
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        MergeSort(A,N);
        int X=0;
        for(int i=N-1;i>=0;i--){
            if(H>A[i]) H-=A[i];
            else{
                X=A[i];
                break;
            }
        }
        printf("%d\n",X);
    }
	return 0;
}

void MergeSort(int *p,int N){
    if(N<=1) return;
    int mid = N/2;

    MergeSort(p,mid);
    MergeSort(p+mid,N-mid);
    Merge(p,mid,p+mid,N-mid);
}

void Merge(int *p,int n1,int *q,int n2){
    int i=0,j=0,k=0;
    int A[n1+n2];
    while(i<n1 && j<n2){
        if((*(p+i)) < (*(q+j))){
            A[k] = (*(p+i));
            i++;
        }
        else{
            A[k] = (*(q+j));
            j++;
        }
        k++;
    }
    if(k!=n1+n2){
        if(i!=n1){
            while(i<n1){
                A[k] = (*(p+i));
                i++;
                k++;
            }
        }
        else{
            while(j<n2){
                A[k] = (*(q+j));
                j++;
                k++;
            }
        }
    }
    i=0;
    j=0;
    k=0;
    while(i<n1){
        (*(p+i)) = A[k];
        i++;
        k++;
    }
    while(j<n2){
        (*(q+j)) = A[k];
        j++;
        k++;
    }
}

