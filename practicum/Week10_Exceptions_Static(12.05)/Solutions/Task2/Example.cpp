#include <type_traits>

template <typename T>
struct name {
  void CreateOtherClass() { T t{}; }
};

template <typename T>
struct name1 {
    void CreateOtherClass() noexcept(std::is_nothrow_default_constructible<T>::value) { T t{}; }
};
