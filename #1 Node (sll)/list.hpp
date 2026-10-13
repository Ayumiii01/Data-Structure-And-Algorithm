class List { // List ADT
	public:
	virtual void add(int) = 0;
	virtual void insertAtHead(int) = 0;
	virtual void insertAtTail(int) = 0;   // same behavior as add()
	virtual void removeFirst() = 0;
	virtual void removeLast() = 0;
	virtual void print() = 0;
	virtual int size() = 0;
};