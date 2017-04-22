#include "./llist/llist.h"
#include <stdio.h>

void selSort(List *unsorted);
void insSort(List *unsorted);
void print_list(List* list);
void create_rnd_list(List *list, long range, int num_elements);

void main(){
	int count;							//<= print counter	
	List* unsorted = list_create();		//<= unsorted list
	List* sorted = list_create();		//<= sorted list	
	
	printf("Welcome to the Sort Demonstration\n");
	printf("\nThis program sorts two random lists, once using Selection Sort,\n");
	printf("and once using Insertion Sort.  For each sort, the iterations are\n");
	printf("displayed so you can see the progress.\n\n");

	create_rnd_list(unsorted, 100, 15);		//<= generate new random list
	count = 1;								//<= initialize print counter

	printf("Selection Sort\n");
	printf("------------------------------------------------------------\n");
	while((unsorted->first) != NULL) {
		printf("Unsorted List:\n");
		print_list(unsorted);
	
		printf("Step %d: Sorted List\n", count++);
		list_push(sorted, ((unsorted->first)->value));
		list_pop(unsorted);	
		selSort(sorted);
		print_list(sorted);
		
	}
	
	list_clear(unsorted);					//<= clear unsorted list free memory
	list_clear(sorted);						//<= clear sorted list free memory
	create_rnd_list(unsorted, 100, 15);		//<= generate new random list	
	count = 1;								//<= reset print counter	
	
	
	
	printf("Insertion Sort\n");
	printf("------------------------------------------------------------\n");
	while((unsorted->first) != NULL) {
		printf("Unsorted List:\n");
		print_list(unsorted);
	
		printf("Step %d: Sorted List\n", count++);
		list_push(sorted, ((unsorted->first)->value));
		list_pop(unsorted);	
		insSort(sorted);
		print_list(sorted);
		
	}	
	
	list_clear(unsorted);					//<= clear unsorted list free memory
	list_clear(sorted);						//<= clear sorted list free memory	
	
}


/**
 * Sort a double linked list using a selection alogrithm O(n^2)
 *
 * @pram unsorted is a pointer to a doubly linked list.
 */
void selSort(List *unsorted) {
	ListNode *head = unsorted->first;
	ListNode *min, *i, *j;
	long temp;
	
	
	for(i = head; ((i != NULL) && (i->next != NULL)); i = i->next) {
		min = i;
		
		for(j = i->next; j != NULL; j = j->next) {
			if(((long*)j->value) < ((long*)min->value)) {
				min = j;
				
			}
			
		}
		
		if(min != i) {
			temp = (long)min->value;
			min->value = (void*)i->value;
			i->value = (void*)temp;
			
		}
		
	}
	
}


/**
 * Sort a double linked list using a insertion alogrithm O(n^2)
 *
 * @pram unsorted is a pointer to a doubly linked list.
 */
void insSort(List *unsorted) {
	ListNode *head = unsorted->first;
	ListNode *min, *i, *j;
	long temp;  
 

	for(i = head->next; i != NULL; i = i->next) {
		temp = (long)i->value;
		j = i;
		
		while((j->prev != NULL) && ((long)((j->prev)->value) > temp)) {
			j->value = (j->prev)->value;
			j = j->prev;
		
		}
		
		j->value = (void*)temp;
		
		
	}
  
}


/**
 * Prints the contents of a doubly linked list in a comma seperated format.
 *
 * @pram list is a pointer to a doubly linked list.
 */
void print_list(List* list) {
	ListNode *current = NULL;		//<= current node, temp pointer
	int i = 0;						//<= loop counter
  
	if((list->count) <= 0) {
		printf("Empty List.\n\n");
		
	} else {
		current = list->first;
		
		if((list->count) == 1) {
			printf("%ld\n\n", (long*)current->value);
			
		} else {
			for(i = 0; i < (list->count); i++) {
				if(current->next != NULL) {
					printf("%ld, ", (long*)current->value);
					
				} else {
					printf("%ld\n\n", (long*)current->value);
					
				}
				
				current = current->next;
			  
			}
			
		}
		
	}
	
}


/**
 * Creates a linked list of specified length, and populates it with positive long integers
 * given an upper bound.
 *
 * @pram list is doubly linked list pointer.
 * @pram range is the upper bound long integer for generating random longs.
 * @pram num_nodes is the number of nodes in the doubly linked list.
 */
void create_rnd_list(List *list, long range, int num_nodes) {
	int i;				//<= loop counter
	long payload = 0;		//<= variable for random long int
	
	for(i = 0; i < num_nodes; i++) {
		payload = rand() % range + 1;
		list_push(list, (void*)payload);

	}
	
}