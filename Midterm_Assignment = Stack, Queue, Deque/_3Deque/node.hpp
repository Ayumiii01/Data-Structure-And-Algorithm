struct node {
	int elem;
	node* next;
	node* prev;
	
	node(int e) : elem(e), next(nullptr), prev(nullptr) { }
};