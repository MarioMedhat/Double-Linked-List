// BY : MARIO MEDHAT
// GITHUB REPOSITORY LINK : https://github.com/MarioMedhat/Double-Linked-List

#include "iostream"
using namespace std;

// we will start first by defining the structure that we want to list
struct product {

	// first : we will define main variables in any double linked list
	
	// a pointer tha refers to the next element in the list 
	struct product* pnext;

	// a pointer tha refers to the next element in the list
	struct product* pprev;

	// second : we will define specific variables for the structure
	// as these are some basic variables for only testing the linked list
	// you can change them on your own with respect to your project

	// the name of the node
	char name[20];

	// the id of the node
	int id;

};

// after defining the structure of the node
// we must define pointers (global varibales)
// that will help us to navigate in the linked list 
// and all of them must be equal 0 at first as before 
// creating any node all of them must have values 

// these variables are : 
// a pointer indicating the start of the the list
struct product* pstart = 0;

// a pointer indicating the end of the the list
struct product* pend = 0;

// a pointer indicating the current node that we refer in the list
struct product* pcurrent = 0;

// then we are now able to define the function 
// that are going to build and handle the linked list

// the functions are going to be clasified in 2 types :

// the first type are the generic functions, 
// these are functions that handle the linked list as nodes 
// that are only dependent on the pointers 
// (pnext, pprev) of the structure

// the second type are the specific functions,
// these are functions that handle the linked list as variables
// that are not only dependent on the pointers 
// (pnext, pprev) of the structure, but also dependent on
// the other internal variables of the structure

//////////////////////////////////////////////////////////////////////////////
///////////////////////////  FIRST TYPE  /////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// the first function is the one that creats a new node
char creat(void) {

	// we will use a function called "malloc", this one takes as input
	// a size to creat in the heap and then returns a pointer refering 
	// to the start of the memory allocated, and if it was not able to 
	// creat or allocate the needed memory size, it returns zero
	// then as we are creating a new node, then the size is equal to the 
	// size of the structure of the linked list nodes 
	struct product* p = (struct product*) malloc(sizeof(struct product)); ;

	// check if the node was not created
	// if yes
	if (p == NULL) { 
		
		// the return zero refering to faillure of the memory allocation
		return 0; 
	
	}

	// if the node was created successfully
	else {

		// then first check if this is the first node to be created
		// if yes
		if (pstart == NULL) {
			
			// define the pointer that refers to the list start
			pstart = p;

		}

		// if this is not the first node
		else {

			// then make the previous node pnext pointer
			// as pend refers to last created node (previous node)
			// refer to the new created one
			pend->pnext = p;

		}

		// then make pprev pointer refer to the previous node
		// as pend refers to last created node (previous node)
		// and if this is the first node then pprev = 0 
		// as pend has no value (= 0)
		p->pprev = pend;

		// then make pnext pointer = 0 as the is no next node created
		// as this is the last one
		p->pnext = NULL;

		// then update the ped value to be = to the new created node
		pend = p;

		// please note that here you can also assign the node variable values
		// but as this is generic library so we will assign any specific terms here

		// finally return 1 indicating that the creation was successful
		return 1;

	}

}

// the first function is the one that find a node
char if_found(struct product* p) {

	// first check if pstart != NULL, because if
	// pstart == NULL, this indicates that there is no node created 
	if (pstart != NULL) {

		// if pstart != NULL, and there are created nodes, then start searching

		// define a pointer to the structure and search
		struct product* p_search = pstart;

		// loop until the list ends
		while (p_search != NULL) {

			// if the loop pointer = the search pointer
			// then FOUND!
			if (p == p_search) {

				// return one indicating that we found the node
				return 1;

			}

			// if still not found, then go the the next element 
			p_search = p_search->pnext;
		}

		// if the loop ends withount finding the node
		// then the node we are serching is not created 
		// or previously deleted, so,
		// return 0 indicating that we did not find the node
		return 0;

	}

	// else if the pstart == 0, so, there is no node creted
	else {

		// return 0 indicating that we did not find the node
		return 0;

	}

}

// the third function is the one that delets a node
char deleteone(struct product* p) {

	// this check can be redundent in many applications
	// so, you can remove it if do not need it
	// first we check if the node that we want to delete is 
	// present or not
	if (if_found(p)) {

		// if present

		// then check if it is the start node
		if (p == pstart) {

			// then we have to update the pstart pointer 
			// to refer the node next to the first one
			pstart = pstart->pnext;

			// then make the pprev of the new start node = 0 
			pstart->pprev = NULL;

		}

		// then check if it is the end node 
		else if (p == pend) {

			// then we have to update the pend pointer 
			// to refer the node before to the last one
			pend = pend->pprev;

			// then make the pnext of the new end node = 0 
			pend->pnext = NULL;
			

		}

		// then check if it is the only present node
		// so, it will be the start and end node
		else if (pend == pstart) {

			// then make the start and end pointers refer to 0
			pstart = NULL;
			pend = NULL;

		}

		// else if it is a normal node in the middle of the list
		else {

			// then make the pnext of the previous node refer to the next node
			(p->pnext)->pprev = p->pprev;
			
			// then make the pprev of the next node refer to the previous node
			(p->pprev)->pnext = p->pnext;
		}

		// then finally delete the node
		// free(), is a function that disallocates an allocated memory
		// it takes only the pointer of the node that we want to delete or disallocate
		free(p);

		// return one indicating that we found the node and it was deleted
		return 1;
	}

	// if the node is not found
	else {
	
		// return 0 indicating that we did not find the node
		return 0;
	
	}
}

// the last one is the delete all function
char deleteall() {

	// check if pstart != 0
	// to be sure that there is a list to delete
	if (pstart) {

		// first define a pointer to the structure
		// as we are going to loop on it
		// and we are not going to refer to the start
		// because if we deleted the node that we are pointing to
		// we can not go to any other node so we are going to delete
		// the node previous to the one we are refering to
		// like that we can go on in the list
		struct product* p = pstart->pnext;

		// start looping until the list ends
		// the list ends when the pointer = 0
		while (p) {

			// delete the node previous to the one we are refering to
			free(p->pprev);

			// go to next node
			p = p->pnext;

		}

		// as we are deleting the node previous to the one we are refering to
		// then we have not deleted the last node yet
		// so, delete the last one
		free(pend);

		// make the start and end pointers = 0
		// as there is no list
		pstart = 0;
		pend = 0;

		// return one indicating that we found the list and it was deleted
		return 1;
	}

	// return 0 indicating that we did not find a list
	return 0;

}

//////////////////////////////////////////////////////////////////////////////
///////////////////////////  SECOND TYPE  ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// define them on your own according to your project


int main() {

	return 0;

}

