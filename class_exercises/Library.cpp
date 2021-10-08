#include <iostream>
#include <string>
#include <vector>

#include "Library.h"

/**
  Zero argument constructor initializes a library with a shelf but no books.
*/
Library::Library() {
  std::vector<Book> tmp;
  shelf_ = tmp;  // initialize my shelf
}

//donate the book
void Library::Donate(Book b){
  shelf_.push_back(b);
};

//donate numberous books
void Library::Donate(Book b, int num_copies){
  for(int i = 0; i < num_copies; i++)
    shelf_.push_back(b);
}




/**
  Prints out each book in the library, one per line to cout
*/
void Library::PrintBooks() {
  for (Book b : shelf_) {
    std::cout << b.title << " by " << b.author << std::endl;
  }
}