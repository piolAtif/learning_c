#include <stdio.h>
#include <assert.h>
#include "linkedList.h"
#define _TYPEINT_ *(int *) 

int isGreater(void *hint, void *item){
	int limitation = _TYPEINT_(hint);
	int val_to_compare = _TYPEINT_(item);
	if(limitation<val_to_compare){
		return 1;
	}
	return 0;
};

void *average_of_sum(void *hint, void *previousItem, void *initialValue){
	_TYPEINT_(initialValue) = _TYPEINT_(initialValue)+_TYPEINT_(previousItem);
	return initialValue;
};

void sum(void *hint, void *source, void *dest){
	int auddend = _TYPEINT_(hint);
	int auggend = _TYPEINT_(source);
	int add = auddend+auggend;
	_TYPEINT_(dest) = add;
};

void print_arr(void **arr, int length){
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", _TYPEINT_(arr[i]));
	}
};

void increaseFloat(void *ele){
	float augend = 0.09;
	_TYPEFLOAT_(ele) += augend;
};

void convertChar(void *ele){
	_TYPECHAR_(ele) = 't';
};

void increase(void *ele){
	++_TYPEINT_(ele);
};

void test_create_linked_list(){
	LinkedList list = createList();
	assert(list.first == list.last);
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
};	

void test_add_if_list_has_oneElement(){
	LinkedList list = createList();
	int number = 23;
	int length = add_to_list(&list, &number);

	assert(length == 1);
	assert(_TYPEINT_(list.first->value) == _TYPEINT_(list.last->value));
	assert(_TYPEINT_(list.first->value) == 23);
};

void test_firstElement_and_lastElement_of_list(){
	LinkedList list = createList();
	int number = 44, number2 = 33;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);

	assert(_TYPEINT_(list.first->value) == 44);
	assert(_TYPEINT_(list.last->value) == 33);
};

void test_first_last_should_not_be_same_if_lengthNotOne(){
	LinkedList list = createList();
	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	assert(_TYPEINT_(list.first->value) != _TYPEINT_(list.last->value));

};

void test_get_first_element(){
	LinkedList list = createList();
	int number = 44, number2 = 33, number3 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);

	void *first_element = get_first_element(list);
	assert(_TYPEINT_(first_element) == 44);
};


void test_get_last_element(){
	LinkedList list = createList();
	int number = 44, number2 = 33, number3 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);

	void *last_element = get_last_element(list);
	assert(_TYPEINT_(last_element) == 23);
};

void test_forEach(){
	LinkedList list = createList();
	int number = 44, number2 = 33, number3 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);

	forEach(list, increase);
	assert(_TYPEINT_(list.first->value) == 45);
	traverse_int(list);
	assert(_TYPEINT_(list.last->value) == 24);
};

void test_getElementAt(){
	LinkedList list = createList();
	int number = 44, number2 = 33, number3 = 23;	
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);

	void *ele = getElementAt(list, 2);
	assert(_TYPEINT_(ele) == 23);

	void *ele2 = getElementAt(list,1);
	assert(_TYPEINT_(ele2) == 33);

	void *ele3 = getElementAt(list,0);
	assert(_TYPEINT_(ele3) == 44);
};

void test_indexOf(){
	LinkedList list = createList();
	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23, number6 = 22;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);
	add_to_list(&list, &number6);

	int value = 23;
	int index_of_element = indexOf(list, &value);
	assert(index_of_element == 2);

	int value2 = 44;
	int index = indexOf(list, &value2);
	assert(index == 3);
};

void test_deleteElementAt(){
	LinkedList list = createList();
	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	void *delete_element = deleteElementAt(&list, 2);
	assert(_TYPEINT_(delete_element) == 23);

	void *ele = getElementAt(list,2);
	assert(_TYPEINT_(ele) == 44);
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
	add_to_list(&list, &number);

	assert(list.length == 1);

	void *delete_element = deleteElementAt(&list, 0);
	assert(_TYPEINT_(delete_element) == 12);

	void *ele = getElementAt(list,0);
	assert(list.length == 0);
};

void test_deleteElementAt_if_indexNotRange(){
	LinkedList list = createList();
	int number = 12, number2 = 33, number3 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);

	void *delete_element = deleteElementAt(&list, 3);
	assert(delete_element == NULL);
};

void test_deleteElementAt_for_lastElement(){
	LinkedList list = createList();
	int number = 12, number2 = 33, number3 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);

	void *delete_element = deleteElementAt(&list, 2);
	assert(_TYPEINT_(delete_element) == 23);

	void *ele = getElementAt(list,1);
	assert(_TYPEINT_(ele) == 33);
	assert(list.length == 2);
};

