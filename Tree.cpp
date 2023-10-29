#include "Tree.h"
#include "Heap.h"

void Tree::print() {
    std::cout << "<" << name << ">  " << value << std::endl;
    for (int i = 0; i < childs.size(); i++) {
        childs[i]->print();
    }
    std::cout << "</" << name << ">  " << std::endl;
}

void Tree::load_t(std::istream& is) {
    std::string s;

    is >> s;
    if (s[0] != '<' || s.back() != '>') {
        throw std::exception();
    }
    name = s.substr(1, s.size() - 2);
    is >> s;
    if (s != "value") {
        throw std::exception();
    }

    is >> s;
    if (s != "=") {
        throw std::exception();
    }
    double x;
    is >> x;
    value = x;

    is >> s;
    std::string close = "</" + name + ">";
    while (!is.eof() && s != close) {
        for (auto it = s.rbegin(); it != s.rend(); it++)
            is.putback(*it);
        childs.emplace_back(new Tree());
        childs.back()->load_t(is);
        is >> s;
    }

    if (s != close) {
        throw std::exception();
    }
}


PTR Tree::create_t(std::string filename) {
    std::ifstream in(filename);
    PTR res = std::make_unique<Tree>();
    try {
        res->load_t(in);
        return std::move(res);
    }
    catch (const std::exception& e) {
        std::cout << "LOAD ERROR" << std::endl;
    }
}
