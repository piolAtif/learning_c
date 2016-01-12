#include <assert.h>
#include "linkedList.h"
#define intType *(int *)

void increase(void *ele){
	++intType(ele);
}

void test_create_linked_list(){
	LinkedList list = createList();
	assert(list.first == list.last);
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
};	

void test_add_first_to_list(){
	LinkedList list = createList();
	int number = 23;
	void *ptr = &number;
	int length = add_to_list(&list, ptr);

	assert(length == 1);
	assert(intType(list.first->value) == intType(list.last->value));
	assert(intType(list.first->value) == 23);
};

void test_add_to_list(){
	LinkedList list = createList();
	int number = 44;
	void *ptr = &number;
	add_to_list(&list, ptr);

	int number2 = 33;
	void *ptr2 = &number2;
	int length2 = add_to_list(&list, ptr2);

	assert(length2 == 2);
	assert(intType(list.last->value) == 33);
};

void test_get_first_element(){
	LinkedList list = createList();
	int number = 44;
	void *ptr = &number;
	add_to_list(&list, ptr);

	int number2 = 33;
	void *ptr2 = &number2;
	add_to_list(&list, ptr2);

	int number3 = 23;
	void *ptr3 = &number2;
	add_to_list(&list, ptr2);

	void *first_element = get_first_element(list);

	assert(intType(first_element) == 44);
};

void test_get_last_element(){
	LinkedList list = createList();
	int number = 44;
	void *ptr = &number;
	add_to_list(&list, ptr);

	int number2 = 33;
	void *ptr2 = &number2;
	add_to_list(&list, ptr2);

	int number3 = 23;
	void *ptr3 = &number3;
	add_to_list(&list, ptr3);

	void *last_element = get_last_element(list);
	assert(intType(last_element) == 23);
};

void test_forEach(){
	LinkedList list = createList();
	int number = 44;
	void *ptr = &number;
	add_to_list(&list, ptr);

	int number2 = 33;
	void *ptr2 = &number2;
	add_to_list(&list, ptr2);

	int number3 = 23;
	void *ptr3 = &number3;
	add_to_list(&list, ptr3);

	forEach(list, increase);
	assert(intType(list.first->value) == 45);
	traverse(list);
	assert(intType(list.last->value) == 24);
};

void test_getElementAt(){
	LinkedList list = createList();
	int number = 44;
	void *ptr = &number;
	add_to_list(&list, ptr);

	int number2 = 33;
	void *ptr2 = &number2;
	add_to_list(&list, ptr2);

	int number3 = 23;
	void *ptr3 = &number3;
	add_to_list(&list, ptr3);

	void *ele = getElementAt(list, 2);
	assert(intType(ele) == 23);

	void *ele2 = getElementAt(list,1);
	assert(intType(ele2) == 33);

	void *ele3 = getElementAt(list,0);
	assert(intType(ele3) == 44);
};

void test_indexOf(){
	LinkedList list = createList();
	int number = 12;
	void *ptr = &number;
	add_to_list(&list, ptr);

	int number2 = 33;
	void *ptr2 = &number2;
	add_to_list(&list, ptr2);

	int number3 = 23;
	void *ptr3 = &number3;
	add_to_list(&list, ptr3);

	int number4 = 44;
	void *ptr4 = &number4;
	add_to_list(&list, ptr4);

	int number5 = 23;
	void *ptr5 = &number5;
	add_to_list(&list, ptr5);

	int number6 = 22;
	void *ptr6 = &number6;
	add_to_list(&list, ptr6);

	int value = 23;
	void *ptr_value = &value;

	int index_of_element = indexOf(list, ptr_value);
	assert(index_of_element == 2);

	int value2 = 44;
	void *ptr_value2 = &value2;
	int index = indexOf(list, ptr_value2);
	assert(index == 3);
}



