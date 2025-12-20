/**
 * ============================================================================
 * Booth's Multiplication Algorithm Implementation
 * ============================================================================
 * 
 * @file        Booths_Multiplication_Algorithm.c
 * @author      Amey Thakur
 * @repository  https://github.com/Amey-Thakur/COMPUTER-ORGANIZATION-AND-ARCHITECTURE-AND-PROCESSOR-ARCHITECTURE-LAB
 * @experiment  Experiment 2 - Processor Architecture Lab
 * 
 * @description This program implements Booth's Multiplication Algorithm,
 *              which is an efficient algorithm for multiplying two signed
 *              binary numbers in two's complement notation. The algorithm
 *              reduces the number of additions required for multiplication
 *              by examining pairs of bits in the multiplier.
 * 
 * @algorithm   Booth's Algorithm works by:
 *              1. Examining consecutive pairs of bits in the multiplier
 *              2. Performing arithmetic right shifts after each operation
 *              3. If bit pair is "10": Subtract multiplicand from accumulator
 *              4. If bit pair is "01": Add multiplicand to accumulator
 *              5. If bit pair is "00" or "11": No operation (just shift)
 * 
 * ============================================================================
 */

#include <stdio.h>
#include <math.h>

/* ========================== Function Prototypes ========================== */

void binary();              /* Converts decimal to binary representation */
void sum(int num[]);        /* Performs binary addition for accumulator */
void arithmetic_shift();    /* Performs arithmetic right shift on registers */

/* ========================== Global Variables ============================= */

/* Constant for two's complement addition (represents +1) */
int comparison[7] = {1, 0, 0, 0, 0, 0, 0};

/* Binary representations of input numbers */
int first_number[7] = {0};      /* Multiplicand (M) in binary */
int second_number[7] = {0};     /* Multiplier (Q) in binary */
int anumcp[7] = {0};            /* Copy of M for multiplication process */

/* Working arrays for computation */
int compare_num1[7] = {0};      /* One's complement of M */
int compare_num2[7] = {0};      /* Two's complement of Q (used for subtraction) */
int product[7] = {0};           /* Accumulator register (A) */
int result[7] = {0};            /* Temporary result storage */

/* Input numbers in decimal */
int num1 = 0;   /* Multiplicand (M) */
int num2 = 0;   /* Multiplier (Q) */
int num3 = 0;   /* Carry bit for binary addition */

/* Absolute values for binary conversion */
int m = 0, n = 0;

/* ========================== Main Function ================================ */

/**
 * @brief Main function to execute Booth's Multiplication Algorithm
 * @return 0 on successful execution
 */
