#include <iostream>
#include <map>
#include "list.hpp"
#include "reserve_allocator.hpp"

int main() {

    std::map<int, int, std::less<int>, Reserve_Allocator<std::pair<const int, int>>> m;
    m[0] = 1;
    m[1] = 1;
    for (int i = 2; i <= 9; ++i) {
        m[i] = m[i - 1] * i;
    }
    for (std::pair<int, int> elem : m) {
        std::cout << elem.first << ' ' << elem.second << std::endl;
    }

    List<int, Reserve_Allocator<int>> list;
    std::string query;
    do {
        std::cin >> query;
        if (query == "push") {
            int v;
            std::cin >> v;
            list.push_back(v);
        }
        else if (query == "pop") {
            list.pop_back();
        }
        else if (query == "insert") {
            int ind, v;
            std::cin >> ind >> v;
            auto itr = std::next(list.begin(), ind);
            list.insert(itr, v);
        }
        else if (query == "erase") {
            int ind;
            std::cin >> ind;
            auto itr = std::next(list.begin(), ind);
            list.erase(itr);
        }
        else if (query == "show") {
            for (int elem : list) {
                std::cout << "\033[36m" << elem << "\033[0m" << ' ';
            }
            std::cout << std::endl;
        }
        else if (query == "size") {
            std::cout << "\033[36m" << list.size() << "\033[0m" << std::endl;
        }
    } while (query != "exit" && query != "quit");
}