//Ralph Taylor.  ID: 1803071.
//Marvin Arnett. ID: 1701403.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int categoryUser();
int loginManager();
int loginClerks();
float calculations();
void update();
void invoice();
void getArtist();
void executeLogins();
void loadfiles();
void storefiles();
void artistInfo();
void displayAllInfo();
void displays(int );
void displayOne();
void artistBooking();
void updateArtist();
void deleteArtist();
void generateReport();
int menu1();
int menu2();
void executeMenu();
void executeMenu2();

FILE *fptr;

typedef union
{
    int fAccountNum;
    char majorCurCharity;
}foundation;

typedef struct Addre
{
    char streetName[20];
    char townName[25];
    char parish[10];
    char stateName[20];
    char country[30];
}address;

typedef struct bookingInfo
{
    int bookingNum;
    char type;
    int date;
    char hotel[35];
    char guide[35];
    char flightInfo[30];
    float localRate;
    float foreignRate;
    //address;
}booking;

typedef struct Artist
{
    int id;
    char stageName[40];
    char realName[35];
    int accountNum;
    float accountBal;
    long telephone;
    float earningPerYr;
    foundation found;
    address add;
    booking book;
}art;
art artArr[7];


int main()
{

    int choice,choice1,choice2;

    do{
        choice=categoryUser();
        executeLogins(choice);

        if(choice==1)
        {
     do
      { loadfiles();
          choice1=menu1();
          executeMenu(choice1);
          Sleep(2500);
      }while(choice!=6);
        }
else
{
    do
        {
            loadfiles();
            choice2=menu2();
            executeMenu2(choice2);
            Sleep(2500);
        }while(choice2!=6);
}
        Sleep(2500);
    }while (choice!=3);

return 0;
}
//This is the menu that asks what type of user that you are(Whether Manager or Clerk).
int categoryUser()
{
    fflush(stdin);
    printf("load files...");
    int cat;

    printf("\t\t\t\t|\tWelcome to the Artist Management system :)\t|\t\n");
    Sleep(2500);
    system("cls");
    printf("What category of user are you?\n\n");
    printf("Please enter 1 for Manager or 2 for Clerk or 3 to leave the system: \n");
    scanf("%d",&cat);
    return cat;
}

//Function to load the different security sections for the manager or clerk.
void executeLogins(int opt)
{
    switch(opt)
    {
        case 1: loginManager();
        break;

        case 2: loginClerks();
        break;

        case 3: exit(0);
        break;

        default: printf("Invalid option chosen. Please try again!!!!!!");
    }
}


//Menu for the Managers once they have enetered the correct username and password.
int menu1()
{
    int option1;

    system("cls");
    printf("\t\t\t\t\t\t|*Welcome to the menu*|\n\n");
    printf("\t\t\t\t\t\t|1.) |*Add an artist\n\n");
    printf("\t\t\t\t\t\t|2.) |*Display an artist.\n\n");
    printf("\t\t\t\t\t\t|3.) |*Display all artists.\n\n");
    printf("\t\t\t\t\t\t|4.) |*Update an artist.\n\n");
    printf("\t\t\t\t\t\t|5.) |*Delete an artist. \n\n");
    printf("\t\t\t\t\t\t|6.) |*Exit the system.\n\n");
    printf("\t\t\t\t\t|Please choose either options 1,2,3,4,5, or 6: |\n");
    scanf("%d",&option1);

    return option1;
}

