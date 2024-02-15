#ifndef LinkedListStack
#define LinkedListStack

template <typename T>
class LLStack {
public:
  /**
   * Push data onto the stack.
  */
  void push(T data) {
    Node* new_node = new Node;
    new_node->data = data;

    if (this->current_node) {
      new_node->previous_node = this->current_node;
    } else {
      new_node->previous_node = nullptr;
    }

    this->current_node = new_node;
    this->size++;
  }

  /**
   * Pop data from the stack.
  */
  T pop() {
    Node* node = this->current_node;
    T data;

    if (node) {
      data = node->data;
      this->current_node = node->previous_node;

      delete node;
      this->size--;
    }

    return data;
  }

  /**
   * Get the current size of the stack.
  */
  int getSize() {
    return this->size;
  }

  ~LLStack() {
    Node* node = this->current_node;
    while (node) {
      Node* prev_node = node->previous_node;

      delete node;

      node = prev_node;
    }
  }

private:
  struct Node {
    T data;
    Node* previous_node;
  };

  int size = 0;
  Node* current_node = nullptr;
};

#endif
