#include <stdio.h>
#include <assert.h>
#include "array_util.h"

void test_array(){
	ArrayUtil util_a = create(1,3);
	assert(util_a.length == 3);
	assert(util_a.typeSize == 1);
};

void test_resize_array(){
	ArrayUtil resize_util= create(1,3);
	resize(&resize_util,4);
	assert(resize_util.length == 4);
	assert(resize_util.typeSize == 1);
};

void test_equal_array_function(){
	ArrayUtil util_a = create(1,3);
	ArrayUtil util_b = create(1,3);
	int equal_arr = areEqual(util_a,util_b);	
	assert(equal_arr);
};

void test_not_equal_array(){
	ArrayUtil util_b = create(1,4);
	ArrayUtil util_c = create(4,4);
	int not_equal_arr = areEqual(util_b,util_c);
	assert(!not_equal_arr);
};

void test_dispose(){
	ArrayUtil util_to_dispose= create(1,3);
	dispose(&util_to_dispose);
	assert(*(int *)(util_to_dispose.base) == 0);
};

void find_index_test(){
	ArrayUtil util_a = create(1,3);
	resize(&util_a,7);
	int a = 3, b = 5, c = 40, d = 2, e = 19, f = 27;
	insert_element(&util_a,&a,0);
	insert_element(&util_a,&b,1);
	insert_element(&util_a,&c,2);
	insert_element(&util_a,&d,4);
	insert_element(&util_a,&e,3);
	insert_element(&util_a,&f,6);

	int x = 19, y = 27, z = 5;
	void *element;
	element = &x;
	int index1 = find_index(util_a, element);

	element = &y;
	int index2 = find_index(util_a, element);

	element = &z;
	int index3 = find_index(util_a,element);

	assert(index1 == 3);
	assert(index2 == 6);
	assert(index3 == 1);

};

void test_find_first(){
	ArrayUtil util_a = create(4,7);
	int a = 9, b = 12, c = 40, d = 2, e = 19, f = 27;
	insert_element(&util_a,&a,0);
	insert_element(&util_a,&b,1);
	insert_element(&util_a,&c,2);
	insert_element(&util_a,&d,4);
	insert_element(&util_a,&e,3);
	insert_element(&util_a,&f,6);

	void *hint = NULL;

	int *first = (int *)find_first(util_a, isEven, hint);
	assert(*first == 12);

	int number = 5;
	void *hint1 = &number;
	int *second = (int *)find_first(util_a, isDivisible, hint1);
	assert(*second == 40);

};

