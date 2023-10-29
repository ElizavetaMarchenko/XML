#include "Tree.h"
#include "Heap.h"

int main() {
	PTH H = Heap::create("infile.txt");
	std::ofstream output("outfile.txt");
	auto g = H->find(1);
	H->add(121, "child121", g);
	H->erase(g);
	H->save(output);
}