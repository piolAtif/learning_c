#include <assert.h>
#include "linkedList.h"

void test_create_linked_list(){
	LinkedList list = createList();
	assert(list.first == list.last);
	assert(list.first == NULL);
	assert(list.last == NULL);
	assert(list.length == 0);
};	