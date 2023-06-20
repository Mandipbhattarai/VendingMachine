// Header Files are included here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Global Variable
int total;
int items_total;
char purchased_items[1000] = ""; // Variable to store purchased items

// Function declarations
void menu();
int harddrink(int total);
void hard_drink_menu();
int softdrink(int total);
void soft_drink_menu();
int snaks(int total);
void snacks_menu();
int child(int total);
void kids_menu();
int promocode(int);
void getCurrentStandardTime();

// Creating structure for name and phone
struct VendingMachine
{
    char first_name[40];
    char last_name[40];
    int phone[10];
};

void name(struct VendingMachine *details)
{
    printf("Enter your first name: ");
    scanf("%s", details->first_name);
    printf("Enter your last name: ");
    scanf("%s", details->last_name);
}

void phone(struct VendingMachine *details)
{
    printf("Enter your phone number: ");
    scanf("%s", details->phone);
}

// main
int main()
{
    // initializing the variables
    int n, code, cash;
    system("cls");
    printf("Hello! Welcome to Our Vending Machine.\n");
    struct VendingMachine details;
    name(&details);
    phone(&details);

    // running do while for taking input
    do
    {
        menu(); // displaying the menu
        printf("\nEnter your choice! ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            total = harddrink(total); // Function call
            break;

        case 2:
            total = softdrink(total); // Function call
            break;

        case 3:
            total = snaks(total); // Function call
            break;

        case 4:
            total = child(total); // Function call
            break;

        case 5:
            printf("You've entered exit\n");
            break;

        default:
            printf("Please enter a valid choice!\n");
            break;
        }
    } while (n != 5);

    printf("Here, it's your bill: Rs.%d\n", total);
    int code_store = promocode(code);
    printf("\n\n");
    printf("*******************************************************\n");
    getCurrentStandardTime();
    printf("-------------------------------------------------------\n");
    printf("Name: %s %s\n", details.first_name, details.last_name);
    printf("-------------------------------------------------------\n");
    printf("Your purchased items:\n%s", purchased_items);
    printf("-------------------------------------------------------\n");
    printf("Your final bill is: Rs.%d\n", code_store);
    printf("*******************************************************\n\n");

    return 0;
}

// Functions definitions

void menu()
{
    // This is menu section!
    printf("Here, We have got these options:\n");
    printf("1. Hard Drinks\n");
    printf("2. Soft Drinks\n");
    printf("3. Snacks\n");
    printf("4. Kids Section\n");
    printf("5. Exit\n");
}
// Function to get current standard time
void getCurrentStandardTime()
{
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);

    // Format and print the date
    char date[100];
    strftime(date, sizeof(date), "%Y-%m-%d", currentTime);
    printf("Date: %s\n", date);
}

int promocode(int code)
{
    printf("Do you have any Promo Code? \n");
    printf("1. Yes\n2. No\n");
    scanf("%d", &code);
    if (code == 1)
    {
        int promo_code;
        printf("Please enter your promocode: ");
        scanf("%d", &promo_code);
        if (promo_code == 1234 || promo_code == 3322)
        {
            printf("\n\n");
            printf("*******************************************************\n");
            printf("Congratulations! You have got 10%% discount\n");
            total = total - (total * 0.10);
        }
        else
        {
            printf("Invalid promo code\n");
        }
    }
    else if (code == 2)
    {
        printf("No promo code applied\n");
    }
    else
    {
        printf("Invalid choice\n");
    }

    return total;
}

int harddrink(int total)
{
    // This is the harddrink function
    printf("\nYou have chosen Hard Drinks\n");
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age >= 18 && age <= 100)
    {
        hard_drink_menu();
        int hard_drinks;
        printf("Enter the number of Hard Drinks you want to purchase: ");
        scanf("%d", &hard_drinks);

        int choice;
        for (int i = 0; i < hard_drinks; i++)
        {
            printf("Enter your choice of Hard Drink: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                total += 150;
                strcat(purchased_items, "Whiskey - Rs.150\n");
                break;
            case 2:
                total += 350;
                strcat(purchased_items, "Vodka - Rs.350\n");
                break;
            case 3:
                total += 355;
                strcat(purchased_items, "Beer - Rs.355\n");
                break;
            case 4:
                total += 250;
                strcat(purchased_items, "Rum - Rs.250\n");
                break;
            case 5:
                total += 300;
                strcat(purchased_items, "Tequila - Rs.300\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
            }
        }
        printf("Your total for Hard Drinks is Rs.%d\n", total);
    }
    else
    {
        printf("Sorry! You're not eligible for purchase of this item!\n");
    }
    return total;
}

