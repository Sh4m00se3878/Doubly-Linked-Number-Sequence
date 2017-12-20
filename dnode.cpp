// FILE: node1.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>
#include "dnode.h"

using namespace std;

void traverse(dnode* head_ptr){
	dnode * current = head_ptr;
	dnode * tail_ptr = NULL;

	cout << "The nodes in the list are : " << endl;

	cout << "   forwards: ";
	while (current != NULL){ 
	cout << current->data() << " ";
		if (current->fore() == NULL) {
			tail_ptr = current;
		}
		current = current->fore();
	}
	current = tail_ptr;
	cout << endl << "   backwards: ";
	 
	while (current != NULL) {
		cout << current->data() << " ";
		current = current->back();
	}
	cout << endl << endl;
}

void traverse(const dnode* head_ptr){
	const dnode * current = head_ptr;
	const dnode * tail_ptr = NULL;

	cout << "The nodes in the list are : " << endl;

	cout << "   forwards: ";
	while (current != NULL){
		cout << current->data() << " ";
		if (current->fore() == NULL) {
			tail_ptr = current;
		}
		current = current->fore();
	}
	current = tail_ptr;
	cout << endl << "   backwards: ";

	while (current != NULL) {
		cout << current->data() << " ";
		current = current->back();
	}
	cout << endl << endl;
}

size_t list_length(const dnode* head_ptr){
	const dnode *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
	    ++answer;
	
	return answer;
}

void list_head_insert(dnode*& head_ptr, const value_type& entry){
	dnode * insert_ptr = new dnode(entry);
	insert_ptr->set_fore(head_ptr);
	
	if (head_ptr != NULL) {
		head_ptr->set_back(insert_ptr);
	}

	head_ptr = insert_ptr;
}

void list_insert(dnode* previous_ptr, const value_type& entry) {
	dnode *next_ptr = previous_ptr->fore(), 
		*insert_ptr = new dnode(entry);
	
	insert_ptr->set_fore(next_ptr);
	insert_ptr->set_back(previous_ptr);
	previous_ptr->set_fore(insert_ptr);
	if (next_ptr != NULL) {
		next_ptr->set_back(insert_ptr);
	}
}

dnode* list_search(dnode* head_ptr, const value_type& target) {
	dnode *cursor;
   
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore( ))
	    if (target == cursor->data( ))
			return cursor;
	return NULL;
 }

const dnode* list_search(const dnode* head_ptr, const value_type& target) {
	const dnode *cursor;
   
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore( ))
	    if (target == cursor->data( ))
			return cursor;
	return NULL;
}


dnode* list_locate(dnode* head_ptr, size_t position) {
	dnode *cursor;
	size_t i;
    
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->fore( );
	return cursor;
}

const dnode* list_locate(const dnode* head_ptr, size_t position) {
	const dnode *cursor;
	size_t i;
    
	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->fore( );
	return cursor;
}

void list_head_remove(dnode*& head_ptr){
	assert (head_ptr != NULL);
	dnode *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->fore( );
	if (head_ptr != NULL){
		head_ptr->set_back(NULL);
	}
	delete remove_ptr;
}

void list_remove(dnode* remove_ptr){
	assert(remove_ptr != NULL);
	dnode *previous_ptr, *next_ptr;

	previous_ptr = remove_ptr->back();
	next_ptr = remove_ptr->fore();
	previous_ptr->set_fore(next_ptr); // ERROR
	if (next_ptr != NULL){
		next_ptr->set_back(previous_ptr);
	}
	delete remove_ptr;
}

void list_clear(dnode*& head_ptr){
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
}


void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;
    
	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;
    
	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->fore( ); 
	while (source_ptr != NULL){
	    list_insert(tail_ptr, source_ptr->data( )); // pointer and entry 
	    tail_ptr = tail_ptr->fore( );
	    source_ptr = source_ptr->fore( );
	}
}

