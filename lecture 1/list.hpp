class List {
	public:
	virtual void add(int) = 0;
 	virtual void print() = 0;
 	virtual int size() = 0;
 	virtual void addFirst(int) = 0;
 	//virtual void addLast is the same us the add(int)
 	virtual void removeLast() = 0;
 	virtual void removeFirst() = 0;
 	virtual void addPosition(int, int) = 0;
 	virtual void removePosition(int) = 0;
 	virtual void sortedNumbers() = 0;
};