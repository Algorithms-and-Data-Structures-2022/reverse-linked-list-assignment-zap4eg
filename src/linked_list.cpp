#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* prev = nullptr;
    Node* cur = front_;
    while (cur != nullptr) {
      Node* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    std::swap(front_, back_);
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    std::swap(front_, back_);
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverse_recursive_helper(next, curr);
  }

}  // namespace assignment
