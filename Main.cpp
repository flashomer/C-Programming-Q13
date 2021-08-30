#include<stdio.h>

float isPrime(float n) {
    if ((int)n == 2)
        return 1;
    if ((int)(1/(n - (int)n)) % (int)n == 0)
        return 0;
    if (n / (int)n == 1)
        return isPrime(n-1 + 1/n); // store original parameter to decimal places
    return isPrime(n-1);

}

	
int main(){
	
	FILE *inpbinary = fopen("bin/others.bin","rb");
	FILE *outbinary = fopen("bin/primes.bin","wb");
	FILE *dispbinary = fopen("bin/primes.bin","rb");

	int numbers;
		
	while(!feof(inpbinary)){
		fread(&numbers,sizeof(int),1,inpbinary);
		if(isPrime((float)numbers)){
			printf("numbers:%d ",numbers);
			fwrite(&numbers,sizeof(int),1,outbinary);
		}
	}
	
	fclose(outbinary);
	fclose(inpbinary);

	int disp_num;
	
	while(!feof(dispbinary)){
		fread(&disp_num,sizeof(int),1,dispbinary);
		printf("%d ",disp_num);

	}
	fclose(dispbinary);
	

	return 0;
}
