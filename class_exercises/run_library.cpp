#include <iostream>
#include <vector>
#include "Library.h"

// Name(s): xiang chen
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments by writing your answer in the comments.
// some experiments might result in non-running/non-compiling code. Leave these experiments in, but
// comment them out.
// Turn in run_library.cpp, Library.h, and Library.cpp on Canvas before the end of class.
// make sure to leave a comment here and on canvas with your name and the name(s) of your partners.

int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books' fields.
    Book * book1 = new Book();
    book1->author = "xiang chen"; book1->title="firsr book";
    std::cout << "I have book named " << book1->title << " with author " << book1->author << std::endl;
    // 2) Instantiate a Library.
   
    Library *Library1 = new Library();


    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.
    //done

    // 4) Donate one of the Books that you instantiated to your Library.
    Library1->Donate(*book1);

    // 5) Print out the books in the Library (use the given PrintBooks method)
    Library1->PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    // Print out the new book information, then print out the books in your
    // Library. Did changing the Book information change it in your Library?
    //
    // Answer (and your hypothesis for why/why not):
    //because the donate method does not accept reference or poineter

    book1->title = "not really first book"; book1->author = "unknown";
    std::cout << "updated info: " << book1->title << std::endl;
    Library1->PrintBooks();
    //answer:
    /*
    
    */
    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: it fails because struct have not overload ==
    
    Book book2;
    book2.author ="john"; book2.title = "second book";
    Book book3;
    book3.author ="john"; book3.title = "second book";
    //std::cout << (book2 == book3) << std::endl;
    
    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: 
    //it fails cause == is not valie operands for reference
    Book &ref_book2 = book2;
    Book &ref_book3 = book3;
    //std::cout << (ref_book2 == ref_book3) << std::endl;

    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer:
    //yes, it compare the address directly beacause c++ supoort == for pointer
    Book *ptr_book2 = &book2;
    Book *ptr_book3 =  &book3;
    std::cout << (ptr_book2 == ptr_book3) << std::endl;
    // 10) Add a void Donate(Book b, int num_copies) method to your Library class.
    // your Library should add num_copies of Book b to its shelf. 
    //done

    // 11) Finally, if you reach this far, work on finding a solution to making it so
    // that you would be able to do any of the comparisons from # 7, 8, and 9
    //
    std::cout << "compare by reference " << (ref_book2 == ref_book3) << std::endl;



    delete book1;
    delete Library1;
}
