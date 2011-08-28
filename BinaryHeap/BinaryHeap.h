#include <vector>

enum Ord { GT, EQ, LT };

template <typename T>
static inline Ord compare (T a, T b) 
{
    return (a > b) ? GT : (a == b) ? EQ : LT;
}

template <typename T, Ord ord>
class BinaryHeap
{
    typedef typename std::vector<T>::size_type size_type;
private:
    std::vector<T> content;      /* contents of the heap */
    void heapify (int);     /* assures the heap property for root index | O(log(N))  */
public:
    BinaryHeap (size_type); /* ctor: capacity */
    void push  (T);         /* push new element to heap                 | O(log(N))  */
    T    top   ()   const;  /* return top element of the heap           | O(1)       */
    T    pop   ();          /* return & remove top element of the heap  | O(log(N))  */
};