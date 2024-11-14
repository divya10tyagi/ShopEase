#include <ctype.h> 
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


FILE *abt;
struct details { // Structure declared for storing details
char uname[50];
int age;
char password[100];
char email[100];
char mobile[10];
};


// Structure to store details about shops
struct Shops {
char shop[100];
char item1[100];
char item2[100];
char item3[100];
char item4[100];
char item5[100];
char item6[100];
char item7[100];
char item8[100];
char item9[100];
char item10[100];
char item11[100];
int first, second, third, fourth, fifth, sixth, seventh, eighth, ninth, tenth, eleventh;
};


// Array of Structure declared
struct Shops m[5];
struct details s[100];

void signup();
void account_validate();
int validate();
void login();
void cart();
void shop();
void items();
void item_order(int item);
void shop_initialize();
void Shop(int shop_choice);
void aboutUs();

// Global variables declared
char t_name[100], t_password1[100];
char t_password2[100], t_email[100];
char t_mobile[100];
int flag = 1, i, j = 0, count = 0, caps = 0;
int Small = 0,total = 0 ,success = 0,special = 0, numbers = 0;
int x, choice,t_age, item_choice, n,shop_choice, search_choice, confirm,ch, item, shop_id;


void aboutUs()
{
    abt=fopen("Name.txt","w");
    fprintf(abt,"\t\t** PROJECT MADE BY  **\n");
    fprintf(abt,"\t\tDivyanshi Tyagi\t23103223\n");
    fclose(abt);
}


// Driver code
int main()
{
    char nm[50];
    aboutUs();
    abt=fopen("Name.txt","r");
    while(fgets(nm,50,abt)!=NULL)
    {
        printf("%s\n",nm);
    }
    fclose(abt);
                    // Loop while till which runs till break is called
    while (1) 
    {
        printf("\n\n\t Welcome to Shop Cart \n");         
        printf("\n\n1)SIGNUP");
        printf("\n2)LOGIN");
        printf("\n3)EXIT");
        printf("\n\n\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: 
            {
                signup(); 
                break;
            } 
            case 2: 
            {
                login(); 
                break;
            }
            case 3: 
            {
                printf("\n\t Thank you,Visit Again \n\n");
                return 0;
            }
            default: 
            {
                printf("\n\nPlease enter valid choice!!\n");
                break;
            }
        }
    }
}


// Signup function declared
void signup()
{
    printf("\n\n\t Welcome to Signup Page \n\n");
    printf("\tEnter Your name : "); 
    scanf("%s", t_name);
    printf("\tEnter Your Email : "); 
    scanf("%s", t_email);
    printf("\tEnter Password : "); 
    scanf("%s", t_password1);
    printf("\tConfirm Password : "); 
    scanf("%s", t_password2);
    printf("\tEnter Your Mobile Number : "); 
    scanf("%s", t_mobile);
    printf("\tEnter Your Age : "); 
    scanf("%d", &t_age);
    x = validate();
    if (x == 1)
    {
        account_validate();
        login();
    }
}


