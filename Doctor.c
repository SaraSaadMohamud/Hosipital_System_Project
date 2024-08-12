
/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------ #include ----------------------------*/
#include <stdio.h>
#include "Header.h"
/*--------------------------------------------------------------*/

/*----------------------- Macros -------------------------------*/
#define One 0
#define Max 50
/*--------------------------------------------------------------*/

/*---------------------- Global Variables ----------------------*/
Doctor Doctor_t[Max];
unsigned int Index1=One;
/*--------------------------------------------------------------*/

/*---------------------- Declaration ---------------------------*/

/*--------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------- Function Definition ---------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------- AddDoctor Function ----------------------*/
void AddDoctor(void)
{
    unsigned int Choice = 0;
    unsigned int ID = Index1+1;

    if(Index1 < Max)
    {
        Add :
        printf("Enter Doctor Name : ");
        fflush(stdin);
        gets(Doctor_t[Index1].Name);

        printf("Enter Doctor Major:");
        fflush(stdin);
        gets(Doctor_t[Index1].Major);
        Doctor_t[Index1].ID = ID;

        printf("Enter Doctor WorkShift(Start hour(am, pm) : End hour(am, pm)) : ");
        fflush(stdin);
        gets(Doctor_t[Index1].WorkShift);

        Invalid :
        printf("\nEnter (1) to Save the Information \n");
        printf("Enter (2) to Change \n");
        scanf("%i",&Choice);

        if(1 == Choice)
        {
            unsigned int Choice=0;

            printf("\nDate Saved Successfully...\n");
            Index1++;

            Option :
            printf("\nEnter (1) to Add New Doctor\n");
            printf("Enter (2) to Main Page\n");
            printf("Enter (3) to Exit\n");
            scanf("%i",&Choice);
            if(1 == Choice)
            {
                printf("\n");
                AddDoctor();
            }
            else if(2 == Choice)
            {
                 printf("\n");
                 Application_Interfacing();
            }
            else if(3 == Choice)
            {
                exit(1);
            }
            else
            {
                printf("Invalid Choice!!!\n");
                goto Option ;
            }
        }
        else if (2 == Choice)
        {
            printf("\n");
            goto Add;
        }
        else
        {
            printf("Invalid Choice!!!\n");
            goto Invalid;
        }

    }
    else
    {
        printf("\nSorry There is no Empty Position for New Doctor!!!\n\n");
        Application_Interfacing();
    }

}
/*-------------------------------------------------------------*/

/*------------------- DeleteDoctor Function ----------------------*/
void DeleteDoctor(void)
{
    unsigned int ID=0;
    signed int Position=-1;

    printf("Enter your ID : ");
    scanf("%i",&ID);

    for(int i=0 ; i<Index1 ; i++)
    {
        if(ID == Doctor_t[i].ID)
        {
            Position = i;
            break;
        }
    }

    if(-1 == Position)
    {
         unsigned int Choice=0;

            printf("\n Sorry, This Doctor is Not Work Here!!!\n");

            Delete :
            printf("\nEnter (1) to Try Again \n");
            printf("Enter (2) to Main Page \n");
            printf("Enter (3) to Exit \n");
            scanf("%i",&Choice);

            if(1 == Choice)
            {
                printf("\n");
                DeleteDoctor();
            }
            else if(2 == Choice)
            {
                printf("\n");
                Application_Interfacing();
            }
            else if(3 == Choice)
            {
                exit(1);
            }
            else
            {
               printf("Invalid Choice!!!\n\n") ;
               goto Delete;
            }

    }
    unsigned int Result=0;
    printf("\nAre you sure you want to Delete Doctor???\n");
    Sure :
    printf("\nEnter (1) If you Sure\n");
    printf("Enter (2) to Main Page\n");
    printf("Enter (3) to Exit\n");
    scanf("%i",&Result);

    if(1 == Result)
    {
        unsigned int Choice=0;

        Doctor_t[Position] = Doctor_t[Position+1];
        Index1--;

        printf("\nDeleteing Process is Successfull\n");

        Error :
        printf("\nEnter (1) to Main Page \n");
        printf("Enter (2) to Exit \n ") ;
        scanf("%i",&Choice) ;

        if(1 == Choice)
        {
            printf("\n");
            Application_Interfacing();
        }
        else if (2 == Choice)
        {
            exit(1);
        }
        else
        {
            printf("Invalid Choice!!!\n\n");
            goto Error;
        }

    }
    else if (2 == Result)
    {
        printf("\n");
        Application_Interfacing();
    }
    else if (3 == Result)
    {
        exit(1);
    }
    else
    {
        printf("Invalid Choice !!!\n\n");
        goto Sure;
    }

}
/*-------------------------------------------------------------*/

