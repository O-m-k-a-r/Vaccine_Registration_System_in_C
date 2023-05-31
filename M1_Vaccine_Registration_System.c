#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void appointment();

struct vaccrec1{
char vacc1_status[10];
char vacc1_type[10];
char vacc1_date[10];
char vacc1_centre[30];

};

struct vaccrec2{
char vacc2_status[10];
char vacc2_type[10];
char vacc2_date[10];
char vacc2_centre[30];

};

struct address{
    char city[15];
    char state[30];
    char zipcode[6];
};
struct userinfo{
    char fname[25];
    char lname[25];
	char aadhar[10];
	char address[40];
	char dob[6];
	char number[12];
	char gender[10];
	char email[40];
	char centre[30];
    struct address itm[50];
    struct vaccrec1 vc1[30];
    struct vaccrec2 vc2[30];
    
};
struct check{
char checkadhr[10];
char checkname[25];
char checkvaccompl[10];
char checkvacpend[10];
char checkcenter[30];
char checkdate[15];
char checkc1[20];
char checkc2[20];
char checkappointed[20];
};


void newregistration()
{
    char z,name[25];
    int k;
    struct userinfo unf;
    struct check chk;
    FILE *inf;
    inf=fopen("record.txt","a+");
   new:
   system("cls");
    printf("\n##################### Welcome to vaccine registration #####################");
    printf("\n\t\t\tPlease fill the given information");
   
    printf("\n\n\t\tFirst Name: ");
   scanf("%s",unf.fname);

   printf("\n\t\tLast Name: ");
   scanf("%s",unf.lname);
  
    printf("\n\t\tAadhar Number: ");
   scanf("%s",unf.aadhar);

    printf("\n\t\tyear of Birth: ");
   scanf("%s",unf.dob);

    printf("\n\t\tNumber: ");
   scanf("%s",unf.number);

    printf("\n\t\tEmail ID: ");
   scanf("%s",unf.email);

    printf("\n\t\tAddress:\n");

           printf("\n\t\t\tCity: ");
          scanf("%s",unf.itm->city);
           printf("\n\t\t\tState: ");
          scanf("%s",unf.itm->state);
           printf("\n\t\t\tZipcode: ");
          scanf("%s",unf.itm->zipcode);
           printf("-----------------------------------------------------\nYou had been Registered..........\n");

            fprintf(inf,"\n%s %s %s %s %s %s %s %s %s\n",unf.fname,unf.lname,unf.aadhar,unf.dob,unf.number,unf.email,unf.itm->city,unf.itm->state,unf.itm->zipcode);


    fclose(inf);

   
   printf("\n\t\tBook an appointment.....[y/n]=");
    scanf("%s",&z);
     k=("%d",z);
     if(z==89||z==121)
     {
         appointment();
     }
    
    else
    {
        main();
    }
  
   
}


