#include<stdio.h>
#include<stdlib.h>
typedef struct complex{
	float real;
	float imaginary;
}complex;
complex add(complex n1, complex n2){
	complex added;
	added.real=n1.real+n2.real;
	added.imaginary=n1.imaginary+n2.imaginary;
	return (added);
}
complex sub(complex n1, complex n2){
	complex subbed;
	subbed.real=n1.real-n2.real;
	subbed.imaginary=n1.imaginary-n2.imaginary;
	return(subbed);
}
complex mul(complex n1, complex n2){
	complex product;
	product.real=(n1.real*n2.real)-(n1.imaginary*n2.imaginary);
	product.imaginary=(n1.real*n2.imaginary)+(n1.imaginary*n2.real);
	return product;
}
int main(){
	complex n1,n2,result1,result2,result3;
	printf("First Complex Number\n");
	printf("Enter real and imaginary parts of first Number: ");
	scanf("%f %f",&n1.real,&n1.imaginary);
	printf("Second Complex Number\n");
	printf("Enter real and imaginary parts of second Number: ");
	scanf("%f %f",&n2.real,&n2.imaginary);
	result1=add(n1,n2);
	printf("Sum is %.1f + %.1f i\n",result1.real,result1.imaginary);
	result2=sub(n1,n2);
	printf("Difference is %.1f + %.1f i\n",result2.real,result2.imaginary);
	result3=mul(n1,n2);
	printf("product is %.1f + %.1f i\n",result3.real,result3.imaginary);

	return 0;
}