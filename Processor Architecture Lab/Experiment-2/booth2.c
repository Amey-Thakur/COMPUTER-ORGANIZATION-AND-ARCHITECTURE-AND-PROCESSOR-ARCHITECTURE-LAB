/*Expt no. 2 - To implement booth's Multiplication algorithm (using C) */

#include<stdio.h>
#include<math.h>
void binary();
void sum(int num[]);
void arithmetic_shift();

int comparison[7] = {1, 0, 0, 0, 0, 0, 0};
int first_number[7] = {0}, second_number[7] = {0}, anumcp[7] = {0};
int compare_num1[7] = {0}, compare_num2[7] = {0}, product[7] = {0}, result[7] = {0};
int num1 = 0, num2 = 0, num3 = 0;
int m = 0, n = 0;

int main()
{
      int count, x = 0;
      printf("Enter Two Numbers (-64 to +64)\n");
      do
      {
            printf("Enter M:\t");
            scanf("%d", &num1);
            printf("Enter Q:\t");
            scanf("%d", &num2);
      }while(num1 >=64 || num2 >=64);
      printf("\nExpected Product of %d * %d = %d", num1, num2, num1 * num2);
      binary();
      printf("\n\nBinary Equivalents\n");
      printf("M:\t");
      for(count = 6; count >= 0; count--)
      {
            printf("%d", first_number[count]);
      }
      printf("\nQ:\t");
      for(count = 6; count >= 0; count--)
      {
            printf("%d", second_number[count]);
      }
      printf("\nQ'+ 1 =\t");
      for(count = 6; count >= 0; count--)
      {
            printf("%d", compare_num2[count]);
      }
      
      printf("\n");
      printf("\nSTEPS -------------------A------Q-----				%d",count);
      for(count = 0; count < 7; count++)
      {
            if(first_number[count] == x)	
            {
                  printf("\nSTEP %d --------------------------------",count);
                  arithmetic_shift();
                  x = first_number[count];
            }
            else if(first_number[count] == 1 && x == 0)
            {
				  printf("\nSTEP %d --------------------------------",count);
                  printf("\nSUB Q:\t\t\t");
                  sum(compare_num2);
                  arithmetic_shift();
                  x = first_number[count];
            }
            else
            {
                  printf("\nSTEP %d --------------------------------",count);
                  printf("\nADD Q:\t\t\t");
                  sum(second_number);
                  arithmetic_shift();
                  x = first_number[count];
            }
      }
      printf("\n\nProduct:\t\t");
      for(count = 6; count >= 0; count--)
      {
            printf("%d", product[count]);
      }
      for(count = 6; count >= 0; count--)
      {
            printf("%d", anumcp[count]);
      }
      printf("\n");
      return 0;
}
 
void binary()
{
      m = fabs(num1);
      n = fabs(num2);
      int r2, remainder, count, temp;
      for(count = 0; count < 7; count++)
      {
            remainder = m % 2;
            m = m / 2;
            r2 = n % 2;
            n = n / 2;
            first_number[count] = remainder;
            anumcp[count] = remainder;
            second_number[count] = r2;
            if(r2 == 0)
            {
                  compare_num2[count] = 1;
            }
            if(remainder == 0)
            {
                  compare_num1[count] =1;
            }
      }
      num3 = 0;
      for(count = 0; count < 8; count++)
      {
            result[count] = comparison[count]+ compare_num2[count] + num3;
            if(result[count] >= 2)
            {
                  num3 = 1;
            }
            else
            {
                  num3 = 0;
            }
            result[count] = result[count] % 2;
      }
      for(count = 7; count >= 0; count--)
      {
            compare_num2[count] = result[count];
      }
      if(num1 < 0)
      {
            num3 = 0;
            for(count = 7; count >= 0; count--)
            {
                  result[count] = 0;
            }
            for(count = 0; count < 8; count++)
            {
                  result[count] = comparison[count] + compare_num1[count] + num3;
                  if(result[count] >= 2)
                  {
                        num3 = 1;
                  }
                  else
                  {
                        num3 = 0;
                  }
                  result[count] = result[count] % 2;
            }
            for(count = 7; count >= 0; count--)
            {
                  first_number[count] = result[count];
                  anumcp[count] = result[count];
            }
      }
      if(num2 < 0)
      {
            for(count = 0; count < 8; count++)
            {
                  temp = second_number[count];
                  second_number[count] = compare_num2[count];
                  compare_num2[count] = temp;
            }
      }
}

void sum(int num[])
{
      int count;
      num3 = 0;
      for(count = 0; count < 8; count++)
      {
            result[count] = product[count] + num[count] + num3;
            if(result[count] >= 2)
            {
                  num3 = 1;
            }
            else
            {
                  num3 = 0;
            } 
            result[count] = result[count] % 2;
      }
      for(count = 7; count >= 0; count--)
      {
            product[count] = result[count];
            printf("%d", product[count]);
      }
      printf(":");
      for(count = 7; count >= 0; count--)
      {
            printf("%d", anumcp[count]);
      }
}

void arithmetic_shift()
{
      int x = product[7], y = product[0], count;
      for(count = 1; count < 8  ; count++)
      {
            product[count - 1] = product[count];
      }
      product[7] = x;
      for(count = 1; count < 5; count++)
      {
            anumcp[count - 1] = anumcp[count];
      }
      anumcp[7] = y;
      printf("\nArithmetic Shift\t");
      for(count = 7; count >= 0; count--)
      {
            printf("%d", product[count]);
      }
      printf(":");
      for(count = 7; count >= 0; count--)
      {
            printf("%d", anumcp[count]);
      }
}

/* OUTPUT
 Enter Two Numbers (-7 to +7)
Enter M:	5
Enter Q:	-3

Expected Product of 5 * -3 = -15

Binary Equivalents
M:		00101
Q:		11101
Q'+ 1 =	00011

STEP 0 -------------------------------
SUB Q:				00011:00101
Arithmetic Shift	00001:10010
STEP 1 -------------------------------
ADD Q:				11110:10010
Arithmetic Shift	11111:01001
STEP 2 -------------------------------
SUB Q:				00010:01001
Arithmetic Shift	00001:00100
STEP 3 -------------------------------
ADD Q:				11110:00100
Arithmetic Shift	11111:00010
STEP 4 -------------------------------
Arithmetic Shift	11111:10001

Product:			11111:10001
------------------------------------- */ 