void appointment()
{
    system("cls");
    struct userinfo unf;
    struct check chk;
    char z,a=0;
    int k,test=0;
    FILE *inf;
    FILE *vacc1;
    FILE *vacc2;
    inf=fopen("record.txt","r");
    vacc1=fopen("vacc1.txt","a+");
    vacc2=fopen("vacc2.txt","a+");
    system("cls");
    printf("======================== This is appointment section========================");
    printf("\n\n\t\tHave you registered earlier......[y/n]=");
     scanf("%s",&z);
    printf("\n\t\tEnter your Aadhar no.: ");
    scanf("%s",chk.checkadhr);
    char completed[10]="Completed";
    char pending[10]="Pending";
    char covishield[20]="Covishield";
    char covaxin[20]="Covaxin";
    char appointed[20]="Appointed";
    

    
    while(fscanf(inf,"\n%s %s %s %s %s %s %s %s %s\n",unf.fname,unf.lname,unf.aadhar,unf.dob,unf.number,unf.email,unf.itm->city,unf.itm->state,unf.itm->zipcode)!=EOF)
    {
        if (strcmp(chk.checkadhr,unf.aadhar)==0)
            {
                printf("\t\t\tName: %s %s",unf.fname,unf.lname);
                printf("\n\t\t\tEmail ID: %s",unf.email);
                while(fscanf(vacc1,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc1->vacc1_date,unf.vc1->vacc1_status,unf.vc1->vacc1_type,unf.vc1->vacc1_centre)!=EOF)
                {
                    printf(".");
                    if(strcmp(chk.checkadhr,unf.aadhar)!=0)
                {
                   
                    printf("\n--------------------------------------------------------------------------------------------------------\n\t\t\tBook for First dose");
                    printf("\n\t\t\tEnter your city: ");
                    scanf("%s",chk.checkcenter);
                    printf("\n\t\t\tEnter Date: ");
                    scanf("%s",chk.checkdate);
                    printf("\n\t\t\t\t\tVaccine type\n\t\t\t1.Covishield\t\t\t2.covaxin\n");
                    scanf("%d",&a);
                    switch(a)
                    {
                        case 1:
                        strcpy(unf.vc1->vacc1_type,covishield);
                        break;

                        case 2:
                        strcpy(unf.vc1->vacc1_type,covaxin);
                        break;
                    }

                    strcpy(unf.vc1->vacc1_date,chk.checkdate);
                    strcpy(unf.vc1->vacc1_centre,chk.checkcenter);
                    strcpy(unf.vc1->vacc1_status,appointed);
                    fprintf(vacc1,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc1->vacc1_date,unf.vc1->vacc1_status,unf.vc1->vacc1_type,unf.vc1->vacc1_centre);
                    printf("\n\t\tAppointment for first dose venue: %s city hospital, Date: %s",chk.checkcenter,chk.checkdate);
                    printf("\n==============YOU HAVE BOOKED FOR FIRST DOSE==============");
                }


               else  if(strcmp(chk.checkadhr,unf.aadhar)==0&&strcmp(unf.vc1->vacc1_status,"Appointed")==0)
                {
                    printf("==============First dose is over==============");
                    printf("\n-------------------------------------------------\n\t\tBook for Second dose");
                     printf("\n\tEnter your city:");
                    scanf("%s",chk.checkcenter);
                    printf("\n\tEnter Date:");
                    scanf("%s",chk.checkdate);
                    printf("\n\t\tVaccine type\n\t1.Covishield\t\t2.covaxin\n");
                    scanf("%d",&a);
                    switch(a)
                    {
                        case 1:
                        strcpy(unf.vc2->vacc2_type,covishield);
                        break;

                        case 2:
                        strcpy(unf.vc2->vacc2_type,"Covaxin");
                        break;
                    }

                    strcpy(unf.vc2->vacc2_date,chk.checkdate);
                    strcpy(unf.vc2->vacc2_centre,chk.checkcenter);
                    strcpy(unf.vc2->vacc2_status,"Appointed");
                    fprintf(vacc2,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc2->vacc2_date,unf.vc2->vacc2_status,unf.vc2->vacc2_type,unf.vc2->vacc2_centre);
                    printf("==============YOU HAVE BOOKED FOR SECOND DOSE==============");

                }

                

                


                test ++;
                }
            }
            
            test++;
    }
fclose(vacc2);    
fclose(vacc1);
fclose(inf);

 printf("\nBack To Main Menu.....[y/n]=");
    scanf("%s",&z);
     k=("%d",z);
     if(z==89||z==121)
     {
         main();
     }
    
    

}
   

void printrecord()

{
    struct userinfo unf;
    struct check chk;
    
    int test1=0,test2=0,k;
    char z;
    FILE *inf;
    FILE *vacc1;
    FILE *vacc2;
    inf=fopen("record.txt","r");
    vacc1=fopen("vacc1.txt","r");
    vacc2=fopen("vacc2.txt","r");
    printf("################### PRINT RECORD ###################");
    printf("\n\tEnter your Aadhar no. ");
    scanf("%s",chk.checkadhr);

      while( fscanf(inf,"\n%s %s %s %s %s %s %s %s %s\n",unf.fname,unf.lname,unf.aadhar,unf.dob,unf.number,unf.email,unf.itm->city,unf.itm->state,unf.itm->zipcode)!=EOF)
      {
          if(strcmp(chk.checkadhr,unf.aadhar)==0)
          {
       printf("Name: %s %s",unf.fname,unf.lname);
       printf("\nAadhar: %s",unf.aadhar);
       printf("\nYear of Birth: %s",unf.dob);
       printf("\nNumber: %s",unf.number);
       printf("\nCity: %s",unf.itm->city);
       printf("\n\t\tVaccination Information");
       while(fscanf(vacc1,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc1->vacc1_date,unf.vc1->vacc1_status,unf.vc1->vacc1_type,unf.vc1->vacc1_centre)!=EOF)
       {   if(strcmp(chk.checkadhr,unf.aadhar)==0)
       {
           if(unf.vc1->vacc1_status!=NULL)
           {
               printf("\nDose 1:\t\t%s\t\t%s\t\t%s\t\t%s",unf.vc1->vacc1_status,unf.vc1->vacc1_type,unf.vc1->vacc1_centre,"13/03/2022");
           }

           else
           {
               printf("You have not completed your First dose");
               

           }
       }
           test1 ++;
       }
       while(fscanf(vacc2,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc2->vacc2_date,unf.vc2->vacc2_status,unf.vc2->vacc2_type,unf.vc2->vacc2_centre)!=EOF)
       {
           if(strcmp(chk.checkadhr,unf.aadhar)==0)
           {
       if(unf.vc2->vacc2_status!=NULL)
       {
       printf("\nDose 2:\t%s\t%s\t\t%s  %s",unf.vc2->vacc2_status,unf.vc2->vacc2_type,unf.vc2->vacc2_centre,unf.vc2->vacc2_date);
       }
       else
       {
           printf("Your second dose is pending");
       }
           }
           test1 ++;

       }
      }
      test2 ++;
      }
      over:

    fclose(vacc2);
    fclose(vacc1);
    fclose(inf);
    printf("\n\nBack To Main Menu.....[y/n]=");
    scanf("%s",&z);
     k=("%d",z);
     if(z==89||z==121)
     {
        main();
     }

}


