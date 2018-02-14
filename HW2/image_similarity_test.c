#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
   time_t t;
   
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));

   int r1 = rand() % 30+1;
   int r2 = rand() % 30+1;
   int c1 = rand() % 30+1;
   int c2 = rand() % 30+1;

   char c[2];
   c[0] = '.';
   c[1] = '#';
   printf("%d %d\n",r1,c1);
   for(int i=0;i<r1;i++){
      for(int j=0;j<c1;j++){
         printf("%c",c[rand()%2]);
      }
      printf("\n");
   }
   printf("%d %d\n",r2,c2);
   for(int i=0;i<r2;i++){
      for(int j=0;j<c2;j++){
         printf("%c",c[rand()%2]);
      }
      printf("\n");
   }


   
   return(0);
}