struct node {
	int elem;
	node* parent;
	node* left;
	node* right;

	node(int e) : elem(e), parent(nullptr), left(nullptr), right(nullptr) {}

	node(int e, node* p) : elem(e), parent(p), left(nullptr), right(nullptr) {}
};