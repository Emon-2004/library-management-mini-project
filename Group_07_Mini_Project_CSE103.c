#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>
//structure for the book
struct book
{
    char name[100];
    char author[100];
    float price;
    char issue_date[20];
};

// Function prototypes
void show_welcome();// Function to display a welcome message
bool login();// Function to handle user login, returns true if successful
void add_book(struct book books[], int *ptr);// Function to add a book to the collection
void search_by_name(struct book books[], int *ptr);// Function to search for a book by its name
void search_by_author(struct book books[], int *ptr);// Function to search for a book by its author
void show_all_books(struct book books[], int *ptr);// Function to display all books in the collection
int delete_last_book(struct book books[], int *ptr);// Function to delete the last added book from the collection
void budget_friendly(struct book books[], int *ptr);// Function to display budget-friendly books
void delete_any_book(struct book books[], int *ptr);// Function to delete any book from the collection
void exitMessage();// Function to display an exit message

int main()// Main function
{
    show_welcome();// Display the welcome message
    bool login_status = login();// Attempt user login and store the status
    if(login_status == false) // Check if login was unsuccessful
    {
        return 0;// Exit the program
    }
    else
    {
        printf("\n\t\t\tLog-in Successful");// Display a welcome message with a delay
        char sentence[] = {"\n\n\t\t\tWelcome Dear User"};

        for (int i = 0; i < 24; i++)  // Loop to print the welcome message with a delay
        {
            usleep(50000); // Sleep for 50,000 microseconds (50 milliseconds)
            printf("%c", sentence[i]);
        }
    }

    struct book books[200]; // Array to store books
    int index = 0;// Index to keep track of the number of books

    int x=0;// Variable to store user's menu choice
    while (x != 8)
    {
        // Display menu
        printf("\n");
        printf("\n\t\t\t 1. Add a New Book.");
        printf("\n\t\t\t 2. Search Book By Name.");
        printf("\n\t\t\t 3. Search Book By Author.");
        printf("\n\t\t\t 4. Show All Book Information.");
        printf("\n\t\t\t 5. Delete Last Book.");
        printf("\n\t\t\t 6. Search For budget Friendly Book.");
        printf("\n\t\t\t 7. Delete Any Book.");
        printf("\n\t\t\t 8. Exit.");
        printf("\n\n\t\t\tPlease Enter Your Choice : ");
        scanf("%d", &x); // Read user's choice
        getchar(); // to consume the newline character after scanf

        switch (x)
        {
        case 1:
        {
            system("cls");
            add_book(books, &index); // Call function to add a new book
            break;
        }
        case 2:
        {
            system("cls");
            search_by_name(books, &index); // Call function to search for a book by name
            break;
        }
        case 3:
        {
            system("cls");
            search_by_author(books, &index); // Call function to search for a book by author
            break;
        }
        case 4:
        {
            system("cls");
            show_all_books(books, &index); // Call function to show all book information
            break;
        }
        case 5:
        {
            system("cls");
            delete_last_book(books, &index); // Call function to delete the last book
            break;
        }
        case 6:
        {
            system("cls");
            budget_friendly(books, &index);// Call function to search for budget-friendly books
            break;
        }
        case 7:
        {
            system("cls");
            fflush(stdin);
            delete_any_book(books, &index);// Call function to delete any book
            break;
        }
        case 8:
        {
            system("cls");
            exitMessage();  // Call function to display exit message
            break;
        }
        default :
        {
            printf("Invalid input"); // Display an error message for invalid input
        }
        }
    }
    return 0;// Return 0 to indicate successful execution
}