int validate()
{
    // Name Validation
    for (i = 0; t_name[i] != '\0'; i++) 
    {
        if (!( (t_name[i] >= 'a' && t_name[i] <= 'z')  || (t_name[i] >= 'A' && t_name[i] <= 'Z') )) 
        {
            printf("\nPlease enter the valid Name!\n");
            flag = 0;
            break;
        }
    }
    if (flag == 1) 
    {
        count = 0;
    // Email ID Validation
        for (i = 0; t_email[i] != '\0'; i++) 
        {
            if (t_email[i] == '@' || t_email[i] == '.')
                count++;
        }
        if (count >= 2 && strlen(t_email) >= 5) 
        {
            // Password Validation
            if (!strcmp(t_password1, t_password2)) 
            {
                if (strlen(t_password1) >= 8 && strlen(t_password1) <= 12) 
                {
                    caps = 0;
                Small = 0;
                numbers = 0;
                special = 0;
                for (i = 0; t_password1[i] != '\0';i++) 
                {
                    if (t_password1[i] >= 'A' && t_password1[i] <= 'Z')
                        caps++;
                    else if (t_password1[i] >= 'a' && t_password1[i] <= 'z')
                        Small++;
                    else if (t_password1[i] >= '0' && t_password1[i] <= '9')
                        numbers++;
                    else if (t_password1[i] == '@'||t_password1[i] == '&'|| t_password1[i] == '#'||
                            t_password1[i] == '*')
                        special++;
                }
                if (caps >= 1 && Small >= 1 && numbers >= 1 && special >= 1) 
                {                                               // Age Validation
                    if (t_age > 0) 
                    {                                               // Mobile Validation
                        if (strlen(t_mobile) == 10) 
                        {
                            for (i = 0; i < 10; i++) 
                            {
                                if (t_mobile[i] >= '0'&& t_mobile[i]<= '9') 
                                    success = 1;
                                else 
                                {
                                   printf("\n\nPlease Enter Valid Mobile Number\n\n");
                                    return 0;
                                    break;
                                }
                            }
                            if (success == 1) // Success flag to know every inputs are valid
                                return 1;
                        }
                        else   
                        {
                            printf("\n\nPlease Enter the 10 digit mobile number\n\n");
                            return 0;
                        }
                    }

                    else 
                    {
                        printf("\n\nPlease Enter the valid age\n\n");
                        return 0;
                    }
                }
                else    
                {
                    printf("\n\nPlease Enter the strong password, Your password must contain atleast one uppercase,Lowercase, Number and special character\n\n ");
                    return 0;
                }
            }
            else 
            {
                printf("\nYour Password is very short\nLength must between 8 to 12\n\n");
                return 0;
            }
            }

            else    
            {
                printf("\nPassword Mismatch\n\n");
                return 0;
            }
        }
        else 
        {
            printf("\nPlease Enter Valid E-Mail\n\n");
            return 0;
        }
    }
}


// Account Validation
void account_validate()
{
    for (i = 0; i < 100; i++) 
    {
// Check account already exist
        if (!(strcmp(t_email, s[i].email) && strcmp(t_password1, s[i].password))) 
        {
            printf("\n\nAccount Already Existed. Please Login !\n\n");
            login();
            break;
        }
    }
// If no account present it creates
    if (i == 100) 
    {
        strcpy(s[j].uname, t_name);
        s[j].age = t_age;
        strcpy(s[j].password, t_password1);
        strcpy(s[j].email, t_email);
        strcpy(s[j].mobile, t_mobile);
        j++;
        printf("\n\n\nAccount Successfully Created!\n\n");
    }
}


// Login function

void login()
{ 
    total=0;
    printf("\n\n\t Welcome to Login Page \n\n");
    printf("\n\nLOGIN\n\n");
    printf("\t Enter Your Email: "); // Askinf for email
    scanf("%s", t_email);
    printf("\t Enter Your Password: "); // Asking for your Password
    scanf("%s", t_password1);
    for (i = 0; i < 100; i++) 
    { 
        if (!strcmp(s[i].email, t_email))               // Check whether the input email is already exists or not
        {                 
            if (!strcmp(s[i].password, t_password1))        // Check whether the password is matched with the email or not
            {
                printf("\n\nWelcome %s, ", s[i].uname);
                printf("Your are successfully logged in\n\n ");
                printf("We Provide two ways of search : \n ");
                printf("1) Search By Shop\n ");
                printf("2) Search by item\n ");
                printf("3) Exit\n\n");
                printf("Please Enter your choice : ");
                scanf("%d", &search_choice);
                    
                    // Getting the input whether the user is going to order by Shop or by item.

                switch (search_choice) 
                {
                    case 1: 
                    {
                        shop();
                        break;
                    }
                    case 2: 
                    {
                        items();
                        break;
                    }
                    case 3: 
                    {
                        main();      // main function called again
                        break;
                    }
                    default: 
                    {
                        printf("Please Enter the valid choice!!!\n\n");      // Choice entered is wrong
                        break;
                    }
                }
                break;
            }

            else 
            {
                printf("\n\nInvalid Password!!\n ");                        // Password entered is wrong
                printf("Please Enter the correct password\n\n");
                login();
                break;
            }
        }
        else 
        {
            printf("\n\nAccount doesn't exist, Please signup!!\n\n ");          // If details are incorrect
            main();
            break;
        }
    }
}


