class List {
	public:
		virtual void add(int num) = 0; 
		virtual void addAt(int, int) = 0;
		virtual int remove(int) = 0;
		virtual int get(int) = 0;
		virtual void print() = 0;
};