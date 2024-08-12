/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------ #include ----------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
/*--------------------------------------------------------------*/

/*----------------------- Macros -------------------------------*/
#define Maxappoint 500
#define MaxPatient 500
#define One 0
/*--------------------------------------------------------------*/

/*---------------------- Global Variables ----------------------*/
patient Patient_t[MaxPatient];
int Index = One;
/*--------------------------------------------------------------*/

/*---------------------- Declaration ---------------------------*/
extern Appointment Appointment_t [Maxappoint];
/*--------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------- Function Definition ---------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------- AddPatient Function ----------------------*/
void AddPatient(void)
{
    unsigned int Choice=0;
    unsigned int Number = Index+1;

   if(Index < MaxPatient)
   {
       Add :

       printf("Enter Patient Name :");
       fflush(stdin);
       gets(Patient_t[Index].Name);

       printf("Enter Patient Age : ");
       scanf("%i",&Patient_t[Index].Age);

       printf("Enter Patient Gender: ");
       fflush(stdin);
       scanf("%s",Patient_t[Index].Gender);

       printf("Enter Patient Diagnosis : ");
       fflush(stdin);
       gets(Patient_t[Index].Diagnosis);

       printf("Enter the Data for Patient Reservation(Day/Month/Year) : ");
       fflush(stdin);
       scanf("%s",Patient_t[Index].Date);

       Patient_t[Index].ID=Number;

       AddAppointment();
       Dec :
       printf("\nDo you Want to Save this Information?\n");
       printf("Enter (1) to Save \n");
       printf("Enter (2) to Change\n");
       scanf("%i",&Choice);

       if(1 == Choice)
       {
           unsigned int Check=0;
           printf("successfully saved\n");
           printf("The Patient ID is : %i\n",Patient_t[Index].ID);
           printf("the Patient Appointment ID is : %i\n",Appointment_t[Index].ID);
           Index++;
           Ques :
           printf("\nEnter (1) to Exit\nEnter (2) to Main Page\n");
           scanf("%i",&Check);

           if (1 == Check)
           {
                exit(1);
           }
           else if (2 == Check)
           {
                printf("\n");
                Application_Interfacing();
           }
           else
           {
                printf("Invalid Choice!!!\n\n");
                goto Ques;
           }
       }
       else if (2 == Choice)
       {
           printf("\n");
           goto Add;
       }
       else
       {
           printf("Invalid Choice!!!\n\n");
           goto Dec;
       }
   }
   else
   {
       printf("\nSorry there are no Empty places!!!\n\n");
       Application_Interfacing();
   }
}
/*--------------------------------------------------------------*/

