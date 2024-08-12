/*--------------------#include--------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
/*------------------------------------------------*/

/*----------------- Global Variable---------------*/
long long User_Password=0;
/*------------------------------------------------*/

/*---------------- Function Decleration-----------*/
void Application_Interfacing(void);
void EnteringFunction(void);
/*------------------------------------------------*/

/*Main Function*/
int main()
{

/*printf("\
                                        ▐░░░░░░░░░░░▐░░░░░░░░░░░▐░░░░░░░░░░░▐░▐     ▐░▌\
                                        ▐░█▀▀▀▀▀▀▀█░▌▀▀▀▀▀▀▀▀▀█░▐░█▀▀▀▀▀▀▀▀▀ ▐░▌   ▐░▌\
                                        ▐░▌       ▐░▌         ▐░▐░▌           ▐░▌ ▐░▌\
                                        ▐░█▄▄▄▄▄▄▄█░▌▄▄▄▄▄▄▄▄▄█░▐░█▄▄▄▄▄▄▄▄▄   ▐░▐░▌\
                                        ▐░░░░░░░░░░░▐░░░░░░░░░░░▐░░░░░░░░░░░▌   ▐░▌\
                                        ▐░█▀▀▀▀▀▀▀█░▐░█▀▀▀▀▀▀▀▀▀▐░█▀▀▀▀▀▀▀▀▀   ▐░▌░▌\
                                        ▐░▌       ▐░▐░▌         ▐░▌           ▐░▌ ▐░▌\
                                        ▐░▌       ▐░▐░█▄▄▄▄▄▄▄▄▄▐░█▄▄▄▄▄▄▄▄▄ ▐░▌   ▐░▌\
                                        ▐░▌       ▐░▐░░░░░░░░░░░▐░░░░░░░░░░░▐░▌     ▐░▌\
                                        ▀         ▀ ▀▀▀▀▀▀▀▀▀▀▀ ▀▀▀▀▀▀▀▀▀▀▀ ▀         ▀\
");
*/
    printf("Welcome to Hospital Application...\n\n");
    printf("Wait....\n\n");
    Application_Interfacing();
    return 0;
}/*---------------------------------------------------------------------------------*/

/*Function Definition*/

/* The Interface Function*/
void Application_Interfacing(void)
{
    EnteringFunction();
    unsigned int UserChoice=0;

    Main :
    printf("Enter (1) to View Patient procedures\n");
    printf("Enter (2) to View Doctor procedures\n");
    printf("Enter (3) to View Appointment Procedures\n");
    scanf("%i",&UserChoice);

    if(UserChoice == 1)
    {
        unsigned int Choices=0;
        Patient :
        printf("\nEnter (1) to AddPatient\n");
        printf("Enter (2) to DeletePatient\n");
        printf("Enter (3) to UpdatePatient\n");
        printf("Enter (4) to ViewPatient\n");
        printf("Enter (5) to Exit\n");
        printf("Enter (6) to Return Main Page\n");
        scanf("%i",&Choices);

        switch(Choices)
        {
        case 1 :
            AddPatient();
            break;
        case 2 :
            DeletePatient();
            break;
        case 3:
            UpdatePatient();
            break;
        case 4 :
            ViewPatient();
            break;
        case 5 :
            exit(1);
            break;
        case 6:
            goto Main;
            break;
        default :
           {
                unsigned int Result=0;
                printf("Invalid Choice!!!\n ");
                printf("Enter (1) to Try again");
                scanf("%i",&Result);

                if(1 == Result)
                {
                    printf ("\n");
                    goto Patient;
                }
                else
                {
                    printf ("\n");
                   goto Main ;
                }
           }
            break;
        }

    }
    else if(2 == UserChoice)
    {
        unsigned int Choice = 0;

        Doctor:
        printf("\nEnter (1) to AddDoctor\n");
        printf("Enter (2) to DeleteDoctor\n");
        printf("Enter (3) To UpdateDoctor\n");
        printf("Enter (4) To ViewDoctor\n");
        printf("Enter (5) To Exit\n");
        printf("Enter (6) To Return Main Page\n");
        scanf("%i",&Choice);

        switch(Choice)
        {
        case 1 :
            printf ("\n");
            AddDoctor();
            break;
        case 2 :
            printf ("\n");
            DeleteDoctor();
            break;
        case 3 :

             printf ("\n");
             UpdateDoctor();
            break;
        case 4 :
            printf ("\n");
            ViewDoctor();
            break;
        case 5 :
            exit(1);;
            break;
        case 6:
            printf ("\n");
            goto Main ;
            break;
        default :
           {
                unsigned int Result=0;

                printf("\nInvalid Choice !!!\n");
                Back :
                printf("\nEnter (1) to Try again\n");
                printf("Enter (2) to Main Page\n");
                scanf("%i",&Result);

                if(1 == Result)
                {
                    printf ("\n");
                    goto Doctor;
                }
                else if (2 == Result)
                {
                    printf ("\n");
                    goto Main;
                }
                else
                {
                    printf("Invalid Choice !!\n\n");
                    goto Back ;
                }

           }
                break;

        }

    }
    else if( 3 == UserChoice)
    {
        printf ("\n");
        ViewAppointment();
    }
    else
    {
        printf("Invalid choice!!!\n\n");
        goto Main;
    }
}
/*-------------------------------------------------------------------------------------------------------------*/
/*The Entering Function*/
void EnteringFunction(void)
{
    unsigned int Choice=0;

    Enter :
    printf("Enter (1) to Sign Up\n");
    printf("Enter (2) to Log in \n");
    scanf("%i",&Choice);

    if(1 == Choice)
    {
        Sign_Up :

        printf("\nEnter the Password To Entering the App (Numbers from (0) to (9)) :");
        scanf("%lli",&User_Password);
        printf("\nSuccessfully Signed Up \n\n");
    }
    else if (2 == Choice)
    {
        long long Entering_ID=0;

        LogIn :

        printf("\nEnter The Password that You Sign Up With : ");
        scanf("%lli",&Entering_ID);

        if(Entering_ID == User_Password)
        {
            printf("\nWelcome Again !!!\n\n");
        }
        else
        {
            unsigned int Choice=0;

            printf("\nInvalid Password!!!\n");
            Again :
            printf("\nEnter (1) to Sign Up \n");
            printf("Enter (2) to Try Again \n");
            scanf("%i",&Choice);

            if(1 == Choice)
            {
                printf ("\n");
                goto Sign_Up ;
            }
            else if(2 == Choice)
            {
                printf ("\n");
                goto LogIn ;
            }
            else
            {
                printf("Invalid Choice !!!\n\n");
                goto Again;
            }

        }

    }
    else
    {
        printf("Invalid Choice !!\n\n");
        goto  Enter;
    }
}
