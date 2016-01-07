#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "array_util.h"

int isEven(void *hint, void *item){
	int number = *(int *)item;
	if(number == 0) return 0;
	return (number%2 == 0);
};

int isDivisible(void *hint, void *item){
	int dividend = *(int *)item;
	int divisor = *(int *)hint;
	if(dividend == 0)return 0;
	return (dividend%divisor == 0); 
};

int isMathChar(void *hint, void *item){
	char forMatching = *(char *)hint;
	char toMatching = *(char *)item;

	return(forMatching-toMatching == 0); 
};

void add_function(void *hint, void *source_item,void *destination_item){
	int addend = *(int *)hint;
	int augend = *(int *)source_item;
	int sum = addend+augend;
	*(int *)destination_item = sum;
};

void multiply_power(void *hint, void *item){
	int number = *(int *)item;
	int power = *(int *)hint;
	int mutliplying = 1;
	for (int i = 0; i < power; ++i)
	{
		mutliplying = mutliplying * number;
	}
	*(int *)item = mutliplying;
};

void *sum_of_element(void *hint, void *previousItem, void *item){
	
	*(int *)item = *(int *)item +*(int *)previousItem;
	return item;
;};

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


//==========================test for integer elements array==================================


void test_find_index_for_int(){
	ArrayUtil util_a = create(4,7);
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

void insert_element_in_util(ArrayUtil util){
	int a = 9, b = 12, c = 40, d = 2, e = 19, f = 27;
	insert_element(&util,&a,0);
	insert_element(&util,&b,1);
	insert_element(&util,&c,2);
	insert_element(&util,&d,4);
	insert_element(&util,&e,3);
	insert_element(&util,&f,6);	
};

void test_find_first_if_isEven(){
	ArrayUtil util_a = create(4,7);
	insert_element_in_util(util_a);
	void *hint = NULL;
	int *first = (int *)find_first(util_a, &isEven, hint);
	assert(*first == 12);
};

void test_find_first_if_isDivisible(){
	ArrayUtil util_a = create(4,7);
	insert_element_in_util(util_a);
	int number = 5;
	void *hint = &number;
	int *first_element = (int *)find_first(util_a, &isDivisible, hint);
	assert(*first_element == 40);
}


void test_find_last_if_isEven(){
	ArrayUtil util_a = create(4,7);
	insert_element_in_util(util_a);
	void *hint = NULL;
	int *last = (int *)find_last(util_a, &isEven, hint);
	assert(*last == 2);
};

void test_find_last_if_isDivisible(){
	ArrayUtil util_a = create(4,7);
	insert_element_in_util(util_a);
	int number = 3;
	void *hint = &number;
	int *last2 = (int *)find_last(util_a, &isDivisible, hint);
	assert(*last2 == 27);
}; 

void insert_element_for_count(ArrayUtil util){
	int a = 9, b = 12, c = 40, d = 2, e = 19, f = 27, g = 15;
	insert_element(&util,&a,0);
	insert_element(&util,&b,1);
	insert_element(&util,&c,2);
	insert_element(&util,&d,4);
	insert_element(&util,&e,3); 
	insert_element(&util,&f,6);
	insert_element(&util,&g,7);
};

void test_count_element_if_isEven(){
	ArrayUtil util = create(4,8);
	insert_element_for_count(util);
	void *hint = NULL;
	int sum_of_match_element  = count(util, &isEven, hint);
	assert(sum_of_match_element == 3);
};

void test_count_element_if_isDivisible(){
	ArrayUtil util = create(4,8);
	insert_element_for_count(util);
	int number = 3;
	void *hint = &number;
	int sum_of_divisible_element = count(util, &isDivisible, hint);
	assert(sum_of_divisible_element == 4);
};

void insert_element_for_filter(ArrayUtil util){
	int a = 10, b = 12, c = 40, d = 2, e = 19, f = 27, g = 15;
	insert_element(&util,&a,0);
	insert_element(&util,&b,1);
	insert_element(&util,&c,2);
	insert_element(&util,&d,4);
	insert_element(&util,&e,3); 
	insert_element(&util,&f,6);
	insert_element(&util,&g,7);
};

void test_filter_if_isEven(){
	ArrayUtil util = create(4,8);
	int maxItem = 5;
	ArrayUtil arr = create(util.typeSize,maxItem);
	insert_element_for_filter(util);

	void *hint = NULL;
	int filter_elements = filter(util, &isEven, hint, arr.base, maxItem);
	assert(filter_elements = 4);
};

void test_filter_if_isDivisible(){
	ArrayUtil util = create(4,8);
	int maxItem = 5;
	ArrayUtil arr = create(util.typeSize,maxItem);
	insert_element_for_filter(util);

	int number = 3;
	void *hint1 = &number;
	int filter_divisible_element = filter(util, &isDivisible, hint1, arr.base, maxItem);
	assert(filter_divisible_element == 3);	
};

void test_int_map(){
	ArrayUtil source_util = create(4,8);
	insert_element_for_filter(source_util);

	ArrayUtil dest_util = create(4,8);

	int number = 2;
	void *hint = &number;
	map(source_util, dest_util, &add_function, hint);

	assert(*(int *)(dest_util.base)-*(int *)(source_util.base) == 2);
	assert(*(int *)source_util.base + 2 == *(int *)(dest_util.base));

};

void test_int_forEach(){
	ArrayUtil util = create(4,4);
	int a =3,b = 2, c = 1, d = 4;
	insert_element(&util,&a,0);
	insert_element(&util,&b,1);
	insert_element(&util,&c,2);
	insert_element(&util,&d,3);

	int number = 3;
	void *hint = &number;
	forEach(util, &multiply_power, hint);

	assert(*(int *)util.base == 27);
	assert(b != 8);
	assert(d == 4);
};

void test_int_reduce(){
	printf("hello\n");
	ArrayUtil util = create(4,4);
	int a =3,b = 2, c = 1, d = 4;
	insert_element(&util,&a,0);
	insert_element(&util,&b,1);
	insert_element(&util,&c,2);
	insert_element(&util,&d,3);

	int value = 0;
	void *initial_val = &value;
	void *hint = NULL;

	int *result = (int *)reduce(util,&sum_of_element, hint, initial_val);
	printf("%d\n", *result);
	assert(*result == 10);

}

//===================================test for character elements in array=========================================

void insert_element_char(ArrayUtil char_util){
	char a ='p', b = 'q', c = 'r', d = 's', e = 't';
	insert_element(&char_util,&a,0);
	insert_element(&char_util,&b,1);
	insert_element(&char_util,&c,2);
	insert_element(&char_util,&d,3);
	insert_element(&char_util,&e,4);
}

void test_find_index_for_char(){
	ArrayUtil char_util = create(1,5);
	insert_element_char(char_util);

	char find = 'q';
	void *find_ptr = &find;
	int index = find_index(char_util, find_ptr);

	assert(index == 1);
};

void insert_element_to_match(ArrayUtil char_util){
	char a ='p', b = 'r', c = 'r', d = 's', e = 't';
	char f ='r',g = 'q',h = 'p',i = 'u',j = 'r';
	insert_element(&char_util,&a,0);
	insert_element(&char_util,&b,1);
	insert_element(&char_util,&c,2);
	insert_element(&char_util,&d,3);
	insert_element(&char_util,&e,4);
	insert_element(&char_util,&f,5);
	insert_element(&char_util,&g,6);
	insert_element(&char_util,&h,7);
	insert_element(&char_util,&i,8);
	insert_element(&char_util,&j,9);
};

void test_count_match_char(){
	ArrayUtil elements = create(1,10);
	insert_element_to_match(elements);

	char single_char = 'r';
	void *hint = &single_char;
	int count_char = count(elements, &isMathChar, hint);
	assert(count_char == 4);

	char second_char = 'p';
	void *hint1 = &second_char;
	count_char = count(elements, &isMathChar, hint1);
	assert(count_char == 2);
};


