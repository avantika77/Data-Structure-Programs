#include <iostream>
using namespace std;
#define N 2
 

void add(int A[][N], int B[][N], int C[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[][N], int B[][N], int F[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            F[i][j] = A[i][j] - B[i][j];
}

void mult(int A[][N], int B[][N], int D[][N]) {
	int i,j,k;
	  for (i = 0; i < N; i++){
	  
        for (j = 0; j < N; j++){
		D[i][j]=0;
		for(k= 0; k< N; k++)
            D[i][j] += A[i][k]*B[k][j];
            
        }}}

void div(int A[][N], int B[][N], int E[][N]) {
	int i,j,k;
	  for (i = 0; i < N; i++){
	  
        for (j = 0; j < N; j++){
		E[i][j]=0;
		for(k= 0; k< N; k++)
            E[i][j] += A[i][k]/B[k][j];
            
        }}
}
 

int main()
{int A[N][N], B[N][N];
	
    	cout<<"enter the values for 1st mattrix (2X2)"<<endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cin>>A[i][j];
			
		}
	}
	
		cout<<"enter the values for 2nd mattrix (2X2)"<<endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cin>>B[i][j];
			
		}
	}
	
 
   
    int C[N][N];
      int D[N][N];
      int E[N][N];
      int F[N][N];
    int i, j;
    add(A, B, C);
    
    
 
    cout << "Result matrix sum is " << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    mult(A, B, D);
      cout << "Result matrix multiplication is " << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
 	
 	div(A, B, E);
 	 cout << "Result matrix Division is " << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << E[i][j] << " ";
        cout << endl;
    }
    
    sub(A, B, F);
 	 cout << "Result matrix Division is " << endl;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            cout << F[i][j] << " ";
        cout << endl;
    }
return 0;
}
