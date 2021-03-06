#include <stdio.h>
#include <stdlib.h>
#include "array_util.h"
#include <string.h>


ArrayUtil create(int typeSize, int length){
		ArrayUtil *util_arr = (ArrayUtil *)malloc(length*typeSize);
		util_arr->base = (void *)calloc(length,typeSize);
		util_arr->typeSize = typeSize;
		util_arr->length = length;	
		util_arr->used_length = 0;
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

void dispose(ArrayUtil *util){
	free(util->base);
};

void insert_element(ArrayUtil * util, void * element,int index){
	void *base = ((util->base)+((util->typeSize)*index));
	memcpy(base, element, util->typeSize);
};

int find_index(ArrayUtil util,void *element){
	for (int i = 0; i < util.length; ++i){
		if(memcmp(util.base+(i*util.typeSize), element, util.typeSize)==0)
			return i;
	}
	return -1;
};

void *find_first(ArrayUtil util, MatchFunc *match, void *hint){
	for (int i = 0; i < util.length; ++i)
	{
		void *item = util.base+(i*util.typeSize);
		if (match(hint, item))
		{
			return item;
		}
	}
	return NULL;
};

void *find_last(ArrayUtil util, MatchFunc *match, void *hint){
	void *item;
	for (int i = util.length; i > 0 ; i--)
	{
		item = util.base+(i*util.typeSize);
		if(match(hint, item)){
			return item;
		}
	}
	return NULL;
};

int count(ArrayUtil util, MatchFunc *match, void * hint){
	void *item;
	int count = 0;
	for (int i = 0; i < util.length; i++)
	{
		item = util.base+(i*util.typeSize);
		if(match(hint, item)){
			count++;
		}
	}
	return count;
};

int filter(ArrayUtil util, MatchFunc *match, void * hint, void** destination, int maxItem){
	void *item;
	int length = 0;
	for (int i = 0; i < util.length; ++i)
	{
		item = util.base+(i*util.typeSize);
		if(match(hint ,item) && (maxItem>length)){
		destination = item;
			length++;
		}	
	}
	return length;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc *convert, void *hint){
	void *source_item;
	void *destination_item;
	for (int i = 0; i < source.length; ++i)
	{
		source_item = source.base+(i*source.typeSize);
		destination_item = destination.base+(i*destination.typeSize);
		convert(hint, source_item, destination_item);
	}
};

void forEach(ArrayUtil util, OperationFunc *operation, void *hint){
	void *item;
	for (int i = 0; i < util.length; ++i)
	{
		item = util.base+(i*util.typeSize);
		operation(hint, item);
	}
};

void *reduce(ArrayUtil util, ReducerFunc *reducer, void *hint, void *initialValue){
	void *previousItem;
	for (int i = 0; i < util.length; ++i)
	{
		previousItem = util.base+(i*util.typeSize);
		reducer(hint, previousItem, initialValue);
	}
	return initialValue;
}