// Function to show welcome message
void show_welcome()
{
    printf("\t\t\t***************************************************************************");
    printf("\n\t\t\t***************************************************************************");
    printf("\n\t\t\t************                                                   ************");
    printf("\n\t\t\t************               Welcome To EWU Library              ************");
    printf("\n\t\t\t************                                                   ************");
    printf("\n\t\t\t***************************************************************************");
    printf("\n\t\t\t***************************************************************************");
}
bool login()// Function to handle user login, returns true if successful
{
    // Arrays to store user input and predefined user ID and password
    char pass[40];
    char user[40];
    int i; // Counter for login attempts

    // Predefined user ID and password
    char id[40] = "cse";
    char password[40] = "103";

    int attempt = 0;  // Counter for login attempts

    for (i = 0; i < 3; i++)// Loop for a maximum of 3 login attempts
    {
        printf("\n\n\n\t\t\tEnter user Id: ");// Prompt user to enter user ID
        scanf("%s", user);

        printf("\n\t\t\tPassword: "); // Prompt user to enter password
        scanf("%s", pass);

        if (strcmp(user, id) == 0 && strcmp(password, pass) == 0)// Check if entered user ID and password match the predefined values

        {
            return true;// Return true if login is successful
        }
        else
        {
            attempt++;// Increment login attempt counter

            if (attempt == 3) // Check if the maximum number of login attempts is reached
            {
                printf("\n\t\t\tAccess Denied.\n\t\t\tTerminating Program.\n\t\t\t");
                return false; // Return false if access is denied after 3 attempts
            }
            // Display an error message for incorrect user ID or password
            printf("\n\t\t\t\tWrong User ID or Password.\n\n\n");
            printf("\n\t\t\t%d attempts left.", (3 - attempt));
        }
    }
}
// Function to add a new book to the collection
void add_book(struct book books[], int *ptr)
{
    // Display section header for adding a new book
    printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t\t\t\t Add New Book");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");

    // Variables to store book details
    char name[100], author[100];
    float price;
    char issue_date[20];

    // Prompt user to enter book details
    printf("\n\t\t\tEnter Book name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // remove newline

    printf("\n\t\t\tEnter Author name: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;

    printf("\n\t\t\tEnter Book price: ");
    scanf("%f",&price);
    getchar(); // to consume the newline character after scanf

    printf("\n\t\t\tEnter Book issue date(DD/MM/YY): ");
    fgets(issue_date, sizeof(issue_date), stdin);
    issue_date[strcspn(issue_date, "\n")] = 0;
    // Copy the entered details to the book structure in the array
    strcpy(books[*ptr].name, name);
    strcpy(books[*ptr].author, author);
    books[*ptr].price = price;
    strcpy(books[*ptr].issue_date, issue_date);

    *ptr=*ptr+1; //Increment the index pointer
}

// Function to search for a book by its name
void search_by_name(struct book books[], int *ptr)
{
    // Display section header for searching by book name
    printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t\t\t\t Search Book By Name");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");


    bool found = false;// Flag to check if the book is found
    char name[100]; // Variable to store the name of the book to be searched

    // Prompt user to enter the book's name
    printf("\n\n\t\t\tPlease Enter The Book's Name : ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")] = 0;

    for (int i = 0; i < *ptr; i++)  // Loop through the array to find the book by name
    {
        if (strcmp(name, books[i].name) == 0)
        {
            found = true;
            break;// Exit the loop if the book is found
        }
    }

    if(found)// Check if the book is found
    {
        // Display section header for the found book
        printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>\n");
        printf("\n\t\t\t<?><?><?><?><?><?><?><?>      Book Found     <?><?><?><?><?><?><?><?><?><?><?>\n");
        printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>\n");

        for (int i = 0; i < *ptr; i++)//Loop through the array to display information for the found book(s)
        {
            if (strcmp(name, books[i].name) == 0)// Check if the current book's name matches the search query
            {
                // Print information for the found book
                printf("\n\n\t\t\t\tBook Name : %s", books[i].name);
                printf("\n\t\t\t\tBook Author: %s", books[i].author);
                printf("\n\t\t\t\tBook price : %.2f tk", books[i].price);
                printf("\n\t\t\t\tIssue Date : %s", books[i].issue_date);
                printf("\n");
            }
        }
    }
    else// If no book matches the search, display an error message
    {
        printf("\n\n\t\t\t<?><?><?><?><?><?> Sorry ! There's no Books in the Inventory.<?><?><?><?><?><?>\n\n");
    }

}

