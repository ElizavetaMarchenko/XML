#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <iterator>
#include "Tree.h"

class Heap;
using PTH = std::unique_ptr<Heap>;


class Heap {
private:
	std::list<PTR> tree_list;
	iterator begin();
	iterator end();
	Heap() = default;
	void load(PTR T);
	class Temp2;
	void save(std::ostream& str, iterator& it);
	iterator parent(iterator son);
public:
	static PTH create(std::string filename);
	void print();
	iterator find(double value);
	iterator find(std::string name);
	iterator add(double value, std::string name, iterator num);
	void save(std::ostream& str);
	bool erase(iterator num);
};

class Heap::Temp2 : public Heap {
public:
	using Heap::Heap;
};