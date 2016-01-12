#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList list;	
	list.first = list.last = NULL;
	list.length = 0;
	return list;
};

int add_to_list(LinkedList *list_of_element,void *element){
	Elements *e = (Elements *)malloc(sizeof(Elements));
	e->next = NULL;
	e->value = element;

	if(list_of_element->length == 0){
		 list_of_element->first = list_of_element->last = e;
	}
	else{
		list_of_element->last->next = e;
		list_of_element->last = e;
	}
	list_of_element->length++;
	return list_of_element->length;
};	

void *get_first_element(LinkedList list){
	if(list.length == 0){
		return NULL;
	}
	return list.first->value;
}

void *get_last_element(LinkedList list){
	if(list.length == 0){
		return NULL;
	}
	return list.last->value;
}

void * getElementAt(LinkedList list, int number){
	if(list.length == 0){
		return NULL;
	}
	Elements *ptr = list.first;
	for (int i = 0; i < number; ++i)
	{
		ptr = ptr->next;	
	}
	return ptr->value;
};

void traverse(LinkedList list){
	Elements *e = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		printf("%d\n", *(int *)e->value);
		e = e->next;
	}
}

void forEach(LinkedList list_of_elements, ElementProcessor e){
	Elements *ele = list_of_elements.first;
	for (int i = 0; i < list_of_elements.length; ++i)
	{
		e(ele->value);
		ele = ele->next;
	}
}