void test_asArray(){
	LinkedList list = createList();
	int number = 12, number2 = 33, number3 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
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

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	int value = 30;
	LinkedList filtered = filter(list, isGreater, &value);

	void *value1 = getElementAt(filtered, 0);
	assert(_TYPEINT_(value1) == 33);

	void *value2 = getElementAt(filtered, 1);
	assert(_TYPEINT_(value2) == 44);
};

void test_reverse_using_traverse_int(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	traverse_int(reverse_list);
	void *reverse_val = getElementAt(reverse_list, 0);

	assert(_TYPEINT_(reverse_val) == 23);
};

void test_reverse_using_getElementAt(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	void *get_reverse_ele = getElementAt(reverse_list, 1);
	assert(_TYPEINT_(get_reverse_ele) == 44);

	void *get_reverse_ele2 = getElementAt(reverse_list,3);
	assert(_TYPEINT_(get_reverse_ele2) == 33);

	void *get_reverse_ele3 = getElementAt(reverse_list, 2);
	assert(_TYPEINT_(get_reverse_ele3) == 23);
};

void test_reverse_using_getFirstElement(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	void *get_reverse_ele = get_first_element(reverse_list);
	assert(_TYPEINT_(get_reverse_ele) == 23);	
};

void test_reverse_using_getLastElement(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	LinkedList reverse_list = reverse(list);
	void *get_reverse_ele = get_last_element(reverse_list);
	assert(_TYPEINT_(get_reverse_ele) == 12);	
};

void test_length_of_reverse_int_should_be_same(){
	LinkedList list = createList();

	int number = 12, number2 = 23, number3 = 47, number4 = 21;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);

	LinkedList reverse_list = reverse(list);
	assert(reverse_list.length == 4);

};

void test_map_using_traverse_int(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	int value = 2;
	LinkedList map_element = map(list, sum, &value);
	traverse_int(map_element);
};

void test_map_using_getElement(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	int value = 2;
	LinkedList map_element = map(list, sum, &value);

	void *map_ele = getElementAt(map_element, 0);
	assert(_TYPEINT_(map_ele) == 14);

	void *map_ele2 = getElementAt(map_element, 2);
	assert(_TYPEINT_(map_ele2) == 25);

	void *map_ele3 = getElementAt(map_element, 4);
	assert(_TYPEINT_(map_ele3) == 25);
};

void test_reduce_using_traverse_int(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);
int hint = 0;
	int value = 0;
	LinkedList reduce_list = reduce(list, average_of_sum, &hint, &value);
	traverse_int(reduce_list);
};

void test_reduce_using_getElement(){
	LinkedList list = createList();

	int number = 12, number2 = 33, number3 = 23, number4 = 44, number5 = 23;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);
	add_to_list(&list, &number5);

	int hint = 0;
	int value = 0;

	LinkedList reduce_list = reduce(list, average_of_sum, &hint, &value);
	void *reduce_ele = getElementAt(reduce_list, 0);
	assert(_TYPEINT_(reduce_ele) == 135);
};

void test_length_reduce_should_be_one(){
	LinkedList list = createList();

	int number = 12, number2 = 23, number3 = 47, number4 = 21;
	add_to_list(&list, &number);
	add_to_list(&list, &number2);
	add_to_list(&list, &number3);
	add_to_list(&list, &number4);

	int hint = 0;
	int value = 0;

	LinkedList reduce_list = reduce(list, average_of_sum, &hint, &value);
	assert(reduce_list.length == 1);

};

//================================char test==============================================//

void test_reverse_for_char_using_traverse_char(){
	LinkedList list = createList();

	char a = 'p', b = 'q', c = 'r';
	add_to_list(&list, &a);
	add_to_list(&list, &b);
	add_to_list(&list, &c);

	LinkedList reverse_char_list = reverse(list);
	traverse_char(reverse_char_list);

};

void test_reverse_for_char_using_getElementAt(){
	LinkedList list = createList();

	char a = 'p', b = 'q', c = 'r';
	add_to_list(&list, &a);
	add_to_list(&list, &b);
	add_to_list(&list, &c);

	LinkedList reverse_char_list = reverse(list);

	void *char_ele = getElementAt(reverse_char_list, 0);
	assert(_TYPECHAR_(char_ele) == 'r');

	void *char_ele2 = getElementAt(reverse_char_list, 1);
	assert(_TYPECHAR_(char_ele2) == 'q');

	void *char_ele3 = getElementAt(reverse_char_list, 2);
	assert(_TYPECHAR_(char_ele3) == 'p');
};