void viewrecord()
{
    system("cls");
    printf("==================== View Record ====================");
    struct userinfo unf;
    struct check chk;
    int test=0,k;
    char z;
    FILE *inf;
    FILE *vacc1;
    FILE *vacc2;
    inf=fopen("record.txt","r");
    vacc1=fopen("vacc1.txt","r");
    vacc2=fopen("vacc2.txt","r");
   


     while( fscanf(inf,"\n%s %s %s %s %s %s %s %s %s\n",unf.fname,unf.lname,unf.aadhar,unf.dob,unf.number,unf.email,unf.itm->city,unf.itm->state,unf.itm->zipcode)!=EOF)
      {
          strcpy(chk.checkadhr,unf.aadhar);
          
          printf("\n==========================================================================\n");
       printf("\nName: %s %s",unf.fname,unf.lname);
       printf("\naadhar: %s",unf.aadhar);
       printf("\nYear of Birth: %s",unf.dob);
       printf("\nnumber: %s",unf.number);
       printf("\ncity: %s",unf.itm->city);
       
       while(fscanf(vacc1,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc1->vacc1_date,unf.vc1->vacc1_status,unf.vc1->vacc1_type,unf.vc1->vacc1_centre)!=EOF)
       {   if(strcmp(chk.checkadhr,unf.aadhar)==0)
       { printf("\n\t\tVaccination Information");
           if(unf.vc1->vacc1_status!=NULL)
           {
               
               printf("\nDose 1:\t%s\t%s\t\t%s  %s",unf.vc1->vacc1_status,unf.vc1->vacc1_type,unf.vc1->vacc1_centre,unf.vc1->vacc1_date);
           }

           else
           {
               printf("You have not completed your First dose");
               

           }
       }
           test ++;
       }
       while(fscanf(vacc2,"\n%s %s %s %s %s\n",unf.aadhar,unf.vc2->vacc2_date,unf.vc2->vacc2_status,unf.vc2->vacc2_type,unf.vc2->vacc2_centre)!=EOF)
       {
           if(strcmp(chk.checkadhr,unf.aadhar)==0)
           {
       if(unf.vc2->vacc2_status!=NULL)
       {
       printf("\nDose 2:\t%s\t%s\t\t%s",unf.vc2->vacc2_status,unf.vc2->vacc2_type,unf.vc2->vacc2_centre);
       }
       else
       {
           printf("Your second dose is pending");
       }
           }
           test ++;

       }
      
      test ++;
      }
      
    fclose(vacc2);
    fclose(vacc1);
    fclose(inf);

     printf("\nBack To Main Menu.....[y/n]=");
    scanf("%s",&z);
     k=("%d",z);
     if(z==89||z==121)
     {
        main();
     }
    
     

}

void main()
{
   

	int a;
   
	system("cls");
	printf("\n########################### Welcome to Vaccine Registration System ###########################\n\n\n");
	printf("\t\t\t1) New Registration\n");
	printf("\t\t\t2) Book an Appointment\n");
    printf("\t\t\t3) Print Vaccination certificate\n");
    printf("\t\t\t4) View Vaccination Record\n\n");
	printf("\t\t\tenter the Choice:");
	scanf("%d", &a);
    system("cls");
    
    switch(a)
    {

        case 1:
        newregistration();
        break;

        case 2:
        appointment();
        break;

        case 3:
        printrecord();
        break;

        case 4:
        viewrecord();
        break;


    }


}






