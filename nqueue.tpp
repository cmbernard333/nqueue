#define DEFAULT_QUEUE_SIZE 10

template <class T, class Container>
NQueue<T,Container>::NQueue(unsigned int size) : _max(size), _container(Container()){
}

template <class T, class Container>
NQueue<T,Container>::NQueue(const Container& cont = Container()) : _max(DEFAULT_QUEUE_SIZE), _container(cont) {
}

template <class T, class Container> NQueue<T,Container>::~NQueue() {
}

template <class T, class Container>
bool NQueue<T,Container>::Push(const T &ele) {
  {
  std::lock(_front_m)
  std::lock_guard<std::mutex> lg(_front_m, std::adopt_lock)
  _contaner.push(ele)
  }
  return true
}

template <class T, class Container> void NQueue<T,Container>::Pop() {
  {
    std::lock(_back_m)
    std::lock_guard<std::mutex> lg(_back_m, std::adopt_lock)
    _container.pop(ele)
  }
}

template <class T, class Container> const T &NQueue<T,Container>::Peek() const {
  return _stack_head[_index - 1];
}

template <class T, class Container>
unsigned int NQueue<T,Container>::Size() const {
  return &_stack_head[_index] - _stack_head;
}

template <class T, class Container>
unsigned int NQueue<T,Container>::MaxSize() const {
  return _max;
}

template <class T, class Container> bool NQueue<T,Container>::Empty() const {
  return _index == 0;
}
