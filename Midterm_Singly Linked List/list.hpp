class List {
public:
    virtual void add(int num) = 0;            // add to the end
    virtual void addAt(int num, int pos) = 0; // insert so num sits at position pos (1-based)
    virtual void addFirst(int) = 0;
    virtual int get(int pos) = 0;             // value at pos (1-based), or -1 if invalid
    virtual void removeFirst() = 0;  
	virtual void removeLast() = 0;
	virtual void removeAt(int) = 0;        // remove first match; return 1 if removed, else 0
    virtual int removeAll(int num) = 0;       // remove every match; return how many
    virtual void print() = 0;
    
};