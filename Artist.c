#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int categoryUser();
int loginManager();
int loginClerks();
void executeLogins();
void loadfiles();
void storefiles();
void artistInfo();
void displayAllInfo();
void displayOne();
void deleteArtiist();
int menu1();
int menu2();
void executeMenu();

FILE *fptr;
//Files not completed as yet.

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
    char date[29];
    char hotel[35];
    char guide[35];
    char flightInfo[30];
    float localRate;
    float foreignRate;
    address;
}booking;

typedef struct Artist
{
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
    loadfiles();
    int choice,choice1,choice2;
    int op, op1;

    do{
        choice=categoryUser();
        op=loginManager();
        op1=loginClerks();
        executeLogins(choice);
        Sleep(2500);
      }while((choice!=3)&&(op!=2||op1!=2));

     do
      {
          choice1=menu1();
          executeMenu(choice1);
          Sleep(2500);
      }while((choice!=3);

    return 0;
}

int categoryUser()
{
    int cat;

    printf("\t\t\t\t|\tWelcome to the Artist Management system :)\t|\t\n");
    Sleep(2500);
    system("cls");
    printf("What category of user are you?\n\n");
    printf("Please enter 1 for Manager or 2 for Clerk or 3 to leave the system: \n");
    scanf("%d",&cat);
    return cat;
}

//Function to enter artists information.
void artistInfo()
{
    printf("Welcome to the artist information system:)");
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

        case 3: storefiles();
        break;

        default: printf("Invalid option chosen. Please try again!!!!!!");
    }
}


//Menu for the Managers once they have enetered the correct username and password.
int menu1()
{
    int option1;
    printf("\t\t\t\t\t|*Welcome to the menu*|");
    printf("1. |*Add an artist\n");
    printf("\t2. |*display an artist.\n");
    printf("\t\t3. |*Display all artists.\n");
    printf("\t\t\t4. |*Update an artist.\n")
    printf("\t\t\t\t5. |*Delete an artist. \n");
    printf("\t\t\t\t\t6. |*Exit the system.\n");
    printf("Please choose either options 1,2,3,4, or 5: \n");
    scanf("%d",&option1);

    return option1;
}

//This menu should execute the menu for the managers.
executeMenu(int op)
{

    switch(op)
    {
    case 1: artistInfo();
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

        default: printf("INVALID OPTION CHOSEN. PLEASE SELECT AGAIN");
    }
}

//Menu for the Clerks once they have entered the correct username and password into their security screen.
int menu2()
{

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
    scanf("%d",password);

    if((strcmp(username,"Clerker12")==0)&&(password==123))
    menu2();
    else
    {
        while((attempts<3)&&(strcmp(username,"Clerker12")!=0)&&(password!=123))
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
        scanf("%d",password);
//This part with the password and username needs to be changed.
        if ((strcmp(username,"Clerker12")!=0)&&(password!=123))
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
    menu2();
  }
 }
 return 2;
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
    scanf("%d",password);
    if((strcmp(username,"Managers123")==0)&&(password==12345))
    menu1();
    else
        {
    while((attempts<3)&&(strcmp(username,"Managers123")!=0)&&(password!=12345))
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
        scanf("%d",password);
//This part with the password and username needs to be changed.
        if ((strcmp(username,"Managers123")!=0)&&(password!=12345))
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
        printf("\n\nWelcome to the system");
        menu1();
    }
    //While do-while post loop  to ensure that the user has three attempts to enter the system.

}
return 2;
}

storefiles()
{
    int i;
    fptr=fopen("Programming 2 project.bin","wb");
    if (fptr == NULL)
    {
        printf("File is not opened.");
    }
    else
    {
        for(i=0;i<7;i++)
        {
            //fprintf(fptr,"",);
            //Sleep(1500);
        }
        printf("Store records successfully!!");
        exit(1);
    }
}

loadfiles()
{
    int i;
    fptr=fopen("Programming 2 project.bin","rb");
    if ((fptr==NULL))
    {
        printf("The file is not open. \n");
    }
    else
        do
    {
//        fscanf(fptr,"",);
        i++;
    }while(!feof(fptr));

     fclose(fptr);
}
