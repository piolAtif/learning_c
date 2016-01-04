#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"


ArrayUtil create(int typeSize, int length){
		ArrayUtil *util_arr = (ArrayUtil *)calloc(length,length*typeSize);
		util_arr->base = (char *)util_arr;
		util_arr->typeSize = typeSize;
		util_arr->length = length;	
		return *util_arr;
};

int areEqual(ArrayUtil a,ArrayUtil b){
	if(a.length == b.length){
		if(a.typeSize == b.typeSize)
		return 1;
	}
	return 0;
};

ArrayUtil resize(ArrayUtil *util, int len){
	util->length = len;
	return *util;
};



