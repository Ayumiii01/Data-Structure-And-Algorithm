class List {
	public: 
		virtual void add(int) = 0;
		virtual void addFirst(int) = 0;
		virtual void addAt(int, int) = 0;
		virtual void remove() = 0;
		virtual void removeFirst() = 0;
		virtual void removeAt(int) = 0;
		virtual int removeAll(int) = 0;
		virtual void print() = 0;
};