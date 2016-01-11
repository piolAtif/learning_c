typedef struct{
	void *next;
	void *value;
}Elements;

typedef struct{
	Elements *first;
	Elements *last;
	int length;
}LinkedList;

LinkedList createList(void);