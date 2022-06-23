/******************************************************************************

                           Matrix multiplication using C language
                           
        In this code we will perform Matrix Multiplication and prnting of matrix using a function

*******************************************************************************/

#include <stdio.h>
#include <conio.h>

int pass_row, pass_col;                     /* Defined global variable to pass the size of the matrix for printing */


void FUN_MAT_print(int MAT_P[pass_row][pass_col])   /* Function for printing the matrix */
{
     
    for (int i = 0; i < pass_row; i++)
    {
        printf("\t");
        for (int j = 0; j < pass_col; j++)
	    {
	        printf ("%d\t", MAT_P[i][j]);
	    }
        printf ("\n");
    }
    
}

void main ()                    /* Main funtion */
{
  int MAT_A[3][3] = { {5, 2, 3}, {1, 5, 4}, {2, 1, 9} };        /* Iniatlizing Matrix A */
  int MAT_B[3][2] = { {2, 1}, {1, 5}, {6, 2} };                 /* Iniatlizing Matrix B */
  
  int n_col_A = sizeof (MAT_A[0]) / 4;                   /* Divide by 4 because int takes 4 bytes of memory */
  int n_row_A = (sizeof (MAT_A) / n_col_A) / 4;
  
  int n_col_B = sizeof (MAT_B[0]) / 4;
  int n_row_B = (sizeof (MAT_B) / n_col_B) / 4;

  printf ("No. of rows    in Matrix A = %d\n", n_row_A);
  printf ("No. of columns in Matrix A = %d\n", n_col_A);

  printf ("No. of rows    in Matrix B = %d\n", n_row_B);
  printf ("No. of columns in Matrix B = %d\n", n_col_B);


  int MAT_C[n_row_A][n_col_B];                      /* Creating a new Matrix C that stores final product */

  if (n_col_A == n_row_B)                           /* Checking if the Matrix multiplication is possible or not*/                 
    {
        
        /* Matrix Multiplication code begins */
        
      for (int i = 0; i < n_row_A; i++)
	    {
	    for (int j = 0; j < n_col_B; j++)
	        {
	            MAT_C[i][j] = 0;
	            for (int k = 0; k < n_row_B; k++)
		            {
		                MAT_C[i][j] = MAT_C[i][j] + MAT_A[i][k] * MAT_B[k][j];
		            }
	        }
	    }
	    
	    /* Matrix Multiplication code ends */
    }
  else
    {
      printf ("Matrix multiplication Not possible");
    }
    
    /* Passing matrix to print fuction */ 
    
    printf("\n");
    printf("---->>>>> Matrix A <<<<<----\n"); 
    pass_row = n_row_A;
    pass_col = n_col_A;
    FUN_MAT_print(MAT_A);
    
    printf("---->>>>> Matrix B <<<<<----\n"); 
    pass_row = n_row_B;
    pass_col = n_col_B;
    FUN_MAT_print(MAT_B);
    
    printf("---->>>>> Matrix C = MAT_A * MAT_B <<<<<----\n"); 
    pass_row = n_row_A;
    pass_col = n_col_B;
    FUN_MAT_print(MAT_C);
    
}
