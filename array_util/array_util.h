typedef struct{
	void *base;
	int typeSize;
	int length;
}ArrayUtil;

int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil create(int, int);
ArrayUtil resize(ArrayUtil *, int);
void dispose(ArrayUtil *);