int i=0;
void getArtist()
{
     fflush(stdin);
    artArr[i].id=111*1;
    printf("Your ID number is: %d\n\n", artArr[i].id);
    printf("Please enter your stage name: ");
    gets(artArr[i].stageName);
    fflush(stdin);
    printf("\nPlease enter your real name: ");
    gets(artArr[i].realName);
    printf("\nPlease enter your telephone number: ");
    scanf("%1d",&artArr[i].telephone);
    fflush(stdin);
    printf("\nPlease enter your account number: ");
    scanf("%d",&artArr[i].accountNum);
    fflush(stdin);
    printf("\nPlease enter your account balance: ");
    scanf("%f",&artArr[i].accountBal);
    fflush(stdin);
    printf("\nPlease enter your yearly earnings: ");
    scanf("%f",&artArr[i].earningPerYr);
    fflush(stdin);
    printf("\nPlease enter your street name: ");
    scanf("%s", artArr[i].add.streetName);
    printf("\nPlease enter your town name: ");
    scanf("%s", artArr[i].add.townName);
    printf("\nPlease enter your parish name: ");
    scanf("%s", artArr[i].add.parish);
    fflush(stdin);
    printf("\nPlease enter your state name: ");
    scanf("%s", artArr[i].add.stateName);
    printf("\nPlease enter your Country's name: ");
    scanf("%s", artArr[i].add.country);
    printf("\n\nYour ID. number is: %d",artArr[i].id);

i++;
}
//This function is used to store files into the binary files respectfully.
void storefiles()
{
    int i;
    fptr=fopen("Program.bin","wb");
    if (fptr == NULL)
    {
        printf("File is not opened.");
    }
    else
    {
        for(i=0;i<5;i++)
        {

            fseek(fptr,sizeof(art)*i,SEEK_SET);
            fwrite(&artArr[i],sizeof(artArr),1,fptr);
            fprintf(fptr,"%s %s %ld %d %f %f ",artArr[i].stageName,artArr[i].realName,artArr[i].telephone,artArr[i].accountNum,artArr[i].accountBal,artArr[i].earningPerYr);
            Sleep(1500);
        }
    }

    printf("Store records successfully!!");
    exit(1);
}
//Function to enter artists information.
 void artistInfo()
{
    int i;
    char d;
    system("cls");

        getArtist();
}
//This menu should execute the menu for the managers.
void executeMenu(int op)
{

    switch(op)
    {
    case 1: artistInfo();
        break;

    case 2: displayOne();
        break;

    case 3: displayAllInfo();
        break;

    case 4: updateArtist();
        break;

    case 5: //deleteArtist();
        break;

    case 6: storefiles();
        break;

        default: printf("INVALID OPTION CHOSEN. PLEASE SELECT AGAIN");
    }
}

//This is the execute function for the clerks.
void executeMenu2(int op)
{
     switch(op)
    {
    case 1: artistInfo();
        break;

    case 2: displayOne();
        break;

    case 3: displayAllInfo();
        break;

    case 4: artistBooking();
        break;

    case 5: updateArtist();
        break;

    case 6: storefiles();
        break;

        default: printf("INVALID OPTION CHOSEN. PLEASE SELECT AGAIN");
    }
}

void artistBooking()
{
    int i;

    printf("Please enter the booking number: ");
    scanf("%d",artArr[i].book.bookingNum);
    printf("\nPlease enter the booking type(c-charity or o-other): ");
    scanf("%c",&artArr[i].book.type);

    if(artArr[i].book.type=='c')
    {
        printf("Please enter the account number: ");
        scanf("%d",&artArr[i].found.fAccountNum);
    }
    else
    {
        printf("Please enter the chariry thing: ");
        scanf("%s",artArr[i].found.majorCurCharity);
    }

    printf("\nPlease enter the date of the event: ");
    scanf("%s",artArr[i].book.date);
    printf("\nPlease enter the hotel: ");
    scanf("%s", artArr[i].book.hotel);
    printf("\nPlease enter the guide: ");
    gets(artArr[i].book.guide);
    printf("\nPlease enter the flight information: ");
    gets(artArr[i].book.flightInfo);
    printf("\nPlease enter the local rate: ");
    scanf("%f",&artArr[i].book.localRate);
    printf("\nPlease enter the foreign rate: ");
    scanf("%f",&artArr[i].book.foreignRate);
    invoice();
}

float calculations()
{
    int sum;

   // sum=artArr[i].book.foreignRate+flightCost;
}

