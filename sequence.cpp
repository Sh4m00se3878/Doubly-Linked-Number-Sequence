#include "sequence.h"
#include <cassert>
#include "dnode.h"
#include <iostream>

using namespace std;

// CONSTRUCTOR
sequence::sequence( ){
	head_ptr = NULL;
	current_ptr = NULL;
}


// COPY CONSTRUCTOR
sequence::sequence(const sequence & source){
	dnode* new_head_ptr, * new_tail_ptr;
	list_copy(source.head_ptr, new_head_ptr, new_tail_ptr);
	head_ptr = new_head_ptr;
	current_ptr = new_head_ptr;
}

// DESTRUCTOR
sequence::~sequence(){ 
	current_ptr = NULL;
	list_clear(head_ptr);
}

// START(): sets current_ptr = head_ptr
void sequence::start() {
	current_ptr = head_ptr;
}

// TAIL(): sets current_ptr = tail_ptr
void sequence::tail() {
	dnode* cursor = head_ptr;
	if (head_ptr == NULL) {
		current_ptr = NULL;
	}
	else {
		while (cursor->fore() != NULL) {
			cursor = cursor->fore();
		}
		current_ptr = cursor;
	}
}

// ADVANCE(): moves forwards in the list
void sequence::advance( ){
	if (is_item())
		current_ptr = current_ptr->fore();
}

// MOVEBACK(): moves backwards in the list
void sequence::moveback() {
	if (is_item()) 
		current_ptr = current_ptr->back();
}
 
// INSERT(): puts a node to the left of cursor
void sequence::insert(const value_type& entry){ 
	if (!is_item()) {
		start();
	}

	if (current_ptr == head_ptr) {
		list_head_insert(head_ptr, entry);
		start();
	}
	else {
		current_ptr = current_ptr->back();
		list_insert(current_ptr, entry);
		current_ptr = current_ptr->fore();
	}
}

// ATTACH(): puts a node to the right of cursor
void sequence::attach(const value_type& entry){ 
	if (head_ptr == NULL) {
		list_head_insert(head_ptr, entry);
		start();
	}
	else {
		if (!is_item()) {
			tail();
		}
		list_insert(current_ptr, entry);
		current_ptr = current_ptr->fore();
	}
}

// REMOVE_CURRENT(): removes current_ptr
void sequence::remove_current( ){
	if (is_item() && current_ptr == head_ptr) {
		list_head_remove(head_ptr);
		start();
	}
	else if (is_item()){
		if (current_ptr->fore() != NULL) {
			dnode * temp = current_ptr->fore();
			list_remove(current_ptr);
			current_ptr = temp;
		}
		else {
			dnode * temp = current_ptr->back();
			list_remove(current_ptr);
			current_ptr = temp;
		}
	}
}

// OPERATOR= : sets sequence = sequence
void sequence::operator=(const sequence& source) {
	if (this == &source) { 
		return;
	}

	dnode* new_head_ptr, *new_tail_ptr;
	list_clear(head_ptr);
	list_copy(source.head_ptr, new_head_ptr, new_tail_ptr);
	head_ptr = new_head_ptr;
	current_ptr = new_head_ptr;
}

// SIZE(): returns length
size_type sequence::size( ){	
	return list_length(head_ptr);
}   

// IS_ITEM(): returns true or false depending on item
bool sequence::is_item( ) const{
	return (current_ptr != NULL);
}
 
// CURRENT(): returns current node
value_type sequence::current( ) const{
	if (is_item())
		return current_ptr->data();
	else
		return NULL;
}