// Calling shop_initialize function
void shop_initialize()
{
    strcpy(m[1].shop, "Stationary");        // All the Products avaiable are being stored in variables
    strcpy(m[1].item1, "Pen");
    strcpy(m[1].item2, "Pencil");
    strcpy(m[1].item3, "Notebook");
    strcpy(m[1].item4, "Stapler");
    strcpy(m[1].item5, "Fevicol");
    strcpy(m[1].item6, "Scissor");
    strcpy(m[1].item7, "Highlighter");
    strcpy(m[1].item8, "Sticky Notes");
    strcpy(m[1].item9, "Folder");
    strcpy(m[1].item10, "Whitener");
    strcpy(m[1].item11, "Geometry Box");
    m[1].first = 10;
    m[1].second = 5;
    m[1].third = 45;
    m[1].fourth = 120;
    m[1].fifth = 20;
    m[1].sixth = 50;
    m[1].seventh = 25;
    m[1].eighth = 25;
    m[1].ninth = 30;
    m[1].tenth = 20;
    m[1].eleventh = 100;
    strcpy(m[2].shop, "Grocery");
    strcpy(m[2].item1, "Fruit: Banana (1 Dozen)");
    strcpy(m[2].item2, "Fruit: Grapes (1 kg)");
    strcpy(m[2].item3, "Fruit: Apple (1 kg)");
    strcpy(m[2].item4, "Fruit: Papaya (1 kg)");
    strcpy(m[2].item5, "Fruit: Guava (1 kg)");
    strcpy(m[2].item6, "Milk 1 ltr");
    strcpy(m[2].item7, "Cheese 1 pkt");
    strcpy(m[2].item8, "Choco-Chip Cookies");
    strcpy(m[2].item9, "Tomato 1 kg");
    strcpy(m[2].item10, "Potato 1 kg");
    strcpy(m[2].item11, "Onion 1 kg");  
    m[2].first = 40;
    m[2].second = 30;
    m[2].third = 60;
    m[2].fourth = 50;
    m[2].fifth = 25;
    m[2].sixth = 28;
    m[2].seventh = 70;
    m[2].eighth= 20;
    m[2].ninth= 80;
    m[2].tenth = 40;
    m[2].eleventh = 35;
    strcpy(m[3].shop, "Books");
    strcpy(m[3].item1, "Atomic Habits - James Clear");
    strcpy(m[3].item2,"Ikigai- Francesc Miralles and Hector Garcia ");
    strcpy(m[3].item3,"Rich Dad Poor Dad - Robert Kiyosaki and Sharon Lechter");
    strcpy(m[3].item4, "Wings Of Fire- Dr. A.P.J. Abdul Kalam");
    strcpy(m[3].item5, "Do Epic Shit- Ankur Warikoo");
    strcpy(m[3].item6, "Think Like A Monk- Jay Shetty");
    strcpy(m[3].item7,"The Monk Who SOld His Ferrari- Robin Sharma");
    strcpy(m[3].item8,"The Psychology Of Money- Morgan Housel");
    strcpy(m[3].item9, "The Complete Novels Of Sherlock Holmes- Arthur Conan Doyle");
    strcpy(m[3].item10, "The Power Of Your Subconcious Mind- Dr. Joseph Murphy");
    strcpy(m[3].item11, "Harry Porter(All Volumes)- J.K. Rowling");
    m[3].first = 399;
    m[3].second = 349;
    m[3].third = 149;
    m[3].fourth = 440;
    m[3].fifth = 159;
    m[3].sixth = 345;
    m[3].seventh = 299;
    m[3].eighth = 235;
    m[3].ninth = 1299;
    m[3].tenth = 99;
    m[3].eleventh = 1199;
}


