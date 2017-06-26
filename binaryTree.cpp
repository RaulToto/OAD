#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <type_traits>

template <typename T> 
struct Node
{
  T data;
  Node<T>* left;
  Node<T>* right;

  Node (T d, Node<T>* l = nullptr, Node<T>* r = nullptr) : data(d), left(l), right(r) {}
};

template<typename T>
void deleteTree ( Node<T>* n)
{
  if ( !n )
    return;
  deleteTree(n->left);
  deleteTree(n->right);
  delete n;
}

template <typename T>
void printBinaryTree (Node<T>* n )
{
  std::unordered_map<int, std::vector<Node<T>*> > m;
  printBinaryTree (n, m, 0);
  for ( auto& i : m )
  {
    std::cout << " Level " << i.first << ": ";
    for ( auto& j : i.second )
      std::cout << j->data << "  ";
  }
  std::cout << std::endl;
}

// print a binary tree level by level
template <typename T>
void printBinaryTree (Node<T>* n, std::unordered_map<int, std::vector<Node<T>*> >& m, int level )
{
  if (n)
  {
    ++level;
    printBinaryTree ( n->left ,m,level);
    printBinaryTree ( n->right,m,level);

    m[level].push_back(n);
  }
}

template <typename ItType>
auto buildBinaryTree (ItType start, ItType end) -> Node<typename std::iterator_traits<ItType>::value_type>*
{
  using T =typename std::iterator_traits<ItType>::value_type;
  auto first = start;
  auto last = std::prev(end);

  if ( first > last ) // error case
    return nullptr;
  else if ( first < last )
  {
    auto mid = first +  ( last - first ) / 2; // avoid overflow
    Node<T>* n = new Node<T>(*mid);
    n->left = buildBinaryTree ( first, mid);
    n->right = buildBinaryTree ( mid+1, end);
    return n;
  }

  // equal
  return new Node<T>(*first);
}

template <typename T> 
Node<T>* buildBinaryTree (std::vector<T>& v)
{
  if  ( v.empty() )
   return nullptr; 

  std::sort(v.begin(), v.end());
  return buildBinaryTree (v.begin(), v.end()); 
}

int main()
{
  std::vector<int> v { 1,2,3,4,5,6,7,8,9,10 };
  Node<int>* root = buildBinaryTree ( v );
  printBinaryTree (root);
  deleteTree(root);
}