void test_length_of_reverse_char_should_be_same(){
	LinkedList list = createList();

	char a = 'p', b = 'q', c = 'r';
	add_to_list(&list, &a);
	add_to_list(&list, &b);
	add_to_list(&list, &c);

	LinkedList reverse_char_list = reverse(list);
	assert(reverse_char_list.length == 3);
};

void test_forEach_for_char(){
	LinkedList list = createList();
	char char1 = 's', char2 = 'q', char3 = 'r';
	add_to_list(&list, &char1);
	add_to_list(&list, &char2);
	add_to_list(&list, &char3);

	forEach(list, convertChar);
	assert(_TYPECHAR_(list.first->value) == 't');
	traverse_int(list);
	assert(_TYPECHAR_(list.last->value) == 't');
};

void test_deleteElementAt_forChar(){
	LinkedList list = createList();
	char char1 = 'p',char2 = 'q', char3 = 'r', char4 = 's';

	add_to_list(&list, &char1);
	add_to_list(&list, &char2);
	add_to_list(&list, &char3);
	add_to_list(&list, &char4);

	void *delete_element = deleteElementAt(&list, 2);
	assert(_TYPECHAR_(delete_element) == 'r');

	void *ele = getElementAt(list,2);
	assert(_TYPECHAR_(ele) == 's');
}

void test_deleteElementAt_forChar_for_null_element(){
	LinkedList list = createList();
	void *delete_element = deleteElementAt(&list, 1);

	assert(delete_element == NULL);
	assert(list.length == 0);
};

void test_deleteElementAt_forChar_if_listLength_one(){
	LinkedList list = createList();
	char value = 'p';
	add_to_list(&list, &value);

	assert(list.length == 1);

	void *delete_element = deleteElementAt(&list, 0);
	assert(_TYPECHAR_(delete_element) == 'p');

	void *ele = getElementAt(list,0);
	assert(list.length == 0);
	assert(ele == NULL);
};

void test_deleteElementAt_forChar_if_indexNotRange(){
	LinkedList list = createList();
	char char1 = 'p',char2 = 'q', char3 = 'r';

	add_to_list(&list, &char1);
	add_to_list(&list, &char2);
	add_to_list(&list, &char3);

	void *delete_element = deleteElementAt(&list, 3);
	assert(delete_element == NULL);
};

void test_deleteElementAt__forChar_for_lastElement(){
	LinkedList list = createList();
	char char1 = 'p',char2 = 'q', char3 = 'r';

	add_to_list(&list, &char1);
	add_to_list(&list, &char2);
	add_to_list(&list, &char3);

	void *delete_element = deleteElementAt(&list, 2);
	assert(_TYPECHAR_(delete_element) == 'r');

	void *ele = getElementAt(list,1);
	assert(_TYPECHAR_(ele) == 'q');
	assert(list.length == 2);
};





//==============================float test==========================================================//
void test_reverse_for_float_using_traverse_float(){
	LinkedList list = createList();

	float float_point = 12.01,float_point2 = 32.21, float_point3 = 45.65, float_point4 = 76.32;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);
	add_to_list(&list, &float_point4);

	LinkedList reverse_float_list = reverse(list);
	traverse_float(reverse_float_list);
};

void test_reverse_for_float_using_getElementAt(){
	LinkedList list = createList();

	float float_point = 12.01,float_point2 = 32.21, float_point3 = 45.65, float_point4 = 76.32;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);
	add_to_list(&list, &float_point4);

	LinkedList reverse_float_list = reverse(list);

	float f_valAfterReverse = 76.32;
	void *float_ele = getElementAt(reverse_float_list, 0);
	assert(_TYPEFLOAT_(float_ele) == f_valAfterReverse);

	void *float_ele2 = getElementAt(reverse_float_list, 2);
	float t_valAfterReverse = 32.21;
	assert(_TYPEFLOAT_(float_ele2) == t_valAfterReverse);

	float l_valAfterReverse = 12.01;
	void *float_ele3 = getElementAt(reverse_float_list, 3);
	assert(_TYPEFLOAT_(float_ele3) == l_valAfterReverse);

};

void test_length_of_reverse_float_should_be_same(){
	LinkedList list = createList();

	float float_point = 12.01,float_point2 = 32.21, float_point3 = 45.65, float_point4 = 76.32;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);
	add_to_list(&list, &float_point4);

	LinkedList reverse_float_list = reverse(list);
	assert(reverse_float_list.length == 4);
	assert(reverse_float_list.length == list.length);	
};

