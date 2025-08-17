/*Program For Bus reservation system using C*/
/*program by
 *Code By FYCM-II A1 20-21*
 01.Sakshi Abhang.
 02.Shweta Ahire.
 03.Sneha Bagul.
 04.Shrutika Barudwale.
 05.Kiran Bendkule.
 06.Rupesh Bhadane.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10][130] = {"Shiv Shahi(6:30am to 6:30pm)", "mauli(7:00am to 8:00pm)", "J.V.Travels(10:00am to 10:00pm)", "Giriraj Travels(11:30am to 12:00am)-AC", "Devesh Travels(6:00pm to 6:00am)-AC",};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int M;/*for Bus*/
void bus(); /*for list of bus*/
void name_number(int booking, char numstr[100]);/*for accepting and storing the info given by passenger*/
void booking();            /*for booking the tickets*/
int read_number(int M); /*for reading the number from the file*/
void read_name(int M);  /*for reading the name from the file*/
void status();             /*for printing the status by user input*/
void status_1(int M);   /*for printing the status while booking ticket*/
void cancle();/*Cancle The Ticket*/

int main()
{
    login();
    int num, i;
    do
    {
        system("cls");
        printf("\n\n\n");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");/*Home menu*/
        printf("\t\t\t\t\t[1]=> View Bus List That are travling from Nashik to Pune\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Book Tickets for Buses traveling from Nashik to Pune\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> Cancle Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> Bus Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("\t\t\tEnter Your Choice:: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            bus(); /*for list of bus*/
            break;
        case 2:
            booking(); /*for booking the tickets*/
            break;
        case 3:
            cancle();
            break;
        case 4:
            status();
            break;
        }
        getch();
    } while (num != 5);
    system("CLS");/*stlib.h*//*For Clear the Screen Before going To Next Step*/
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t *Code By FYCM-II A1 20-21*\n 01.Sakshi Abhang. \n 02.Shweta Ahire. \n 03.Sneha Bagul. \n 04.Shrutika Barudwale. \n 05.Kiran Bendkule. \n 06.Rupesh Bhadane.");
    getch();
    return 0;
}

void bus()
{
    system("cls");/*stlib.h*/
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");/*This is for list of buses*/
    printf("\t\t\t\t\t[1]  =>  %s\n", ch[0]);
    printf("\n");
    printf("\t\t\t\t\t[2]  =>  %s\n", ch[1]);
    printf("\n");
    printf("\t\t\t\t\t[3]  =>  %s\n", ch[2]);
    printf("\n");
    printf("\t\t\t\t\t[4]  =>  %s\n", ch[3]);
    printf("\n");
    printf("\t\t\t\t\t[5]  =>  %s\n", ch[4]);
}

