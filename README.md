# Doubly Linked Number Sequence

Implement the sequence class using your double linked list class created in Project #3 (dnode.h and dnode.cpp).  
// FILE: sequence.h
#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include "dnode.h"
using namespace std;

// TYPEDEFS and MEMBER CONSTANTS
typedef double value_type;
typedef size_t size_type;
      
class sequence
{
public:
       	sequence( );
        	sequence(const sequence & source);
        	~sequence();
           	void start( );
        	void tail( );
        	void advance( );
        	void moveback( );
        	void insert(const value_type& entry);
        	void attach(const value_type& entry);
        	void remove_current( );
        	void operator=(const sequence & source);
        	size_type size( );
        	bool is_item( ) const;
        	value_type current( ) const;
    	private:
		dnode * head_ptr,		
 * current_ptr;
};
#endif

The information listed in bold above is new to the sequence class.  The copy constructor, destructor, and assignment operator are required now that the class uses dynamic memory allocation.  The function moveback is similar to the advance function (moves current_ptr to the next node) but it moves the current_ptr to the previous node (the node immediately preceding it).

In the Project #4 folder, there is a sub folder titled Sequence.  You will find three files that implement the original sequence class (sequence1.h, sequence1.cpp, seqDriver.cpp).  You may want to review the documentation in sequence1.h and run these 3 files to see how the sequence class works.  The code in sequence1.cpp will need to be completely rewritten so you are only using these files to understand the sequence class.

You need to update the sequence class using the header file above which is a sequence class that uses a double linked list implementation.  
Be sure you add options to the driver to test all of the existing functions, as well as, the following new functions:  
•	copy constructor (X)
•	destructor (D)
•	tail (T)
•	moveback (-)
•	operator= (=)

In addition your show_sequence function MUST displays the sequence both forwards and backwards.

Submit files: Zip the following 5 files: dnode.h, dnode.cpp, sequence.h, sequence.cpp, and lastname4.cpp and attach the zipped file in the Project #4 assignment link.  The file extension must be zip.
