#include "Heap.h"


void Heap::load(PTR T) {
    tree_list.push_back(T);
    for (int i = 0; i < T->childs.size(); i++) {
        load(T->childs[i]);
    }
}

PTH Heap::create(std::string filename) {
    PTR T = Tree::create_t(filename);
    PTH res = std::make_unique<Temp2>();
    res->load(T);
    return std::move(res);
}

void Heap::print() {
    for (auto x : tree_list) {
        std::cout << x->value << std::endl;
    }
}

iterator Heap::begin() {
    return tree_list.begin();
}

iterator Heap::end() {
    return tree_list.end();
}

iterator Heap::find(double value) {
    iterator it = this->begin();
    while (it != this->end()) {
        if ((*it)->value == value) {
            break;
        }
        it++;
    }
    return it;
}

iterator Heap::find(std::string name) {
    iterator it = this->begin();
    while (it != this->end()) {
        if ((*it)->name == name) {
            break;
        }
        it++;
    }
    return it;
}

iterator Heap::add(double value, std::string name, iterator num) {
    try {
        auto temp = std::make_shared<Tree>(value, name);
        (*num)->childs.insert((*num)->childs.begin(), temp);
        num++;
        tree_list.insert(num, temp);
        return num;
    }
    catch (...) {
        std::cout << "add error" << std::endl;
    }
}

void Heap::save(std::ostream& str) {
    iterator start = begin();
    save(str, start);
}


void Heap::save(std::ostream& str, iterator& it) {
    std::string s = (*it)->name;
    str << "<" << s << ">" << std::endl;
    str << " value = " << (*it)->value << std::endl;
    iterator t = it;
    it++;
    for (int i = 0; i < (*t)->childs.size(); i++) {
        save(str, it);
    }

    str << "</" << s << ">" << std::endl;
}

iterator Heap::parent(iterator son) {
    iterator it = begin();
    if (son == it)
        return it;
    iterator res = it;
    while (res != this->end()) {
        for (int i = 0; i < (*res)->childs.size(); i++) {
            it++;
            if (son == it) return res;
        }
        res++;
    }
}



bool Heap::erase(iterator num) {
    if (num == begin()) {
        std::cout << "erase error" << std::endl;
        return 0;
    }
    try {
        PTR k = *tree_list.begin();
        iterator key = parent(num);
        for (int i = 0; i < (*key)->childs.size(); i++) {
            if (*num == (*key)->childs[i]) {
                (*key)->childs.erase((*key)->childs.begin() + i);
            }
        }
        tree_list.clear();
        load(k);
        return 1;
    }
    catch (...) {
        std::cout << "erase error" << std::endl;
    }
}
