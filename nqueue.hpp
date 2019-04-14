#pragma once

#include <deque>
#include <mutex>

template <class T, class Container = std::deque<T> > class NQueue {
public:
  typedef T value_type;
  typedef const value_type& const_reference;
  typedef value_type& reference;
  typedef Container container_type;

  explicit NQueue(unsigned int size);
  explicit NQueue(const Container& cont = Container());
  ~NQueue();
  bool Push(const T &ele);
  void Pop();
  T &Front();
  T &Back();
  const T &Front() const;
  const T &Back() const;
  unsigned int Size() const;
  bool Empty() const;

private:
  unsigned int _max;
  std::mutex _front_m;
  std::mutex _back_m;
  container_type _container;

};

#include "nqueue.tpp"