void invoice()
{
    printf("*************************INVOICE*******************************");
    printf("YOUR BILL AS FOLLOWS IS: ");
    //system("cls");
    Sleep(1000);
    printf("");
    printf("");
    printf("");
    printf("");
}
//Menu for the Clerks once they have entered the correct username and password into their security screen.
int menu2()
{
    int op;

    system("cls");
    printf("*Welcome to the Clerk's Menu*\n\n");
    printf("1) Add an artist information.\n");
    printf("2) Display one artist's information.\n");
    printf("3) Display all artist information.\n");
    printf("4) To book an artist.\n");
    printf("5) Update the Artist Information.\n");
    printf("6) Exit the system.\n");
    printf("Please choose either option 1,2,3,4,5,or, 6: ");
    scanf("%d",&op);

    return op;
}

//This is the security screen for the Clerks to enter their password and username.
int loginClerks()
{
    //The USERNAME IS Clerker12
      //The PASSWORD IS 123

    char username[15];
    int password;
    int attempts=1, i;

    system("cls");
    fflush(stdin);
    printf("Please enter the Username: ");
    gets(username);
    fflush(stdin);
    printf("\nPlease enter the password: ");
    scanf("%d",&password);

    if((strcmp(username,"Clerk")==0)&&(password==123))
    menu2();
    else
    {
        while((attempts<3)&&(strcmp(username,"Clerk")!=0)&&(password!=123))
        {
            if(i==2)
                {
                printf("This is your last attempt to enter the system!!");
                Sleep(1200);
                }
        system("cls");
        fflush(stdin);
        printf("Please enter the Username: ");
        gets(username);
        fflush(stdin);
        printf("\nPlease enter the password: ");
        scanf("%d",&password);
//This part with the password and username needs to be changed.
        if ((strcmp(username,"Clerk")!=0)&&(password!=123))
        {
            printf("\n\nINCORRECT username and/or password ENTERED!!!!!");
            Sleep(1600);
        }
        attempts++;
        if(attempts==3)
        {
            system("cls");
        printf("\nTOO MANY ATTEMPTS WERE MADE TO LOGIN TO THE SYSTEM\n\n");
        for(i=0;i<=7;i++)
        {
            printf(".");
            Sleep(1000);
        }
        system("cls");
        printf("\n\n\n\n\t\t\t\t\tYOU ARE LOCKED OUT OF THE SYSTEM. SORRY:(\t\t\t\t\n\n\n");
        Sleep(2000);

    exit(0);
    }
    if((strcmp(username,"Clerk")==0)&&(password==123))
        {
            menu2();
        }
  }
 }
 return 0;
}

void updateArtist()
{
    int ad,flag;
    int i;

    system("cls");
    printf("Please enter the id of the artist you want to update: ");
    scanf("%d",&ad);

    for(i=0;i<5;i++)
    {
        if(ad==artArr[i].id)
        {
            printf("ID FOUND!!!");
            Sleep(1500);
            system("cls");
            update(i);
        }
        if(ad!=artArr[i].id&&i==4)
            flag=1;
    }
    if(flag=1)
    {
        printf("\n\nARTIST ID NOT FOUND. PLEASE TRY AGAIN\n\n");
        categoryUser();
    }
    else
    if(flag=0)
        {
    system("cls");
    update();
    }
}

void update(int i)
{
    fflush(stdin);
    printf("Your ID number does not change!!!");
    printf("Your ID number is: %d\n\n", artArr[i].id);
    printf("Please enter your new stage name: ");
    gets(artArr[i].stageName);
    fflush(stdin);
    printf("\nPlease enter your new real name: ");
    gets(artArr[i].realName);
    printf("\nPlease enter your new telephone number: ");
    scanf("%1d",&artArr[i].telephone);
    fflush(stdin);
    printf("\nPlease enter your new account number: ");
    scanf("%d",&artArr[i].accountNum);
    fflush(stdin);
    printf("\nPlease enter your new account balance: ");
    scanf("%f",&artArr[i].accountBal);
    fflush(stdin);
    printf("\nPlease enter your new yearly earnings: ");
    scanf("%f",&artArr[i].earningPerYr);
    fflush(stdin);
    printf("\nPlease enter your new street name: ");
    scanf("%s", artArr[i].add.streetName);
    printf("\nPlease enter your new town name: ");
    scanf("%s", artArr[i].add.townName);
    printf("\nPlease enter your new parish name: ");
    scanf("%s", artArr[i].add.parish);
    fflush(stdin);
    printf("\nPlease enter your new state name: ");
    scanf("%s", artArr[i].add.stateName);
    printf("\nPlease enter your new Country's name: ");
    scanf("%s", artArr[i].add.country);
    printf("\n\nYour ID. number is: %d",artArr[i].id);

}


