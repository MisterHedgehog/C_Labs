typedef struct Element {
	int data;
	struct Element* left;
	struct Element* right;
	int position;
	int level;
} Element;
typedef struct Item {
	Element * data;
	struct Item* next;
} Item;
typedef struct Queue {
	Item* head;
	Item* tail;
} Queue;
// Функция создания очереди
Queue * createQueue();
// Функция создания элемента
Item * createItem(Element*);
// Функция заполнения очереди
void pushElement(Queue*, Element*);
// Функция изъятия элемента из очередь
Element * popElement(Queue*);