// Function to search for a book by its author name
void search_by_author(struct book books[], int *ptr)
{
    // Display section header for searching by author name
    printf("\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
    printf("\n\t\t\t\t\t\t Search Book By Author Name");
    printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>\n");

    bool found = false;// Flag to check if the author is found
    char author[100];  // Variable to store the name of the author to be searched

    // Prompt user to enter the author's name
    printf("\n\n\t\t\tPlease Enter The Book's Author Name : ");
    fgets(author,sizeof(author),stdin);
    author[strcspn(author,"\n")] = 0;

    for (int i = 0; i < *ptr; i++)// Loop through the array to find the book(s) by author name
    {
        if (strcmp(author, books[i].author) == 0)//Loop through the array to display information for the found book(s)
        {
            found = true;
            break;// Exit the loop if the author is found
        }
    }

    if(found) // Check if the author is found
    {
        // Display section header for the found author
        printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>\n");
        printf("\n\t\t\t<?><?><?><?><?><?><?><?>      Author Found     <?><?><?><?><?><?><?><?><?><?><?>\n");
        printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>\n");

        for (int i = 0; i < *ptr; i++)// Loop through the array to display information for the found book(s) by the author
        {
            if (strcmp(author, books[i].author) == 0)
            {
                // Print information for the found book
                printf("\n\n\t\t\t\tBook Name : %s", books[i].name);
                printf("\n\t\t\t\tBook Author: %s", books[i].author);
                printf("\n\t\t\t\tBook price : %.2f tk", books[i].price);
                printf("\n\t\t\t\tIssue Date : %s", books[i].issue_date);
                printf("\n");
                printf("\n\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");
            }
        }
    }
    else// If no book matches the search, display an error message
    {
        printf("\n\n\t\t\t<?><?><?><?><?><?> Sorry ! There's no Books in the Inventory.<?><?><?><?><?><?>\n\n");
    }
}

// Function to display information for all books in the inventory
void show_all_books(struct book books[], int *ptr)
{
    if (*ptr <= 0)// Check if there are no books in the inventory
    {
        // Display a message if there are no books
        printf("\n\n\t\t\t<?><?><?><?><?><?> No Books in the Inventory.<?><?><?><?><?><?>\n\n");

    }

    else
    {
        // Display section header for showing all books
        printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
        printf("\n\t\t\t\t\t\t\tShow All Books");
        printf("\n\t\t\t<~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~><~>");
        printf("\n\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");

        printf("\n\n\t\t\tTotal Number of Books: %d\n", *ptr);// Display the total number of books

        for (int i = 0; i < *ptr; i++) // Loop through the array to display information for each book
        {
            // Display information for each book
            printf("\n\t\t\t\tBook Index : %d",i+1);
            printf("\n\t\t\t\tBook Name  : %s", books[i].name);
            printf("\n\t\t\t\tBook Author: %s", books[i].author);
            printf("\n\t\t\t\tBook price : %.2f tk", books[i].price);
            printf("\n\t\t\t\tIssue Date : %s", books[i].issue_date);
            printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");
            printf("\n");
        }
    }
}

// Function to delete the last book in the inventory
int delete_last_book(struct book books[], int *ptr)
{
    if (*ptr > 0)// Check if there are books in the inventory
    {
        // Display section header for deleting the last book
        printf("\n\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");
        printf("\n\t\t\t\t\t\t\tDelete Last Book");
        printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");

        *ptr = *ptr - 1; // Decrement the book count to remove the last book

        printf("\n\n\t\t\tLast Book Deleted Successfully!\n\n"); // Display a success message
        printf("\n\t\t\tTotal Number of Books Left: %d\n", *ptr);// Display the total number of books left in the inventory

        return *ptr;// Return the updated book count
    }
    else // Display a message if there are no books in the inventory
    {
        printf("\n\n\t\t\t<?><?><?><?><?><?> Sorry, there's no Books in the Inventory.<?><?><?><?><?><?>\n\n");
        return *ptr; // Return the current book count
    }
}

// Function to find budget-friendly books
void budget_friendly(struct book books[], int *ptr)
{
    if(*ptr == 0)
    {
        printf("\n\n\t\t\tNo books available in inventory.\n");
        return;
    }

    float budget;// Variable to store the budget entered by the user

    printf("\n\t\t\tPlease Enter Budget: "); // Prompt user to enter their budget
    fflush(stdin);
    scanf("%f", &budget);

    bool found = false; // Flag to check if any budget-friendly books are found

    for(int i = 0; i < *ptr; i++)// Loop through the array to find budget-friendly books
    {
        // Check if the book's price is within the budget range (�50)
        if(books[i].price >= budget - 50 && books[i].price <= budget + 50)
        {
            
            if(!found)// Check if budget-friendly books are found
            
            {
                printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>\n");
                printf("\n\t\t\t<?><?><?><?><?><?><?><?>      Book Found     <?><?><?><?><?><?><?><?><?><?><?>\n");
                printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>\n");
            }

                found = true;            
                // Display information for each budget-friendly book
                printf("\n\t\t\tBook Title: %s", books[i].name);
                printf("\n\t\t\tBook Author: %s", books[i].author);
                printf("\n\t\t\tBook price: %.2f tk", books[i].price);
                printf("\n\t\t\tIssue Date : %s", books[i].issue_date);
                printf("\n");
                    
        }
    }

    
    if(!found) // Display a message if no budget-friendly books are found
    {
        printf("\n\t\t\t<?><?><?><?><?><?><?><?>Sorry!No Book Found<?><?><?><?><?><?><?><?><?><?><?><?>\n");
    }
}

// Function to delete a book at a user-specified index
void delete_any_book(struct book books[], int *ptr)
{
    if (*ptr > 0) // Check if there are books in the inventory
    {
        // Display section header for deleting any book
        printf("\n\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");
        printf("\n\t\t\t\t\t\t\tDelete Any Book");
        printf("\n\t\t\t<?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?><?>");

        printf("\n\n\t\t\tTotal Number of Books: %d\n", *ptr); // Display the total number of books before deletion

        int bookIndex;
        // Ask the user for the book index to delete
        printf("\n\t\t\tEnter the index of the book you want to delete: ");
        fflush(stdin);
        scanf("%d", &bookIndex);
                --bookIndex;// Adjust the index to match array indexing (starting from 0)


        if (bookIndex >= 0 && bookIndex < *ptr) // Check if the provided index is valid
        {
            // Move all books after the deleted book one position back
            for (int i = bookIndex; i < *ptr - 1; i++)
            {
                // Update each book's information based on the next book in the array
                strcpy(books[i].name, books[i + 1].name);
                strcpy(books[i].author, books[i + 1].author);
                books[i].price = books[i + 1].price;
                strcpy(books[i].issue_date, books[i + 1].issue_date);
            }

            *ptr = *ptr - 1;// Decrement the book count to reflect the deletion

            printf("\n\n\t\t\tBook Deleted Successfully!\n\n"); // Display a success message
            printf("\n\t\t\tTotal Number of Books Left: %d\n", *ptr);// Display the total number of books after deletion

        }
        else // Display a message for an invalid book index
        {
            printf("\n\t\t\tInvalid book index. Deletion failed.");
        }
    }
}
// Function to show goodbye messege
void exitMessage()

{
    printf("\n\t\t\t**********************  **********************  *******************");
    printf("\n\t\t\t**********************  **********************  *******************");
    printf("\n\t\t\t************                                             **********");
    printf("\n\t\t\t************           Thanks for using EWU Library      **********");
    printf("\n\t\t\t************                                             **********");
    printf("\n\t\t\t**********************  **********************  *******************");
    printf("\n\t\t\t**********************  **********************  *******************");
    exit(0);
}
