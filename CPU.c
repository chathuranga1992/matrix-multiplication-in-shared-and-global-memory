#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **Arr1;
int **Arr2;
int **Rarr;
int SIZE;
double Rtime=0;
void Matrices();
void fill(int **arr);
void mul();
void Mfree();
int main(int narg, char *arg[]){
	srand(time(NULL));
	SIZE = atoi(arg[1]);
	Matrices();
	mul();
	//Mfree();
	printf("%2.8f",Rtime);

}

// Shalika
void Matrices(){

	Arr1=(int**)malloc(SIZE*sizeof(int*));
	for(int i=0; i<SIZE; i++){
		Arr1[i]=(int*)malloc(SIZE*sizeof (int));
	}

	Arr2=(int**)malloc(SIZE*sizeof(int*));
	for(int i=0; i<SIZE; i++){
		Arr2[i]=(int*)malloc(SIZE*sizeof (int));
	}
	
	Rarr=(int**)malloc(SIZE*sizeof(int*));
	for(int i=0; i<SIZE; i++){
		Rarr[i]=(int*)malloc(SIZE*sizeof (int));
	}
	
	fill(Arr1);
	fill(Arr2);

}
void fill(int **arr){
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			arr[i][j]=rand()%2;
		}
	}
}

void mul(){
	clock_t begin = clock();
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			Rarr[j][i]=0;
			for(int k=0; k<SIZE; k++){
				Rarr[j][i]=Rarr[j][i]+(Arr1[k][i]*Arr2[j][k]);
			}
		}
	}
	clock_t end = clock();
	Rtime = (double)(end - begin) / CLOCKS_PER_SEC;

}

void Mfree(){
	for(int i=0; i<SIZE; i++){
		free(Arr1[i]);
		free(Arr2[i]);
		free(Rarr[i]);
	}
	free(Arr1);
	free(Arr2);
	free(Rarr);
}
