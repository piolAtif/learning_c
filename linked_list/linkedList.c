#include <stdio.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList *list;	
	list->first = list->last = NULL;
	list->length = 0;
	return *list;
};