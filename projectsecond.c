//program to demonstrate the use of array,structure,function,filehandling:
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a book
struct Book {
    char title[100];
    char author[100];
    float price;
};

// Function to add a book to the file
void addBookToFile(struct Book b) {
    FILE *file = fopen("books.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s|%s|%.2f\n", b.title, b.author, b.price);//|: This is a literal character in the format string. It serves as a delimiter to separate different fields of data in the file
    fclose(file);
}

// Function to display all books from the file
void displayBooksFromFile() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    struct Book b;
    printf("Books:\n");//file: This is a pointer to a FILE structure, representing the file from which we want to read data. It should have been previously opened using the fopen function.
    while (fscanf(file, "%[^|]|%[^|]|%f\n", b.title, b.author, &b.price) != EOF) {//%[^|]: This is a format specifier for a string that scans characters until the '|' character is encountered. It reads the title of the book up to the '|' character and stores it in b.title.
        printf("Title: %s\nAuthor: %s\nPrice: $%.2f\n\n", b.title, b.author, b.price);
    }
    fclose(file);
}

int main() {
    // Create some sample books
    struct Book books[3] = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 12.99},
        {"To Kill a Mockingbird", "Harper Lee", 10.50},
        {"1984", "George Orwell", 8.75}
    };
    int num_books = sizeof(books) / sizeof(books[0]);

    // Add books to the file
    for (int i = 0; i < 3; i++) {
        addBookToFile(books[i]);
    }

    // Display all books from the file
    displayBooksFromFile();

    return 0;
}

//File Handling : The program reads from and writes to a file named "books.txt" using fopen, fprintf, and fclose.

//Arguments passed by value vs Argument passed by reference : The addBookToFile function takes a struct Book argument by value, and the displayBooksFromFile function uses a local struct Book variable and passes its address to fscanf.

//Structs : It defines a structure struct Book to represent book data, including their title, author, and price.

//Arrays : An array of struct Book is used to store sample book data.

//Formatted IO : It uses formatted input/output functions like printf, fprintf, and fscanf to display and read data.

//Documentation/Organization/Explanation : The program is well-organized and adequately commented to explain its structure, purpose, and functionality.
