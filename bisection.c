#include <stdio.h>
#include <conio.h>

float fnvalue(float x, int a, int b, int c, int d)
{
      float result;
      result = ( a*x*x*x + b*x*x + c*x + d);
      return result;
}//end fnvalue

int main (void)
{
    int a3, a2, a1, a0, i= 0;
    float xl, xu, err, xm, errcheck, fxl, fxm;
    
    
    printf ("This Program Supports solution upto 3 degree polynomial equation of format\n"
           "f(x) = a3x^3 + a2x^2 + a1x + a0 \n"
           "Enter the value of x and coefficient values of x for a3, a2, a1 and a0 respectively \n");
    scanf("%d%d%d%d", &a3, &a2, &a1, &a0);
    
    printf ("\nEnter the guess values for xl and xu \n");
    scanf("%f%f",&xl, &xu);
    
    printf ("\nEnter error precision: ");
    scanf("%f",&err);
    
       
    while (1)
    {
          xm = ((xl+xu)/2);
          errcheck = ((xu-xl)/xu);
          fxl = fnvalue(xl,a3,a2,a1,a0);
          fxm = fnvalue(xm,a3,a2,a1,a0);
          printf("Iteration %d \n",++i);
          printf("\n------------------------------------------\n\n");
          printf(" xl\t= %.3f \t xm\t= %.3f \n",xl, xm);
          printf(" f(xl)\t= %.3f \t f(xu)\t= %.3f \t f(xm)\t= %.3f \n\n", fxl, fnvalue(xu,a3,a2,a1,a0), fxm);
          
          if ( errcheck < err)
          {
               printf(" root\t= %f \n",xm);
               break;
          }
             
          else 
          {
               if ( (fxl * fxm) < 0 )
                  xu = xm;
               else 
                    xl = xm;
          }
    }//end while
    getch();
    return 0;
      
}//end main    
