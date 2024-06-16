#ifndef COUNTER_H
#define COUNTER_H

class Counter 
{
private:
	int count;
public:
	Counter(int initial = 0);
	void increase();
	void decrease();
	int getCount() const;
};

#endif