void test_add_float_if_list_has_oneElement(){
	LinkedList list = createList();
	float float_point = 23.235;
	int length = add_to_list(&list, &float_point);

	assert(length == 1);
	assert(_TYPEFLOAT_(list.first->value) == _TYPEFLOAT_(list.last->value));

	float firstValue = 23.235;
	assert(_TYPEFLOAT_(list.first->value) == firstValue);
};

void test_firstElement_and_lastElement_of_list_float(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 33.32;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);

	float l_valAfterReverse = 33.32;
	assert(_TYPEFLOAT_(list.first->value) == 44.5);
	assert(_TYPEFLOAT_(list.last->value) == l_valAfterReverse);
};

void test_first_last_float_should_not_be_same_if_lengthNotOne(){
	LinkedList list = createList();
	float float_point = 12.212, float_point2 = 33.4565, float_point3 = 23.0099, float_point4 = 44.321, float_point5 = 23.322;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);
	add_to_list(&list, &float_point4);
	add_to_list(&list, &float_point5);

	assert(_TYPEFLOAT_(list.first->value) != _TYPEFLOAT_(list.last->value));
};

void test_forEach_forFloat(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 32.145, float_point3 = 23.0987;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);

	forEach(list, increaseFloat);

	float f_valAfterforEach = 44.59;
	float l_valAfterforEach = 23.1887;
	assert(_TYPEFLOAT_(list.first->value) == f_valAfterforEach);
	traverse_int(list);
	assert(_TYPEFLOAT_(list.last->value) == l_valAfterforEach);
};

void test_forEach_forFloat_using_getElement(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 32.145, float_point3 = 23.0987;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);

	forEach(list, increaseFloat);

	float f_valAfterforEach = 44.59;
	float t_valAfterforEach = 23.1887;

	void *forEach_ele = getElementAt(list, 0);
	assert(_TYPEFLOAT_(forEach_ele) == f_valAfterforEach);

	void *forEach_ele2 = getElementAt(list, 2);
	assert(_TYPEFLOAT_(forEach_ele2) == t_valAfterforEach);
};

void test_forEach_if_indexDoesnotExist(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 32.145;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);

	forEach(list, increaseFloat);
	void *forEach_ele3 = getElementAt(list, 4);
	assert(forEach_ele3 == NULL);
};

void test_indexOf_forFloat(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 32.145, float_point3 = 23.0987,float_point4 = 3421.24;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);
	add_to_list(&list, &float_point4);

	float value = 32.145;
	int index_of_element = indexOf(list, &value);
	assert(index_of_element == 1);

	float value2 = 3421.24;
	int index = indexOf(list, &value2);
	assert(index == 3);
};

void test_deleteElementAt_forFloat(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 32.145, float_point3 = 23.0987,float_point4 = 3421.24;

	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);
	add_to_list(&list, &float_point4);

	float deleted_ele = 23.0987;
	void *delete_element = deleteElementAt(&list, 2);
	assert(_TYPEFLOAT_(delete_element) == deleted_ele);

	float s_index_ele = 3421.24;
	void *ele = getElementAt(list,2);
	assert(_TYPEFLOAT_(ele) == s_index_ele);
}

void test_deleteElementAt_forFloat_for_null_element(){
	LinkedList list = createList();
	void *delete_element = deleteElementAt(&list, 1);

	assert(delete_element == NULL);
	assert(list.length == 0);
};

void test_deleteElementAt_forFloat_if_listLength_one(){
	LinkedList list = createList();
	float number = 23.43;
	add_to_list(&list, &number);

	assert(list.length == 1);

	float deleted_ele = 23.43;
	void *delete_element = deleteElementAt(&list, 0);
	assert(_TYPEFLOAT_(delete_element) == deleted_ele);

	void *ele = getElementAt(list,0);
	assert(list.length == 0);
	assert(ele == NULL);
};

void test_deleteElementAt_forFloat_if_indexNotRange(){
	LinkedList list = createList();

	float float_point = 44.5, float_point2 = 32.145, float_point3 = 23.0987;
	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);

	void *delete_element = deleteElementAt(&list, 3);
	assert(delete_element == NULL);
};

void test_deleteElementAt__forFloat_for_lastElement(){
	LinkedList list = createList();
	float float_point = 44.5, float_point2 = 32.145, float_point3 = 23.0987;

	add_to_list(&list, &float_point);
	add_to_list(&list, &float_point2);
	add_to_list(&list, &float_point3);

	float deleted_ele = 23.0987;
	float f_index_ele = 32.145;
	void *delete_element = deleteElementAt(&list, 2);
	assert(_TYPEFLOAT_(delete_element) == deleted_ele);

	void *ele = getElementAt(list,1);
	assert(_TYPEFLOAT_(ele) == f_index_ele);
	assert(list.length == 2);
};

