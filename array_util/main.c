#include <stdio.h>
#include "util_test.h"

int main(){
	
	test_array();
	test_resize_array();
	test_equal_array_function();
	test_not_equal_array();
	test_dispose();
	find_index_test();
	test_find_first();
	test_find_last();
	count_element_test();

	return 0;
}