// shop Function is called
void shop()
{ 
    shop_initialize();              // Shop Products are collected

    printf("\n\nPlease Choose the Shop \n\n1) %s\n2) %s\n3) %s",m[1].shop, m[2].shop, m[3].shop);           // Showing all the availableshop
    printf("\n4) Exit\n\n Please select the shop ");
    scanf("%d", &shop_choice); 
    
    if (shop_choice > 4) 
    {
        printf("Please Enter the valid choice\n\n");
        shop();
    }
    else if (shop_choice == 4)
        main();
    else
    {
        Shop(shop_choice);
    }
}

// Function to implement the shop
void Shop(int shop_choice)
{
    while (1) 
    {
        printf("\n\nList of items available ");
        printf("in %s\n\n1) %s --> %d\n",m[shop_choice].shop, m[shop_choice].item1,m[shop_choice].first);
        printf("2) %s --> %d\n3) %s --> %d\n",m[shop_choice].item2, m[shop_choice].second,m[shop_choice].item3, m[shop_choice].third);
        printf("4) %s --> %d\n5) %s --> %d\n",m[shop_choice].item4, m[shop_choice].fourth,m[shop_choice].item5, m[shop_choice].fifth);
        printf("6) %s --> %d\n7) %s --> %d\n",m[shop_choice].item6, m[shop_choice].sixth,m[shop_choice].item7, m[shop_choice].seventh);
        printf("8) %s --> %d\n9) %s --> %d\n",m[shop_choice].item8, m[shop_choice].eighth,m[shop_choice].item9, m[shop_choice].ninth);
        printf("10) %s --> %d\n11) %s --> %d\n",m[shop_choice].item10, m[shop_choice].tenth,m[shop_choice].item11, m[shop_choice].eleventh);
        printf("12) Cart\n13) Exit\n\nPlease Enter Your Choice : ");
        scanf("%d", &item_choice);
        
        // Get the input for no of items to calculate the total amount
        if (item_choice == 1) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item1);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].first);
        }
        else if (item_choice == 2) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item2);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].second);
        }
        else if (item_choice == 3) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item3);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].third);
        }
        else if (item_choice == 4) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item4);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].fourth);
        }
        else if (item_choice == 5) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item5);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].fifth);
        }
        else if (item_choice == 6) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item6);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].sixth);
        }
        else if (item_choice == 7) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item7);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].seventh);
        }
        else if (item_choice == 8) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item8);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].eighth);
        }
        else if (item_choice == 9) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item9);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].ninth);
        }
        else if (item_choice == 10) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item10);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].tenth);
        }
        else if (item_choice == 11) 
        {
            printf("Please Enter the Count of %s\t", m[shop_choice].item11);
            scanf("%d", &n);
            total = total + (n * m[shop_choice].eleventh);
        }
        else if (item_choice == 12) 
        {
            cart();
        }
        else if (item_choice == 13) 
        {
            shop();
        }
        else 
        {
            printf("Please Enter the valid Choice\n\n");
        }
    }
}

