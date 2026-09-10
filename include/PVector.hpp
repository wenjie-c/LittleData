#ifndef PVector_HPP
#define PVector_HPP

#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

template <typename E> class PVector {
public:
  PVector() {}
  void insert(E *item) { _vector.push_back(item); }
  E *find(function<bool(E *)> pred) {
    auto found = find_if(_vector.cbegin(), _vector.cend(), pred);
    if (found == _vector.cend())
      return NULL;
    return (*found);
  }

  void remove(function<bool(E *)> pred) {
    auto found = find_if(_vector.cbegin(), _vector.cend(), pred);
    if (found == _vector.cend())
      return;
    delete (*found);
    _vector.erase(found);
  }

  void clear() {
    for (E *item : _vector) {
      delete item;
    }
    _vector.clear();
  }

  ~PVector<E>() { clear(); }

private:
#pragma region PVector_VARIABLES
  vector<E *> _vector;
#pragma endregion PVector_VARIABLES
};
#endif // PVector_HPP