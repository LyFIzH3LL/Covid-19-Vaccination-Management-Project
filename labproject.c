#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>


int num;
struct admin
{
    char username[50];
    char password[50];
};

struct user
{
    char username[50];
    char password[50];
};

struct userinfo
{

    char name[50];
    char gender[10];
    int age;
    char address[50];
    int date;
    int month;
    int year;
    char NID[50];
} user01[100];

void createuserinfo()
{
    system("cls");
    printf("Registration for Vaccination");
    printf("\n");

    FILE *fp_u;
    fp_u = fopen("userinfo.txt", "w");
    if (fp_u == NULL)
    {
        puts("Error Getting File");
    }
    printf("\n");

    printf("How Many Persons You Want to Get Registered For Vaccination:");
    int input3;
    scanf("%d", &input3);
    for (int i = num; i < input3; i++)
    {

        printf("Serial No: %d\n", i);

        printf("Enter Name:");
        scanf("%s", user01[i].name);
        fflush(stdin);

        while (1)
        {
            printf("Enter Gender:");
            scanf("%s", user01[i].gender);

            if (strcmp(user01[i].gender, "male") == 0 || strcmp(user01[i].gender, "Male") == 0 || strcmp(user01[i].gender, "female") == 0 || strcmp(user01[i].gender, "Female") == 0)
            {
                break;
            }
            else
            {
                printf("Invalid Input.Please Try again.\n");
            }
        }

        fflush(stdin);

        while (1)
        {
            printf("Enter age:");
            scanf("%d", &user01[i].age);
            if (user01[i].age >= 18)
            {
                break;
            }
            else
            {
                printf("Sorry,only those who are above 18 are eligible for vaccination\n");
            }
        }

        fflush(stdin);

        printf("Enter Address:");
        scanf("%s", user01[i].address);

        fflush(stdin);

        while (1)
        {

            printf("Enter Date of Birth:");
            scanf("%d/%d/%d", &user01[i].date, &user01[i].month, &user01[i].year);
            if (user01[i].date <= 31 && user01[i].month <= 12 && user01[i].year <= 2004)
            {
                break;
            }
            else
            {
                printf("Invalid Input,Please Try Again.\n");
            }
        }

        fflush(stdin);

        while (1)
        {
            printf("Enter NID:");
            scanf("%s", user01[i].NID);
            if ((strlen(user01[i].NID)) == 10 || (strlen(user01[i].NID)) == 14)
            {
                break;
            }
            else
            {
                printf("Invalid NID Format,NID must be 10 or 14 digits\n");
            }
        }

        fflush(stdin);
        num++;
    }

    for (int i = 0; i < input3; i++)
    {
        fprintf(fp_u, "Serial No: %d\n", i);
        fprintf(fp_u, "Name:%s\n", user01[i].name);
        fprintf(fp_u, "Gender:%s\n", user01[i].gender);
        fprintf(fp_u, "Age:%d\n", user01[i].age);
        fprintf(fp_u, "Address:%s\n", user01[i].address);
        fprintf(fp_u, "Date of Birth:%d/%d/%d\n", user01[i].date, user01[i].month, user01[i].year);
        fprintf(fp_u, "NID:%s\n", user01[i].NID);
        fprintf(fp_u, "Vaccinated:No\n");
        fprintf(fp_u, "End of Information about Registered Person:%d\n", i);
        fprintf(fp_u, "\n");
    }

    fclose(fp_u);
    printf("Successfully Registered For Vaccination\n");
    LoadingBar("Redirecting to User Panel.......", 45);
    UserPanel();
}

void readuserinfoall()
{
    FILE *fp_user;
    char ch;
    fp_user = fopen("userinfo.txt", "r");
    if (fp_user == NULL)
    {
        printf("Error Getting File");
    }
    printf("All Registered Person List:\n");
    do
    {
        ch = fgetc(fp_user);
        printf("%c", ch);
    } while (ch != EOF);
    fclose(fp_user);
}

void createVaccinationCertificate()
{
    int input2;
    char vaccinated[100];

    printf("Please Enter The Serial Number of the Patient:");

    scanf("%d", &input2);

    if (input2 < num)
    {

        sprintf(vaccinated, "vaccinated%d.txt", input2);
        FILE *fp = fopen(vaccinated, "w+");
        fprintf(fp, "Serial No: %d\n", input2);
        fprintf(fp, "Name:%s\n", user01[input2].name);
        fprintf(fp, "Gender:%s\n", user01[input2].gender);
        fprintf(fp, "Age:%d\n", user01[input2].age);
        fprintf(fp, "Address:%s\n", user01[input2].address);
        fprintf(fp, "Date of Birth:%d/%d/%d\n", user01[input2].date, user01[input2].month, user01[input2].year);
        fprintf(fp, "NID:%s\n", user01[input2].NID);
        fprintf(fp, "Vaccinated:Yes\n");
        fprintf(fp, "\n");

        fclose(fp);

        printf("Certificate Successfully Generated");
    }
}