void booking()
{

    int i = 0;
    char numstr[100];
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n"); /*for entering Bus number*/
    bus();                                                                                                                           /*for seeing Bus least*/
    printf("Enter the Bus number:--->");
    scanf("%d", &M);
    system("cls");/*stlib.h*/
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n"); /*for selecting line/bus*/
    printf("Your Bus Number is %d ********** %s", M, ch[M - 1]);
    status_1(M);
    FILE *f1, *fopen(); /*for reading no of the seats from the user.*//*File Function is Used Beacuse we have created A File That we have to open annd close and that file holds the Program as in a stored manner and not get reset while run program Again*/
    char str1[80] = "32", str2[4], str3[4];
    int seat1, seat2, booking = 0;  /*fopen for Open the  file where the Program is stored , And fclose for Close Our Opened File*/
    if (M == 1)
    {
        f1 = fopen("tr1.txt", "r+");
        fgets(str1, 80, f1);/*gets is used for get/Accept the Contain into File*/
        fclose(f1);
    }
    else if (M == 2)
    {
        f1 = fopen("tr2.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (M == 3)
    {
        f1 = fopen("tr3.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (M == 4)
    {
        f1 = fopen("tr4.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (M == 5)
    {
        f1 = fopen("tr5.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    seat1 = atoi(str1);/*stlib.h*/ /*covert the string into number*/
    if (seat1 <= 0)
    {
        printf("There is no blank seat in this bus ");
    }
    else
    {
    	int fair= (M<=3)?250:350;/*if Else for AC non-AC bus Prise*/
    	
        printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n", seat1);
        printf("\n The Value of 1 ticket is rs%d per person.",fair);
        printf("\n\t\t\t\tNumber of Tickets:----->");
        scanf("%d", &booking);
        printf("\n");

        seat1 = seat1 - booking;
        itoa(M, numstr, 10);/*stlib.h*/
        name_number(booking, numstr);
        
        
        printf("\n\t\t\t\tThe Total booking amount is %d", fair* booking);
        itoa(seat1, str1, 10);/*stlib.h*/
        /*for reading the seats from the user.*/
        if (M == 1)
        {
            f1 = fopen("tr1.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (M == 2)
        {
            f1 = fopen("tr2.txt", "w");
            fputs(str1, f1);/*Puts is used for Put or Show the Contain in File*/
            fclose(f1);
        }
        else if (M == 3)
        {
            f1 = fopen("tr3.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (M == 4)
        {
            f1 = fopen("tr4.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (M == 5)
        {
            f1 = fopen("tr5.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
    }
}

void name_number(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
    int number;
    FILE *a, *b;
    int i = 0;
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    a = fopen(tempstr1, "a");     /*for open the file to write the name in the file*/
    b = fopen(tempstr2, "a");     /*for open the file for writing the number of seats in the file*/
    for (i = 0; i < booking; i++) /*for entering the person name and seat number in the file*/
    {
        printf("============================Enter the details for ticket no %d============================\n\n\n", i + 1);/*for ticket details*/
        printf("\t\t\t\tEnter the seat number:--->");
        scanf("%d", &number);
        printf("\t\t\t\tEnter the name of person:--->");
        scanf("%s", name[number - 1]);
        printf("\n======================================================================================================\n\n");
        printf("\n");
        itoa(number, tempstr, 10);
        fprintf(a, "%s ", name[number - 1]);
        fprintf(b, "%s ", tempstr);
    }
    fclose(a);
    fclose(b);
}

int read_number(int M) /*for putting the numeric value in the array*/
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(M, numstr, 10);/*for Convert Integer into String*/
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "a+"); /*for open the file to write the name in the file*/
    while (!feof(a))
    {
        number[i][j] = fgetc(a);

        if (number[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++)
    {
        num1[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}

void read_name(int M) /*for putting the numeric value in the array*/
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(M, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "a+"); /*for open the file to write the name in the file*/
    while (!feof(b))
    {
        name[i][j] = fgetc(b);

        if (name[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}

void status()
{
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, M, index = 0, j;
    printf("Enter the number of bus:---->");
    scanf("%d", &M);
    j = read_number(M);
    read_name(M);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                      Bus.no-->%d---->%s                                                            \n", M, ch[M - 1]);/*for booking enter the bus number you want*/
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void status_1(int M)
{
    printf("Your Bus Number is %d ********** %s", M, ch[M - 1]);
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i, index = 0, j;
    j = read_number(M);
    read_name(M);
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[num1[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("\t\t\t\t");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void cancle()
{
    int seat_no, i, j;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    printf("Enter the bus number:---->");
    scanf("%d", &M);
    
    int fair= (M<=3)?250:350;/*if Else for AC non-AC bus Prise*/
    
    
    itoa(M, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    read_number(M);
    read_name(M);
    status_1(M);
    printf("Enter the seat number:--->");
    scanf("%d", &seat_no);
    FILE *a, *b;
    a = fopen(tempstr1, "w+");
    b = fopen(tempstr2, "w+");
    for (i = 0; i < 32; i++)
    {
        if (num1[i] == seat_no)
        {
            for (j = 0; j < 32; j++)
            {
                if (num1[j] != seat_no && num1[j] != 0)
                {
                    fprintf(b, "%d ", num1[j]);
                    fprintf(a, "%s", name[j]);
                }
                else if (num1[j] == seat_no && num1[j] != 0)
                {
                    strcpy(name[j], "Empty ");
                }
            }
        }
    }
    fclose(a);
    fclose(b);
    printf("\n\n");
    printf("======================================================================================================\n");
    printf("\t\t\t\tYour %d rupees has been Returned from %d ,50.Rs Cut.t\t\t\n",fair-50,fair);
    printf("======================================================================================================\n");
}

void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {
        system("cls");

        printf("\n  =========================  LOGIN FORM Enter username=user and password=pass   =========================  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        /*char code=pword;*/
        i = 0;
        /*scanf("%s",&pword);*/
        if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
        {
            printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch(); /*holds the screen*/
            break;
        }
        else
        {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;

            getch(); /*holds the screen*/
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
    }
    system("cls");
}