#ifndef __LLIST_HH__
#define __LLIST_HH__
template<class T>
struct Node{
    T elem;
    Node* next;
    Node(const T& _elem, Node* _next = nullptr): elem{_elem}, next{_next}{}
};

template<class T>
class LList{
    Node<T>* start;
    Node<T>* end;
    size_t size;
    void copyList(const LList<T>&);
    void destroyList();
    public:
    LList();
    LList(const LList&);
    ~LList();
    LList& operator=(const LList&);
    void print() const;
    void toEnd(const T&);
    void toStart(const T&);
    // void addBefore(const T& element, const T& new_elem);
    // void addBefore(const Node<T>*& element,const T& new_elem);
    // void addAfter(const T& element, const T& new_elem);
    // void addAfter(const Node<T>*& element,const T& new_elem);
    void insertElementAt(const size_t&,const T&);
};
#endif

// int* arr = new int[3]{1,2,3} <=> 1 -> 2 -> 3 -> 4 -> 5

// 1:[elem:1, next: 2]->2:[elem:22, next: 3]->3:[elem:3, next:nullptr] <=> 1 -> 2 -> 3

// resizing to 5 and add 4 and 5
// #############1###########
// #####_____###############
// ###########2####_________
// #######34####5###########
// #########################
