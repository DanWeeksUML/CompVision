/******
* EECE.4811/5811: Operating Systems
* Instructor: M. Geiger
* Programming problem for Spring '21 Exam 1
******/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct N {
	int val;			// Value in node
	struct N* next;			// Pointer to next node
	pthread_mutex_t L;	// Lock for given node
} Node;

Node* list;				// Globally accessible linked list

/****
 COMPLETE traverse() TO ADD HAND-OVER-HAND LOCKING
 AND MAKE THIS FUNCTION THREAD-SAFE

 IF YOU NEED ADDITIONAL VARIABLES, FEEL FREE TO ADD THEM
 YOU MAY ALSO NEED TO MODIFY EXISTING LINES OF CODE IN
 THIS FUNCTION

 FUNCTION ACCESSES EVERY NODE IN LINKED LIST, PRINTS
 EACH VALUE, THEN INCREMENTS THE VALUE BEFORE MOVING
 TO NEXT NODE
****/
void traverse(Node* first, unsigned TID) {
	Node* p;

	p = first;
	while (p != NULL) {
		pthread_mutex_lock(&(p->L));
		printf("T%u: %d\n", TID, p->val);
		p->val++;
		pthread_mutex_unlock(&(p->L));
		p = p->next;
	}
}
/****
 DO NOT MODIFY ANYTHING BELOW THIS LINE
 ****/
void* threadfunc(void* arg) {
	unsigned id = (unsigned)arg;
	printf("Starting T%u ...\n", id);
	traverse(list, id);
	printf("T%u done\n", id);
	return NULL;
}

int main() {
	pthread_t TIDs[4];		// Thread IDs
	pthread_attr_t attr;	// Attribute structure
	unsigned i;				// Loop index
	Node* n;				// Generic node pointer
	int rc;					// Return code

	list = NULL;		// Initialize empty list

	/* Initialize and set thread detached attribute */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	// Allocate 10 new nodes, fill them with random values,
	//   and add them to the list
	for (i = 0; i < 10; i++) {
		n = (Node *)malloc(sizeof(Node));
		n->val = rand() % 10;
		n->next = list;
		list = n;
	}

	// Start 4 threads and have them run
	for (i = 0; i < 4; i++) {
		printf("Creating thread %u\n", i);
		rc = pthread_create(&TIDs[i], &attr, threadfunc, (void*)i);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	// Force all threads to join before deallocating list
	pthread_attr_destroy(&attr);
	for (i = 0; i < 4; i++) {
		rc = pthread_join(TIDs[i], NULL);
		if (rc) {
			printf("ERROR; return code from pthread_join() is %d\n", rc);
			exit(-1);
		}
	}

	// Clean up (deallocate) list when you're done
	while (list != NULL) {
		n = list;
		list = list->next;
		free(n);
	}

	pthread_exit(NULL);
}