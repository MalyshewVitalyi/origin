#include "counter.h"

Counter::Counter(int initial) : count(initial) {}

void Counter::increase() {
	count++;
}

void Counter::decrease() {
	count--;
}

int Counter::getCount() const {
	return count;
}