/*------------------- DeletePatient Function ----------------------*/
void DeletePatient(void)
{
    unsigned int Patient_ID=0;
    signed int Position=-1;

    Delete :

    printf("Enter you ID : ");
    scanf("%i",&Patient_ID);

    for(int i=0 ; i< Index ; i++)
    {
        if(Patient_t[i].ID == Patient_ID)
        {
            Position=i;
            break;
        }
    }

    if(-1 == Position)
    {
        unsigned int Check;

        printf("\nThe Patient is not Found!!!\n");
        printf("\nEnter (1) to Try again\n");
        printf("Enter (2) to Main\n");
        printf("Enter (3) to Exit\n");
        scanf("%i",&Check);

        if(1==Check)
        {
            printf("\n");
            goto Delete;
        }
        else if (2 == Check)
        {
             printf("\n");
             Application_Interfacing();
        }
        else if (3 == Check)
        {
            exit(1);
        }
        else
        {
            printf("Invalid Choice!!!\n\n");
            goto Delete;
        }

    }
    else
    {
        unsigned int Result=0;
        printf("\n");
        DeleteAppointment(Position);

        for(int i=Position ; i<Index-1 ; i++)
        {
            Patient_t[Position] = Patient_t[Position+1];
        }

        Index--;
        printf("\nPatient Deleted successfully !!!\n\n");

        Fault :
        printf("Enter (1) to Main Page\n");
        printf("Enter (2) to exit ");
        scanf("%i",&Result);

        if(1== Result)
        {
            printf("\n");
            Application_Interfacing();
        }
        else if (2 == Result)
        {
            exit(1);
        }
        else
        {
            printf("Invalid Choice!!!\n\n");
            goto Fault;
        }

    }

}
/*-----------------------------------------------------------------*/
/*------------------- UpdatePatient Function ----------------------*/
void UpdatePatient(void)
{
    unsigned int ID=0;
    unsigned int UserUpdate=0;
    signed int Position=-1;

    printf("Enter your ID :");
    scanf("%i",&ID);

    for(int i=0 ; i<Index ; i++)
    {
        if(Patient_t[i].ID == ID)
        {
            Position = i;
            break;
        }
    }

    if(Position == -1)
    {
        unsigned int Choice =0;

        printf("\nThe patient is not found !!!\n");
        Chock :
        printf("\nEnter (1) Try Again\n");
        printf("Enter (2) Main Page\n");
        printf("Enter (3) Exit\n");
        scanf("%i",&Choice);

            if(1== Choice)
            {
                printf("\n");
                UpdatePatient();
            }
            else if(2 == Choice)
            {
                printf("\n");
                Application_Interfacing();
            }
            else if (3 == Choice)
            {
                exit(1);
            }
            else
            {
                printf("Invalid Choice !!!\n\n");
                goto  Chock;
            }
        }

        Change :
        printf("\nEnter (1) to change the Name \n");
        printf("Enter (2) to change the Age \n");
        printf("Enter (3) to change the Date \n");
        printf("Enter (4) to change the diagnosis\n");
        printf("Enter (5) to change the gender \n");
        printf("Enter (6) to main \n");
        printf("Enter (7) to Exit \n");
        scanf("%i",&UserUpdate);

        switch(UserUpdate)
        {
        case 1:
            {
                unsigned int Choice=0;

                Name :
                printf("Enter the New Name :");
                fflush(stdin);
                gets(Patient_t[Position].Name);

                Default :
                printf("\nEnter(1) to Save the Update \n");
                printf("Enter(2) to Change the Current Update\n");
                printf("Enter(3) to Anther Update\n");
                printf("Enter(4) to Main Page \n");
                printf("Enter(5) to Exit\n");
                scanf("%i",&Choice);

                switch(Choice)
                {
                case 1 :
                   {
                        unsigned int Check;

                        printf("\nUpdate is Successed\n");
                        Down :
                        printf("\nEnter (1) to Main Page\n");
                        printf("Enter (2) to Exit\n");
                        scanf("%i",&Check);

                        if(Check == 1)
                        {
                            printf("\n");
                            Application_Interfacing();
                        }
                        else if (2 == Check)
                        {
                            exit(1);
                        }
                        else
                        {
                            printf("Invalid Choice!!!\n\n");
                            goto Down;
                        }

                   }
                   break;

                case 2:
                    printf("\n");
                    goto Name;
                    break;

                case 3:
                    printf("\n");
                    goto Change;
                    break;

                case 4 :
                    printf("\n");
                    Application_Interfacing();
                    break;

                case 5 :
                   exit(1);
                    break;

                default :
                    printf("Invalid Choice!!!\n\n");
                    goto Default;
                    break;

                }

            }
            break;

        case 2:
            {
                unsigned int Choice=0;

                Age :
                printf("Enter the New age : ");
                scanf("%i",&Patient_t[Position].Age);

                Default2 :
                printf("\nEnter(1) to Save the Update \n");
                printf("Enter(2) to Change the Current Update\n");
                printf("Enter(3) to Anther Update\n");
                printf("Enter(4) to Main Page \n");
                printf("Enter(5) to Exit\n");
                scanf("%i",&Choice);

                switch(Choice)
                {
                case 1 :
                   {
                        unsigned int Check;

                        printf("\nUpdate is  successed\n");

                        New :
                        printf("\nEnter (1) to Main Page\n");
                        printf("Enter (2) to Exit\n");
                        scanf("%i",&Check);

                        if(1 == Check)
                        {
                            printf("\n");
                            Application_Interfacing();
                        }
                        else if (2 == Check)
                        {
                            exit(1);
                        }
                        else
                        {
                            printf("Invalid Choice!!!\n\n");
                            goto New;
                        }
                   }
                   break;

                case 2:
                    printf("\n");
                    goto Age;
                    break;

                case 3:
                    printf("\n");
                    goto Change;
                    break;

                case 4 :
                    printf("\n");
                    Application_Interfacing();
                    break;

                case 5 :
                   exit(1);
                    break;

                default :
                    printf("Invalid Choice!!!\n\n");
                    goto Default2;
                    break;
                }
            }
            break;

        case 3 :
            {
                unsigned int Choice =0 ;

                Date :
                printf("Enter the New Date : ");
                fflush(stdin);
                scanf("%s",Patient_t[Position].Date);
                Default3 :
                printf("\nEnter(1) to Save the Update \n");
                printf("Enter(2) to Change the Current Update\n");
                printf("Enter(3) to Anther Update\n");
                printf("Enter(4) to Main Page \n");
                printf("Enter(5) to Exit\n");
                scanf("%i",&Choice);

                switch(Choice)
                {
                case 1 :
                   {
                        unsigned int Check;

                        printf("\nUpdate successed\n\n");
                        Old :
                        printf("Enter (1) to Main Page\n");
                        printf("Enter (2) to Exit\n");
                        scanf("%i",&Check);

                        if(1 == Check)
                        {
                             printf("\n");
                             Application_Interfacing();
                        }
                        else if (2 == Check)
                        {
                              exit(1);
                        }
                        else
                        {
                            printf("Invalid Choice!!!\n\n");
                            goto Old;
                        }
                   }
                   break;

                case 2:
                    printf("\n");
                    goto Date;
                    break;

                case 3:
                    printf("\n");
                    goto Change;
                    break;

                case 4 :
                    printf("\n");
                    Application_Interfacing();
                    break;

                case 5 :
                   exit(1);
                    break;

                default :
                    printf("Invalid Choice!!!\n\n");
                    goto Default3;
                    break;

                }

            }
            break;

        case 4 :
            {
                unsigned int Choice =0 ;

                diagnosis :
                printf("Enter the New diagnosis : ");
                fflush(stdin);
                gets(Patient_t[Position].Diagnosis);

                UpdateAppointment(Patient_t[Position].Diagnosis);

                Default4 :
                printf("\nEnter(1) to Save the Update \n");
                printf("Enter(2) to Change the Current Update\n");
                printf("Enter(3) to Anther Update\n");
                printf("Enter(4) to Main Page \n");
                printf("Enter(5) to Exit\n");
                scanf("%i",&Choice);

                switch(Choice)
                {
                case 1 :
                   {
                        unsigned int Check;
                        printf("\nUpdate successed\n\n");

                        Modern :
                        printf("Enter (1) to main Page\n");
                        printf("Enter (2) to Exit\n");
                        scanf("%i",&Check);

                        if(1 == Check)
                        {
                            printf("\n");
                            Application_Interfacing();
                        }
                        else if (2 == Check)
                        {
                            exit(1);
                        }
                        else
                        {
                            printf("Invalid Choice!!!\n\n");
                            goto Modern;
                        }
                   }
                   break;

                case 2:
                    printf("\n");
                    goto diagnosis;
                    break;

                case 3:
                    printf("\n");
                    goto Change;
                    break;

                case 4 :
                    printf("\n");
                    Application_Interfacing();
                    break;

                case 5 :
                    exit(1);
                    break;

                default :
                    printf("Invalid Choice!!!\n\n");
                    goto Default4;
                    break;

                }

            }
            break;

        case 5:
            {
                unsigned int Choice =0 ;

                Gender :
                printf("Enter the New Gender : ");
                fflush(stdin);
                scanf("%s",Patient_t[Position].Gender);

                Default5 :
                printf("\nEnter(1) to Save the Update \n");
                printf("Enter(2) to Change the Current Update\n");
                printf("Enter(3) to Anther Update\n");
                printf("Enter(4) to Main Page \n");
                printf("Enter(5) to Exit\n");
                scanf("%i",&Choice);

                switch(Choice)
                {
                case 1 :
                   {
                        unsigned int Check;
                        printf("\nUpdate successed\n\n");

                        anchient :
                        printf("Enter (1) to Main Page\n");
                        printf("Enter (2) to Exit\n");
                        scanf("%i",&Check);

                        if(1 == Check)
                        {
                            printf("\n");
                            Application_Interfacing();
                        }
                        else if (2 == Check)
                        {
                             exit(1);
                        }
                        else
                        {
                            printf("Invalid Choice!!!\n\n");
                            goto anchient;
                        }

                   }
                   break;

                case 2:
                    printf("\n");
                    goto Gender;
                    break;

                case 3:
                    printf("\n");
                    goto Change;
                    break;

                case 4 :
                    printf("\n");
                    Application_Interfacing();
                    break;

                case 5 :
                    exit(1);
                    break;

                default :
                    printf("Invalid Choice!!!\n\n");
                    goto Default5;
                    break;
                }

            }
            break;

        case 6:
            printf("\n");
            Application_Interfacing();
            break;

        case 7 :
           exit(1);
            break;

        default :
            printf("\n");
           goto Change;
           break;

        }

}
/*------------------------------------------------------------------*/