int main()
{
    int count, x = 0;
    
    /* Get two signed numbers from user within valid range */
    printf("Enter Two Numbers (-64 to +64)\n");
    do
    {
        printf("Enter M:\t");
        scanf("%d", &num1);
        printf("Enter Q:\t");
        scanf("%d", &num2);
    } while(num1 >= 64 || num2 >= 64);
    
    /* Display expected product for verification */
    printf("\nExpected Product of %d * %d = %d", num1, num2, num1 * num2);
    
    /* Convert input numbers to binary representation */
    binary();
    
    /* Display binary equivalents of input numbers */
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
    
    /* Execute Booth's Algorithm main loop */
    printf("\n");
    printf("\nSTEPS -------------------A------Q-----\t\t\t\t%d", count);
    
    for(count = 0; count < 7; count++)
    {
        if(first_number[count] == x)	
        {
            /* Case: Bit pair is "00" or "11" - No operation, just shift */
            printf("\nSTEP %d --------------------------------", count);
            arithmetic_shift();
            x = first_number[count];
        }
        else if(first_number[count] == 1 && x == 0)
        {
            /* Case: Bit pair is "10" - Subtract multiplicand */
            printf("\nSTEP %d --------------------------------", count);
            printf("\nSUB Q:\t\t\t");
            sum(compare_num2);      /* Subtract by adding two's complement */
            arithmetic_shift();
            x = first_number[count];
        }
        else
        {
            /* Case: Bit pair is "01" - Add multiplicand */
            printf("\nSTEP %d --------------------------------", count);
            printf("\nADD Q:\t\t\t");
            sum(second_number);     /* Add multiplicand */
            arithmetic_shift();
            x = first_number[count];
        }
    }
    
    /* Display final product in binary */
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

/* ========================== Function Definitions ========================= */

/**
 * @brief Converts decimal numbers to binary and computes two's complement
 * 
 * This function:
 * 1. Converts both M and Q to their binary representations
 * 2. Computes one's complement of both numbers
 * 3. Computes two's complement of Q for subtraction operations
 * 4. Handles sign conversion for negative numbers
 */
void binary()
{
    /* Get absolute values for binary conversion */
    m = fabs(num1);
    n = fabs(num2);
    
    int r2, remainder, count, temp;
    
    /* Convert both numbers to binary simultaneously */
    for(count = 0; count < 7; count++)
    {
        remainder = m % 2;
        m = m / 2;
        r2 = n % 2;
        n = n / 2;
        
        /* Store binary digits of multiplicand */
        first_number[count] = remainder;
        anumcp[count] = remainder;
        
        /* Store binary digits of multiplier */
        second_number[count] = r2;
        
        /* Compute one's complement */
        if(r2 == 0)
        {
            compare_num2[count] = 1;
        }
        if(remainder == 0)
        {
            compare_num1[count] = 1;
        }
    }
    
    /* Compute two's complement of Q (Q' + 1) */
    num3 = 0;
    for(count = 0; count < 8; count++)
    {
        result[count] = comparison[count] + compare_num2[count] + num3;
        if(result[count] >= 2)
        {
            num3 = 1;   /* Carry bit */
        }
        else
        {
            num3 = 0;
        }
        result[count] = result[count] % 2;
    }
    
    /* Store two's complement result */
    for(count = 7; count >= 0; count--)
    {
        compare_num2[count] = result[count];
    }
    
    /* Handle negative multiplicand - convert to two's complement */
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
    
    /* Handle negative multiplier - swap Q and Q' representations */
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

/**
 * @brief Performs binary addition of accumulator with given number
 * @param num[] The binary number to add to the accumulator
 * 
 * Adds the input array to the product (accumulator) register
 * and displays the result. Used for both addition and subtraction
 * (subtraction is performed by adding two's complement).
 */
void sum(int num[])
{
    int count;
    num3 = 0;   /* Initialize carry */
    
    /* Perform binary addition bit by bit */
    for(count = 0; count < 8; count++)
    {
        result[count] = product[count] + num[count] + num3;
        if(result[count] >= 2)
        {
            num3 = 1;   /* Set carry for next bit */
        }
        else
        {
            num3 = 0;
        } 
        result[count] = result[count] % 2;
    }
    
    /* Store result and display */
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

/**
 * @brief Performs arithmetic right shift on A and Q registers
 * 
 * In arithmetic right shift:
 * - The sign bit (MSB) is preserved
 * - All bits shift right by one position
 * - The LSB of A becomes the MSB of Q
 * 
 * This operation is crucial for Booth's algorithm as it
 * effectively divides the combined A:Q register by 2.
 */
void arithmetic_shift()
{
    int x = product[7];     /* Preserve sign bit of A */
    int y = product[0];     /* LSB of A to become MSB of Q */
    int count;
    
    /* Shift accumulator (A) right */
    for(count = 1; count < 8; count++)
    {
        product[count - 1] = product[count];
    }
    product[7] = x;         /* Preserve sign bit */
    
    /* Shift multiplier register right */
    for(count = 1; count < 5; count++)
    {
        anumcp[count - 1] = anumcp[count];
    }
    anumcp[7] = y;          /* Insert bit from A */
    
    /* Display shift result */
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

/* ========================== Sample Output ================================ 
 
 Enter Two Numbers (-7 to +7)
 Enter M:    5
 Enter Q:    -3

 Expected Product of 5 * -3 = -15

 Binary Equivalents
 M:      00101
 Q:      11101
 Q'+ 1 = 00011

 STEP 0 -------------------------------
 SUB Q:              00011:00101
 Arithmetic Shift    00001:10010
 STEP 1 -------------------------------
 ADD Q:              11110:10010
 Arithmetic Shift    11111:01001
 STEP 2 -------------------------------
 SUB Q:              00010:01001
 Arithmetic Shift    00001:00100
 STEP 3 -------------------------------
 ADD Q:              11110:00100
 Arithmetic Shift    11111:00010
 STEP 4 -------------------------------
 Arithmetic Shift    11111:10001

 Product:            11111:10001
 
 ========================================================================== */
