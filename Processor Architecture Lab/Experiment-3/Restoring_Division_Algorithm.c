/**
 * ============================================================================
 * Restoring Division Algorithm Implementation
 * ============================================================================
 * 
 * @file        Restoring_Division_Algorithm.c
 * @author      Amey Thakur
 * @repository  https://github.com/Amey-Thakur/COMPUTER-ORGANIZATION-AND-ARCHITECTURE-AND-PROCESSOR-ARCHITECTURE-LAB
 * @experiment  Experiment 3 - Processor Architecture Lab
 * 
 * @description This program implements the Restoring Division Algorithm,
 *              which is a method for dividing two unsigned binary numbers.
 *              The algorithm gets its name from the "restoration" step where
 *              if the result of subtraction is negative, the original value
 *              is restored by adding the divisor back.
 * 
 * @algorithm   Restoring Division works by:
 *              1. Left shift the A:Q register pair
 *              2. Subtract divisor M from accumulator A
 *              3. If A is negative:
 *                 - Restore A by adding M back
 *                 - Set Q[0] = 0
 *              4. If A is positive or zero:
 *                 - Keep the subtraction result
 *                 - Set Q[0] = 1
 *              5. Repeat for n-1 iterations (where n = bit length)
 *              6. Final: Q = Quotient, A = Remainder
 * 
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

/* ========================== Global Variables ============================= */

int *a;     /* Accumulator register (A) - stores partial remainders */
int *q;     /* Quotient register (Q) - stores dividend, then quotient */
int *m;     /* Divisor register (M) */
int *mc;    /* Two's complement of divisor (-M) for subtraction */
int *c;     /* Temporary array */
int n;      /* Numerator (dividend) */
int d;      /* Denominator (divisor) */

/* ========================== Function Prototypes ========================== */

int  powr(int x, int y);            /* Power function: calculates x^y */
void print(int arr[], int n);       /* Prints array elements */
void bin(int n, int arr[]);         /* Converts decimal to binary */
void set(int array[], int x);       /* Reverses array for proper bit order */
int  len(int x);                    /* Calculates number of bits needed */
void addBinary(int a1[], int a2[]); /* Binary addition of two arrays */
void twoCom(int arr[]);             /* Computes two's complement */
void ls(int alen, int blen);        /* Left shift operation on A:Q */
void printaq();                     /* Prints A and Q register contents */

/* ========================== Function Definitions ========================= */

/**
 * @brief Calculates power x^y using iterative multiplication
 * @param x Base value
 * @param y Exponent value
 * @return Result of x raised to power y
 */
int powr(int x, int y)
{
    int s = 1, i;
    for(i = 0; i < y; i++)
    {
        s = s * x;
    }
    return s;
}

/**
 * @brief Prints array elements with proper formatting
 * @param arr[] Array to print
 * @param n Size of array
 * 
 * Note: '?' characters represent uninitialized (placeholder) bits
 */
