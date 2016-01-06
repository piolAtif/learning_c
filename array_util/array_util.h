typedef int(MatchFunc)(void *, void *);

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
void *find_first(ArrayUtil, MatchFunc *, void *);
void *find_last(ArrayUtil, MatchFunc *, void *);
int isEven(void *, void *);
int isDivisible(void *, void *);
int count(ArrayUtil, MatchFunc *, void *);

int filter(ArrayUtil, MatchFunc *, void *, void **, int);