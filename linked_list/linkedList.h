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