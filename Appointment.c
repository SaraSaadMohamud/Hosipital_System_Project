/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------ #include ----------------------------*/
#include <stdio.h>
#include "string.h"
#include "Header.h"
/*--------------------------------------------------------------*/

/*----------------------- Macros -------------------------------*/
#define Max_Patient 500
#define Max_appoint 500
#define String "50$"
#define Max 50
#define One 0
/*--------------------------------------------------------------*/

/*---------------------- Declaration ---------------------------*/
extern unsigned int Index1;
extern Doctor Doctor_t[Max];
extern patient Patient_t[Max_Patient];
/*--------------------------------------------------------------*/

/*---------------------- Global Variables ----------------------*/
Appointment Appointment_t [Max_appoint];
unsigned int Index2 = One;
const char TicketPrice[3] = String;
unsigned int i=0;
/*--------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------------------------------- Function Definition ---------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/

/*------------------- AddِAppointment Function ----------------------*/
void AddAppointment()
{
    signed int CmpResult=2;
    unsigned int Number = Index2+1;

    for(i=0 ; i<Index1 ; i++)
    {
        CmpResult=stricmp(Patient_t[Index2].Diagnosis , Doctor_t[i].Major);
         if(0 == CmpResult)
         {
             unsigned int Choice=0;

             Appointment_t[Index2].PatientID =Patient_t[Index2].ID;
             Appointment_t[Index2].DoctorID  = Doctor_t[i].ID;
             Appointment_t[Index2].ID = Number;
             strcpy( Appointment_t[Index2].Date , Doctor_t[i].WorkShift);
             printf("\n----------------------------------------------\n");
             printf("The Price For the Ticket is = %s\n",TicketPrice);
             printf("----------------------------------------------\n");
             Index2++;
             break;
         }

    }
    if (CmpResult != 0)
    {
        unsigned int Choice=0;

        printf("\nSorry, There is no Available Doctor for This Diagnosis \n");
        choice2 :
        printf("\nEnter (1) to Enter Another Patient\n");
        printf("Enter (2) to  Main Page\n");
        printf("Enter (3) to Exit\n");
        scanf("%i",&Choice);

        if(1 == Choice)
        {
            printf("\n");
            AddPatient();
        }
        else if (2 == Choice)
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
            goto choice2 ;
        }

         }
}
/*------------------------------------------------------------------*/

/*------------------- DeletrِAppointment Function -------------------*/

void DeleteAppointment(int Position)
{
    for(int i=0 ; i< Index2 ; i++)
    {
        Appointment_t[Position] = Appointment_t[Position+1];
    }
    Index2--;
}
/*-------------------------------------------------------------------*/


/*------------------- ViewAppointment Function ----------------------*/
void UpdateAppointment(char x[100])
{
     int i = 0;
     signed int Result = 2;

     for(i=0 ; i<Index1 ; i++)
     {
         Result = stricmp(Doctor_t[i].Major ,x);
         if(Result == 0)
            break;
     }

     if(0 == Result)
     {
         Appointment_t[i].DoctorID = Doctor_t[i].ID;
         strcpy(Appointment_t[i].Date,Doctor_t[i].WorkShift);

     }

     else
     {
         unsigned int Choice=0;

         printf("\nSorry,There is available docotr for this major!!!\n ");
         Error4 :
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
            printf("Invalid Choice !!\n\n");
            goto Error4;
         }

     }

}
/*-------------------------------------------------------------------*/


/*------------------- ViewAppointment Function ----------------------*/
void ViewAppointment(void)
{
    unsigned int Choice = 0 ;

    View :
    printf("Enter (1) to Show All Appointment\n");
    printf("Enter (2) to Show Special Appointment\n");
    scanf("%i",&Choice);

    if(0 == Index2)
    {
        unsigned int Result=0 ;

        printf("There is No Appointment!!\n");
        Var :
        printf("Enter (1) to Main Page \n");
        printf("Enter (2) to Exit \n");
        scanf("%i",&Result);

        if(1 == Result)
        {
             printf("\n");
             Application_Interfacing();
        }

        else if(2 == Result)
            exit (1);
        else
        {
            printf("Invalid Choice!!!\n\n");
            goto Var;
        }

    }
    if(1 == Choice)
    {
        unsigned int Choice1=0;

        printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("AppointmentID\t |\tPatientID\t|\tDoctorID\t|\tAppointmentDate\t\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");

        for(int j=0 ; j <Index2 ; j++)
        {
            printf("%i\t  |\t%i\t|\t%s\t|\t%s\t\n",Appointment_t[j].ID,Appointment_t[j].PatientID,Doctor_t[i].Name,Appointment_t[j].Date);
            printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
        }

        Error2 :
        printf("Enter (1) to Main Page\n");
        printf("Enter (2) to Exit\n");
        scanf("%i",&Choice1);
        if(1 == Choice1)
        {
            printf("\n");
            Application_Interfacing();
        }
        else if(2 == Choice1)
        {
             exit(1);
        }
        else
        {
            printf("Invalid Choice!!!\n\n");
            goto Error2 ;
        }
    }
    else if(2 == Choice)
    {
        unsigned int ID=0;
        unsigned int DID=0;
        signed int Position=-1;

        printf("\nEnter The Appointment ID : ");
        scanf("%i",&ID);

        for(int i=0 ; i <Index2 ; i++)
        {
            if(ID == Appointment_t[i].ID)
            {
                Position = i;
            }
        }
        for(int i=0 ; i>Index1 ; i++)
        {
            if(Appointment_t[Position].DoctorID == Doctor_t[i].ID)
            {
                DID=i;
                break;
            }
        }

        if(1 != Position)
        {
            unsigned int Choice=0;

            printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("AppointmentID\t  |\tPatientID\t|\tDoctorName\t|\tAppointmentDate\t\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------ \n");
            printf("%i\t  |\t%i\t|\t%s\t|\t%s\t\n",Appointment_t[Position].ID,Patient_t[Position].ID,Doctor_t[DID].Name,Appointment_t[Position].Date);
            printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");

            Error3 :
            printf("\nEnter (1) to Main Page\n");
            printf("Enter (2) to Exit\n");
            scanf("%i",&Choice);

            if(1 == Choice)
            {
                printf("\n");
                 Application_Interfacing();
            }
            else if(2 == Choice)
                exit(1);
            else
            {
                printf("Invalid Choice!!!\n\n");
                goto Error3 ;
            }

        }

    }

    else
        {
            printf("Invalid choice!!!\n\n");
            goto View ;
        }
}
/*-------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------------------------*/
