#pragma once
#include <stdlib.h>

typedef struct LL {
	struct LL *nxt;
	void* val;
}LL;

/* Initialize a linked list pointer with a given value. The list is initialized with malloc,
 * so the list will eventually have to be freed before the end of the program is reached. The
 * pointer for the next link is set to NULL, which the list always takes to mean that said 
 * link is the end of the list.
 */
LL *initLinkedList(void* val)
{
	LL *ll = (LL*)malloc(sizeof(LL));
	ll->nxt = NULL;
	ll->val = val;
	return ll;
}

/* Frees every link in the list sequentially. This method assumes that the only methods used
 * to instatiate the list were the ones provided here, or malloc. 
 */
void freeLinkedList(LL* start)
{
	LL *t = start;
	while(t->nxt)
	{
		start = t->nxt;
		free(t);
		t=start;
	}
}

/* Adds an element to the back of the list.
 */
void pushBackLinkedList(LL *start, void* val)
{
	LL *t = start;
	while(t->nxt != NULL)
		t = t->nxt;
	LL *nxt = initLinkedList(val);
	t->nxt = nxt;
}

/* Adds a link to the list at a certain index, pushing back the rest on the links.
 */
LL* insertLinkedList(LL *start, int index, void* val)
{
	LL *t = start;
	for(int i = 0; i < index - 1; i++)
	{
		if(t->nxt != NULL)
			t = t->nxt;
		else
			break;
	}
	LL *nxt = t->nxt;
	LL *insert = initLinkedList(val);
	t->nxt = insert;
	insert->nxt = nxt;
	if(index == 0)
		return insert;
	return start;
}


/* Returns the amount of links in the list.
 */
int linkedListSize(LL *start)
{
	if(start == NULL)
		return 0;
	LL *t = start;
	int count = 1;
	while(t->nxt != NULL)
	{
		t = t->nxt;
		count++;
	}
	return count;
}

/* Returns the value stored at a specific index in the list.
 */
void* getLink(LL *start, int index)
{
	LL *t = start;
	for(int i = 0; i < index; i++)
	{
		if(t->nxt == NULL)
			break;
		t = t->nxt;
	}
	return t->val;
}

/* Removes a link from the list, and relinks the proceeding and preceeding links to each 
 * other to preserve continuity.
 */
void deleteLink(LL *start, int index)
{
	LL *t = start, *t2;
	for(int i = 0; i < index - 1; i++)
	{
		if(t == NULL)
			return;
		t=t->nxt;
	}
	t2 = t;
	t = t->nxt;
	t2->nxt = t->nxt;
	free(t);
}

/* Sets the value of a specific link to given value.
 */
void setLink(LL *start, int index, void* val)
{
	LL *t = start;
	for(int i = 0; i < index; i++)
	{
		t = t->nxt;
		if(t == NULL)
			return;
	}
	t->val = val;
}

/* Gets the first value in the list. Basically useless, but whatever.
 */
void* frontLink(LL *start)
{
	return start->val;
}

/* Deletes the last link in the list.
 */
void popBackLinkedList(LL *start)
{
	LL *t = start, *t2;
	while(t->nxt)
	{
		t2 = t;
		t = t->nxt;
	}
	t2->nxt = NULL;
	free(t);
}

/* Returns the last link in the list.
 */
void* backLink(LL *start)
{
	LL *t = start;
	while(t->nxt)
		t=t->nxt;
	return t->val;
}

/* Returns the pointer to the link at the given index. If the index is greater than the size of the
 * list, returns a pointer to the last link in the list. If the index is less than 0, returns a
 * pointer to the first element, which is essentialy the pointer already passed to the method by the
 * "start" parameter.
 */ 
LL* linkPointer(LL *start, int index)
{
	LL *t = start;
	for(int i = 0; i < index && t->nxt; i++)
	{
		t =  t->nxt;
	}
	return t;
}

/* Swaps the contents of two links at separate (or equal indexes.
 */
void swapLink(LL *start, int index1, int index2)
{
	LL *t1 = linkPointer(start, index1),
	       *t2 = linkPointer(start, index2);
	void* n1 = t1->val,
	    *n2 = t2->val;
	t1->val = n2;
	t2->val = n1;
}