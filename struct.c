#include <stdio.h>
#include <string.h>

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

// 提前声明函数
void printInfo(struct Books book);
void printPointInfo(struct Books *book);


int main(int argc, char const *argv[])
{
    struct Books book = {"JavaProgrammingIdeas", "hzs", "computer science", 100};

    printf("title: %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);

    strcpy(book.author, "hsk");
    book.book_id = 1000;
    printf("\nupdated: \ntitle: %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);

    printInfo(book);

    printPointInfo(&book);

    return 0;
}

void printInfo(struct Books book)
{
    printf("Book title: %s\n", book.title);
    printf("Book author: %s\n", book.author);
}

void printPointInfo(struct Books *book)
{
    printf("Book title: %s\n", book->title);
    printf("Book author: %s\n", book->author);
}