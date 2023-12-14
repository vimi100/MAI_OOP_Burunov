#include <vector>
#include <map>
#include <memory>

// аллокатор должен работать правильно во всех случаях

template<class T, uint64_t MAX_SIZE = 1000>
class Reserve_Allocator {
    std::vector<T> buffer;
    std::map<uint64_t, uint64_t> free_indexes;
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Reserve_Allocator():
    buffer(MAX_SIZE) {
        free_indexes[0] = MAX_SIZE;
    }

    ~Reserve_Allocator() = default;

    pointer allocate(size_t n) {
        pointer result = nullptr;
        for (std::pair<uint64_t, uint64_t> elem : free_indexes) {
            if (elem.second > n) {
                free_indexes.erase(elem.first);
                free_indexes[elem.first + n] = elem.second - n;
                result = &buffer[elem.first];
                break;
            }
            else if (elem.second == n) {
                free_indexes.erase(elem.first);
                result = &buffer[elem.first];
                break;
            }
        }
        if (result == nullptr) {
            throw std::bad_alloc();
        }
        return result;
    }

    void deallocate(pointer p, size_t n) {
        uint64_t index = (p - &buffer[0]);
        free_indexes[index] = n;
        
        if (free_indexes.count(index + n) > 0) {
            free_indexes[index] += free_indexes[index + n];
            free_indexes.erase(index + n);
        }
        
        auto itr = free_indexes.begin();
        for (; itr->first != index; ++itr);
        --itr;
        if (index != free_indexes.begin()->first && (itr->first + itr->second) == index) {
            itr->second += free_indexes[index];
            free_indexes.erase(index);
        }
    }

    template <class U, class... Args>
    void construct(U *p, Args&& ...args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

    template <class U>
    struct rebind {
        using other = Reserve_Allocator<U>;
    };
};

template <class T, class U>
constexpr bool operator==(const Reserve_Allocator<T> &lhs, const Reserve_Allocator<U> &rhs) 
{
    return true;
}

template <class T, class U>
constexpr bool operator!=(const Reserve_Allocator<T> &lhs, const Reserve_Allocator<U> &rhs)  
{
    return false;
}