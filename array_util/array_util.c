#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"


ArrayUtil create(int typeSize, int length){
		ArrayUtil *arr = (ArrayUtil *)calloc(length,length*typeSize);
		arr->base = (char *)arr;
		arr->typeSize = typeSize;
		arr->length = length;	
		return *arr;
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