void getvaccinationcertificate()
{
    int input4;
    char vaccinated_read[100];

    FILE *fp_vac;

    printf("Please Enter The Serial Number of the Patient:");

    scanf("%d", &input4);

    if (input4 < num)
    {
        char ch;
        sprintf(vaccinated_read, "vaccinated%d.txt", input4);
        fp_vac = fopen(vaccinated_read, "r");
        if (fp_vac == NULL)
        {
            Sleep(5000);
            printf("Sorry,Your Vaccination Certificate is Not Ready Yet.");
        }
        do
        {

            ch=fgetc(fp_vac);
            printf("%c",ch);

        }
        while(ch!=EOF);
        fclose(fp_vac);
        Sleep(5000);
    }

}

int adminIDVerification(char username[], char password[])
{
    char savedUserNameAdmin[101];
    char savedPasswordAdmin[101];

    FILE *admin = fopen("adminID.txt", "r");
    FILE *admin_2 = fopen("adminID.txt", "r");
    if (admin == NULL)
    {
        printf("Error Reading File=adminID");
        return 0;
    }

    while (!feof(admin))
    {
        while ((fscanf(admin, "%[^\n] ", savedUserNameAdmin)) != EOF)

            while ((fscanf(admin_2, "%[^\n] ", savedPasswordAdmin)) != EOF)

                if (strncmp(savedUserNameAdmin, username, strlen(username)) == 0 && strncmp(savedPasswordAdmin, password, strlen(password)) == 0)
                {
                    printf("Access Granted");
                    printf("\n");
                    return 1;
                }
                else
                {
                    printf("Access Denied");
                    printf("\n");
                    return -1;
                }
    }
    fclose(admin);
    fclose(admin_2);
    return 0;
}

int userIDVerification(char username[], char password[])
{
    char savedUserNameUser[101];
    char savedPasswordUser[101];

    FILE *user = fopen("userID.txt", "r");
    FILE *user_2 = fopen("userID.txt", "r");
    if (user == 0)
    {
        printf("Error Reading File=user");
        return 0;
    }

    while (!feof(user))
    {
        while ((fscanf(user, "%[^\n] ", savedUserNameUser)) != EOF)

            while ((fscanf(user_2, "%[^\n] ", savedPasswordUser)) != EOF)

                if (strncmp(savedUserNameUser, username, strlen(username)) == 0 && strncmp(savedPasswordUser, password, strlen(password)) == 0)
                {
                    printf("Access Granted");
                    printf("\n");
                    return 1;
                }
                else
                {
                    printf("Access Denied");
                    printf("\n");
                    return -1;
                }
    }
    fclose(user);
    fclose(user_2);
    return 0;
}

void LoadingBar(char *s, int n)
{
    system("color 0b");
    char x = 219;
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t");
    printf("%s\n", s);

    printf("\t\t\t\t\t");

    for (int i = 0; i <= n; i++)
    {
        printf("%c", x);
        Sleep(70);
    }
}

void AdminPanel()
{
ADMIN:
    printf("\t\t\tWelcome,Admin\n");
    int inputadmin;

    printf("\n");
    printf("1.Display All Registered User Info\n");
    printf("2.Mark a User as Vaccinated\n");
    printf("0.Log out\n");
    printf("Enter Input:");
    scanf("%d", &inputadmin);
    switch (inputadmin)
    {
    case 0:
        system("cls");
        LoadingBar("Logging Out From Admin Panel.......", 43);
        system("cls");
        main();

    case 1:
        readuserinfoall();
        goto ADMIN;

    case 2:
        createVaccinationCertificate();
        goto ADMIN;
    }
}

void UserPanel()
{
USER:
    system("cls");
    printf("\t\t\tWelcome,User");
    printf("\n");
    printf("1.Register For Vaccination\n");
    printf("2.Get Certificate of Vaccination\n");
    printf("0.Log Out\n");
    printf("\n");
    printf("Enter Input:");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        createuserinfo();
        goto USER;

    case 2:
        getvaccinationcertificate();
        goto USER;

    case 0:
        system("cls");
        LoadingBar("Logging Out From User Panel.......", 43);
        system("cls");
        main();
    }
}

