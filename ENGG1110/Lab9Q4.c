
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

#include <stdio.h>
#include <string.h>
// include extra header file here


int main(void) {
  // Write your code here
  
  while(1){
    char a[100];
    fgets(a, 100, stdin);

    // lower case the input
    for(int i = 0; i < strlen(a); i++){
      if(a[i] >= 'A' && a[i] <= 'Z'){
        a[i] = a[i] + 32;
      }
    }

    // check if the input is "quit" 
    if(a[0] == 'q' && a[1] == 'u' && a[2] == 'i' && a[3] == 't'){
      break;
    }

    // check palindrom
    int size = strlen(a) - 1;
    int flag = 0;
    for(int i=0; i < size/2; i++){
        // printf("%c %c\n", a[i], a[size-i-1]);
      if(a[i] != a[size-i-1]){
        flag = 1;
        // break;
      }
    }
    if(flag == 0){
        printf("Palindrome\n");
    }else{
        printf("Not Palindrome\n");
    }
  }
  
  // End of your code
  return 0;
}
