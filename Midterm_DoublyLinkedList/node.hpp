struct node {
	int elem;
	node* next;
	node* prev;
	
	node(int e) : elem(e), next(NULL), prev(NULL) { }
};