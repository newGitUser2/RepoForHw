#include "list2.hpp"
#include <iostream>

int main(){

        List<int> l1;
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_back(4);
        l1.push_back(5);
        l1.push_back(6);
        l1.push_front(7);
        l1.push_front(8);
        l1.push_front(9);
        l1.pop_front();
        l1.pop_front();
        l1.pop_front();
        l1.pop_back();
        l1.pop_back();
        l1.pop_back();
	std::cout << "Size is " << l1.get_size() << '\n';
        l1.insert(14, 3);
        l1.print();
        std::cout << "Size is " << l1.get_size() << '\n';
        std::cout << "Elements of List are: ";
        for(int i = 0; i < l1.get_size(); i++){
                std::cout << l1[i] << " ";
        }
        std::cout << '\n';
        l1.reverse();
        std::cout << "Size is " << l1.get_size() << '\n';
        std::cout << "First element is " << l1.front() << '\n';
        std::cout << "Last element is " << l1.back() << '\n';
	l1.insertion_sort();
	std::cout << "After insertion_sort.\t";
	l1.print();

        return 0;
}
