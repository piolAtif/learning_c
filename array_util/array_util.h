typedef struct{
	void *base;
	int typeSize;
	int length;
	int used_length;
}ArrayUtil;


int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil create(int, int);
ArrayUtil resize(ArrayUtil *, int);
void dispose(ArrayUtil *);
void insert_element(ArrayUtil *, void *, int);
int find_index(ArrayUtil , void *);
