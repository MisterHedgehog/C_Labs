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
// ������� �������� �������
Queue * createQueue();
// ������� �������� ��������
Item * createItem(Element*);
// ������� ���������� �������
void pushElement(Queue*, Element*);
// ������� ������� �������� �� �������
Element * popElement(Queue*);