void mainmenu()
{
    system("cls");
    system("color 0b");
    printf("\t\t\t****************************************\n");
    printf("\t\t\t Covid-19 Vaccination Management System\n ");
    printf("\t\t\t****************************************\n");

    printf("\n");

    printf("\t\t\t\tCurrent date: %s\n", __DATE__);

    printf("\n");
    printf("\n");
    printf("-----------------------\n");
    printf("| 1.Admin Registration|\n");
    printf("| 2.Admin Login       |\n");
    printf("| 3.User Registration |\n");
    printf("| 4.User Login        | \n");
    printf("| 0.Shut Down System  |\n");
    printf("-----------------------\n");
    printf("\n");
}

void Shutdown()
{
    system("cls");
    LoadingBar("Shutting Down System.......", 35);
    system("cls");
    exit(0);
}

void adminlogin()
{
    system("cls");
    printf("\t\t\tAdmin Login\n");
    for (int i = 3; i > 0; i--)
    {

        char username[100];
        printf("Username:");
        scanf("%s", username);

        char password[100];
        printf("Password:");
        fflush(stdin);

        scanf("%s",password);
        if (adminIDVerification(username, password) == 1)
        {
            system("cls");
            LoadingBar("Loading Admin Panel.......", 35);
            system("cls");
            AdminPanel();
            break;
        }
        else
        {
            printf("%d attempt(s) remaining", i - 1);
            printf("\n");
        }
        if (i == 1)
        {
            system("cls");
            LoadingBar("Due to security purposes the system will now shut down.......", 70);
            system("cls");
            exit(0);
        }
    }
}



void adminreg()
{
    system("cls");
    printf("\t\t\t\tAdmin Registration");
    printf("\n");
    FILE *fp;
    struct admin admin01;
    fp = fopen("adminID.txt", "w+");
    if (fp == NULL)
    {
        puts("Error Getting File");
    }
    printf("Enter Username:");
    scanf("%s", admin01.username);
    fflush(stdin);

    fprintf(fp, "%s\n", admin01.username);

    printf("Enter Password:");
    scanf("%s", admin01.password);
    fflush(stdin);

    fprintf(fp, "%s\n", admin01.password);

    fclose(fp);

    printf("Successfully registered as an admin\n");
    system("cls");

    LoadingBar("Please wait while you are being redirected to the main menu.......", 75);
}

void userreg()
{
    system("cls");
    printf("User Registration");
    printf("\n");
    FILE *fp_u;
    struct user user01;
    fp_u = fopen("userID.txt", "w");
    if (fp_u == NULL)
    {
        puts("Error Getting File:userID.txt");
    }
    printf("Enter Username:");
    scanf("%s", user01.username);
    fflush(stdin);

    fprintf(fp_u, "%s\n", user01.username);

    printf("Enter Password:");
    scanf("%s", user01.password);

    fflush(stdin);

    fprintf(fp_u, "%s\n", user01.password);

    fclose(fp_u);

    printf("Successfully registered as an user\n");
    system("cls");

    LoadingBar("Please wait while you are redirected to the main menu.......", 75);
}

void userlogin()
{
    system("cls");
    printf("\t\t\t\tUser Login");
    printf("\n");
    for (int i = 3; i > 0; i--)
    {

        char username[100];
        printf("Username:");
        scanf("%s", username);

        char password[100];
        printf("Password:");
        fflush(stdin);


        scanf("%s",password);

        if (userIDVerification(username, password) == 1)
        {
            system("cls");
            LoadingBar("Loading User Panel.......", 35);
            system("cls");
            UserPanel();
            break;
        }
        else
        {
            printf("%d attempt(s) remaining", i - 1);
            printf("\n");
        }
        if (i == 1)
        {
            system("cls");
            LoadingBar("Due to security purposes the system will now shut down.......", 70);
            system("cls");
            exit(0);
        }
    }
}

int main()
{
MAIN:
    LoadingBar("Please Wait While The System Loads.......", 50);
    mainmenu();
    int input;
    printf("Enter Input:");
    scanf("%d", &input);

    switch (input)
    {
    case 0:
        Shutdown();

    case 1:

        adminreg();
        system("cls");
        goto MAIN;

    case 2:

        adminlogin();
        break;

    case 3:
        userreg();
        system("cls");
        goto MAIN;

    case 4:
        userlogin();
        break;
    }

    return 0;
}
