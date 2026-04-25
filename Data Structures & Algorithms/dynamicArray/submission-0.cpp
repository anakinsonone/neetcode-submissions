class DynamicArray {
private:
  int *array;
  int capacity;
  int current;

public:
  // constructor
  DynamicArray(int capacity) : capacity(capacity), current(0) {
    array = new int[capacity];
  }
  // destructor - free up space
  ~DynamicArray() { delete[] array; }

  int get(int i) { return array[i]; }

  void set(int i, int n) { array[i] = n; }

  void pushback(int n) {
    if (current == capacity) {
      resize();
    }

    array[current] = n;
    current++;
  }

  int popback() {
    current--;
    return array[current];
  }

  void resize() {
    capacity *= 2;
    int *newArray = new int[capacity];
    for (int i = 0; i < current; i++) {
      newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
  }

  int getSize() { return current; }

  int getCapacity() { return capacity; }
};