void displays(int i)
{
    system("cls");
    printf("\n\nYour id is:\t %d",artArr[i].id);
    printf("\nYour real name is:\t %s", artArr[i].realName);
    printf("\nYour stage name is:\t %s", artArr[i].stageName);
    printf("\nYour account number is:\t%d", artArr[i].accountNum);
    printf("\nYour acount balance is:\t%.2f", artArr[i].accountBal);
    printf("\nYour telephone number is:\t %1d",artArr[i].telephone);
    printf("\nYour yearly earning is:\t %.2f", artArr[i].earningPerYr);
    Sleep(2000);
}

void displayOne()
{
    int num, i;
    printf("Please enter your id number: ");
    scanf("%d",&num);

    for(i=0;i<7;i++)
    {
        if(num==artArr[i].id)
            break;
    }
    displays(i);
}

void displayAllInfo()
{
    int i;

    for(i=0;i<7;i++)
    {
        if(artArr[i].id==0)
            break;
        else
        displays(i);
    }
}
//Security screen for the Manager to login.
int loginManager()
{
    //The USERNAME IS Managers123
      //PASSWORD IS 12345

    char username[15];
    int  password;
    int attempts=1, i;

    system("cls");
    fflush(stdin);

    printf("Please enter the Username: ");
    gets(username);
    fflush(stdin);
    printf("\nPlease enter the password: ");
    scanf("%d",&password);
    if((strcmp(username,"Managers")==0)&&(password==12345))
    menu1();
    else
        {
    while((attempts<3)&&(strcmp(username,"Managers")!=0)&&(password!=12345))
        {
            printf("\n\nINCORRECT username and/or password ENTERED!!!!!");
            Sleep(1600);
          //  if ((strcmp(username,"Managers123")!=0)&&(password!=12345))
        //{
          //printf("\n\nINCORRECT username and/or password ENTERED!!!!!");
            //Sleep(1600);
        //}
            if(i==2)
                {
                printf("This is your last attempt to enter the system!!");
                Sleep(1200);
                }
        system("cls");
        fflush(stdin);
        printf("Please enter the Username: ");
        gets(username);
        fflush(stdin);
        printf("\nPlease enter the password: ");
        scanf("%d",&password);
//This part with the password and username needs to be changed.
        //if ((strcmp(username,"Managers123")!=0)&&(password!=12345))
        //{
          //  printf("\n\nINCORRECT username and/or password ENTERED!!!!!");
           // Sleep(1600);
        //}
        attempts++;
        if(attempts==3)
        {
            system("cls");
        printf("\nTOO MANY ATTEMPTS WERE MADE TO LOGIN TO THE SYSTEM\n\n");
        for(i=0;i<=7;i++)
        {
            printf(".");
            Sleep(1000);
        }
        system("cls");
        printf("\n\n\n\n\t\t\t\t\tYOU ARE LOCKED OUT OF THE SYSTEM. SORRY:(\t\t\t\t\n\n\n");
        Sleep(2000);

    exit(0);
        }

        if((strcmp(username,"Managers")==0)&&(password==12345))
            {
                printf("\n\nWelcome to the system");
                Sleep(1500);
                menu1();
            }
    }
    //While do-while post loop  to ensure that the user has three attempts to enter the system.

}
return 0;
}



void loadfiles()
{
    int i = 0;

    fptr=fopen("Program","rb");
    if ((fptr==NULL))
    {
        printf("The file is not open. \n");
    }
    else
        for(i=0;i<7;i++)

    {
        fseek(fptr,sizeof(art)*i,SEEK_SET);
        fread(&artArr[i],sizeof(artArr[i]),1,fptr);
      fscanf(fptr,"%s %s %ld %d %f %f ",artArr[i].stageName,artArr[i].realName,artArr[i].telephone,artArr[i].accountNum,artArr[i].accountBal,artArr[i].earningPerYr);
        i++;
    }
    fclose(fptr);
}
