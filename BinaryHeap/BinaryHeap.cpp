#include <stdio.h>
#include <vector>
#include "BinaryHeap.h"

using namespace std;

template <typename T, Ord _>
inline BinaryHeap<T,_>::BinaryHeap (size_type capacity)
{
    content . reserve (capacity);
}

template <typename T, Ord ord>
void BinaryHeap<T,ord>::heapify (int i)
{
    auto lim = content . size ();    
  
    int a, b, k = i;

    for (;;)
    {
        a = i * 2 + 1;
        b = a + 1;
      
        if (a < lim && compare(content [a], content [i]) == ord)
            k = a;
      
        if (b < lim && compare(content [b], content [k]) == ord)
            k = b;
      
        if (k == i) break;
    
        swap(content [i], content [k]);
        i = k;
    }
}

template <typename T, Ord ord>
void BinaryHeap<T,ord>::push (T element)
{
    content . push_back (element);

    int i = content . size () - 1, k = (i - 1) / 2;

    while (i > 0 && compare(content [i], content [k]) == ord)
    {    
        swap(content [i], content [k]);
        i = k;
        k = (i - 1) / 2;
    }
}

template <typename T, Ord _>
inline T BinaryHeap<T,_>::top () const
{
    return this -> content [0];
}

template <typename T, Ord ord>
T BinaryHeap<T,ord>::pop ()
{
    T top = content [0];
  
    content [0] = content . back ();
    content . pop_back ();
    heapify(0);
  
    return top;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int main (void) {
  auto heap = BinaryHeap<int,LT>(20);
  heap.push(1);
  heap.push(6);
  heap.push(3);
  
  //for (int i = 0; i < 20; ++i)
  //heap.push(rand() % 15);
  //for (int i = 0; i < 3; ++i)
  //  printf("heap[%d]: %d\n", i, heap.content[i]);
  return 0;
}