void items()
{
    total = 0;
    // Initialize all the Shop and their items

    shop_initialize();
    
    while (1) 
    {
        //Showing all the choices of items for shop 1
        printf("\n\nPlease choose the ");
        printf("item\n\n1) %s --> %d\n2) %s --> %d",m[1].item1, m[1].first, m[1].item2,m[1].second);
        printf("\n3) %s --> %d\n4) %s--> %d",m[1].item3, m[1].third, m[1].item4, m[1].fourth);
        printf("\n5) %s --> %d\n6) %s --> %d",m[1].item5, m[1].fifth, m[1].item6, m[1].sixth);
        printf("\n7) %s --> %d\n8) %s --> %d",m[1].item7, m[1].seventh, m[1].item8, m[1].eighth);
        printf("\n9) %s --> %d\n10) %s --> %d",m[1].item9, m[1].ninth, m[1].item10, m[1].tenth);
        printf("\n11) %s --> %d\n\n",m[1].item11, m[1].eleventh);
        printf("\n12) %s --> %d\n13) %s --> %d",m[2].item1, m[2].first, m[2].item2,m[2].second);
        printf("\n14) %s --> %d\n15) %s--> %d",m[2].item3, m[2].third, m[2].item4, m[2].fourth);
        printf("\n16) %s --> %d\n17) %s --> %d",m[2].item5, m[2].fifth, m[2].item6, m[2].sixth);
        printf("\n18) %s --> %d\n19) %s --> %d",m[2].item7, m[2].seventh, m[2].item8, m[2].eighth);
        printf("\n20) %s --> %d\n21) %s --> %d",m[2].item9, m[2].ninth, m[2].item10, m[2].tenth);
        printf("\n22) %s --> %d\n\n",m[2].item11, m[2].eleventh);
        printf("\n23) %s --> %d\n24) %s --> %d",m[3].item1, m[3].first, m[3].item2,m[3].second);
        printf("\n25) %s --> %d\n26) %s--> %d",m[3].item3, m[3].third, m[3].item4, m[3].fourth);
        printf("\n27) %s --> %d\n28) %s --> %d",m[3].item5, m[3].fifth, m[3].item6, m[3].sixth);
        printf("\n29) %s --> %d\n30) %s --> %d",m[3].item7, m[3].seventh, m[3].item8, m[3].eighth);
        printf("\n31) %s --> %d\n32) %s --> %d",m[3].item9, m[3].ninth, m[3].item10, m[3].tenth);
        printf("\n33) %s --> %d\n\n",m[3].item11, m[3].eleventh);
        printf("34) Cart\n");
        printf("35) Exit");
        printf("\nPlease Enter Your Choice :");
        scanf("%d", &item);
        if (item > 35) 
        {
            printf("Please Enter the valid choice\n\n");
            items();
        }
        else if (item == 34) // Moves to the cart
            cart();

        else if (item == 35)
            exit(1); // return;

        else
            item_order(item);       // Function to get the no of items and to calculate the total amount of the order.
    }
}


