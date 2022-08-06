/* Assignment 2 Programming C16518763 Tega Orogun 
  12/03/2017 */


#include <stdio.h>
#define SIZE 4

//Function Prototypes
void option_1 (int* en_code);
void option_2 (int [], int[], int*, int*);
void option_3 (int[]);
void option_4 (void);

//main function
int main() {
    
    int menu, counterS =0, counterI = 0;
    int access_code [SIZE] = {4, 5, 2, 3};
    int en_code [SIZE] = {0, 0, 0, 0};
    int encrypt_count = 0;
    int t = 0;
    
    //menu using case
    do
    {
        printf("Enter the number for what menu option you want: \n");
        printf("1. Enter Code \n");
        printf("2. Encrypt Code and verify if correct \n");
        printf("3. Decrypt Code\n");
        printf("4. Display the number of times the code was entered successfully and incorrectly \n");
        printf("5. Exit Program \n");
        
        scanf("%d", &menu);
        
        //switch for the different options
        switch(menu)
        {
            case 1 :
            {
                if(encrypt_count != 0)
                {
                    encrypt_count--;
                }
                
                option_1(en_code);
                t++;
                break;
            }//end case
                
            case 2 :
            {
                if (encrypt_count == 0 && t > 0)
                {
                    encrypt_count++;
                    option_2(en_code, access_code, &counterS, &counterI);
                }
                else
                {
                    printf("Can't encrypt \n");
                }
                break;
            }//end case
                
            case 3 :
            {
                if (encrypt_count == 1)
                {
                    option_3(en_code);
                }
                else
                {
                    printf("Can't decrypt \n");
                }
                break;
            }//end case
                
            case 4 :
            {
                printf("Successfully entered = %d \n", counterS);
                printf("Incorrectly entered = %d \n", counterI);
                break;
            }//end case
        
            case 5 :
            {
                printf("\n Exiting Program \n");
                break;
            }
                
            default :
            {
                printf("Invalid value please enter again \n");
                break;
            }//end default
        } //end switch
    }
    while(menu != 5);
    
    
    return 0;
}//end main

//entering the code
void option_1(int* (en_code))
{
    int i;
    
    printf("Enter the code one digit at a time \n");
    
    //entering the code digit by digit
    for (i=0; i<SIZE; i++)
    {
        printf("Enter a digit of the code \n");
        scanf("%d", (en_code + i));
        
        while(*(en_code + i) > 9 || *(en_code + i) < 0)
        {
            printf("Invalid digit entered. Please enter a single digit \n");
            scanf("%d", (en_code + i));
        }
    }
}//end option_1

void option_2(int *(en_code), int *(access_code), int *ptr1, int *ptr2)
{
    int my_array[SIZE] = {0, 0, 0, 0};
    
    //encrypting the code moving it to another array
    *(my_array) = *(en_code + 2) + 1;
    *(my_array + 1)  = *(en_code + 3) + 1;
    *(my_array + 2) = *(en_code + 0) + 1;
    *(my_array + 3) = *(en_code +1) + 1;
    
    //moving it back to the original array
    *(en_code + 0) = *(my_array + 0);
    *(en_code + 1) = *(my_array + 1);
    *(en_code + 2) = *(my_array + 2);
    *(en_code + 3) = *(my_array + 3);
    
    //checking id the acces_code is correct
    if (*(en_code + 0) == *(access_code + 0) && *(en_code + 1) == *(access_code + 1) && *(en_code + 2) == *(access_code + 2) && *(en_code + 3) == *(access_code + 3) )
    {
        printf("CORRECT CODE \n");
        *ptr1++;
    }
    else
    {
        printf("ERROR CODE \n");
        *ptr2++;
    }

}//end option_2

void option_3(int *(en_code))
{
    int my_array[SIZE] = {0, 0, 0, 0};
    
    *(my_array) = *(en_code + 2) - 1;
    *(my_array + 1)  = *(en_code + 3) - 1;
    *(my_array + 2) = *(en_code + 0) - 1;
    *(my_array + 3) = *(en_code +1) - 1;
    
    *(en_code + 0) = *(my_array + 0);
    *(en_code + 1) = *(my_array + 1);
    *(en_code + 2) = *(my_array + 2);
    *(en_code + 3) = *(my_array + 3);

}


