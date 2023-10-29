#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <iterator>

class Tree;
class Heap;
using PTR = std::shared_ptr<Tree>;
using PTH = std::unique_ptr<Heap>;
using Children = std::vector<PTR>;
using iterator = std::list<PTR>::iterator;

class Tree {
private:
	class Temp;
	void load_t(std::istream& is);
public:
	Tree() = default;
	Tree(double val, std::string n) { value = val; name = n; };
	static PTR create_t(std::string filename);
	void print();
	Children childs;
	double value;
	std::string name;
	void del() { childs.clear(); delete this; }
};