void print(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(arr[i] == -1)
        {
            printf("?");    /* Placeholder for unset bit */
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
}

/**
 * @brief Converts decimal number to binary representation
 * @param n Decimal number to convert
 * @param arr[] Array to store binary digits (LSB first)
 */
void bin(int n, int arr[])
{
    int r, i = 0;
    do
    {
        r = n % 2;
        n /= 2;
        arr[i] = r;
        i++;
    } while(n > 0);
}

/**
 * @brief Reverses array to convert LSB-first to MSB-first order
 * @param array[] Array to reverse
 * @param x Size of array
 * 
 * Binary is stored LSB-first during conversion but displayed MSB-first
 */
void set(int array[], int x)
{
    int i, tmp[20] = {0};
    for(i = x - 1; i >= 0; i--)
    {
        tmp[x - 1 - i] = array[i];
    }
    for(i = 0; i < x; i++)
    {
        array[i] = tmp[i];
    }
}

/**
 * @brief Determines the number of bits needed to represent a number
 * @param x Number to analyze
 * @return Number of bits required plus one (for sign handling)
 */
int len(int x)
{
    int i = 0;
    while(powr(2, i) <= x)
    {
        i++;
    }
    return ++i;
}

/**
 * @brief Performs binary addition of two arrays
 * @param a1[] First operand (also stores result)
 * @param a2[] Second operand
 * 
 * Implements ripple-carry addition bit by bit
 */
void addBinary(int a1[], int a2[])
{
    int bi[2] = {0};            /* Binary representation of sum */
    int ca[20] = {0};           /* Carry array */
    int t = len(n);             /* Number of bits */
    int tmp = 0;
    
    int *su = (int*)malloc(sizeof(int) * len(n));
    
    /* Add corresponding bits with carry propagation */
    while(t-- > 0)
    {
        tmp = a1[t] + a2[t] + ca[t];
        bin(tmp, bi);           /* Convert sum to binary */
        su[t] = bi[0];          /* Store sum bit */
        ca[t-1] = bi[1];        /* Store carry for next position */
        bi[0] = 0;
        bi[1] = 0;
    }
    
    /* Copy result back to a1 */
    for(t = 0; t < len(n); t++)
    {
        a1[t] = su[t];
    }
    
    free(su);
}

/**
 * @brief Computes two's complement of a binary number
 * @param arr[] Binary number (modified in place)
 * 
 * Two's complement = One's complement + 1
 * Used for subtraction: A - M = A + (-M) = A + twoCom(M)
 */
void twoCom(int arr[])
{
    int i;
    
    /* Allocate array representing value 1 */
    int *one = (int*)malloc(sizeof(int) * len(n));
    for(i = 0; i < len(n) - 1; i++)
    {
        one[i] = 0;
    }
    one[i] = 1;     /* LSB = 1 */
    
    /* Compute one's complement (flip all bits) */
    for(i = 0; i < len(n); i++)
    {
        arr[i] = 1 - arr[i];
    }
    
    /* Add 1 to get two's complement */
    addBinary(arr, one);
    
    free(one);
}

/**
 * @brief Performs left shift on combined A:Q register pair
 * @param alen Length of A register
 * @param blen Length of Q register
 * 
 * Left shift operation:
 * - MSB of Q enters LSB of A
 * - LSB of Q becomes placeholder (-1)
 */
void ls(int alen, int blen)
{
    int i = 0;
    
    /* Shift A register left */
    for(i = 0; i < alen - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[i] = q[0];    /* MSB of Q moves to LSB of A */
    
    /* Shift Q register left */
    for(i = 0; i < blen - 1; i++)
    {
        q[i] = q[i + 1];
    }
    q[i] = -1;      /* Placeholder for quotient bit */
}

/**
 * @brief Prints current state of A and Q registers
 */
void printaq()
{
    print(a, len(n));
    printf("\t");
    print(q, len(n) - 1);
    printf("\t");
    printf("\n");
}

/* ========================== Main Function ================================ */

/**
 * @brief Main function to execute Restoring Division Algorithm
 * @return 0 on successful execution
 * 
 * Divides numerator n by denominator d using restoring division
 * Result: Q = Quotient, A = Remainder
 */
int main()
{
    int i, cnt = 0;
    
    /* Get division operands from user */
    printf("Enter The Numerator/Denominator: ");
    scanf("%d/%d", &n, &d);
    
    /* Allocate and initialize Q register (quotient/dividend) */
    q = (int*)malloc(sizeof(int) * len(n) - 1);
    bin(n, q);
    
    /* Allocate and initialize M register (divisor) */
    m = (int*)malloc(sizeof(int) * (len(n)));
    bin(d, m);
    
    /* Allocate and initialize A register (accumulator) to zero */
    a = (int*)malloc(sizeof(int) * (len(n)));
    for(i = 0; i < len(n); i++)
    {
        a[i] = 0;
    }
    
    /* Allocate and compute -M (two's complement of divisor) */
    mc = (int*)malloc(sizeof(int) * (len(n)));
    bin(d, mc);
    
    /* Set proper bit ordering (MSB first) */
    set(q, len(n) - 1);
    set(m, len(n));
    set(mc, len(n));
    
    /* Compute -M for subtraction */
    twoCom(mc);
    
    /* Initialize iteration counter */
    cnt = len(n) - 1;
    
    /* Display header for step-by-step trace */
    printf("\t    A\t\t   Q\t\t    M\t    Count\n");
    printf("\t---------\t-------\t\t--------- ---------\n");
    
    /* Main division loop */
    while(cnt > 0)
    {
        /* Display current state */
        printf("\t");
        print(a, len(n));
        printf("\t");
        print(q, len(n) - 1);
        printf("\t\t");
        print(m, len(n));
        printf("\t%d\n", cnt);
        
        /* Step 1: Left shift A:Q */
        ls(len(n), len(n) - 1);
        printf("LSHIFT\t");
        printaq();
        
        /* Step 2: Subtract divisor from accumulator */
        addBinary(a, mc);   /* A = A - M (using two's complement) */
        printf("A=A-M\t");
        printaq();
        
        /* Step 3: Check sign of A and restore if negative */
        if(a[0] == 1)   /* MSB = 1 means negative in two's complement */
        {
            /* Restore: A = A + M (undo subtraction) */
            q[len(n) - 2] = 0;      /* Set quotient bit to 0 */
            addBinary(a, m);
        }
        else
        {
            /* Keep result: subtraction was successful */
            q[len(n) - 2] = 1;      /* Set quotient bit to 1 */
        }
        
        printf("A=A+M\t");
        printaq();
        
        cnt -= 1;
    }
    
    return 0;
}

/* ========================== Sample Output ================================ 

 Enter The Numerator/Denominator: 5/2
     A           Q              M      Count
 ---------   -------       --------- ---------
 0 0 0 0     1 0 1         0 0 1 0     3
 LSHIFT  0 0 0 1     0 1 ?     
 A=A-M   1 1 1 1     0 1 ?     
 A=A+M   0 0 0 1     0 1 0     
         0 0 0 1     0 1 0         0 0 1 0     2
 LSHIFT  0 0 1 0     1 0 ?     
 A=A-M   0 0 0 0     1 0 ?     
 A=A+M   0 0 0 0     1 0 1     
         0 0 0 0     1 0 1         0 0 1 0     1
 LSHIFT  0 0 0 1     0 1 ?     
 A=A-M   1 1 1 1     0 1 ?     
 A=A+M   0 0 0 1     0 1 0     

 Result: 5 / 2 = Quotient: 2, Remainder: 1
 
 ========================================================================== */