/*------------------- UpdatePatient Function ----------------------*/
void ViewPatient(void)
{
    unsigned int Result=0;

    Error :
    printf("Enter (1) to Show All Patients\n");
    printf("Enter (2) to Show Specific Patient \n");
    scanf("%i",&Result);

    if (0 == Index)
    {
        unsigned int Result=0;

        Var :
        printf("\nThere is no Patient !!\n");
        printf("Enter (1) to Main Page \n");
        printf("Enter (2) to Exit \n");
        scanf("%i",&Result);

        if(1 ==Result)
        {
            printf("\n");
             Application_Interfacing();
        }
        else if(2 == Result)
        {
            exit (1);
        }
        else
        {
            printf("Invalid Choice !!!\n\n");
            goto Var;
        }

    }

    if(1 == Result)
    {
        unsigned int Var=0;

        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Name\t  |\tID\t|\tAge\t|\tGender\t|\tDiagnosis\t\t|\tDate\t\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");

        for(int i=0 ; i<Index ; i++)
        {
            printf("%s\t|\t%i\t|\t%i\t|\t%s\t|\t%s\t|\t%s\t\n",Patient_t[i].Name,Patient_t[i].ID,Patient_t[i].Age,Patient_t[i].Gender,Patient_t[i].Diagnosis,Patient_t[i].Date);
            printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

         Var1 :
            printf("\nEnter (1) to Main Page\n");
            printf("Enter (2) to Exit \n");
            scanf("%i",&Var);

            if(1 == Var)
            {
                printf("\n");
                Application_Interfacing();
            }
            else if(Var == 2)
            {
                exit(1);
            }
            else
            {
                printf("Invalid Choice!!!\n\n");
                goto Var1;
            }

    }

    else if (2 == Result)
    {
        unsigned int ID=0;
        signed int Position=-1;

        printf("Enter your ID : ");
        scanf("%i",&ID);

        for(int i=0 ; i<Index ; i++)
        {
            if(Patient_t[i].ID == ID)
            {
                Position=i;
                break;
            }
        }
        if(Position == -1)
        {
            unsigned int Choice =0;

            printf("The patient is not Founded !!!\n\n");
            Found :
            printf("Enter (1) to Try Again\n");
            printf("Enter (2) to Main Page\n");
            printf("Enter (3) to Exit\n");
            scanf("%i",&Choice);

                    if(1== Choice)
                    {
                        printf("\n");
                        ViewPatient();
                    }
                    else if(2 == Choice )
                    {
                        printf("\n");
                        Application_Interfacing();
                    }
                    else if (3 == Choice)
                    {
                        exit(1);
                    }
                    else
                    {
                        printf("Invalid Choice!!!\n\n");
                        goto Found;
                    }

             }
            unsigned int Var=0;

            printf("Patient Information ....\n");
            printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("Name\t  |\tID\t|\tAge\t|\tGender\t|\tDiagnosis\t\t|\tDate\t\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");
            printf("%s\t|\t%i\t|\t%i\t|\t%s\t|\t%s\t|\t|\t%s\t\n",Patient_t[Position].Name,Patient_t[Position].ID,Patient_t[Position].Age,Patient_t[Position].Gender,Patient_t[Position].Diagnosis,Patient_t[Position].Date);
            printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");

            Var2 :
            printf("Enter (1) to Main Page\n");
            printf("Enter (2) to Exit \n");
            scanf("%i",&Var);
            if(1 == Var)
            {
                printf("\n");
                Application_Interfacing();
            }
            else if(Var == 2)
            {
                exit(1);
            }
            else
            {
                printf("Invalid Choice!!!\n\n");
                goto Var2;
            }

        }

        else
        {
            printf("Invalid Choice !!!\n\n");
            goto Error;
        }

}
/*------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------------*/