/*------------------- ViewDoctor Function ----------------------*/
void ViewDoctor(void)
{
    unsigned int Result=0;

    Error :
    printf("\nEnter (1) to Show All Docotrs\n");
    printf("Enter (2) to Show Specific Doctor \n");
    scanf("%i",&Result);
    if(0 == Index1)
    {
        unsigned int Choice =0;

        printf("\nSorry, There are no Doctors at the System!!\n");
        NODoctor :
        printf("\nEnter (1) to Main Page\n");
        printf("Enter (2) to Exit\n");
        scanf("%i",&Choice);

        if(1 == Choice)
        {
            printf("\n");
            Application_Interfacing();
        }
        else if (2 == Choice)
        {
            exit(1);
        }
        else
        {
            printf("Invalid Choice!!\n\n");
            goto NODoctor;
        }
    }
    if(1 == Result)
    {
        unsigned int Var=0;

        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Name\t |\tID\t|\tMajor\t|\tWorkShift\t\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");

        for(int i=0 ; i<Index1 ; i++)
        {
            printf("%s\t |\t%i\t|\t%s\t|\t%s\t\n",Doctor_t[i].Name,Doctor_t[i].ID,Doctor_t[i].Major,Doctor_t[i].WorkShift);
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
        else if(2 == Var)
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

        printf("\nEnter your ID : ");
        scanf("%i",&ID);

        for(int i=0 ; i<Index1 ; i++)
        {
            if(Doctor_t[i].ID == ID)
            {
                Position=i;
                break;
            }
        }

        if(Position == -1)
        {
            unsigned int Choice =0;
            AddD :
            printf("\nThe Doctor is Not Found !!!\n");
            printf("Enter (1) to Try Again\n");
            printf("Enter (2) to Main Page\n");
            printf("Enter (3) to Exit\n");
            scanf("%i",&Choice);

            if(1== Choice)
            {
                printf("\n");
                ViewDoctor();
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
                goto AddD;
            }

        }

        unsigned int Var=0;

        printf("Doctor Information ....\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Name\t  |\tID\t|\tMajor\t|\tWorkShift\t\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");
        printf("%s\t|\t%i\t|\t%s\t|\t%s\t\n",Doctor_t[Position].Name,Doctor_t[Position].ID,Doctor_t[Position].Major,Doctor_t[Position].WorkShift);
        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");

        Var :
        printf("\nEnter (1) to Main Page\n");
        printf("Enter (2) to Exit \n");
        scanf("%i",&Var);

        if(1 == Var)
        {
            printf("\n");
            Application_Interfacing();
        }
        else if(2 == Var)
        {
            exit(1);
        }
        else
        {
            printf("Invalid Choice!!!\n\n");
            goto Var;
        }

    }
    else
    {
        printf("Invalid Choice!!!\n\n");
        goto Error;
    }

}
/*----------------------------------------------------------------*/

/*------------------- UpdateDoctor Function ----------------------*/
void UpdateDoctor(void)
{
    unsigned int ID=0;
    unsigned int UserUpdate=0;
    signed int Position=-1;

    printf("\nEnter your ID :");
    scanf("%i",&ID);

    for(int i=0 ; i<Index1 ; i++)
    {
        if(Doctor_t[i].ID == ID)
        {
            Position = i;
            break;
        }
    }

    if(Position)
    {
        unsigned int Choice =0;
        Update :
        printf("\nThe Doctor is Not Founded !!!\n");
        printf("Enter (1) to Try Again\n");
        printf("Enter (2) to Main Page\n");
        printf("Enter (3) to Exit\n");
        scanf("%i",&Choice);

        if(1== Choice)
        {
            printf("\n");
            UpdateDoctor();
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
            printf("Invalid Choice!!!\n");
            goto Update;
        }

        }
        Change :
        printf("\nEnter (1) to Change the Name \n");
        printf("Enter (2) to Change the Major \n");
        printf("Enter (3) to Change the workShift \n");
        printf("Enter (4) to Main Page \n");
        printf("Enter (5) to Exit \n");
        scanf("%i",&UserUpdate);

        switch(UserUpdate)
        {
        case 1:
            {
                unsigned int Choice=0;

                Name :
                printf("\nEnter the New Name :");
                fflush(stdin);
                gets(Doctor_t[Position].Name);

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

                        printf("\nUpdate is successed\n");
                        DUpdate :
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
                            goto DUpdate;
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
                printf("\nEnter the New Major : ");
                fflush(stdin);
                gets(Doctor_t[Position].Major);

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
                        DMjor :
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
                            goto DMjor;
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
                printf("\nEnter the New WorkShift : ");
                fflush(stdin);
                gets(Doctor_t[Position].WorkShift);

                Default3 :
                printf("\nEnter(1) to Save the Update \n");
                printf("Enter(2) to Change the Current Update\n");
                printf("Enter(3) to Anther Update\n");
                printf("Enter(4) to Main page \n");
                printf("Enter(5) to Exit\n");
                scanf("%i",&Choice);

                switch(Choice)
                {
                case 1 :
                   {
                        unsigned int Check;

                        printf("\nUpdate is successed\n");
                        DWShift :
                        printf("\nEnter (1) to main Page\n");
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
                            goto DWShift;
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

        case 4:
            printf("\n");
            Application_Interfacing();
            break;

        case 5 :
           exit(1);
            break;

        default :
            printf("Invalid Choice!!!\n\n");
            goto Change;
            break;

        }

}


