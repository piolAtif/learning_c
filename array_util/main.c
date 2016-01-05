#include <stdio.h>
#include "array_util.h"
#include <assert.h>

void test_array(ArrayUtil util){
	assert(util.length == 3);
	assert(util.typeSize == 1);
};

void test_resize_array(ArrayUtil resize_util){
	assert(resize_util.length == 4);
	assert(resize_util.typeSize == 1);
};

void test_equal_array(int equal_arr){
	assert(equal_arr);
};

void test_not_equal_array(int not_equal){
	assert(!not_equal);
};

void test_dispose(ArrayUtil util, ArrayUtil pre_util){
	assert(util.base != pre_util.base);
	assert(util.base == NULL);
}

int main(){
	ArrayUtil util_a = create(1,3);
	test_array(util_a);
	
	resize(&util_a,4);
	test_resize_array(util_a);

	ArrayUtil util_b = create(1,4);
	int equal_array = areEqual(util_a,util_b);	
	test_equal_array(equal_array);

	ArrayUtil util_c = create(4,4);
	int not_equal_array = areEqual(util_b,util_c);
	test_not_equal_array(not_equal_array);

	ArrayUtil prev_util_a = util_a;
	dispose(&util_a);

	test_dispose(util_a, prev_util_a);

	return 0;
}