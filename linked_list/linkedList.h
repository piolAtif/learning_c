typedef int (MatchFunc)(void *, void *);
typedef void (ConvertFunc)(void *, void *, void *);
typedef void *(Reducer)(void *, void *, void *);

typedef struct{
	void *next;
	void *value;
}Elements;

typedef struct{
	Elements *first;
	Elements *last;
	int length;
}LinkedList;

typedef void (*ElementProcessor)(void *);

LinkedList createList(void);
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void forEach(LinkedList, ElementProcessor);
void traverse(LinkedList);
void *getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int maxElements);
LinkedList filter(LinkedList, MatchFunc, void *);
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void * );
LinkedList reduce(LinkedList, Reducer, void *, void *);