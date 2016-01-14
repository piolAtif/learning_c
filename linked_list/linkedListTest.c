#include <stdio.h>
#include <assert.h>
#include "linkedList.h"
#define intType *(int *)

int isGreater(void *hint, void *item){
	int limitation = intType(hint);
	int val_to_compare = intType(item);
	if(limitation<val_to_compare){
		return 1;
	}
	return 0;
};

void *average_of_sum(void *hint, void *previousItem, void *initialValue){
	intType(initialValue) = intType(initialValue)+intType(previousItem);
	return initialValue;
};

void sum(void *hint, void *source, void *dest){
	int auddend = intType(hint);
	int auggend = intType(source);
	int add = auddend+auggend;
	intType(dest) = add;
};

void print_arr(void **arr, int length){
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", intType(arr[i]));
	}
}

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
};

void test_deleteElementAt(){
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

	void *delete_element = deleteElementAt(&list, 2);
	assert(intType(delete_element) == 23);

	void *ele = getElementAt(list,2);
	assert(intType(ele) == 44);
}

void test_deleteElementAt_for_null_element(){
	LinkedList list = createList();
	void *delete_element = deleteElementAt(&list, 1);

	assert(delete_element == NULL);
	assert(list.length == 0);
};

void test_deleteElementAt_if_listLength_one(){
	LinkedList list = createList();
	int number = 12;
	void *ptr = &number;
	add_to_list(&list, ptr);

	assert(list.length == 1);

	void *delete_element = deleteElementAt(&list, 0);
	assert(intType(delete_element) == 12);

	void *ele = getElementAt(list,0);
	assert(list.length == 0);
};

void test_deleteElementAt_if_indexNotRange(){
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

	void *delete_element = deleteElementAt(&list, 3);
	assert(delete_element == NULL);
};

void test_deleteElementAt_for_lastElement(){
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

	void *delete_element = deleteElementAt(&list, 2);
	assert(intType(delete_element) == 23);

	void *ele = getElementAt(list,1);
	assert(intType(ele) == 33);
	assert(list.length == 2);
};

void test_asArray(){
	LinkedList list = createList();
	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int a[10];
	void *arr_ptr = &a;
	int maxLength = 2;

	int length_of_arr = asArray(list, arr_ptr, maxLength);
	assert(maxLength == 2);

	print_arr(arr_ptr,2);
};

void test_filter_isGreater(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	int value = 30;
	void *hint = &value;

	LinkedList filtered = filter(list, isGreater, hint);

	void *value1 = getElementAt(filtered, 0);
	assert(intType(value1) == 33);

	void *value2 = getElementAt(filtered, 1);
	assert(intType(value2) == 44);
};

void test_reverse_using_traverse(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	traverse(reverse_list);
	void *reverse_val = getElementAt(reverse_list, 0);

	assert(intType(reverse_val) == 23);
};

void test_reverse_using_getElementAt(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	void *get_reverse_ele = getElementAt(reverse_list, 1);
	assert(intType(get_reverse_ele) == 44);

	void *get_reverse_ele2 = getElementAt(reverse_list,3);
	assert(intType(get_reverse_ele2) == 33);

	void *get_reverse_ele3 = getElementAt(reverse_list, 2);
	assert(intType(get_reverse_ele3) == 23);
};

void test_reverse_using_getFirstElement(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	void *get_reverse_ele = get_first_element(reverse_list);
	assert(intType(get_reverse_ele) == 23);	
};

void test_reverse_using_getLastElement(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	void *get_reverse_ele = get_last_element(reverse_list);
	assert(intType(get_reverse_ele) == 12);	
};

void test_map_using_traverse(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	int value = 2;
	LinkedList map_element = map(list, sum, &value);
	traverse(map_element);
};

void test_map_using_getElement(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	int value = 2;
	LinkedList map_element = map(list, sum, &value);

	void *map_ele = getElementAt(map_element, 0);
	assert(intType(map_ele) == 14);

	void *map_ele2 = getElementAt(map_element, 2);
	assert(intType(map_ele2) == 25);

	void *map_ele3 = getElementAt(map_element, 4);
	assert(intType(map_ele3) == 25);
};

void test_reduce_using_traverse(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	int hint = 0;
	int value = 0;
	LinkedList reduce_list = reduce(list, average_of_sum, &hint, &value);
	traverse(reduce_list);
};

void test_reduce_using_getElement(){
	LinkedList list = createList();

	int number = 12;
	add_to_list(&list, &number);

	int number2 = 33;
	add_to_list(&list, &number2);

	int number3 = 23;
	add_to_list(&list, &number3);

	int number4 = 44;
	add_to_list(&list, &number4);

	int number5 = 23;
	add_to_list(&list, &number5);

	int hint = 0;
	int value = 0;

	LinkedList reduce_list = reduce(list, average_of_sum, &hint, &value);
	void *reduce_ele = getElementAt(reduce_list, 0);
	assert(intType(reduce_ele) == 135);
};