void hard_drink_menu()
{
    printf("\nHard Drinks:\n");
    printf("1. Whiskey - Rs.150\n");
    printf("2. Vodka - Rs.350\n");
    printf("3. Beer - Rs.355\n");
    printf("4. Rum - Rs.250\n");
    printf("5. Tequila - Rs.300\n");
}

int softdrink(int total)
{
    // This is the softdrink function
    printf("\nYou have chosen Soft Drinks\n");
    soft_drink_menu();
    int soft_drinks;
    printf("Enter the number of Soft Drinks you want to purchase: ");
    scanf("%d", &soft_drinks);

    int choice;
    for (int i = 0; i < soft_drinks; i++)
    {
        printf("Enter your choice of Soft Drink: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            total += 40;
            strcat(purchased_items, "Coke - Rs.40\n");
            break;
        case 2:
            total += 35;
            strcat(purchased_items, "Pepsi - Rs.35\n");
            break;
        case 3:
            total += 45;
            strcat(purchased_items, "Sprite - Rs.45\n");
            break;
        case 4:
            total += 50;
            strcat(purchased_items, "Fanta - Rs.50\n");
            break;
        case 5:
            total += 60;
            strcat(purchased_items, "Mirinda - Rs.60\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    printf("Your total for Soft Drinks is Rs.%d\n", total);
    return total;
}

void soft_drink_menu()
{
    printf("\nSoft Drinks:\n");
    printf("1. Coke - Rs.40\n");
    printf("2. Pepsi - Rs.35\n");
    printf("3. Sprite - Rs.45\n");
    printf("4. Fanta - Rs.50\n");
    printf("5. Mirinda - Rs.60\n");
}

int snaks(int total)
{
    // This is the snaks function
    printf("\nYou have chosen Snacks\n");
    snacks_menu();
    int snacks;
    printf("Enter the number of Snacks you want to purchase: ");
    scanf("%d", &snacks);

    int choice;
    for (int i = 0; i < snacks; i++)
    {
        printf("Enter your choice of Snack: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            total += 50;
            strcat(purchased_items, "Chips - Rs.50\n");
            break;
        case 2:
            total += 30;
            strcat(purchased_items, "Pretzels - Rs.30\n");
            break;
        case 3:
            total += 25;
            strcat(purchased_items, "Popcorn - Rs.25\n");
            break;
        case 4:
            total += 45;
            strcat(purchased_items, "Nuts - Rs.45\n");
            break;
        case 5:
            total += 40;
            strcat(purchased_items, "Biscuits - Rs.40\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    printf("Your total for Snacks is Rs.%d\n", total);
    return total;
}

void snacks_menu()
{
    printf("\nSnacks:\n");
    printf("1. Chips - Rs.50\n");
    printf("2. Pretzels - Rs.30\n");
    printf("3. Popcorn - Rs.25\n");
    printf("4. Nuts - Rs.45\n");
    printf("5. Biscuits - Rs.40\n");
}

int child(int total)
{
    // This is the child function
    printf("\nYou have chosen Kids Section\n");
    kids_menu();
    int kids;
    printf("Enter the number of items you want to purchase from Kids Section: ");
    scanf("%d", &kids);

    int choice;
    for (int i = 0; i < kids; i++)
    {
        printf("Enter your choice from Kids Section: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            total += 100;
            strcat(purchased_items, "Toy - Rs.100\n");
            break;
        case 2:
            total += 200;
            strcat(purchased_items, "Candy - Rs.200\n");
            break;
        case 3:
            total += 150;
            strcat(purchased_items, "Balloon - Rs.150\n");
            break;
        case 4:
            total += 80;
            strcat(purchased_items, "Sticker - Rs.80\n");
            break;
        case 5:
            total += 120;
            strcat(purchased_items, "Coloring Book - Rs.120\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    printf("Your total for Kids Section is Rs.%d\n", total);
    return total;
}

void kids_menu()
{
    printf("\nKids Section:\n");
    printf("1. Toy - Rs.100\n");
    printf("2. Candy - Rs.200\n");
    printf("3. Balloon - Rs.150\n");
    printf("4. Sticker - Rs.80\n");
    printf("5. Coloring Book - Rs.120\n");
}