
/**
* ENGG1110 Problem Solving by Programming
*
* I declare that the assignment here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* http://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : Ankhbayar Enkhtaivan
* Student ID   : 1155185142
* Class/Section: ENGG1110D
* Date         : 06/04/2023
*/

#include<stdio.h>

// THIS IS DONE ALREADY! DO NOT CHANGE!
typedef struct _complex {
  int real;
  int imgr;
} Complex;

// THIS IS DONE ALREADY! DO NOT CHANGE!
void printComplex(Complex x) {
  if (x.real == 0 && x.imgr == 0) {
    printf("0\n");
    return;
  }
  
  if (x.real == 0) {
    printf("%di\n", x.imgr);
    return;
  }
  
  if (x.imgr == 0) {
    printf("%d\n", x.real);
    return;
  }
  
  if (x.imgr > 0) {
    printf("%d + %di\n", x.real, x.imgr);
  } else {
    printf("%d - %di\n", x.real, (-1) * x.imgr);
  }
}

Complex addComplex(Complex x, Complex y) {
  // compute complex number addition (x + y)
    Complex tmp;
    tmp.real = x.real + y.real;
    tmp.imgr = x.imgr + y.imgr;
    return tmp;
}

Complex multiplyComplex(Complex x, Complex y) {
  // compute complex number multiplication (x * y)
    Complex tmp;
    tmp.real = x.real * y.real - x.imgr * y.imgr;
    tmp.imgr = x.real * y.imgr + x.imgr * y.real;
    return tmp;
}

/* starting point of this C program */
int main(void) {
  // Enter your code here.
  // 1. Read the two complex numbers
  
    Complex x, y;
    scanf("%d %d %d %d", &x.real, &x.imgr, &y.real, &y.imgr);

  // 2. Perfrom complex addition and multiplication
  
    Complex sum = addComplex(x, y);
    Complex product = multiplyComplex(x, y);

  // 3. Output complex sum and product
  
    printComplex(sum);
    printComplex(product);

  /* last statement of this C program */
  return 0;
}
