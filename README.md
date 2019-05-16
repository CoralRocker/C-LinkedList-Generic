# C-LinkedList

# Accessor Methods
|Method|Usage|
|:-:|:-|
|int linkedListSize(LL *start)|linkedListSize(ll) where ll is the linkedList start. Returns the amount of links in the list.
|void* getLink(LL *start, int index)|getLink(ll, index) where ll is the linkedList start, and index is the index. Returns the value held by the link. If the pointer directly to the link is desired, the `LL* linkPointer(LL *start, int index)` method should be used.|
|void* frontLink(LL *start)|frontLink(ll) where ll is the linkedList start. Returns the first link in the list.|
|void* backLink(LL *start)|backLink(ll) where ll is the linkedList start. Returns the last link in the list.|
|LL* linkPointer(LL *start, int index)|linkPointer(ll, index) where ll is the linkedList start, and index is the index. Returns the pointer to requested link.|

# Modifier Methods
|Method|Usage|
|:-:|:-|
|void insertLinkedList(LL *start, int index, void* val)|insertLinkedList(ll, index, yourNum) where ll is the linkedList start, index is the index, and yourNum is the value to place. Places a new link into the list at a given index, and relinks list in order to preserve continuity.|
|void pushBackLinkedList(LL *start, void* val)|pushBackLinkedList(ll, yourNum) where ll is the linkedList start, and yourNum is the value to place. Adds given value to a new link at the back of the list.|
|void popBackLinkedList(LL *start)|popBackLinkedList(ll) where ll is the linkedList start. Removes the last link from the list.|
|void deleteLink(LL *start, int index)|deleteLink(ll, index) where ll is the linkedList start, and index is the index. Removes the link at the given index. Relinks list for continuity.|
|void setLink(LL *start, int index, void* val)|setLink(ll, index, yourNum) where ll is the linkedList start, index is the index, and yourNum is the value to place. Updates the given link to hold the given value.|
|void swapLink(LL *start, int index1, int index2)|swapLink(ll, index1, index2) where ll is the linkedList start, and the indeces are indeces. Swaps the value held by the links in each of the indeces. |

# Creating a Linked List
Linked Lists should be created by using the provided `LL* initLinkedList(void* val)` method and manipulated using the given methods to ensure that no undocumented behavior occurs. The `void freeLinkedList(LL* start)` method is provided to free memory used by the list.

# More information
The header file is thoroughly commented, and contains more insights on the uses and quirks of each method in its headings and comments.