// item_order function to process items ordered
void item_order(int item)
{
    if (item >= 1 && item <= 11)
    {
        shop_id = 1;
        if(item ==1 )
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item1);
            scanf("%d", &n);
            total = total + (n * m[shop_id].first);
        }
        else if(item ==2)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item2);
            scanf("%d", &n);
            total = total + (n * m[shop_id].second);
        }
        else if(item ==3)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item3);
            scanf("%d", &n);
            total = total + (n * m[shop_id].third);
        }
        else if(item ==4)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item4);
            scanf("%d", &n);
            total = total + (n * m[shop_id].fourth);
        }
        else if(item ==5)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item5);
            scanf("%d", &n);
            total = total + (n * m[shop_id].fifth);
        }
        else if(item ==6)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item6);
            scanf("%d", &n);
            total = total + (n * m[shop_id].sixth);
        }
        else if(item ==7)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item7);
            scanf("%d", &n);
            total = total + (n * m[shop_id].seventh);
        }
        else if(item ==8)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item8);
            scanf("%d", &n);
            total = total + (n * m[shop_id].eighth);
        }
        else if(item ==9)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item9);
            scanf("%d", &n);
            total = total + (n * m[shop_id].ninth);
        }
        else if(item ==10)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item10);
            scanf("%d", &n);
            total = total + (n * m[shop_id].tenth);
        }
        else if(item ==11)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item11);
            scanf("%d", &n);
            total = total + (n * m[shop_id].eleventh);
        }
    }
    
    else if (item >= 12 && item <= 22)
    {
        shop_id = 2;
        if(item ==12 )
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item1);
            scanf("%d", &n);
            total = total + (n * m[shop_id].first);
        }
        else if(item ==13)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item2);
            scanf("%d", &n);
            total = total + (n * m[shop_id].second);
        }
        else if(item ==14)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item3);
            scanf("%d", &n);
            total = total + (n * m[shop_id].third);
        }
        else if(item ==15)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item4);
            scanf("%d", &n);
            total = total + (n * m[shop_id].fourth);
        }
        else if(item ==16)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item5);
            scanf("%d", &n);
            total = total + (n * m[shop_id].fifth);
        }
        else if(item ==17)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item6);
            scanf("%d", &n);
            total = total + (n * m[shop_id].sixth);
        }

        else if(item ==18)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item7);
            scanf("%d", &n);
            total = total + (n * m[shop_id].seventh);
        }
        else if(item ==19)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item8);
            scanf("%d", &n);
            total = total + (n * m[shop_id].eighth);
        }
        else if(item ==20)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item9);
            scanf("%d", &n);
            total = total + (n * m[shop_id].ninth);
        }
        else if(item ==21)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item10);
            scanf("%d", &n);
            total = total + (n * m[shop_id].tenth);
        }
        else
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item11);
            scanf("%d", &n);
            total = total + (n * m[shop_id].eleventh);
        }
    }
    else if(item>=23 && item<=33)
    {
        shop_id = 3;
        if(item ==23 )
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item1);
            scanf("%d", &n);
            total = total + (n * m[shop_id].first);
        }
        else if(item ==24)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item2);
            scanf("%d", &n);
            total = total + (n * m[shop_id].second);
        }
        else if(item ==25)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item3);
            scanf("%d", &n);
            total = total + (n * m[shop_id].third);
        }
        else if(item ==26)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item4);
            scanf("%d", &n);
            total = total + (n * m[shop_id].fourth);
        }
        else if(item ==27)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item5);
            scanf("%d", &n);
            total = total + (n * m[shop_id].fifth);
        }
        else if(item ==28)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item6);
            scanf("%d", &n);
            total = total + (n * m[shop_id].sixth);
        }
        else if(item ==29)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item7);
            scanf("%d", &n);
            total = total + (n * m[shop_id].seventh);
        }
        else if(item ==30)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item8);
            scanf("%d", &n);
            total = total + (n * m[shop_id].eighth);
        }
        else if(item ==31)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item9);
            scanf("%d", &n);
            total = total + (n * m[shop_id].ninth);
        }
        else if(item ==32)
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item10);
            scanf("%d", &n);
            total = total + (n * m[shop_id].tenth);
        }
        else
        {
            printf("Please Enter the");
            printf(" Count of %s : ", m[shop_id].item11);
            scanf("%d", &n);
            total = total + (n * m[shop_id].eleventh);
        }
    }
    else if(item == 34)
        cart();
    else
        shop();
}


// Function to implement the cart
void cart()
{
    printf("\n\n\n\n\t Cart ");                     // details about the products in cart
    printf("\n\nYour Total Order Amount is : %d\n", total);
    printf("\n\nDo You wish to order (y=1/n=0):");
    scanf("%d", &ch);
    if (ch == 1) 
    {
        printf("\n\nThank You for your Order");
        printf("\nYour item is on the way. Welcome again  \n\n ");
         main();
        return;
    }
    else if (ch == 0) 
    {
        printf("To cancel Your Order = 1 \nTo Exit = 0 ");
        printf("Select option : ");
        scanf("%d", &confirm);
        if (confirm == 1) 
        {
            //Failed
            printf("\n\nOops! Your item is cancelled!! \n Exiting..\n\n");
            printf("Thank You visit again!\n");
            main();
            return;
        }
        else 
        {
            // Product is bought
            printf("\n\n\t\t Thank You \n\n");
            login();
        }
    }
    else 
    {
        // Asking for choice
        printf("\n\nPlease Enter the correct choice\n\n ");
        cart();
    }
}
