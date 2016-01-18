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

void *getElementAt(LinkedList list, int number){
	if(list.length == 0 || number>list.length){
		return NULL;
	}
	Elements *ptr = list.first;
	for (int i = 0; i < number; ++i)
	{
		ptr = ptr->next;	
	}
	return ptr->value;
};

void traverse_int(LinkedList list){
	Elements *e = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		printf("%d\n", _TYPEINT_(e->value));
		e = e->next;
	}
};

void traverse_char(LinkedList list){
	Elements *e = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		printf("%c\n", _TYPECHAR_(e->value));
		e = e->next;
	}
};

void traverse_float(LinkedList list){
	Elements *e = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		printf("%.2f\n",_TYPEFLOAT_(e->value));
		e = e->next;
	}
};

void forEach(LinkedList list_of_elements, ElementProcessor e){
	Elements *ele = list_of_elements.first;
	for (int i = 0; i < list_of_elements.length; ++i)
	{
		e(ele->value);
		ele = ele->next;
	}
};

int indexOf(LinkedList list, void *element){
	Elements *ptr = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		if(_TYPEINT_(ptr->value) == _TYPEINT_(element)){
			return i;
		}
		ptr = ptr->next;
	}
	return -1;
};

void *deleteElementAt(LinkedList *list, int index){
	void *val;
	Elements *loc = (Elements *)malloc(sizeof(Elements));
	Elements *ptr = (Elements *)malloc(sizeof(Elements));
	ptr = list->first;
	if((list->length == 0 )|| (list->length<=index)){
		return NULL;
	}
	
	else if(list->first->next == NULL){
		val = ptr->value;
		free(ptr);	
	}
	else{
		loc = ptr->next;
		for (int i = 1; i < index; ++i)
		{	
			loc = loc->next;
			ptr = ptr->next;
		};
		val = loc->value;
		if(index == list->length-1){
			ptr->next = NULL;
		}
		else{
			ptr->next = loc->next;
		}
		free(loc);	
	}
	list->length--;
	return val;
};

int asArray(LinkedList list, void **match_arr, int maxElements){
	Elements *e = list.first;
	int length = 0;
	for (int i = 0; i < maxElements; ++i)
	{
		match_arr[i] = e->value;
		e = e->next;
		length++;
	}
	return length;
};

LinkedList filter(LinkedList list, MatchFunc m, void *hint){
	Elements *e = list.first;
	LinkedList filtered_list = createList();
	for (int i = 0; i < list.length; ++i)
	{
		if(m(hint, e->value)){
			add_to_list(&filtered_list, e->value);
		}
		e = e->next;
	}
	return filtered_list;
};

LinkedList reverse(LinkedList list){
	LinkedList reverse_list = createList();

	reverse_list.first = list.last;
	reverse_list.last = list.first;
	for (int i = list.length; i > 0 ; --i)
	{
		Elements *e = list.first;
		for (int j = 1; j < i; j++)
		{
			e = e->next;
		}
		if(e->value){
			add_to_list(&reverse_list, e->value);
		}
	}
	return reverse_list;
};

LinkedList map(LinkedList list, ConvertFunc con, void * hint){
	LinkedList dest_list = createList();
	Elements *source = list.first;
	for (int i = 0; i < list.length; ++i)
	{
		void *destination = malloc(sizeof(void *));
		con(hint, source->value, destination);
		add_to_list(&dest_list, destination);
		source = source->next;
	};
	return dest_list;
};

LinkedList reduce(LinkedList list, Reducer reducer, void *hint, void *initialValue){
	Elements *previous = list.first;
	LinkedList new_list = createList();
	for (int i = 0; i < list.length; ++i)
	{
		initialValue = reducer(hint, previous->value, initialValue);
		previous = previous->next;
	}
	add_to_list(&new_list, initialValue);
	return new_list;
};

